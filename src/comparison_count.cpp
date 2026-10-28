#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "search.h"

using namespace std;

struct CountResult {
    vector<int> matches;
    long long comparisons = 0;
};

CountResult naiveWithCount(const string& text,
                           const string& pattern) {
    CountResult result;

    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());

    if (m == 0 || n < m) return result;

    for (int i = 0; i <= n - m; ++i) {
        int j = 0;

        while (j < m) {
            ++result.comparisons;

            if (text[i + j] != pattern[j]) {
                break;
            }

            ++j;
        }

        if (j == m) {
            result.matches.push_back(i);
        }
    }

    return result;
}

struct LPSResult {
    vector<int> lps;
    long long comparisons = 0;
};

LPSResult buildLPSWithCount(const string& pattern) {
    LPSResult result;

    int m = static_cast<int>(pattern.size());
    result.lps.assign(m, 0);

    int len = 0;

    for (int i = 1; i < m;) {
        ++result.comparisons;

        if (pattern[i] == pattern[len]) {
            result.lps[i++] = ++len;
        } else if (len != 0) {
            len = result.lps[len - 1];
        } else {
            result.lps[i++] = 0;
        }
    }

    return result;
}

CountResult kmpWithCount(const string& text,
                         const string& pattern,
                         const vector<int>& lps) {
    CountResult result;

    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());

    if (m == 0 || n < m) return result;

    int i = 0;
    int j = 0;

    while (i < n) {
        ++result.comparisons;

        if (text[i] == pattern[j]) {
            ++i;
            ++j;

            if (j == m) {
                result.matches.push_back(i - j);
                j = lps[j - 1];
            }
        } else if (j != 0) {
            j = lps[j - 1];
        } else {
            ++i;
        }
    }

    return result;
}


int main() {
    ofstream csv("results/week2_comparison_counts.csv");

    if (!csv.is_open()) {
        cerr << "Cannot open CSV file.\n";
        return 1;
    }

    csv << "Dataset,TextLength,PatternLength,"
        << "NaiveComparisons,LPSComparisons,"
        << "KMPSearchComparisons,KMPTotalComparisons,Verification\n";

    vector<int> sizes = {10000, 50000, 100000};

    for (int n : sizes) {
        for (int type = 0; type < 2; ++type) {
            string name;
            string text;
            string pattern;

            if (type == 0) {
                name = "Natural";

                string sentence =
                    "Learning algorithms and data structures helps solve programming problems. ";

                while (static_cast<int>(text.size()) < n) {
                    text += sentence;
                }

                text.resize(n);
                pattern = "algorithms";
            } else {
                name = "Adversarial";
                text = string(n, 'a');
                pattern = string(100, 'a') + 'b';
            }

            CountResult naive = naiveWithCount(text, pattern);
            LPSResult lps = buildLPSWithCount(pattern);
            CountResult kmp = kmpWithCount(text, pattern, lps.lps);

            bool valid =
                naive.matches == NaiveSearch(text, pattern) &&
                kmp.matches == KMPSearch(text, pattern) &&
                lps.lps == buildLPS(pattern) &&
                naive.matches == kmp.matches;

            long long kmpTotal =
                lps.comparisons + kmp.comparisons;

            csv << name << ","
                << n << ","
                << pattern.size() << ","
                << naive.comparisons << ","
                << lps.comparisons << ","
                << kmp.comparisons << ","
                << kmpTotal << ","
                << (valid ? "PASS" : "FAIL") << '\n';

            cout << name
                 << " | N = " << n
                 << " | Naive = " << naive.comparisons
                 << " | KMP Total = " << kmpTotal
                 << " | " << (valid ? "PASS" : "FAIL")
                 << '\n';

            if (!valid) {
                return 1;
            }
        }
    }

    cout << "\nResults saved to "
         << "results/week2_comparison_counts.csv\n";

    return 0;
}
