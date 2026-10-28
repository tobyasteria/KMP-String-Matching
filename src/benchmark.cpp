#include "search.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <fstream>

using namespace std;

string makeNaturalText(int n) {
    string sentence =
        "Learning algorithms and data structures helps solve programming problems. ";

    string text;
    while ((int)text.size() < n) {
        text += sentence;
    }

    text.resize(n);
    return text;
}

vector<int> referenceSearch(const string& text, const string& pattern) {
    vector<int> positions;

    if (pattern.empty()) {
        return positions;
    }

    size_t pos = text.find(pattern);

    while (pos != string::npos) {
        positions.push_back((int)pos);
        pos = text.find(pattern, pos + 1);
    }

    return positions;
}

bool runBenchmark(string name, string text, string pattern, ofstream& csv) {
    vector<int> naiveResult = NaiveSearch(text, pattern);
    vector<int> kmpResult = KMPSearch(text, pattern);
    vector<int> referenceResult = referenceSearch(text, pattern);

    cout << "\nDataset: " << name << endl;
    cout << "Text length: " << text.size() << endl;
    cout << "Pattern length: " << pattern.size() << endl;

    if (naiveResult != kmpResult ||
    naiveResult != referenceResult) {
    cout << "Verification: FAIL" << endl;
    return false;
    }

    cout << "Verification: PASS" << endl;
    cout << "Match count: " << naiveResult.size() << endl;

    const int repetitions = 10;

    for (int i = 0; i < 2; i++) {
        vector<int> a = NaiveSearch(text, pattern);
        vector<int> b = KMPSearch(text, pattern);

        if (a != b) {
            cout << "Verification: FAIL" << endl;
            return false;
        }
    }

    long long naiveTotal = 0;
    auto startNaive = chrono::steady_clock::now();

    for (int i = 0; i < repetitions; i++) {
        vector<int> result = NaiveSearch(text, pattern);
        naiveTotal += result.size();
    }

    auto endNaive = chrono::steady_clock::now();

    long long kmpTotal = 0;
    auto startKMP = chrono::steady_clock::now();

    for (int i = 0; i < repetitions; i++) {
        vector<int> result = KMPSearch(text, pattern);
        kmpTotal += result.size();
    }

    auto endKMP = chrono::steady_clock::now();

    double naiveTime =
        chrono::duration<double, micro>(
            endNaive - startNaive
        ).count() / repetitions;

    double kmpTime =
        chrono::duration<double, micro>(
            endKMP - startKMP
        ).count() / repetitions;

    cout << fixed << setprecision(3);
    cout << "Naive average: " << naiveTime << " us" << endl;
    cout << "KMP average: " << kmpTime << " us" << endl;

    cout << "Naive total matches: " << naiveTotal << endl;
    cout << "KMP total matches: " << kmpTotal << endl;

    csv << name << ","
    << text.size() << ","
    << pattern.size() << ","
    << repetitions << ","
    << fixed << setprecision(3)
    << naiveTime << ","
    << kmpTime << ","
    << naiveResult.size() << ",PASS\n";

    return true;
}

int main() {
    vector<int> sizes = {10000, 50000, 100000};

    ofstream csv("results/benchmark_week2.csv");

    if (!csv.is_open()) {
        cerr << "Cannot open results/benchmark_week2.csv" << endl;
        return 1;
    }

    csv << "Dataset,TextLength,PatternLength,Repetitions,"
        << "NaiveAvg_us,KMPAvg_us,MatchCount,Verification\n";

    for (int n : sizes) {
        string text = makeNaturalText(n);
        string pattern = "algorithms";

        if (!runBenchmark("Natural", text, pattern, csv)) {
            return 1;
        }
    }

    for (int n : sizes) {
        string text(n, 'a');
        string pattern = string(100, 'a') + 'b';

        if (!runBenchmark("Adversarial", text, pattern, csv)) {
            return 1;
        }
    }

    return 0;
}