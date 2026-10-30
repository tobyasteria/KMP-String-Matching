
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "search.h"

using namespace std;

const int TEXT_LENGTH = 100000;

struct CountResult {
    vector<int> matches;
    long long comparisons = 0;
};

struct LPSResult {
    vector<int> lps;
    long long comparisons = 0;
};

vector<int> findWithStd(const string& text, const string& pattern) {
    vector<int> positions;

    if (pattern.empty()) return positions;

    size_t pos = text.find(pattern);

    while (pos != string::npos) {
        positions.push_back((int)pos);
        pos = text.find(pattern, pos + 1);
    }

    return positions;
}

CountResult naiveWithCount(const string& text, const string& pattern) {
    CountResult result;

    int n = text.size();
    int m = pattern.size();

    if (m == 0 || n < m) return result;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        while (j < m) {
            result.comparisons++;

            if (text[i + j] != pattern[j]) {
                break;
            }

            j++;
        }

        if (j == m) {
            result.matches.push_back(i);
        }
    }

    return result;
}

LPSResult buildLPSWithCount(const string& pattern) {
    LPSResult result;

    int m = pattern.size();
    result.lps.assign(m, 0);

    int len = 0;

    for (int i = 1; i < m;) {
        result.comparisons++;

        if (pattern[i] == pattern[len]) {
            result.lps[i++] = ++len;
        }
        else if (len != 0) {
            len = result.lps[len - 1];
        }
        else {
            result.lps[i++] = 0;
        }
    }

    return result;
}

CountResult kmpWithCount(const string& text,
                         const string& pattern,
                         const vector<int>& lps) {
    CountResult result;

    int n = text.size();
    int m = pattern.size();

    if (m == 0 || n < m) return result;

    int i = 0;
    int j = 0;

    while (i < n) {
        result.comparisons++;

        if (text[i] == pattern[j]) {
            i++;
            j++;

            if (j == m) {
                result.matches.push_back(i - j);
                j = lps[j - 1];
            }
        }
        else if (j != 0) {
            j = lps[j - 1];
        }
        else {
            i++;
        }
    }

    return result;
}

int main() {
    vector<int> patternLengths = {10, 50, 100, 500, 1000};
    string text(TEXT_LENGTH, 'a');

    filesystem::create_directories("results");

    ofstream csv("results/week3_pattern_comparisons.csv");

    if (!csv.is_open()) {
        cerr << "Cannot create comparison CSV file.\n";
        return 1;
    }

    csv << "Dataset,TextLength,PatternLength,"
        << "NaiveComparisons,LPSComparisons,"
        << "KMPSearchComparisons,KMPTotalComparisons,Verification" <<'\n';

    cout << "Week 3 - Pattern Comparison Count\n";
    cout << "Dataset: Adversarial | Text length: "
         << TEXT_LENGTH << '\n';

    cout << "Pattern m | Naive | LPS | KMP Search | KMP Total | Verification\n";

    for (int m : patternLengths) {
        string pattern = string(m - 1, 'a') + 'b';

        vector<int> expected = findWithStd(text, pattern);

        if (!expected.empty()) {
            cerr << "Verification FAIL: std::string::find() "
                 << "returned unexpected matches for m = " << m << '\n';
            return 2;
        }

        CountResult naive = naiveWithCount(text, pattern);
        LPSResult lps = buildLPSWithCount(pattern);
        CountResult kmp = kmpWithCount(text, pattern, lps.lps);

        bool valid =
            naive.matches == NaiveSearch(text, pattern) &&
            kmp.matches == KMPSearch(text, pattern) &&
            lps.lps == buildLPS(pattern) &&
            naive.matches == expected &&
            kmp.matches == expected;

        long long kmpTotal =
            lps.comparisons + kmp.comparisons;

        csv << "Adversarial,"
            << TEXT_LENGTH << ","
            << m << ","
            << naive.comparisons << ","
            << lps.comparisons << ","
            << kmp.comparisons << ","
            << kmpTotal << ","
            << (valid ? "PASS" : "FAIL") << '\n';

        cout << m << " | "
             << naive.comparisons << " | "
             << lps.comparisons << " | "
             << kmp.comparisons << " | "
             << kmpTotal << " | "
             << (valid ? "PASS" : "FAIL") << '\n';

        if (!valid) {
            cerr << "Verification FAIL for m = " << m << '\n';
            csv.close();
            return 3;
        }
    }

    csv.close();

    cout << "\nResults saved to "
         << "results/week3_pattern_comparisons.csv\n";

    cout << "Overall verification: PASS\n";

    return 0;
}
