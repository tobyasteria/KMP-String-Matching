## Week 3 — Complexity Analysis and Extended Benchmarking

| Area | AI assistance | Student work and verification |
|---|---|---|
| Complexity Analysis | Explained Time and Space Complexity of Naive, LPS and KMP; suggested formulas connecting theoretical complexity to Week 2 comparison counts | Lương Anh Hào reviewed the formulas and prepared `week3_complexity_analysis.md` |
| Pattern Length Benchmark | Suggested experiment design with fixed text length and varying pattern lengths | Nguyễn Quốc Hào implemented and executed the benchmark, producing 5 verified cases |
| Natural Text Benchmark | Suggested using a more varied natural-language source and independent result verification | Nguyễn Quốc Hào used Project Gutenberg text and recorded 3 benchmark cases |
| Comparison Counting | Suggested counting Naive, LPS and KMP comparisons for different pattern lengths | Nguyễn Quốc Hào implemented the comparison-counting program and recorded 5 verified cases |
| Code Review | Reviewed PR #4 and suggested improvements for checksum handling, verification and comparison counting | Nguyễn Quốc Hào updated the code, reran the experiments and pushed corrections |
| Documentation and Visualization | Assisted with organizing complexity explanations, interpreting experimental results and preparing performance charts | Lương Anh Hào integrated the documentation and reviewed the resulting evidence |

**Observed results:**
- Pattern Length Benchmark: 5/5 PASS.
- Natural Text Benchmark: 3/3 PASS.
- Pattern Comparison Counting: 5/5 PASS.
- Results are stored in the Week 3 CSV files.
- PR #4 and the Complexity Analysis branch were merged into `main`.

**Limitations:** Benchmark timings depend on the execution environment. The comparison-counting implementation is separate from the original algorithms. The recorded results do not establish that KMP is faster for every possible input.