# KMP String Matching — Đồ án cuối kỳ DSA

Dự án C++17 triển khai và so sánh hai thuật toán tìm kiếm chuỗi **Naive Search** và **Knuth–Morris–Pratt (KMP)**.

Dự án bao gồm chương trình Console, kiểm thử tự động, Benchmark thời gian thực thi, thống kê số phép so sánh ký tự và phân tích độ phức tạp thuật toán.

## 1. Thông tin dự án

| Nội dung | Thông tin |
|---|---|
| Môn học | Cấu trúc dữ liệu và giải thuật (DASA230179) |
| Giảng viên | Huỳnh Xuân Phụng |
| Đề tài | Knuth–Morris–Pratt String Matching |
| Ngôn ngữ | C++17 |
| Repository | https://github.com/tobyasteria/KMP-String-Matching |

### Thành viên và phân công

| Thành viên | MSSV | GitHub | Công việc |
|---|---|---|---|
| Lương Anh Hào | 25110017 | `tobyasteria` | Triển khai Naive/LPS/KMP, Automated Testing, Benchmark Validation, Comparison Counting Tuần 2, Complexity Analysis Tuần 3, quản lý GitHub |
| Nguyễn Quốc Hào | 25110018 | `haonguyen457` | Rà soát thuật toán, xây dựng Benchmark Tuần 2, mở rộng thí nghiệm pattern length và Natural Text Tuần 3, thống kê phép so sánh, lưu minh chứng |

## 2. Cấu trúc project

```text
KMP-String-Matching/
├── .vscode/                        # Cấu hình VS Code
├── include/
│   └── search.h                    # Khai báo hàm thuật toán
├── src/
│   ├── main.cpp                    # Chương trình Console
│   ├── naive.cpp                   # NaiveSearch()
│   ├── kmp.cpp                     # buildLPS(), KMPSearch()
│   ├── benchmark.cpp               # Benchmark Tuần 2
│   ├── comparison_count.cpp        # Đếm phép so sánh Tuần 2
│   ├── week3_pattern_benchmark.cpp # Benchmark theo pattern length
│   ├── week3_natural_benchmark.cpp # Benchmark Natural Text
│   └── week3_pattern_comparison.cpp # Đếm so sánh theo pattern length
├── tests/
│   ├── test_cases.cpp              # 17 Automated Tests
│   └── benchmark_validation.cpp    # 5 Validation Tests
├── results/
│   ├── week2_test_results.txt
│   ├── benchmark_week2.csv
│   ├── week2_comparison_counts.csv
│   ├── week3_pattern_benchmark.csv
│   ├── week3_natural_benchmark.csv
│   └── week3_pattern_comparisons.csv
├── evidence/                       # Ảnh Terminal và biểu đồ
├── report/
│   ├── weekly_report_01.md
│   ├── weekly_report_02.md
│   ├── week1_hand_trace.md
│   ├── week1_self_explanation.md
│   ├── week2_benchmark_method.md
│   ├── week3_complexity_analysis.md
│   └── week3_benchmark_method.md
├── tools/
│   └── download_week3_natural_text.ps1
├── README.md
├── AI_USAGE_LOG.md
└── .gitignore
```

**Lưu ý:** Thư mục `data/` được tạo trên máy khi tải dữ liệu Natural Text và không cần đưa toàn bộ văn bản nguồn lên GitHub.

## 3. Biên dịch và chạy

Yêu cầu: G++ hỗ trợ C++17. Chạy lệnh trong PowerShell tại thư mục gốc project.

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

Vị trí tìm thấy được đánh số từ 0.

### 3.2. Automated Testing

```powershell
g++ -std=c++17 -Wall -Wextra -Iinclude tests/test_cases.cpp src/naive.cpp src/kmp.cpp -o tests.exe
.\tests.exe
```

Kết quả ghi nhận: **17/17 PASS**.

### 3.3. Benchmark Validation

```powershell
g++ -std=c++17 -Wall -Wextra -Iinclude tests/benchmark_validation.cpp src/naive.cpp src/kmp.cpp -o validation.exe
.\validation.exe
```

Kết quả ghi nhận: **5/5 PASS**.

### 3.4. Benchmark và Comparison Counting Tuần 2

```powershell
g++ -std=c++17 -Wall -Wextra -Iinclude src/benchmark.cpp src/naive.cpp src/kmp.cpp -o benchmark.exe
.\benchmark.exe

g++ -std=c++17 -O2 -Wall -Wextra -Iinclude src/comparison_count.cpp src/naive.cpp src/kmp.cpp -o comparison.exe
.\comparison.exe
```

### 3.5. Pattern Length Benchmark Tuần 3

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -Iinclude src/week3_pattern_benchmark.cpp src/naive.cpp src/kmp.cpp -o week3_pattern_benchmark.exe
.\week3_pattern_benchmark.exe
```

### 3.6. Natural Text Benchmark Tuần 3

Tải văn bản nguồn từ Project Gutenberg:

```powershell
powershell -File tools/download_week3_natural_text.ps1
```

Biên dịch và chạy:

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -Iinclude src/week3_natural_benchmark.cpp src/naive.cpp src/kmp.cpp -o week3_natural_benchmark.exe
.\week3_natural_benchmark.exe
```

Nguồn văn bản: *The Adventures of Sherlock Holmes* — Arthur Conan Doyle, Project Gutenberg eBook #1661.

### 3.7. Pattern Comparison Counting Tuần 3

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -Iinclude src/week3_pattern_comparison.cpp src/naive.cpp src/kmp.cpp -o week3_pattern_comparison.exe
.\week3_pattern_comparison.exe
```

**Lưu ý:** Chạy Benchmark có thể ghi đè CSV kết quả đã lưu. Thời gian chạy thay đổi theo máy tính, trình biên dịch và mức tối ưu hóa.

## 4. Tiến độ và kết quả

### Tuần 1 — Core Implementation

- Triển khai `NaiveSearch()`, `buildLPS()` và `KMPSearch()`.
- Tích hợp chương trình Console và đối chiếu kết quả.
- Hoàn thành Hand Trace với text `ABABABAC` và pattern `ABABAC`.
- Cấu hình môi trường G++/VS Code và quản lý GitHub.

**Trạng thái:** Đã được giảng viên duyệt.

### Tuần 2 — Automated Testing và Benchmarking

- Automated Testing: **17/17 PASS**.
- Benchmark Validation: **5/5 PASS**.
- Benchmark trên 6 bộ dữ liệu Natural và Adversarial.
- Triển khai bộ đếm phép so sánh ký tự.
- Xuất kết quả CSV và ảnh Terminal.
- Hoàn thành và merge PR #1, #2 và #3.

**Kết quả:** Trên dữ liệu đối kháng dài 100.000 ký tự, KMP chạy nhanh hơn khoảng 21,6 lần và thực hiện ít hơn khoảng 50,4 lần số phép so sánh. Trên dữ liệu Natural mô phỏng bằng một câu tiếng Anh lặp lại, Naive chạy nhanh hơn trong các thí nghiệm đã thực hiện.

**Trạng thái:** Đã được giảng viên duyệt.

### Tuần 3 — Complexity Analysis và Benchmark mở rộng

**Phân công:**

- Lương Anh Hào: phân tích Time Complexity và Space Complexity của Naive, LPS, KMP; đối chiếu lý thuyết với số liệu Tuần 2; review và tích hợp GitHub.
- Nguyễn Quốc Hào: Benchmark thay đổi pattern length, bổ sung dữ liệu Natural đa dạng, đếm phép so sánh và lưu minh chứng.

**Công việc hoàn thành:**

- Phân tích độ phức tạp Naive: O(n × m) trong trường hợp xấu nhất.
- Phân tích LPS Construction: O(m).
- Phân tích KMP tổng: O(n + m).
- Pattern Length Benchmark: **5/5 PASS**.
- Natural Text Benchmark: **3/3 PASS**.
- Pattern Comparison Counting: **5/5 PASS**.
- Tạo biểu đồ so sánh thời gian thực thi và số phép so sánh.

**Thiết kế thí nghiệm:**

- Dữ liệu Adversarial: giữ `n = 100000`, thay đổi `m = 10, 50, 100, 500, 1000`.
- Dữ liệu Natural: sử dụng văn bản *The Adventures of Sherlock Holmes* với `n = 10000, 50000, 100000` và pattern `Sherlock Holmes` dài 15 ký tự.
- Đo thời gian bằng `std::chrono::steady_clock`, 2 lượt warm-up và 10 lượt đo.
- Kiểm chứng kết quả tìm kiếm bằng `std::string::find()`.

**Kết quả Pattern Length Benchmark:**

| Pattern Length | Naive Avg (µs) | KMP Avg (µs) |
|---|---:|---:|
| 10 | 493,140 | 239,310 |
| 50 | 2.177,650 | 240,590 |
| 100 | 4.939,690 | 240,950 |
| 500 | 21.681,930 | 241,510 |
| 1.000 | 42.249,980 | 240,690 |

**Kết quả Pattern Comparison Counting:**

| Pattern Length | Naive Comparisons | KMP Total |
|---|---:|---:|
| 10 | 999.910 | 200.008 |
| 50 | 4.997.550 | 200.048 |
| 100 | 9.990.100 | 200.098 |
| 500 | 49.750.500 | 200.498 |
| 1.000 | 99.001.000 | 200.998 |

Khi độ dài pattern tăng, số phép so sánh của Naive tăng rất mạnh, còn KMP gần như ổn định trong thí nghiệm này. Đây là kết quả phù hợp với phân tích lý thuyết O(n × m) và O(n + m).

Trên dữ liệu Natural từ văn bản thực tế, Naive tiếp tục có thời gian chạy thấp hơn KMP trong ba kích thước đã thử nghiệm.

**Trạng thái:** Đã triển khai và tích hợp vào nhánh `main`; chưa có kết quả xét duyệt Tuần 3.

## 5. Minh chứng và tài liệu

### Tuần 1

- [Báo cáo tiến độ Tuần 1](report/weekly_report_01.md)
- [Hand Trace KMP](report/week1_hand_trace.md)
- [Self-Explanation](report/week1_self_explanation.md)
- [Ảnh chạy Console](evidence/01_basic_string_matching.png)

### Tuần 2

- [Báo cáo tiến độ Tuần 2](report/weekly_report_02.md)
- [Automated Testing Results](results/week2_test_results.txt)
- [Benchmark CSV](results/benchmark_week2.csv)
- [Comparison Counts CSV](results/week2_comparison_counts.csv)
- [Benchmark Method](report/week2_benchmark_method.md)
- [Ảnh Automated Testing](evidence/week2_automated_tests.png)
- [Ảnh Benchmark](evidence/week2_benchmark.png)
- [Ảnh Comparison Counting](evidence/week2_comparison_benchmark.png)

### Tuần 3

- [Complexity Analysis](report/week3_complexity_analysis.md)
- [Benchmark Method](report/week3_benchmark_method.md)
- [Pattern Length Benchmark CSV](results/week3_pattern_benchmark.csv)
- [Natural Text Benchmark CSV](results/week3_natural_benchmark.csv)
- [Pattern Comparison Counts CSV](results/week3_pattern_comparisons.csv)
- [Ảnh Pattern Benchmark](evidence/week3_pattern_benchmark.png)
- [Ảnh Natural Benchmark](evidence/week3_natural_benchmark.png)
- [Ảnh Pattern Comparison](evidence/week3_pattern_comparison.png)

**Biểu đồ:**

- [Pattern Length — Execution Time](evidence/week3_chart_pattern_time.png)
- [Pattern Length — Character Comparisons](evidence/week3_chart_pattern_comparisons.png)
- [Natural Text — Execution Time](evidence/week3_chart_natural_time.png)

### Lịch sử GitHub

- [PR #1 — Automated Testing](https://github.com/tobyasteria/KMP-String-Matching/pull/1)
- [PR #2 — Benchmark Validation và Comparison Counting](https://github.com/tobyasteria/KMP-String-Matching/pull/2)
- [PR #3 — Benchmark và Evidence](https://github.com/tobyasteria/KMP-String-Matching/pull/3)
- [PR #4 — Week 3 Benchmark](https://github.com/tobyasteria/KMP-String-Matching/pull/4)
- [Toàn bộ lịch sử commit](https://github.com/tobyasteria/KMP-String-Matching/commits/main)

## 6. Giới hạn và lưu ý

- Các kết quả PASS chỉ xác nhận những trường hợp đã kiểm tra, không chứng minh chương trình đúng với mọi đầu vào.
- Thời gian thực thi phụ thuộc vào phần cứng, trình biên dịch và điều kiện hệ thống.
- Các chương trình đếm phép so sánh được triển khai riêng để đo số lần so sánh ký tự; kết quả không nhất thiết bằng số lần đánh giá điều kiện trong mã thuật toán gốc.
- Bộ dữ liệu Adversarial được thiết kế để làm rõ trường hợp bất lợi của Naive Search, không đại diện cho mọi loại văn bản.
- Natural Text Tuần 3 sử dụng một tác phẩm văn học và một pattern cụ thể, nên chưa thể khái quát hiệu suất cho mọi dữ liệu tự nhiên.
- Big-O mô tả giới hạn tăng trưởng tiệm cận, không khẳng định KMP luôn chạy nhanh hơn Naive trong thực tế.

