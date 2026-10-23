# KMP String Matching — DSA Final Project

Implementation and comparison of **Naive String Search** and **Knuth–Morris–Pratt (KMP)** in C++17.

## Project Information

| Field | Detail |
|---|---|
| Course | Data Structures and Algorithms (DASA230179) |
| Semester | HK1 2026–2027 |
| Instructor | Huỳnh Xuân Phụng |
| Language | C++17 |
| Environment | Visual Studio Code, GCC (MSYS2 / MinGW-w64) |
| Repository | https://github.com/tobyasteria/KMP-String-Matching |

## Team and Week 1 Contributions

| Member | Student ID | GitHub | Completed Week 1 work |
|---|---|---|---|
| Lương Anh Hào | 25110017 | [tobyasteria](https://github.com/tobyasteria) | Project setup; implemented Naive Search, LPS and KMP Search with AI assistance; integrated console program; local execution checks; repository management and documentation |
| Nguyễn Quốc Hào | 25110018 | [haonguyen457](https://github.com/haonguyen457) | Reviewed source code and algorithm logic; compiled and executed the program independently on his computer; checked outputs and provided feedback |

The repository is mainly managed through `tobyasteria`. Commits pushed by this account do not imply that the second team member made no contributions. The remaining tasks for Weeks 2–4 will be assigned and recorded according to actual work completed.

## Objectives

1. Implement Naive substring search.
2. Compute the KMP longest proper prefix which is also a suffix (LPS) array.
3. Implement KMP substring search and return all starting positions, including overlaps.
4. Verify both algorithms against each other and independent expected outputs.
5. Benchmark natural-language and adversarial repetitive inputs (Week 2).
6. Explain the LPS fallback through a hand-traced example.
7. Analyze theoretical complexity and experimental evidence (Weeks 2–3).

## Project Structure

```text
KMP_Project/
├── .vscode/                  # Local compiler/build/debug configuration
├── src/
│   ├── main.cpp              # Console input, printing, basic cross-check
│   ├── naive.cpp             # NaiveSearch()
│   ├── kmp.cpp               # buildLPS(), KMPSearch()
│   └── benchmark.cpp         # Placeholder: planned Week 2
├── include/
│   └── search.h              # Function declarations
├── tests/
│   └── test_cases.cpp        # Placeholder: planned Week 2
├── evidence/
│   └── 01_basic_string_matching.png
├── results/                  # Benchmark output: planned Week 2
├── report/
│   ├── week1_hand_trace.md
│   ├── week1_self_explanation.md
│   └── weekly_report_01.md
├── README.md
├── AI_USAGE_LOG.md
└── .gitignore
```

## Build and Run

**Requirements:** G++ supporting C++17, Windows PowerShell or equivalent terminal.

From the project root, compile **all three** source files:

```powershell
g++ -std=c++17 -Wall -Wextra -Iinclude src/main.cpp src/naive.cpp src/kmp.cpp -o main.exe
.\main.exe
```

The application asks for the text and the pattern, prints the LPS array, the positions found by each algorithm, and `Verification: PASS` if their position vectors match. This comparison alone is **not** a complete correctness proof because two implementations could share an error.

**Worked example (expected values):**

```text
Text:    ABABABAC
Pattern: ABABAC
LPS:     0 0 1 2 3 0
Naive matches: 2
KMP matches:   2
Verification: PASS
```

Positions use **0-based indexing**. By project convention, empty patterns return no match positions. For `text = AAAAA` and `pattern = AAA`, expected positions are `0 1 2` (overlapping matches).

## Algorithm Summary

- **Naive:** Check possible starting positions, comparing pattern characters until a mismatch or a full match. Worst-case time: **O(n × m)**.
- **LPS:** For each pattern prefix, compute the length of its longest proper prefix also appearing as a suffix. Preprocessing time: **O(m)**.
- **KMP:** On mismatch, use LPS to change the pattern index rather than moving backward in the text. Search time after preprocessing: **O(n)**; combined time: **O(n + m)**.

Here, `n` is the text length and `m` is the pattern length. Details are in [Hand Trace](report/week1_hand_trace.md) and [Self-Explanation](report/week1_self_explanation.md).

## Progress and Documentation

| Stage | Status |
|---|---|
| Week 1: Core Naive/LPS/KMP functions and console integration | Implemented |
| Week 1: Hand Trace and documentation | Prepared; verify and commit this package |
| Week 2: Automated edge-case tests, comparison counts, natural/adversarial benchmarks | Planned |
| Week 3: Complexity discussion, evaluation and report | Planned |
| Week 4: Final evidence and oral defense preparation | Planned |

- [Week 1 progress report](report/weekly_report_01.md)
- [KMP hand trace](report/week1_hand_trace.md)
- [Student explanation](report/week1_self_explanation.md)
- [AI usage disclosure](AI_USAGE_LOG.md)
- [Week 1 console screenshot](evidence/01_basic_string_matching.png)

## Source Links and Commit History

| Source | GitHub |
|---|---|
| Naive | [src/naive.cpp](https://github.com/tobyasteria/KMP-String-Matching/blob/main/src/naive.cpp) |
| KMP and LPS | [src/kmp.cpp](https://github.com/tobyasteria/KMP-String-Matching/blob/main/src/kmp.cpp) |
| Console entry point | [src/main.cpp](https://github.com/tobyasteria/KMP-String-Matching/blob/main/src/main.cpp) |
| Header | [include/search.h](https://github.com/tobyasteria/KMP-String-Matching/blob/main/include/search.h) |

Existing commits: [core algorithms](https://github.com/tobyasteria/KMP-String-Matching/commit/4a2fe8b92f87982f1c895bb501e94f513fb637c1), [KMP declaration fix](https://github.com/tobyasteria/KMP-String-Matching/commit/a310f75eb8635ec6616e85d6555c4995d2f7ecf5), [Week 1 implementation](https://github.com/tobyasteria/KMP-String-Matching/commit/ee9eee8ae3d123e3aec20c481f7bceac0d0e6631), [screenshot evidence](https://github.com/tobyasteria/KMP-String-Matching/commit/997a1a53be35621cb8ee15e82d09e855b9bf9b05).

## AI Disclosure

ChatGPT assisted with algorithm explanations, sample approaches, code review, compiler troubleshooting, hand-trace preparation, and documentation drafting. The team is responsible for verifying the code and understanding the submitted explanations. See [AI_USAGE_LOG.md](AI_USAGE_LOG.md) for the detailed record.

## Reference

Knuth, D. E., Morris, J. H., & Pratt, V. R. (1977). *Fast Pattern Matching in Strings*. SIAM Journal on Computing, 6(2), 323–350.
