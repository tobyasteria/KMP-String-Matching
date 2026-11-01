# WEEK 4 — FINAL PROJECT SUMMARY

**Đề tài:** Knuth–Morris–Pratt (KMP) String Matching  
**Môn học:** Cấu trúc dữ liệu và giải thuật (DASA230179)  
**Nhóm:** Lương Anh Hào (25110017), Nguyễn Quốc Hào (25110018)

## 1. Mục tiêu

Xây dựng và so sánh hai thuật toán tìm kiếm chuỗi Naive Search và KMP bằng C++17; đánh giá tính đúng đắn, thời gian thực thi, số phép so sánh ký tự và độ phức tạp.

## 2. Kết quả thực hiện

- **Tuần 1:** Triển khai Naive, LPS và KMP; mô phỏng thuật toán bằng hand trace.
- **Tuần 2:** Xây dựng 17 test case, 5 trường hợp kiểm chứng độc lập; đo thời gian và số phép so sánh.
- **Tuần 3:** Phân tích độ phức tạp; Benchmark thay đổi độ dài pattern; mở rộng dữ liệu Natural và tạo biểu đồ.
- **Tuần 4:** Chạy lại kiểm thử cuối cùng, kiểm tra kết quả thực nghiệm và lưu minh chứng trên GitHub.

## 3. Tổng hợp kết quả

| Nội dung | Kết quả |
|---|---|
| Automated Testing | 17/17 PASS |
| Benchmark Validation | 5/5 PASS |
| Pattern Comparison Counting | 5/5 PASS |
| Worst-case Naive | O(n × m) |
| KMP tổng | O(n + m) |
| KMP Auxiliary Space | O(m), chưa tính kết quả trả về |

Trong Benchmark Tuần 3, với text dài 100.000 ký tự và pattern dài 1.000 ký tự:

- Naive: 42.249,980 µs.
- KMP: 240,690 µs.
- KMP nhanh hơn khoảng **175,5 lần**.
- Naive: 99.001.000 phép so sánh.
- KMP Total: 200.998 phép so sánh.

Trên dữ liệu Natural đã thử nghiệm, Naive có thời gian thực thi thấp hơn KMP. Điều này cho thấy hiệu quả thực tế còn phụ thuộc vào đặc điểm dữ liệu, không chỉ độ phức tạp Big-O.

## 4. Hạn chế

- Thời gian chạy phụ thuộc môi trường và cấu hình máy.
- Benchmark mới khảo sát một số kích thước dữ liệu và pattern.
- Kết quả không đại diện cho mọi loại văn bản hoặc mọi tình huống sử dụng.

## 5. Kết luận

Nhóm đã hoàn thành việc triển khai, kiểm thử và đánh giá thuật toán. Kết quả thực nghiệm phù hợp với phân tích lý thuyết: KMP có lợi thế rõ rệt trong các trường hợp phát sinh nhiều phép so sánh lặp lại, còn Naive vẫn có thể hoạt động nhanh trên dữ liệu thông thường.

**Minh chứng:** [Final Tests](../evidence/week4_final_tests.png), [Complexity Analysis](week3_complexity_analysis.md), [Pattern Benchmark CSV](../results/week3_pattern_benchmark.csv).