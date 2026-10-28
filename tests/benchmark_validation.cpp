
#include <iostream>
#include <string>
#include <vector>
#include "search.h"

using namespace std;

struct ValidationCase {
    string name;
    string text;
    string pattern;
    vector<int> expected;
};

bool validate(const ValidationCase& test) {
    vector<int> naive = NaiveSearch(test.text, test.pattern);
    vector<int> kmp = KMPSearch(test.text, test.pattern);

    bool passed = (naive == test.expected && kmp == test.expected);

    cout << (passed ? "[PASS] " : "[FAIL] ")
         << test.name << '\n';

    return passed;
}

int main() {
    vector<ValidationCase> tests = {
        {"Natural small", "Learning algorithms is fun", "algorithms", {9}},
        {"Natural repeated", "abc abc abc", "abc", {0, 4, 8}},
        {"Adversarial no match", string(1000, 'a'),
            string(100, 'a') + 'b', {}},
        {"Adversarial overlap", "aaaaaa", "aaaa", {0, 1, 2}},
        {"Pattern absent", "hello world", "xyz", {}}
    };

    int passed = 0;

    for (const auto& test : tests) {
        if (validate(test)) {
            ++passed;
        }
    }

    cout << "\nValidation passed: "
         << passed << "/" << tests.size() << '\n';

    return passed == static_cast<int>(tests.size()) ? 0 : 1;
}
