# AI Usage Log — KMP String Matching

**Course:** Data Structures and Algorithms (DASA230179)  
**Week:** 1 — Core Implementation  
**Team:** Lương Anh Hào (25110017), Nguyễn Quốc Hào (25110018)  
**AI used:** ChatGPT (OpenAI)

This record distinguishes **AI assistance** from student activities. It records assistance received during Week 1 rather than claiming all source code was written unaided. Specific prompt wording is summarized, not presented as verbatim transcripts.

| Area | How AI was used | What the students did / checked |
|---|---|---|
| Project planning | Helped break project requirements into four weeks and proposed folder organization | Chose a C++17 console structure, created project files, and managed the repository |
| Naive Search | Explained index bounds, comparisons, and overlap handling; reviewed implementation | Lương Anh Hào implemented/integrated `NaiveSearch()` and inspected its output |
| LPS construction | Explained the prefix/suffix definition, `len = lps[len - 1]` fallback, and sample LPS values; supported implementation | Lương Anh Hào implemented/integrated `buildLPS()` and traced `ABABAC` |
| KMP Search | Explained `i`/`j`, mismatch fallback, and match recording; reviewed implementation | Lương Anh Hào implemented/integrated `KMPSearch()` and compared output to Naive Search |
| Console integration | Suggested example input/output structure and a comparison of returned position vectors | Lương Anh Hào edited `main.cpp`, compiled, and ran the program |
| Development tools | Explained G++, `-std=c++17`, `-Iinclude`, `-o`, PowerShell commands, VS Code IntelliSense and Git commands | Configured the environment, corrected settings, ran commands, and pushed code |
| Hand trace | Helped construct and check a step-by-step example for `ABABABAC` / `ABABAC` | Reviewed the trace and retained it as part of the explanatory documentation |
| Documentation | Helped draft README, progress report, task allocation, and this AI usage log | Team should read, edit, and validate all statements before submission |

## Work and Verification by Team Member

**Lương Anh Hào (25110017):** Set up the project, implemented and integrated the C++ algorithm functions with AI guidance and review, performed local execution checks, managed GitHub, and organized documents/evidence.

**Nguyễn Quốc Hào (25110018):** Reviewed implementation logic and compiled/ran the program independently on his own computer, checking execution results and sharing feedback.

## Limitations and Integrity Notes

- AI supplied explanations, approaches, code suggestions, and documentation drafts; the submitted work is **AI-assisted**, not claimed to be entirely independent of AI.
- A displayed `Verification: PASS` means Naive and KMP returned equal vectors for that input. It does not by itself establish full correctness.
- `tests/test_cases.cpp` and `src/benchmark.cpp` were not implemented during Week 1. Do not report automated tests or measured speedups as completed.
- The independent execution by the second team member is reported from team activity. A separate screenshot is useful if available, but should not be falsely claimed as attached.
- No performance numbers, test-pass counts, or tool versions should be invented.

## Changes and Learning After AI Assistance

During development, the team encountered IntelliSense include/declaration issues and clarified how to compile multiple C++ files. They revised compiler settings, learned to inspect the meaning of G++ flags, and corrected function declarations. The algorithm trace was used to understand why KMP reuses a matched prefix rather than restarting from earlier text positions.

## Planned Week 2 Disclosure

Record any new AI assistance with test generation, benchmark design, profiling, interpretation, and report drafting **after those activities actually take place**. Distinguish AI-suggested test cases from tests that were run and verified.
