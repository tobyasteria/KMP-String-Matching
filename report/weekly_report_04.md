# BÁO CÁO TIẾN ĐỘ TUẦN 4 – ĐỒ ÁN CUỐI KỲ

**Môn học:** Cấu trúc dữ liệu và giải thuật (DASA230179)  
**Giảng viên:** Huỳnh Xuân Phụng  
**Đề tài:** Knuth–Morris–Pratt (KMP) String Matching  
**Ngôn ngữ:** C++17  
**GitHub:** https://github.com/tobyasteria/KMP-String-Matching

## 1. Thông tin nhóm và phân công

**Lương Anh Hào — 25110017 — `tobyasteria`**

- Chạy kiểm thử cuối cùng, kiểm tra kết quả và lưu minh chứng.
- Tổng hợp kết quả, chuẩn bị tài liệu và nội dung bảo vệ.
- Quản lý repository và tích hợp tài liệu.

**Nguyễn Quốc Hào — 25110018 — `haonguyen457`**

- Phụ trách giải thích thiết kế Benchmark và kết quả thực nghiệm đã thực hiện.
- Chuẩn bị nội dung trình bày về dữ liệu, biểu đồ và phương pháp đo.

## 2. Công việc đã thực hiện

- Chạy lại Automated Testing và Benchmark Validation.
- Kiểm tra kết quả thống kê phép so sánh theo độ dài pattern.
- Tổng hợp kết quả lý thuyết và thực nghiệm Tuần 1–3.
- Lưu minh chứng kiểm thử cuối tại `evidence/week4_final_tests.png`.
- Chuẩn bị tài liệu tổng kết và nội dung bảo vệ đồ án.

## 3. Kết quả và minh chứng

| Hạng mục | Kết quả |
|---|---|
| Automated Testing | 17/17 PASS |
| Benchmark Validation | 5/5 PASS |
| Pattern Comparison Counting | 5/5 PASS |
| GitHub | Đã push minh chứng Tuần 4 |

Kết quả quan trọng của đồ án:

- Naive có độ phức tạp trường hợp xấu nhất O(n × m).
- KMP có độ phức tạp tổng O(n + m).
- Trên dữ liệu đối kháng Tuần 3 với n = 100.000, m = 1.000, KMP nhanh hơn khoảng 175,5 lần.
- Trên dữ liệu Natural đã kiểm tra, Naive có thể chạy nhanh hơn KMP.

**Minh chứng:**

- [Final Verification](../evidence/week4_final_tests.png)
- [Automated Tests](../tests/test_cases.cpp)
- [Benchmark Validation](../tests/benchmark_validation.cpp)
- [Complexity Analysis](week3_complexity_analysis.md)
- [Pattern Benchmark](../results/week3_pattern_benchmark.csv)
- [Natural Benchmark](../results/week3_natural_benchmark.csv)
- [Comparison Counting](../results/week3_pattern_comparisons.csv)
- [Commit minh chứng Tuần 4](https://github.com/tobyasteria/KMP-String-Matching/commit/1f5de88)

## 4. Khó khăn gặp phải

- Cần phân biệt sự khác nhau giữa thời gian thực thi và số phép so sánh ký tự.
- Kết quả Benchmark có thể thay đổi theo môi trường chạy.
- Cần tổng hợp nhiều kết quả thực nghiệm thành nội dung ngắn gọn, dễ giải thích khi bảo vệ.

## 5. Kế hoạch tiếp theo

- Rà soát tài liệu và đường dẫn GitHub.
- Ôn tập thuật toán, LPS, độ phức tạp và kết quả Benchmark.
- Hoàn tất việc nộp và bảo vệ đồ án theo yêu cầu giảng viên.

## 6. Đánh giá tiến độ

Nhóm đã hoàn thành phần triển khai thuật toán, kiểm thử, Benchmark và phân tích độ phức tạp. Các lượt kiểm tra cuối cùng đều PASS. Kết quả thực nghiệm và minh chứng được lưu trên GitHub.

Đồ án đã sẵn sàng cho bước rà soát cuối và chuẩn bị bảo vệ.