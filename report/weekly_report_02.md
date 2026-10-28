# BÁO CÁO TIẾN ĐỘ TUẦN 2 – ĐỒ ÁN CUỐI KỲ

**Môn học:** Cấu trúc dữ liệu và giải thuật (DASA230179)  
**Giảng viên hướng dẫn:** Huỳnh Xuân Phụng  
**Đề tài:** Knuth–Morris–Pratt (KMP) String Matching  
**Ngôn ngữ lập trình:** C++17  
**GitHub Repository:** https://github.com/tobyasteria/KMP-String-Matching

---

## 1. Thông tin nhóm và phân công công việc

**Lương Anh Hào — MSSV: 25110017 — GitHub: `tobyasteria`**

- Triển khai Automated Testing gồm 17 test case.
- Xây dựng Benchmark Validation với 5 trường hợp kiểm tra độc lập.
- Triển khai bộ đếm số phép so sánh ký tự cho Naive, LPS và KMP.
- Kiểm tra, tích hợp code và quản lý GitHub.

**Nguyễn Quốc Hào — MSSV: 25110018 — GitHub: `haonguyen457`**

- Xây dựng chương trình Benchmark bằng C++17 và `std::chrono`.
- Chuẩn bị dữ liệu Natural và Adversarial.
- Đo thời gian thực thi, xuất CSV và kiểm tra kết quả bằng `std::string::find()`.
- Lưu ảnh minh chứng và mô tả phương pháp đo.

## 2. Công việc đã thực hiện

- `tests/test_cases.cpp`: triển khai 17 test case kiểm tra Naive, LPS và KMP.
- `tests/benchmark_validation.cpp`: kiểm tra thêm 5 trường hợp với đáp án độc lập.
- `src/benchmark.cpp`: đo thời gian chạy của Naive và KMP trên 6 bộ dữ liệu.
- `src/comparison_count.cpp`: thống kê số phép so sánh ký tự của Naive, LPS và KMP.
- Sử dụng hai nhóm dữ liệu Natural và Adversarial với độ dài 10.000, 50.000 và 100.000 ký tự.
- Chạy Benchmark 10 lần cho mỗi trường hợp và tính thời gian trung bình.
- Lưu kết quả CSV, ảnh Console và tài liệu phương pháp đo lên GitHub.
- Hoàn thành và merge 3 Pull Request vào nhánh `main`.

## 3. Kết quả và minh chứng

### 3.1. Automated Testing

- Naive và KMP: **12/12 PASS**.
- LPS Construction: **5/5 PASS**.
- Benchmark Validation: **5/5 PASS**.

Bộ kiểm thử sử dụng đáp án mong đợi độc lập, gồm các trường hợp chuỗi rỗng, không tìm thấy, pattern dài hơn text và khớp chồng lấp.

### 3.2. Benchmark đo thời gian

Đơn vị: microseconds (µs).

| Dataset | Text Length | Naive | KMP |
|---|---:|---:|---:|
| Natural | 10.000 | 13,300 | 19,960 |
| Natural | 50.000 | 55,490 | 93,380 |
| Natural | 100.000 | 110,740 | 197,560 |
| Adversarial | 10.000 | 556,320 | 34,770 |
| Adversarial | 50.000 | 3.953,760 | 206,670 |
| Adversarial | 100.000 | 8.144,380 | 376,770 |

Trên dữ liệu Natural mô phỏng bằng một câu tiếng Anh lặp lại, Naive chạy nhanh hơn. Tuy nhiên, với dữ liệu Adversarial dạng `aaaa...ab`, KMP nhanh hơn đáng kể, khoảng 21,6 lần ở kích thước 100.000 ký tự.

### 3.3. Thống kê số phép so sánh

| Dataset | Text Length | Naive | KMP Total |
|---|---:|---:|---:|
| Natural | 10.000 | 11.881 | 10.685 |
| Natural | 50.000 | 59.454 | 53.388 |
| Natural | 100.000 | 118.915 | 106.766 |
| Adversarial | 10.000 | 999.900 | 20.099 |
| Adversarial | 50.000 | 5.039.900 | 100.099 |
| Adversarial | 100.000 | 10.089.900 | 200.099 |

KMP Total bao gồm số phép so sánh khi xây dựng LPS và khi tìm kiếm. Số liệu được ghi nhận từ phiên bản thuật toán có bổ sung bộ đếm riêng.

Ở dữ liệu Adversarial dài 100.000 ký tự, Naive thực hiện khoảng 50,4 lần số phép so sánh của KMP. Kết quả phù hợp với ưu điểm lý thuyết của KMP là O(n + m), so với độ phức tạp trường hợp xấu nhất O(n × m) của Naive.

### 3.4. Minh chứng GitHub (C3)

- **Automated Testing:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/tests/test_cases.cpp
- **Benchmark Validation:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/tests/benchmark_validation.cpp
- **Benchmark:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/src/benchmark.cpp
- **Comparison Counting:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/src/comparison_count.cpp
- **Kết quả Testing:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/results/week2_test_results.txt
- **Benchmark CSV:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/results/benchmark_week2.csv
- **Comparison CSV:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/results/week2_comparison_counts.csv
- **Ảnh Testing:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/evidence/week2_automated_tests.png
- **Ảnh Benchmark:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/evidence/week2_benchmark.png
- **Ảnh Comparison:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/evidence/week2_comparison_benchmark.png
- **Phương pháp đo:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/report/week2_benchmark_method.md

### 3.5. Lịch sử commit và Pull Request (C6)

1. **Automated Testing — Lương Anh Hào:** https://github.com/tobyasteria/KMP-String-Matching/pull/1
2. **Comparison Counting và Validation — Lương Anh Hào:** https://github.com/tobyasteria/KMP-String-Matching/pull/2
3. **Benchmark Evidence — Nguyễn Quốc Hào:** https://github.com/tobyasteria/KMP-String-Matching/pull/3

**Commit Benchmark ban đầu của Nguyễn Quốc Hào:** https://github.com/tobyasteria/KMP-String-Matching/commit/a466c5d5eefd8aa53505a9003fdf2477b996117d

**Toàn bộ lịch sử:** https://github.com/tobyasteria/KMP-String-Matching/commits/main

## 4. Khó khăn gặp phải

- Cần xây dựng test với đáp án độc lập thay vì chỉ so sánh kết quả giữa Naive và KMP.
- Việc đo thời gian có thể chênh lệch tùy cấu hình máy và điều kiện thực thi.
- Khi bổ sung bộ đếm, phải kiểm tra để bảo đảm kết quả tìm kiếm không thay đổi.
- Dữ liệu Natural hiện được tạo bằng cách lặp một câu tiếng Anh, chưa phản ánh đầy đủ văn bản tự nhiên.
- Chưa khảo sát ảnh hưởng của việc thay đổi độ dài pattern đến hiệu suất.

## 5. Kế hoạch Tuần 3

- Phân tích độ phức tạp thời gian và không gian của Naive, LPS và KMP.
- So sánh kết quả Benchmark với lý thuyết O(n × m) và O(n + m).
- Thử nghiệm thêm với các độ dài pattern khác nhau.
- Bổ sung dữ liệu văn bản tự nhiên đa dạng hơn.
- Xây dựng biểu đồ, phân tích kết quả và hoàn thiện tài liệu.

## 6. Đánh giá tiến độ

Tuần 2, nhóm đã hoàn thành Automated Testing, Benchmarking, kiểm chứng kết quả độc lập và thống kê số phép so sánh ký tự.

Kết quả kiểm thử đạt 17/17 và 5/5 PASS. Sáu bộ dữ liệu Benchmark cho thấy KMP có lợi thế rõ rệt trên chuỗi đối kháng, trong khi Naive có thời gian chạy thấp hơn trên dữ liệu Natural trong thí nghiệm này.

Source code, kết quả thực nghiệm và minh chứng đã được cập nhật lên GitHub. Nhóm sẽ tiếp tục phân tích độ phức tạp và mở rộng thí nghiệm trong Tuần 3.