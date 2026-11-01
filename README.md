# KMP String Matching — Đồ án cuối kỳ DSA

Dự án C++17 triển khai, kiểm thử và so sánh hai thuật toán tìm kiếm chuỗi **Naive Search** và **Knuth–Morris–Pratt (KMP)**.

Nội dung bao gồm chương trình Console, Automated Testing, Benchmarking, thống kê phép so sánh ký tự, phân tích độ phức tạp và đánh giá hiệu suất thực nghiệm.

## 1. Thông tin dự án

| Nội dung | Thông tin |
|---|---|
| Môn học | Cấu trúc dữ liệu và giải thuật (DASA230179) |
| Giảng viên | Huỳnh Xuân Phụng |
| Đề tài | Knuth–Morris–Pratt String Matching |
| Ngôn ngữ | C++17 |
| Repository | https://github.com/tobyasteria/KMP-String-Matching |

### Thành viên và phân công

| Thành viên | MSSV | GitHub | Công việc chính |
|---|---|---|---|
| Lương Anh Hào | 25110017 | `tobyasteria` | Triển khai thuật toán, Automated Testing, Benchmark Validation, Complexity Analysis, tích hợp và quản lý GitHub |
| Nguyễn Quốc Hào | 25110018 | `haonguyen457` | Benchmarking, Natural/Adversarial Datasets, Pattern Length Experiments, Comparison Counting và minh chứng thực nghiệm |

## 2. Cấu trúc dự án

```text
KMP-String-Matching/
├── include/
│   └── search.h
├── src/
│   ├── main.cpp
│   ├── naive.cpp
│   ├── kmp.cpp
│   ├── benchmark.cpp
│   ├── comparison_count.cpp
│   ├── week3_pattern_benchmark.cpp
│   ├── week3_natural_benchmark.cpp
│   └── week3_pattern_comparison.cpp
├── tests/
│   ├── test_cases.cpp
│   └── benchmark_validation.cpp
├── results/
│   ├── week2_test_results.txt
│   ├── benchmark_week2.csv
│   ├── week2_comparison_counts.csv
│   ├── week3_pattern_benchmark.csv
│   ├── week3_natural_benchmark.csv
│   └── week3_pattern_comparisons.csv
├── evidence/
│   └── week4_final_tests.png
├── report/
│   ├── weekly_report_01.md
│   ├── weekly_report_02.md
│   ├── weekly_report_03.md
│   ├── weekly_report_04.md
│   ├── week1_hand_trace.md
│   ├── week1_self_explanation.md
│   ├── week2_benchmark_method.md
│   ├── week3_benchmark_method.md
│   ├── week3_complexity_analysis.md
│   ├── week4_final_summary.md
│   └── week4_defense_notes.md
├── tools/
│   └── download_week3_natural_text.ps1
├── README.md
└── AI_USAGE_LOG.md
```

Thư mục `evidence/` còn chứa ảnh Benchmark, Comparison Counting và biểu đồ của các tuần trước. Dữ liệu Natural Text được tải về máy khi thực hiện thí nghiệm, không lưu toàn bộ văn bản nguồn trong repository.

## 3. Hướng dẫn biên dịch và chạy

**Yêu cầu:** Trình biên dịch G++ hỗ trợ C++17.

Thực hiện các lệnh trong PowerShell tại thư mục gốc dự án.

### 3.1. Chương trình chính

```powershell
g++ -std=c++17 -Wall -Wextra -Iinclude src/main.cpp src/naive.cpp src/kmp.cpp -o main.exe
.\main.exe
```

Ví dụ:

```text
Text: ABABABAC
Pattern: ABABAC
LPS: 0 0 1 2 3 0
Naive matches: 2
KMP matches: 2
Verification: PASS
```

Vị trí khớp được đánh số từ 0.

### 3.2. Automated Testing

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -Iinclude tests/test_cases.cpp src/naive.cpp src/kmp.cpp -o tests.exe
.\tests.exe
```

**Kết quả:** 17/17 PASS.

### 3.3. Benchmark Validation

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -Iinclude tests/benchmark_validation.cpp src/naive.cpp src/kmp.cpp -o validation.exe
.\validation.exe
```

**Kết quả:** 5/5 PASS.

### 3.4. Benchmark Tuần 2

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -Iinclude src/benchmark.cpp src/naive.cpp src/kmp.cpp -o benchmark.exe
.\benchmark.exe
```

### 3.5. Comparison Counting Tuần 2

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -Iinclude src/comparison_count.cpp src/naive.cpp src/kmp.cpp -o comparison.exe
.\comparison.exe
```

### 3.6. Pattern Length Benchmark Tuần 3

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -Iinclude src/week3_pattern_benchmark.cpp src/naive.cpp src/kmp.cpp -o week3_pattern_benchmark.exe
.\week3_pattern_benchmark.exe
```

### 3.7. Natural Text Benchmark Tuần 3

Tải dữ liệu:

```powershell
powershell -File tools/download_week3_natural_text.ps1
```

Biên dịch và chạy:

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -Iinclude src/week3_natural_benchmark.cpp src/naive.cpp src/kmp.cpp -o week3_natural_benchmark.exe
.\week3_natural_benchmark.exe
```

Nguồn văn bản: *The Adventures of Sherlock Holmes* — Arthur Conan Doyle, Project Gutenberg eBook #1661.

### 3.8. Pattern Comparison Counting Tuần 3 và kiểm chứng Tuần 4

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -Iinclude src/week3_pattern_comparison.cpp src/naive.cpp src/kmp.cpp -o week3_pattern_comparison.exe
.\week3_pattern_comparison.exe
```

**Kết quả:** 5/5 PASS.

Lưu ý: Khi chạy lại Benchmark, chương trình có thể ghi đè các file CSV đã lưu. Thời gian thực thi có thể thay đổi theo phần cứng, trình biên dịch và môi trường chạy.

## 4. Tiến độ thực hiện

### Tuần 1 — Core Implementation

- Triển khai `NaiveSearch()`, `buildLPS()` và `KMPSearch()`.
- Xây dựng chương trình Console bằng C++17.
- Kiểm tra kết quả tìm kiếm giữa Naive và KMP.
- Thực hiện Hand Trace với text `ABABABAC` và pattern `ABABAC`.
- Cấu hình môi trường phát triển và GitHub.

**Trạng thái:** Hoàn thành, đã được giảng viên duyệt.

### Tuần 2 — Automated Testing và Benchmarking

- Xây dựng 17 Automated Tests.
- Thực hiện 5 Benchmark Validation Tests.
- Benchmark trên dữ liệu Natural và Adversarial.
- Đo số phép so sánh ký tự của Naive, LPS và KMP.
- Xuất dữ liệu CSV, lưu ảnh minh chứng.
- Hoàn thành và merge PR #1, #2 và #3.

**Kết quả:** Với dữ liệu đối kháng dài 100.000 ký tự, KMP nhanh hơn khoảng 21,6 lần và thực hiện ít hơn khoảng 50,4 lần số phép so sánh so với Naive.

Trên dữ liệu Natural đã thử nghiệm, Naive có thời gian chạy thấp hơn.

**Trạng thái:** Hoàn thành, đã được giảng viên duyệt.

### Tuần 3 — Complexity Analysis và Extended Benchmarking

- Phân tích Time Complexity và Space Complexity.
- Liên hệ lý thuyết với dữ liệu thực nghiệm.
- Giữ text length `n = 100000`, thay đổi pattern length `m = 10, 50, 100, 500, 1000`.
- Mở rộng Benchmark bằng văn bản *The Adventures of Sherlock Holmes*.
- Kiểm tra kết quả bằng `std::string::find()`.
- Xây dựng bộ đếm phép so sánh và biểu đồ.
- Review và merge PR #4.

**Kết quả:**

- Pattern Length Benchmark: 5/5 PASS.
- Natural Text Benchmark: 3/3 PASS.
- Pattern Comparison Counting: 5/5 PASS.

**Trạng thái:** Hoàn thành và tích hợp vào `main`.

### Tuần 4 — Final Verification và Project Completion

- Chạy lại Automated Testing: **17/17 PASS**.
- Chạy lại Benchmark Validation: **5/5 PASS**.
- Chạy lại Pattern Comparison Counting: **5/5 PASS**.
- Lưu ảnh minh chứng `evidence/week4_final_tests.png`.
- Tổng hợp kết quả triển khai, kiểm thử và Benchmark.
- Hoàn thiện Final Project Summary, Defense Notes và Weekly Report 04.
- Cập nhật tài liệu GitHub và chuẩn bị bảo vệ.

**Trạng thái:** Hoàn thành phần triển khai, kiểm thử và tài liệu.

## 5. Tổng hợp kết quả thực nghiệm

### 5.1. Độ phức tạp thuật toán

| Thuật toán | Time Complexity | Auxiliary Space |
|---|---|---|
| Naive Search | O(n × m), worst case | O(1) |
| LPS Construction | O(m) | O(m) |
| KMP Search | O(n), sau tiền xử lý | O(1) ngoài LPS |
| KMP tổng | O(n + m) | O(m) |

Bộ nhớ phụ chưa tính danh sách các vị trí khớp trả về.

### 5.2. Pattern Length Benchmark

Dữ liệu Adversarial: `n = 100000`, pattern gồm `m - 1` ký tự `a` và kết thúc bằng `b`.

| Pattern m | Naive Avg (µs) | KMP Avg (µs) |
|---|---:|---:|
| 10 | 493,140 | 239,310 |
| 50 | 2.177,650 | 240,590 |
| 100 | 4.939,690 | 240,950 |
| 500 | 21.681,930 | 241,510 |
| 1.000 | 42.249,980 | 240,690 |

Với `m = 1000`, KMP nhanh hơn khoảng **175,5 lần** trong phép đo này.

### 5.3. Character Comparison Counting

| Pattern m | Naive Comparisons | KMP Total Comparisons |
|---|---:|---:|
| 10 | 999.910 | 200.008 |
| 50 | 4.997.550 | 200.048 |
| 100 | 9.990.100 | 200.098 |
| 500 | 49.750.500 | 200.498 |
| 1.000 | 99.001.000 | 200.998 |

Với `m = 1000`, Naive thực hiện khoảng **492,5 lần** số phép so sánh của KMP.

### 5.4. Natural Text Benchmark

Pattern: `Sherlock Holmes`, độ dài 15 ký tự.

| Text Length | Naive Avg (µs) | KMP Avg (µs) |
|---|---:|---:|
| 10.000 | 10,540 | 17,780 |
| 50.000 | 50,060 | 91,340 |
| 100.000 | 100,660 | 174,410 |

Trên các trường hợp Natural này, Naive chạy nhanh hơn KMP.

**Nhận xét:** KMP có ưu thế về độ phức tạp trường hợp xấu nhất, nhưng không luôn có thời gian chạy thấp hơn Naive trên mọi dữ liệu.

## 6. Báo cáo và minh chứng

### Tuần 1

- [Weekly Report 01](report/weekly_report_01.md)
- [Hand Trace](report/week1_hand_trace.md)
- [Self Explanation](report/week1_self_explanation.md)
- [Console Evidence](evidence/01_basic_string_matching.png)

### Tuần 2

- [Weekly Report 02](report/weekly_report_02.md)
- [Automated Testing Results](results/week2_test_results.txt)
- [Benchmark CSV](results/benchmark_week2.csv)
- [Comparison Counting CSV](results/week2_comparison_counts.csv)
- [Benchmark Method](report/week2_benchmark_method.md)
- [Automated Testing Evidence](evidence/week2_automated_tests.png)
- [Benchmark Evidence](evidence/week2_benchmark.png)

### Tuần 3

- [Weekly Report 03](report/weekly_report_03.md)
- [Complexity Analysis](report/week3_complexity_analysis.md)
- [Benchmark Method](report/week3_benchmark_method.md)
- [Pattern Benchmark CSV](results/week3_pattern_benchmark.csv)
- [Natural Benchmark CSV](results/week3_natural_benchmark.csv)
- [Pattern Comparison CSV](results/week3_pattern_comparisons.csv)
- [Pattern Benchmark Evidence](evidence/week3_pattern_benchmark.png)
- [Natural Benchmark Evidence](evidence/week3_natural_benchmark.png)
- [Comparison Evidence](evidence/week3_pattern_comparison.png)
- [Pattern Time Chart](evidence/week3_chart_pattern_time.png)
- [Pattern Comparison Chart](evidence/week3_chart_pattern_comparisons.png)
- [Natural Time Chart](evidence/week3_chart_natural_time.png)

### Tuần 4

- [Weekly Report 04](report/weekly_report_04.md)
- [Final Project Summary](report/week4_final_summary.md)
- [Defense Notes](report/week4_defense_notes.md)
- [Final Testing Evidence](evidence/week4_final_tests.png)

### Pull Requests và lịch sử GitHub

- [PR #1 — Automated Testing](https://github.com/tobyasteria/KMP-String-Matching/pull/1)
- [PR #2 — Benchmark Validation và Comparison Counting](https://github.com/tobyasteria/KMP-String-Matching/pull/2)
- [PR #3 — Benchmark và Evidence](https://github.com/tobyasteria/KMP-String-Matching/pull/3)
- [PR #4 — Extended Benchmarking](https://github.com/tobyasteria/KMP-String-Matching/pull/4)
- [Commit History](https://github.com/tobyasteria/KMP-String-Matching/commits/main)
- [AI Usage Log](AI_USAGE_LOG.md)

## 7. Hạn chế

- Benchmark được thực hiện trên một số nhóm dữ liệu và kích thước cụ thể.
- Thời gian chạy phụ thuộc cấu hình máy và trình biên dịch.
- Các bộ đếm phép so sánh là phiên bản có instrumentation riêng.
- Automated Testing không bảo đảm tính đúng đắn cho mọi đầu vào.
- Natural Text Benchmark chưa đại diện cho tất cả loại văn bản thực tế.

## 8. Kết luận

Đồ án đã hoàn thành việc triển khai, kiểm thử và đánh giá Naive Search và KMP bằng C++17.

Kết quả cho thấy KMP hạn chế số phép so sánh lặp lại nhờ LPS và đạt độ phức tạp tổng O(n + m), trong khi Naive có độ phức tạp trường hợp xấu nhất O(n × m).

Thực nghiệm cũng chứng minh rằng hiệu suất thực tế phụ thuộc vào dữ liệu: KMP có lợi thế lớn trong trường hợp đối kháng, còn Naive có thể nhanh hơn trên dữ liệu Natural.

Source code, kết quả CSV, tài liệu và minh chứng được lưu trong repository để phục vụ việc kiểm tra và bảo vệ đồ án.