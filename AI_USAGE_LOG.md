# AI Usage Log — KMP String Matching

**Course:** Data Structures and Algorithms (DASA230179)  
**Week:** 1 — Core Implementation  
**Team:** Lương Anh Hào (25110017), Nguyễn Quốc Hào (25110018)  
**AI used:** ChatGPT (OpenAI)

This log records AI assistance used strictly for programming concepts, algorithm logic, and debugging during Week 1. All code implementation, integration, documentation, reports, and hand traces were written independently by the team members.

## 1. Area and Extent of AI Assistance

| Area | AI assistance | Student work / checks |
|---|---|---|
| Naive Search | Explained index bounds, comparisons, and overlapping matches; reviewed code | Lương Anh Hào integrated `NaiveSearch()` and checked its output |
| LPS Construction | Explained prefix/suffix, `len = lps[len - 1]` fallback and examples; suggested implementation approaches | Lương Anh Hào integrated `buildLPS()` and traced sample patterns |
| KMP Search | Explained `i`/`j`, mismatch fallback, matching and overlap handling; reviewed code | Lương Anh Hào integrated `KMPSearch()` and compared outputs |
| Console integration | Suggested a basic input/output flow and result comparison | Lương Anh Hào edited, compiled and ran `main.cpp` |
| Development tools | Explained G++ flags, VS Code IntelliSense/build tasks, PowerShell and Git commands | Configured the environment, corrected build settings and managed GitHub |
| Algorithm logic | Explained step-by-step state changes for pattern matching (`ABABABAC` / `ABABAC`) | Team reviewed the trace logic and created documentation independently |

## 2. Work and Verification by Team Member

**Lương Anh Hào (25110017):** Organized the C++ project, implemented and integrated algorithm functions with AI conceptual guidance and code review, performed local execution checks, configured VS Code, and managed GitHub.

**Nguyễn Quốc Hào (25110018):** Reviewed source code and logic and compiled/ran the program independently on his own computer, checking the results.

## 3. Limitations and Integrity Notes

- AI assistance was strictly restricted to conceptual explanations, algorithm logic, and debugging for C++ code.
- All text, reports, README files, hand traces, and documentation were written entirely by the students without AI text generation or drafting assistance.
- `Verification: PASS` only confirms that Naive and KMP return the same match positions for the entered input; it is not a full correctness proof.
- `tests/test_cases.cpp` and `src/benchmark.cpp` were not implemented in Week 1.