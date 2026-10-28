# KMP String Matching — Đồ án cuối kỳ DSA

Dự án C++17 triển khai và so sánh hai thuật toán tìm kiếm chuỗi **Naive Search** và **Knuth–Morris–Pratt (KMP)**. Ngoài chương trình Console, nhóm xây dựng kiểm thử tự động, đo thời gian thực thi và thống kê số phép so sánh ký tự.

## 1. Thông tin dự án

| Nội dung | Thông tin |
|---|---|
| Môn học | Cấu trúc dữ liệu và giải thuật (DASA230179) |
| Giảng viên | Huỳnh Xuân Phụng |
| Ngôn ngữ | C++17 |
| Repository | https://github.com/tobyasteria/KMP-String-Matching |

### Thành viên và phân công thực tế

| Thành viên | MSSV | GitHub | Tuần 1 | Tuần 2 |
|---|---|---|---|---|
| Lương Anh Hào | 25110017 | `tobyasteria` | Triển khai Naive/LPS/KMP, tích hợp Console, cấu hình môi trường, quản lý GitHub | Automated Testing; kiểm chứng benchmark trên các ví dụ có đáp án xác định trước; thống kê phép so sánh; review và tích hợp qua PR |
| Nguyễn Quốc Hào | 25110018 | `haonguyen457` | Rà soát code, biên dịch và chạy độc lập | Xây dựng benchmark bằng `std::chrono`, tạo dữ liệu Natural/Adversarial, xuất CSV, bổ sung đối chiếu với `std::string::find()`, mô tả phương pháp và ảnh minh chứng |

## 2. Cấu trúc project

```text
KMP_Project/
├── .vscode/                       # Cấu hình môi trường
├── include/
│   └── search.h                   # Khai báo các thuật toán
├── src/
│   ├── main.cpp                   # Chương trình Console
│   ├── naive.cpp                  # NaiveSearch()
│   ├── kmp.cpp                    # buildLPS(), KMPSearch()
│   ├── benchmark.cpp              # Đo thời gian chạy
│   └── comparison_count.cpp       # Thống kê phép so sánh
├── tests/
│   ├── test_cases.cpp             # 17 bài kiểm thử tự động
│   └── benchmark_validation.cpp   # 5 bài kiểm chứng bổ sung
├── results/
│   ├── week2_test_results.txt
│   ├── benchmark_week2.csv
│   └── week2_comparison_counts.csv
├── evidence/                      # Ảnh Console, kết quả benchmark
├── report/
│   ├── weekly_report_01.md
│   ├── week1_hand_trace.md
│   ├── week1_self_explanation.md
│   └── week2_benchmark_method.md
├── README.md
└── AI_USAGE_LOG.md
```

## 3. Biên dịch và chạy (Windows / PowerShell)

Yêu cầu: G++ hỗ trợ C++17. Chạy các lệnh từ thư mục gốc project.

**Chương trình tìm kiếm:**

```powershell
g++ -std=c++17 -Wall -Wextra -Iinclude src/main.cpp src/naive.cpp src/kmp.cpp -o main.exe
.\main.exe
```

**Kiểm thử tự động:**

```powershell
g++ -std=c++17 -Wall -Wextra -Iinclude tests/test_cases.cpp src/naive.cpp src/kmp.cpp -o tests.exe
.\tests.exe
```

**Kiểm chứng bổ sung:**

```powershell
g++ -std=c++17 -Wall -Wextra -Iinclude tests/benchmark_validation.cpp src/naive.cpp src/kmp.cpp -o validation.exe
.\validation.exe
```

**Benchmark thời gian:**

```powershell
g++ -std=c++17 -Wall -Wextra -Iinclude src/benchmark.cpp src/naive.cpp src/kmp.cpp -o benchmark.exe
.\benchmark.exe
```

**Thống kê phép so sánh ký tự:**

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -Iinclude src/comparison_count.cpp src/naive.cpp src/kmp.cpp -o comparison.exe
.\comparison.exe
```

> Chạy benchmark sẽ ghi lại `results/benchmark_week2.csv` trên máy đang chạy. Thời gian đo thay đổi theo phần cứng, trình biên dịch, cờ tối ưu hóa và điều kiện hệ thống. Không so sánh trực tiếp các phép đo có cấu hình biên dịch khác nhau.

## 4. Tiến độ và kết quả Tuần 1–2

| Thành phần | Tình trạng |
|---|---|
| Naive Search, xây dựng LPS và KMP Search | Hoàn thành Tuần 1 |
| Console, Hand Trace | Hoàn thành Tuần 1 |
| Automated Testing | 17/17 PASS trên máy thành viên |
| Benchmark Validation | 5/5 PASS trên máy thành viên |
| Benchmark thời gian | 6 bộ dữ liệu, kết quả lưu trong CSV |
| Character Comparison Counting | 6 bộ dữ liệu, đối chiếu với thuật toán gốc đều PASS |

Bộ benchmark dùng hai nhóm dữ liệu: **Natural** (một câu tiếng Anh được lặp lại) và **Adversarial** (text toàn ký tự `a`, pattern gồm 100 ký tự `a` và ký tự `b` cuối cùng), với độ dài text 10.000, 50.000 và 100.000 ký tự. Thời gian được đo bằng `std::chrono::steady_clock` với hai lượt warm-up và trung bình 10 lượt chạy. Mã benchmark còn đối chiếu vị trí khớp bằng `std::string::find()`.

Các bộ đếm phép so sánh được triển khai trong file riêng, không sửa các hàm thuật toán ban đầu. **Số phép so sánh của phiên bản có bộ đếm không được hiểu là phép đo trực tiếp trên bản `src/kmp.cpp` gốc**, do cách tổ chức điều kiện của KMP có khác biệt.

`PASS` chỉ xác nhận các trường hợp đã chạy và các phép đối chiếu đã thực hiện; không phải chứng minh thuật toán đúng với mọi dữ liệu.

## 5. Minh chứng và tài liệu

- [Báo cáo tiến độ Tuần 1](report/weekly_report_01.md)
- [Báo cáo tiến độ Tuần 2](report/weekly_report_02.md)
- [Hand Trace KMP](report/week1_hand_trace.md)
- [Ghi chú giải thích thuật toán](report/week1_self_explanation.md)
- [Kết quả kiểm thử tự động](results/week2_test_results.txt)
- [Kết quả benchmark thời gian](results/benchmark_week2.csv)
- [Kết quả thống kê phép so sánh](results/week2_comparison_counts.csv)
- [Phương pháp đo Benchmark Tuần 2](report/week2_benchmark_method.md)
- [Ảnh Automated Testing](evidence/week2_automated_tests.png)
- [Ảnh Comparison Counting cơ bản](evidence/week2_comparison_basic.png)
- [Ảnh Comparison Counting trên dữ liệu lớn](evidence/week2_comparison_benchmark.png)
- [Ảnh Benchmark](evidence/week2_benchmark.png)
- [Pull Request #1 — Testing](https://github.com/tobyasteria/KMP-String-Matching/pull/1)
- [Pull Request #2 — Comparison Counting](https://github.com/tobyasteria/KMP-String-Matching/pull/2)
- [Pull Request #3 — Benchmark](https://github.com/tobyasteria/KMP-String-Matching/pull/3)
- [Lịch sử commit](https://github.com/tobyasteria/KMP-String-Matching/commits/main)

## 6. Sử dụng AI

Nhóm sử dụng ChatGPT (OpenAI) trong quá trình tìm hiểu thuật toán, tham khảo các gợi ý triển khai code, hỗ trợ xử lý lỗi C++/VS Code/Git, kiểm tra kết quả và hoàn thiện quy trình làm việc. Mức độ hỗ trợ cụ thể của từng tuần và trách nhiệm kiểm tra của các thành viên được ghi tại [AI_USAGE_LOG.md](AI_USAGE_LOG.md).
