### Tiến độ Tuần 3 — Complexity Analysis và Benchmark mở rộng

**Phân công:**
- Lương Anh Hào: phân tích độ phức tạp Naive, LPS và KMP; đối chiếu lý thuyết với kết quả Tuần 2; kiểm tra và tích hợp GitHub.
- Nguyễn Quốc Hào: Benchmark thay đổi pattern length, bổ sung dữ liệu Natural từ Project Gutenberg, thống kê phép so sánh và lưu minh chứng.

**Kết quả:**
- Hoàn thành phân tích Time Complexity và Space Complexity.
- Pattern Length Benchmark: 5/5 PASS, với `n = 100000` và `m = 10, 50, 100, 500, 1000`.
- Natural Text Benchmark: 3/3 PASS, sử dụng *The Adventures of Sherlock Holmes*.
- Pattern Comparison Counting: 5/5 PASS.
- Các Benchmark sử dụng C++17, `std::chrono::steady_clock`, 2 lần warm-up và 10 lần đo.
- Kết quả được lưu trong CSV và minh chứng bằng ảnh Terminal.

**Nhận xét:** Trên dữ liệu đối kháng, khi độ dài pattern tăng, số phép so sánh của Naive tăng mạnh, trong khi KMP tăng rất ít. Trên dữ liệu Natural đã thử nghiệm, Naive vẫn có thời gian thực thi thấp hơn KMP.

### Minh chứng Tuần 3

- [Complexity Analysis](report/week3_complexity_analysis.md)
- [Benchmark Method](report/week3_benchmark_method.md)
- [Pattern Length Benchmark](results/week3_pattern_benchmark.csv)
- [Natural Text Benchmark](results/week3_natural_benchmark.csv)
- [Pattern Comparison Counting](results/week3_pattern_comparisons.csv)
- [Ảnh Pattern Benchmark](evidence/week3_pattern_benchmark.png)
- [Ảnh Natural Benchmark](evidence/week3_natural_benchmark.png)
- [Ảnh Pattern Comparison](evidence/week3_pattern_comparison.png)
- [Pull Request #4](https://github.com/tobyasteria/KMP-String-Matching/pull/4)