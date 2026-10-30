#include <chrono>
#include <cctype>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

#include "search.h"

namespace {

const int WARM_UP_RUNS = 2;
const int REPETITIONS = 10;
const std::string PATTERN = "Sherlock Holmes"; // 15 ASCII characters
const std::vector<int> TEXT_LENGTHS = {10000, 50000, 100000};
const std::string DEFAULT_SOURCE = "data/week3_natural_source.txt";

std::string loadNaturalText(const std::string& filePath) {
    std::ifstream input(filePath, std::ios::binary);
    if (!input.is_open()) {
        throw std::runtime_error("Cannot open " + filePath +
            ". Run tools/download_week3_natural_text.ps1 first.");
    }

    std::string raw((std::istreambuf_iterator<char>(input)),
                    std::istreambuf_iterator<char>());

    // Remove Project Gutenberg's wrapper so only the book text is benchmarked.
    const std::string startTag = "*** START OF THE PROJECT GUTENBERG EBOOK";
    const std::string endTag = "*** END OF THE PROJECT GUTENBERG EBOOK";
    const std::size_t start = raw.find(startTag);
    if (start != std::string::npos) {
        const std::size_t newline = raw.find('\n', start);
        raw = (newline == std::string::npos) ? std::string() : raw.substr(newline + 1);
    }

    const std::size_t end = raw.find(endTag);
    if (end != std::string::npos) {
        raw.resize(end);
    }

    // Convert to printable ASCII and collapse whitespace. This makes string
    // length equal to character count for the selected benchmark text.
    std::string cleaned;
    cleaned.reserve(raw.size());
    bool previousWasSpace = true;

    for (unsigned char ch : raw) {
        if (ch <= 127 && std::isspace(ch)) {
            if (!previousWasSpace) {
                cleaned.push_back(' ');
                previousWasSpace = true;
            }
        } else if (ch >= 32 && ch <= 126) {
            cleaned.push_back(static_cast<char>(ch));
            previousWasSpace = false;
        } else {
            if (!previousWasSpace) {
                cleaned.push_back(' ');
                previousWasSpace = true;
            }
        }
    }

    while (!cleaned.empty() && cleaned.back() == ' ') {
        cleaned.pop_back();
    }

    return cleaned;
}

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

int main(int argc, char* argv[]) {
    const std::string sourcePath = (argc > 1) ? argv[1] : DEFAULT_SOURCE;

    try {
        const std::string fullText = loadNaturalText(sourcePath);
        const int patternLength = static_cast<int>(PATTERN.size());

        if (fullText.size() < static_cast<std::size_t>(TEXT_LENGTHS.back())) {
            std::cerr << "Error: cleaned source has only " << fullText.size()
                      << " characters; at least 100000 are required.\n";
            return 1;
        }

        std::filesystem::create_directories("results");
        std::ofstream csv("results/week3_natural_benchmark.csv");
        if (!csv.is_open()) {
            std::cerr << "Error: cannot create results/week3_natural_benchmark.csv\n";
            return 1;
        }

        csv << "Dataset,TextLength,PatternLength,Repetitions,NaiveAvg_us,"
               "KMPAvg_us,MatchCount,Verification\n";

        std::cout << "Week 3 - Natural Text Benchmark\n";
        std::cout << "Source file: " << sourcePath << '\n';
        std::cout << "Pattern: \"" << PATTERN << "\" (m = "
                  << patternLength << ")\n";
        std::cout << "Warm-up: " << WARM_UP_RUNS
                  << " | Measured repetitions: " << REPETITIONS << "\n\n";
        std::cout << std::left << std::setw(14) << "Text n"
                  << std::setw(18) << "Naive avg (us)"
                  << std::setw(18) << "KMP avg (us)"
                  << std::setw(14) << "Matches"
                  << "Verification\n";

        bool allPassed = true;

        for (int n : TEXT_LENGTHS) {
            const std::string text = fullText.substr(0, static_cast<std::size_t>(n));

            warmUp(text, PATTERN);

            const std::vector<int> expected = findWithStd(text, PATTERN);
            if (expected.empty()) {
                std::cerr << "Error: pattern was not found in the Natural text prefix of length "
                          << n << ". Choose a pattern that occurs in every tested prefix.\n";
                return 2;
            }
            const std::vector<int> naiveResult = NaiveSearch(text, PATTERN);
            const std::vector<int> kmpResult = KMPSearch(text, PATTERN);
            const bool verified =
                (naiveResult == expected && kmpResult == expected);
            allPassed = allPassed && verified;

            const double naiveAvg = measureAverageUs(NaiveSearch, text, PATTERN);
            const double kmpAvg = measureAverageUs(KMPSearch, text, PATTERN);
            const char* verification = verified ? "PASS" : "FAIL";

            csv << "Natural," << n << ',' << patternLength << ',' << REPETITIONS
                << ',' << std::fixed << std::setprecision(3) << naiveAvg
                << ',' << kmpAvg << ',' << expected.size() << ',' << verification
                << '\n';

            std::cout << std::left << std::setw(14) << n
                      << std::setw(18) << std::fixed << std::setprecision(3)
                      << naiveAvg << std::setw(18) << kmpAvg
                      << std::setw(14) << expected.size() << verification << '\n';
        }

        csv.close();
        std::cout << "\nCSV saved: results/week3_natural_benchmark.csv\n";
        std::cout << "Overall verification: " << (allPassed ? "PASS" : "FAIL")
                  << '\n';

        return allPassed ? 0 : 2;
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << '\n';
        return 1;
    }
}
