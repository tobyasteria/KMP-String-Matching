# BÁO CÁO TIẾN ĐỘ TUẦN 4 – ĐỒ ÁN CUỐI KỲ

**Môn học:** Cấu trúc dữ liệu và giải thuật (DASA230179)  
**Giảng viên hướng dẫn:** Huỳnh Xuân Phụng  
**Đề tài:** Knuth–Morris–Pratt (KMP) String Matching  
**Ngôn ngữ lập trình:** C++17  
**GitHub Repository:** https://github.com/tobyasteria/KMP-String-Matching

---

## 1. Thông tin nhóm và phân công công việc

**Lương Anh Hào — MSSV: 25110017 — GitHub: `tobyasteria`**

- Chạy lại bộ kiểm thử cuối kỳ và đối chiếu kết quả.
- Tổng hợp phân tích độ phức tạp và kết quả Benchmark.
- Hoàn thiện báo cáo, tài liệu bảo vệ và README.
- Quản lý GitHub, commit và lưu minh chứng.

**Nguyễn Quốc Hào — MSSV: 25110018 — GitHub: `haonguyen457`**

- Phụ trách nội dung thực nghiệm Benchmark đã triển khai.
- Tổng hợp phương pháp đo, dữ liệu Natural và Adversarial.
- Chuẩn bị nội dung giải thích kết quả và biểu đồ phục vụ bảo vệ.

## 2. Công việc đã thực hiện

- Biên dịch và chạy lại Automated Testing bằng C++17.
- Chạy Benchmark Validation để kiểm tra tính đúng đắn.
- Kiểm tra Pattern Comparison Counting với 5 độ dài pattern.
- Tổng hợp kết quả lý thuyết và thực nghiệm từ Tuần 1–3.
- Lưu minh chứng kiểm thử cuối kỳ vào `evidence/week4_final_tests.png`.
- Hoàn thiện Final Project Summary, Defense Notes và báo cáo Tuần 4.
- Rà soát repository và cập nhật tài liệu phục vụ nộp bài.

## 3. Kết quả và minh chứng

### 3.1. Kiểm thử cuối kỳ

| Hạng mục | Kết quả |
|---|---|
| Automated Testing | 17/17 PASS |
| Benchmark Validation | 5/5 PASS |
| Pattern Comparison Counting | 5/5 PASS |

Tất cả các lượt kiểm tra đã thực hiện trong Tuần 4 đều PASS. Không phát hiện sai lệch kết quả trong những trường hợp đã kiểm tra.

### 3.2. Tổng hợp kết quả thuật toán

| Thuật toán | Time Complexity | Auxiliary Space |
|---|---|---|
| Naive Search | O(n × m), trường hợp xấu nhất | O(1) |
| LPS Construction | O(m) | O(m) |
| KMP tổng | O(n + m) | O(m) |

Bộ nhớ phụ chưa tính danh sách vị trí khớp trả về.

### 3.3. Kết quả Benchmark tiêu biểu

Với dữ liệu Adversarial, text length `n = 100000` và pattern length `m = 1000`:

| Chỉ số | Naive | KMP |
|---|---:|---:|
| Average Time (µs) | 42.249,980 | 240,690 |
| Character Comparisons | 99.001.000 | 200.998 |

- KMP nhanh hơn khoảng **175,5 lần**.
- KMP thực hiện ít phép so sánh hơn khoảng **492,5 lần**.

Trên dữ liệu Natural đã thử nghiệm, Naive có thời gian chạy thấp hơn KMP. Điều này cho thấy Big-O không bảo đảm KMP luôn nhanh hơn trong mọi trường hợp thực tế.

### 3.4. Minh chứng GitHub (C3)

- **Automated Testing:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/tests/test_cases.cpp
- **Benchmark Validation:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/tests/benchmark_validation.cpp
- **Final Testing Evidence:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/evidence/week4_final_tests.png
- **Complexity Analysis:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/report/week3_complexity_analysis.md
- **Pattern Benchmark CSV:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/results/week3_pattern_benchmark.csv
- **Comparison Counting CSV:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/results/week3_pattern_comparisons.csv
- **Final Project Summary:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/report/week4_final_summary.md
- **Defense Notes:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/report/week4_defense_notes.md

### 3.5. Lịch sử GitHub (C6)

- **Final Verification Evidence:** https://github.com/tobyasteria/KMP-String-Matching/commit/1f5de88
- **Week 4 Documentation:** https://github.com/tobyasteria/KMP-String-Matching/commit/f92aa4b
- **Toàn bộ lịch sử:** https://github.com/tobyasteria/KMP-String-Matching/commits/main

## 4. Khó khăn gặp phải

- Cần kiểm tra lại các chương trình để bảo đảm kết quả nhất quán với những tuần trước.
- Phải phân biệt thời gian thực thi với số phép so sánh ký tự khi đánh giá hiệu suất.
- Cần rà soát việc lưu và commit tài liệu để tránh thiếu nội dung trên GitHub.

Các vấn đề về lưu minh chứng và commit tài liệu đã được xử lý trong quá trình hoàn thiện.

## 5. Kế hoạch tiếp theo

- Kiểm tra lần cuối các tài liệu và liên kết minh chứng.
- Ôn tập LPS, nguyên lý hoạt động của KMP và phân tích độ phức tạp.
- Chuẩn bị giải thích phương pháp Benchmark và kết quả thực nghiệm.
- Hoàn tất nộp bài và bảo vệ đồ án theo yêu cầu giảng viên.

## 6. Đánh giá tiến độ

Trong Tuần 4, nhóm đã hoàn thành kiểm thử cuối kỳ và tổng hợp kết quả đồ án. Automated Testing đạt **17/17 PASS**, Benchmark Validation đạt **5/5 PASS** và Pattern Comparison Counting đạt **5/5 PASS**.

Kết quả thực nghiệm cho thấy KMP có ưu thế rõ rệt trên dữ liệu đối kháng nhờ sử dụng LPS để hạn chế các phép so sánh lặp lại. Tuy nhiên, Naive vẫn có thể chạy nhanh hơn trên dữ liệu Natural đã thử nghiệm.

Source code, dữ liệu CSV, biểu đồ và minh chứng được lưu trên GitHub. **Phần triển khai, kiểm thử và tài liệu đã hoàn thành; nhóm chuyển sang giai đoạn nộp bài và chuẩn bị bảo vệ.*