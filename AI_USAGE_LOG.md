# AI Usage Log — KMP String Matching

**Course:** Data Structures and Algorithms (DASA230179)  
**Team:** Lương Anh Hào (25110017), Nguyễn Quốc Hào (25110018)  
**AI used:** ChatGPT (OpenAI)  
**Coverage:** Weeks 1–2

This log distinguishes AI assistance from the team's work, verification, and responsibility for the submitted source code and results.

## 1. Week 1 — Core Implementation

| Area | AI assistance | Student work and verification |
|---|---|---|
| Naive Search | Explained index bounds, overlapping matches and implementation approaches; reviewed logic | Lương Anh Hào integrated `NaiveSearch()` and tested sample results |
| LPS Construction | Explained prefix/suffix definitions and `len = lps[len - 1]` fallback; provided examples and suggestions | Lương Anh Hào integrated `buildLPS()` and examined hand traces |
| KMP Search | Explained `i`/`j`, mismatch fallback and matching cases; reviewed implementation | Lương Anh Hào integrated `KMPSearch()` and compared its outputs |
| Console and tools | Suggested input/output organization and explained G++, VS Code, PowerShell and Git | Team configured the environment, compiled, ran and managed the repository |
| Algorithm understanding | Explained the example `ABABABAC` / `ABABAC` and LPS behavior | Team reviewed the logic and checked examples |

**Actual team contributions:** Lương Anh Hào set up and integrated the program and managed GitHub. Nguyễn Quốc Hào independently reviewed, compiled and ran the code on another computer.

**Week 1 limits:** `Verification: PASS` compared the two algorithms on the selected input; automated tests and benchmarks were not yet implemented.

## 2. Week 2 — Automated Testing, Benchmarking and Analysis

| Area | AI assistance | Student work and verification |
|---|---|---|
| Automated Testing | Suggested test structure, cases, expected outputs, `PASS/FAIL` reporting and G++ build instructions | Lương Anh Hào edited and ran `tests/test_cases.cpp`, reporting **17/17 PASS** (12 search tests, 5 LPS tests) |
| Benchmark Validation | Suggested 5 independently specified test cases and a separate validation program | Lương Anh Hào integrated `tests/benchmark_validation.cpp` and reported **5/5 PASS** |
| Character Comparison Counting | Provided an instrumented design and code suggestions for Naive, LPS and KMP; explained what is counted | Lương Anh Hào integrated `src/comparison_count.cpp`, ran 6 datasets and exported `results/week2_comparison_counts.csv` |
| Benchmark and datasets | AI-assisted explanation and implementation planning for timing, repetitions, dataset selection and verification | Nguyễn Quốc Hào implemented and ran `src/benchmark.cpp`, produced `results/benchmark_week2.csv`, added a reference check with `std::string::find()` and recorded methodology |
| Development workflow | Explained branches, `git add`, commits, pull requests and merge review | Team pushed and merged PR #1 (testing), #2 (comparison counting) and #3 (benchmark evidence/code) |
| Review and documentation | Assisted with organizing evidence, explaining technical limitations and structuring updates | Team captured evidence, checked results and remains responsible for reviewing the final submissions |

### Measured/observed results

- Automated tests: **17/17 PASS**, as reported by Lương Anh Hào.
- Additional benchmark validation: **5/5 PASS**, as reported by Lương Anh Hào.
- Comparison-count analysis: **6/6 verification PASS** across Natural and Adversarial datasets; actual counts are stored in `results/week2_comparison_counts.csv`.
- Benchmark timing: six dataset records, with results saved in `results/benchmark_week2.csv`.
- The benchmark uses two warm-up iterations and ten measured repetitions per algorithm, with time from `std::chrono::steady_clock`.

### Important interpretation notes

- The separately instrumented KMP algorithm uses a different arrangement of character comparisons than the original `src/kmp.cpp`. Its counted comparisons describe the **instrumented version**, not an exact count of evaluations in the original implementation.
- Equality of outputs for the six large datasets is a consistency check. The benchmark's `referenceSearch()` using `std::string::find()` provides a further independent reference for match positions.
- Test passes and measured timings are limited to the datasets, environment and runs used; they are not proof of universal correctness or performance.
- AI generated explanations and code suggestions during the project. The students are responsible for inspecting, integrating, running and validating what they submit. AI involvement in drafts or formatting should be described accurately if the course submission form requests it.

## 3. Responsibility and GitHub Evidence

- **Lương Anh Hào (25110017):** Week 1 algorithm integration; Week 2 automated tests, benchmark validation, comparison counting and PR integration.
- **Nguyễn Quốc Hào (25110018):** Week 1 independent review; Week 2 time benchmark implementation, datasets, CSV, reference verification, method description and screenshots.

GitHub repository: https://github.com/tobyasteria/KMP-String-Matching

- [PR #1 — Automated Testing](https://github.com/tobyasteria/KMP-String-Matching/pull/1)
- [PR #2 — Benchmark Validation and Comparison Counting](https://github.com/tobyasteria/KMP-String-Matching/pull/2)
- [PR #3 — Benchmark Improvements and Evidence](https://github.com/tobyasteria/KMP-String-Matching/pull/3)
