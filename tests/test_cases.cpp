
#include <iostream>
#include <string>
#include <vector>
#include "search.h"

struct TestCase {
    std::string name;
    std::string text;
    std::string pattern;
    std::vector<int> expected;
};

bool runTest(const TestCase& test) {
    std::vector<int> naive = NaiveSearch(test.text, test.pattern);
    std::vector<int> kmp = KMPSearch(test.text, test.pattern);

    bool naivePass = (naive == test.expected);
    bool kmpPass = (kmp == test.expected);

    bool passed = naivePass && kmpPass;

    std::cout << (passed ? "[PASS] " : "[FAIL] ")
              << test.name << '\n';

    if (!passed) {
        std::cout << "  Naive: "
                  << (naivePass ? "PASS" : "FAIL") << '\n';
        std::cout << "  KMP: "
                  << (kmpPass ? "PASS" : "FAIL") << '\n';
    }

    return passed;
}


bool runLPSTest(const std::string& pattern,
                const std::vector<int>& expected) {
    std::vector<int> actual = buildLPS(pattern);

    bool passed = (actual == expected);

    std::cout << (passed ? "[PASS] " : "[FAIL] ")
              << "LPS: " << pattern << '\n';

    return passed;
}

int main() {
    std::vector<TestCase> tests = {
        {"Basic match", "ABABABAC", "ABABAC", {2}},
        {"Overlapping matches", "AAAAA", "AAA", {0, 1, 2}},
        {"No match", "HELLO", "XYZ", {}},
        {"Pattern longer than text", "ABC", "ABCDE", {}},
        {"Exact match", "ABC", "ABC", {0}},
        {"Empty text", "", "ABC", {}},
        {"Empty pattern", "ABC", "", {}},
        {"Single character pattern", "AAAA", "A", {0, 1, 2, 3}},
        {"Multiple matches", "ABCDABC", "ABC", {0, 4}},
        {"Overlapping pattern", "ABABAB", "ABAB", {0, 2}},
        {"Both empty", "", "", {}},
        {"Single character not found", "ABC", "D", {}}
    };

    int passed = 0;

    for (const TestCase& test : tests) {
        if (runTest(test)) {
            ++passed;
        }
    }


    std::cout << "\n--- LPS Tests ---\n";

    std::vector<std::pair<std::string, std::vector<int>>> lpsTests = {
        {"ABABAC", {0, 0, 1, 2, 3, 0}},
        {"AAAA", {0, 1, 2, 3}},
        {"ABCDE", {0, 0, 0, 0, 0}},
        {"AABAACAABAA", {0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5}},
        {"", {}}
    };

    for (const auto& test : lpsTests) {
        if (runLPSTest(test.first, test.second)) {
            ++passed;
        }
    }


    int total = static_cast<int>(tests.size() + lpsTests.size());

    std::cout << "\nTests passed: "
            << passed << "/" << total << '\n';

    return passed == total ? 0 : 1;


}
