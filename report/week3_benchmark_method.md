# Week 3 Benchmark Method

## 1. Purpose

This experiment studies how pattern length affects Naive Search and KMP Search, then compares both algorithms on a varied English-language text. The benchmark reuses the existing `NaiveSearch()` and `KMPSearch()` implementations from `src/naive.cpp` and `src/kmp.cpp`.

## 2. Pattern Length Benchmark

- Dataset: Adversarial.
- Text length: `n = 100000` characters, all equal to `a`.
- Pattern lengths: `m = 10, 50, 100, 500, 1000`.
- Each pattern contains `m - 1` characters `a`, followed by one final character `b`.
- None of these patterns occurs in the text, so the expected match count is zero.

This input makes Naive Search repeatedly compare a long prefix of `a` before reaching the final mismatch. KMP can use its LPS table to avoid restarting the comparison from the beginning at every text position.

## 3. Natural Text Benchmark

The benchmark uses *The Adventures of Sherlock Holmes* by Arthur Conan Doyle, Project Gutenberg eBook #1661:

- Source page: https://www.gutenberg.org/ebooks/1661
- Plain-text source: https://www.gutenberg.org/cache/epub/1661/pg1661.txt
- The source page identifies the work as public domain in the United States. Copyright status can differ by country; check local requirements before redistributing the source text.
- Download the source with `tools/download_week3_natural_text.ps1`. The downloaded text file is kept in `data/week3_natural_source.txt` and is not required to be committed to the repository.
- The program removes the Project Gutenberg wrapper, converts the remaining text to printable ASCII, and collapses repeated whitespace. This makes `std::string::size()` correspond to the character count used in this experiment.
- Text lengths: `n = 10000, 50000, 100000`, taken as prefixes of the cleaned source.
- Pattern: `Sherlock Holmes`, with `m = 15` characters.

The Natural dataset contains many different sentences and words from the source text; it is not made by repeating one sentence.

## 4. Timing Procedure

- C++ standard: C++17.
- Suggested compiler: G++.
- Optimization flag: `-O2`.
- Timer: `std::chrono::steady_clock`.
- Warm-up: 2 calls to each algorithm for every test case.
- Measurement: 10 calls to each algorithm for every test case.
- Reported time: arithmetic mean of the 10 measured durations, in microseconds (`us`).
- KMP timing includes the LPS preprocessing performed inside the existing `KMPSearch()` function.
- Timing covers the search function calls and result-vector construction. Dataset generation, verification, CSV writing, and console output are outside the timed sections.

## 5. Correctness Verification

For every test case, the program obtains all match positions using repeated calls to `std::string::find()`. It then checks that both `NaiveSearch()` and `KMPSearch()` return exactly the same position vector. A `PASS` is printed and written to the CSV only when both comparisons succeed. A failed comparison makes the program exit with a non-zero status.

## 6. Build and Run

Run these commands from the repository root in PowerShell:

```powershell
g++ --version

g++ -std=c++17 -O2 -Wall -Wextra -Iinclude src/week3_pattern_benchmark.cpp src/naive.cpp src/kmp.cpp -o week3_pattern_benchmark.exe
.\week3_pattern_benchmark.exe

g++ -std=c++17 -O2 -Wall -Wextra -Iinclude src/week3_natural_benchmark.cpp src/naive.cpp src/kmp.cpp -o week3_natural_benchmark.exe
powershell -File tools/download_week3_natural_text.ps1
.\week3_natural_benchmark.exe
```

The programs create the `results` directory if it does not exist and write:

- `results/week3_pattern_benchmark.csv`
- `results/week3_natural_benchmark.csv`

Record the actual compiler version and machine configuration from the computer used for the final run. Do not copy timing values from another machine.

## 7. Limitations

- Execution times depend on CPU, operating system, compiler version, optimization flags, background workload, and thermal/power settings.
- The Natural benchmark uses one English work and one selected pattern; it does not represent every natural-language corpus.
- The selected pattern must appear in every tested prefix; the program stops with an error if it is absent, and verifies the exact match positions rather than assuming a count.
- The benchmark measures complete search calls. Since the current `KMPSearch()` builds LPS internally, its reported time includes preprocessing.
- The adversarial test is intentionally structured to expose repeated prefix comparisons in Naive Search; it is not representative of every practical search workload.



## 8. Actual Run Environment

Both benchmarks were compiled and executed on the student's Windows computer.

- Operating environment: Windows PowerShell with MSYS2.
- Compiler: G++ 14.2.0 (Rev2, built by MSYS2 project).
- C++ standard: C++17.
- Compiler flags: `-O2 -Wall -Wextra`.
- Timer: `std::chrono::steady_clock`.
- Warm-up: 2 runs per test case.
- Measurement: 10 repetitions per algorithm per test case.

Both CSV files were regenerated on the student's computer using the downloaded Project Gutenberg text and the specified benchmark datasets. All test cases passed verification against `std::string::find()`.

The measured execution times are specific to this computer and should not be treated as universal performance values. The CPU model was not recorded.
## 9. Pattern Comparison Count

An additional experiment was implemented in `src/week3_pattern_comparison.cpp` to count character comparisons for different pattern lengths.

- Text length: `n = 100000`.
- Pattern lengths: `m = 10, 50, 100, 500, 1000`.
- Dataset: Adversarial text consisting of 100,000 characters `a`.
- Each pattern contains `m - 1` characters `a`, followed by `b`.

The program records four comparison counts:

- `NaiveComparisons`: character comparisons performed by Naive Search, including mismatches.
- `LPSComparisons`: character comparisons performed while constructing the LPS table.
- `KMPSearchComparisons`: character comparisons performed during KMP searching.
- `KMPTotalComparisons`: the sum of LPS preprocessing and KMP searching comparisons.

The comparison-counting implementations are kept separate from the original search algorithms. Their match positions and LPS results are checked against the existing implementations and `std::string::find()`.

The results are saved in `results/week3_pattern_comparisons.csv`. All five test cases passed verification.

Build and run:

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -Iinclude src/week3_pattern_comparison.cpp src/naive.cpp src/kmp.cpp -o week3_pattern_comparison.exe
.\week3_pattern_comparison.exe
```

The comparison counts describe character comparisons, not execution time. They should be interpreted separately from the timing results.
