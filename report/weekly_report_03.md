# BÁO CÁO TIẾN ĐỘ TUẦN 3 – ĐỒ ÁN CUỐI KỲ

**Môn học:** Cấu trúc dữ liệu và giải thuật (DASA230179)  
**Giảng viên hướng dẫn:** Huỳnh Xuân Phụng  
**Đề tài:** Knuth–Morris–Pratt (KMP) String Matching  
**Ngôn ngữ lập trình:** C++17  
**GitHub Repository:** https://github.com/tobyasteria/KMP-String-Matching

---

## 1. Thông tin nhóm và phân công công việc

**Lương Anh Hào — MSSV: 25110017 — GitHub: `tobyasteria`**

- Phân tích độ phức tạp thời gian và không gian của Naive, LPS và KMP.
- Đối chiếu lý thuyết với số phép so sánh đã đo trong Tuần 2.
- Review PR #4, kiểm tra kết quả, tích hợp code và xây dựng biểu đồ.

**Nguyễn Quốc Hào — MSSV: 25110018 — GitHub: `haonguyen457`**

- Xây dựng Benchmark thay đổi độ dài pattern.
- Bổ sung Natural Text từ Project Gutenberg.
- Triển khai bộ đếm phép so sánh theo pattern length.
- Chạy thực nghiệm, xuất CSV, lưu ảnh và mô tả phương pháp đo.

## 2. Công việc đã thực hiện

- `report/week3_complexity_analysis.md`: phân tích Time Complexity và Space Complexity của Naive, LPS, KMP.
- `src/week3_pattern_benchmark.cpp`: giữ `n = 100000`, thay đổi `m = 10, 50, 100, 500, 1000`.
- `src/week3_natural_benchmark.cpp`: Benchmark trên văn bản *The Adventures of Sherlock Holmes*.
- `src/week3_pattern_comparison.cpp`: đếm số phép so sánh của Naive, LPS và KMP theo độ dài pattern.
- Kiểm chứng kết quả bằng `std::string::find()`.
- Đo thời gian bằng `std::chrono::steady_clock`, 2 lần warm-up và 10 lần chạy lấy trung bình.
- Lưu kết quả CSV, ảnh Terminal, biểu đồ và tài liệu phương pháp đo lên GitHub.

## 3. Kết quả và minh chứng

### 3.1. Phân tích độ phức tạp

| Thuật toán | Time Complexity | Auxiliary Space |
|---|---|---|
| Naive Search | O(n × m) — trường hợp xấu nhất | O(1) |
| LPS Construction | O(m) | O(m) |
| KMP Search | O(n) — sau tiền xử lý | O(1) ngoài LPS |
| KMP tổng | O(n + m) | O(m) |

Bộ nhớ phụ chưa tính danh sách vị trí khớp trả về.

Trong dữ liệu đối kháng, Naive phải so sánh gần hết pattern tại nhiều vị trí bắt đầu. KMP sử dụng LPS để tránh thực hiện lại các phép so sánh không cần thiết.

### 3.2. Pattern Length Benchmark

Giữ text gồm 100.000 ký tự `a`, thay đổi độ dài pattern. Mỗi pattern gồm `m - 1` ký tự `a` và kết thúc bằng `b`.

**Kết quả: 5/5 PASS.**

Đơn vị: microseconds (µs).

| Pattern m | Naive Avg | KMP Avg |
|---|---:|---:|
| 10 | 493,140 | 239,310 |
| 50 | 2.177,650 | 240,590 |
| 100 | 4.939,690 | 240,950 |
| 500 | 21.681,930 | 241,510 |
| 1.000 | 42.249,980 | 240,690 |

Khi m tăng từ 10 lên 1.000, thời gian Naive tăng mạnh, trong khi KMP gần như ổn định. Với m = 1.000, KMP chạy nhanh hơn khoảng **175,5 lần** trong phép đo này.

### 3.3. Thống kê số phép so sánh

**Kết quả: 5/5 PASS.**

| Pattern m | Naive Comparisons | KMP Total |
|---|---:|---:|
| 10 | 999.910 | 200.008 |
| 50 | 4.997.550 | 200.048 |
| 100 | 9.990.100 | 200.098 |
| 500 | 49.750.500 | 200.498 |
| 1.000 | 99.001.000 | 200.998 |

KMP Total bao gồm số phép so sánh khi xây dựng LPS và khi tìm kiếm, được thống kê bằng phiên bản thuật toán có bộ đếm riêng.

Với dữ liệu đối kháng:

`C_Naive = (n - m + 1) × m`

Khi `n = 100000` và `m = 1000`:

`C_Naive = (100000 - 1000 + 1) × 1000 = 99001000`

Kết quả khớp với CSV. KMP Total là 200.998 phép so sánh, thấp hơn Naive khoảng **492,5 lần**.

Sự khác biệt này liên hệ trực tiếp với độ phức tạp trường hợp xấu nhất O(n × m) của Naive và O(n + m) của KMP.

### 3.4. Natural Text Benchmark

Nhóm sử dụng *The Adventures of Sherlock Holmes* từ Project Gutenberg, với pattern `Sherlock Holmes` dài 15 ký tự.

**Kết quả: 3/3 PASS.**

| Text Length | Naive Avg (µs) | KMP Avg (µs) |
|---|---:|---:|
| 10.000 | 10,540 | 17,780 |
| 50.000 | 50,060 | 91,340 |
| 100.000 | 100,660 | 174,410 |

Trên dữ liệu Natural này, Naive tiếp tục chạy nhanh hơn KMP trong cả ba trường hợp. Kết quả không mâu thuẫn với Big-O vì độ phức tạp tiệm cận không bảo đảm KMP luôn nhanh hơn trên mọi dữ liệu thực tế.

### 3.5. Link file và minh chứng (C3)

- **Complexity Analysis:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/report/week3_complexity_analysis.md
- **Pattern Benchmark:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/src/week3_pattern_benchmark.cpp
- **Natural Benchmark:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/src/week3_natural_benchmark.cpp
- **Pattern Comparison:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/src/week3_pattern_comparison.cpp
- **Pattern Benchmark CSV:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/results/week3_pattern_benchmark.csv
- **Natural Benchmark CSV:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/results/week3_natural_benchmark.csv
- **Comparison CSV:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/results/week3_pattern_comparisons.csv
- **Benchmark Method:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/report/week3_benchmark_method.md
- **Ảnh Pattern Benchmark:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/evidence/week3_pattern_benchmark.png
- **Ảnh Natural Benchmark:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/evidence/week3_natural_benchmark.png
- **Ảnh Comparison:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/evidence/week3_pattern_comparison.png
- **Biểu đồ thời gian:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/evidence/week3_chart_pattern_time.png
- **Biểu đồ phép so sánh:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/evidence/week3_chart_pattern_comparisons.png
- **Biểu đồ Natural:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/evidence/week3_chart_natural_time.png

### 3.6. Lịch sử GitHub (C6)

- **PR #4 — Benchmark Tuần 3, Nguyễn Quốc Hào:** https://github.com/tobyasteria/KMP-String-Matching/pull/4
- **Commit Complexity Analysis:** https://github.com/tobyasteria/KMP-String-Matching/commits/feature/week3-complexity
- **Toàn bộ lịch sử:** https://github.com/tobyasteria/KMP-String-Matching/commits/main

Các công việc đã được tích hợp vào nhánh `main`.

## 4. Khó khăn gặp phải

- Kết quả thời gian chạy có thể thay đổi theo máy tính, trình biên dịch và điều kiện thực thi.
- Cần xử lý việc trình biên dịch tối ưu hóa các phép tính trong Benchmark để tránh ảnh hưởng đến tính tin cậy của phép đo.
- Bộ đếm số phép so sánh được triển khai riêng nên phải kiểm tra kết quả với các thuật toán gốc.
- Dữ liệu Natural sử dụng một tác phẩm văn học và một pattern cố định, chưa đại diện cho mọi loại văn bản.
- Phải phân biệt số phép so sánh với thời gian thực thi vì hai chỉ số không tỷ lệ hoàn toàn với nhau.

## 5. Kế hoạch Tuần 4

- Tổng hợp kết quả thực nghiệm của Tuần 1–3.
- Rà soát tính đúng đắn của code và các test case.
- Hoàn thiện bảng, biểu đồ và phần phân tích so sánh cuối kỳ.
- Kiểm tra README, tài liệu và các link minh chứng GitHub.
- Chuẩn bị phần trình bày, giải thích thuật toán và trả lời câu hỏi bảo vệ.

## 6. Đánh giá tiến độ

Trong Tuần 3, nhóm đã hoàn thành phân tích độ phức tạp, mở rộng Benchmark theo độ dài pattern và sử dụng dữ liệu Natural đa dạng hơn.

Kết quả 5/5 Pattern Benchmark, 5/5 Comparison Counting và 3/3 Natural Benchmark đều PASS. Số phép so sánh trên dữ liệu đối kháng cho thấy ảnh hưởng rõ rệt của độ dài pattern đối với Naive, trong khi KMP tận dụng LPS để hạn chế so sánh lặp lại.

Source code, dữ liệu CSV, biểu đồ và minh chứng đã được cập nhật trên GitHub. Nhóm sẽ hoàn thiện sản phẩm và chuẩn bị bảo vệ trong Tuần 4.