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
volatile std::size_t totalChecksum = 0;

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
    std::vector<std::vector<int>> results(REPETITIONS);

    const auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < REPETITIONS; ++i) {
        results[i] = search(text, pattern);
    }

    const auto finish = std::chrono::steady_clock::now();

    std::size_t checksum = 0;

    for (const auto& result : results) {
        checksum = checksum * 31 + result.size() + 1;

        for (int pos : result) {
            checksum = checksum * 31 + static_cast<std::size_t>(pos + 1);
        }
    }

    totalChecksum = totalChecksum + checksum;

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
    const std::string pattern = std::string(m - 1, 'a') + 'b';

    const std::vector<int> expected = findWithStd(text, pattern);

    if (!expected.empty()) {
        std::cerr << "Verification FAIL: std::string::find() "
                  << "returned unexpected matches for m = " << m << '\n';
        return 2;
    }

    const std::vector<int> naiveResult = NaiveSearch(text, pattern);
    const std::vector<int> kmpResult = KMPSearch(text, pattern);

    if (naiveResult != expected || kmpResult != expected) {
        std::cerr << "Verification FAIL for m = " << m << '\n';
        return 3;
    }

    warmUp(text, pattern);

    const double naiveAvg =
        measureAverageUs(NaiveSearch, text, pattern);

    const double kmpAvg =
        measureAverageUs(KMPSearch, text, pattern);

    csv << "Adversarial," << TEXT_LENGTH << ',' << m << ',' << REPETITIONS
        << ',' << std::fixed << std::setprecision(3) << naiveAvg
        << ',' << kmpAvg << ',' << expected.size() << ",PASS\n";

    std::cout << std::left << std::setw(12) << m
              << std::setw(18) << std::fixed << std::setprecision(3)
              << naiveAvg << std::setw(18) << kmpAvg
              << std::setw(14) << expected.size() << "PASS\n";
}

    csv.close();
    std::cout << "\nCSV saved: results/week3_pattern_benchmark.csv\n";
    std::cout << "Total checksum: " << totalChecksum << '\n';
    std::cout << "Overall verification: " << (allPassed ? "PASS" : "FAIL")
              << '\n';

    return allPassed ? 0 : 2;
}
