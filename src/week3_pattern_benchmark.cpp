#include <chrono>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "search.h"

namespace {

const int TEXT_LENGTH = 100000;
const int WARM_UP_RUNS = 2;
const int REPETITIONS = 10;

std::vector<int> findWithStd(const std::string& text, const std::string& pattern) {
    std::vector<int> positions;

    if (pattern.empty()) {
        return positions;
    }

    std::size_t pos = text.find(pattern);
    while (pos != std::string::npos) {
        positions.push_back(static_cast<int>(pos));
        pos = text.find(pattern, pos + 1);
    }

    return positions;
}

template <typename SearchFunction>
double measureAverageUs(SearchFunction search, const std::string& text,
                        const std::string& pattern) {
    std::size_t checksum = 0;
    const auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < REPETITIONS; ++i) {
        std::vector<int> result = search(text, pattern);
        checksum += result.size();
        if (!result.empty()) {
            checksum += static_cast<std::size_t>(result.back());
        }
    }

    const auto finish = std::chrono::steady_clock::now();
    // Keep the returned results observable outside the timed section.
    static std::size_t totalChecksum = 0;
    totalChecksum += checksum;

    const double totalUs =
        std::chrono::duration<double, std::micro>(finish - start).count();
    return totalUs / REPETITIONS;
}

void warmUp(const std::string& text, const std::string& pattern) {
    for (int i = 0; i < WARM_UP_RUNS; ++i) {
        const std::vector<int> naive = NaiveSearch(text, pattern);
        const std::vector<int> kmp = KMPSearch(text, pattern);
        (void)naive;
        (void)kmp;
    }
}

} // namespace

int main() {
    const std::vector<int> patternLengths = {10, 50, 100, 500, 1000};
    const std::string text(TEXT_LENGTH, 'a');

    std::filesystem::create_directories("results");
    std::ofstream csv("results/week3_pattern_benchmark.csv");
    if (!csv.is_open()) {
        std::cerr << "Error: cannot create results/week3_pattern_benchmark.csv\n";
        return 1;
    }

    csv << "Dataset,TextLength,PatternLength,Repetitions,NaiveAvg_us,"
           "KMPAvg_us,MatchCount,Verification\n";

    std::cout << "Week 3 - Pattern Length Benchmark\n";
    std::cout << "Dataset: Adversarial | Text length: " << TEXT_LENGTH << '\n';
    std::cout << "Warm-up: " << WARM_UP_RUNS
              << " | Measured repetitions: " << REPETITIONS << "\n\n";
    std::cout << std::left << std::setw(12) << "Pattern m"
              << std::setw(18) << "Naive avg (us)"
              << std::setw(18) << "KMP avg (us)"
              << std::setw(14) << "Matches"
              << "Verification\n";

    bool allPassed = true;

    for (int m : patternLengths) {
        // m - 1 'a' characters followed by 'b'; this pattern is absent.
        const std::string pattern = std::string(m - 1, 'a') + 'b';

        warmUp(text, pattern);

        const std::vector<int> expected = findWithStd(text, pattern);
        const std::vector<int> naiveResult = NaiveSearch(text, pattern);
        const std::vector<int> kmpResult = KMPSearch(text, pattern);
        const bool verified = (naiveResult == expected && kmpResult == expected);
        allPassed = allPassed && verified;

        const double naiveAvg =
            measureAverageUs(NaiveSearch, text, pattern);
        const double kmpAvg =
            measureAverageUs(KMPSearch, text, pattern);

        const char* verification = verified ? "PASS" : "FAIL";

        csv << "Adversarial," << TEXT_LENGTH << ',' << m << ',' << REPETITIONS
            << ',' << std::fixed << std::setprecision(3) << naiveAvg
            << ',' << kmpAvg << ',' << expected.size() << ',' << verification
            << '\n';

        std::cout << std::left << std::setw(12) << m
                  << std::setw(18) << std::fixed << std::setprecision(3)
                  << naiveAvg << std::setw(18) << kmpAvg
                  << std::setw(14) << expected.size() << verification << '\n';
    }

    csv.close();
    std::cout << "\nCSV saved: results/week3_pattern_benchmark.csv\n";
    std::cout << "Overall verification: " << (allPassed ? "PASS" : "FAIL")
              << '\n';

    return allPassed ? 0 : 2;
}
