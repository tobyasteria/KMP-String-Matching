# WEEK 4 — DEFENSE NOTES

## 1. KMP hoạt động như thế nào?

KMP sử dụng mảng LPS để xác định vị trí tiếp tục so sánh sau khi gặp mismatch, tránh kiểm tra lại những ký tự đã biết.

## 2. LPS là gì?

LPS là độ dài tiền tố thực sự dài nhất đồng thời là hậu tố của từng đoạn pattern.

Ví dụ: `ABABAC` có LPS `[0, 0, 1, 2, 3, 0]`.

## 3. Vì sao KMP có độ phức tạp O(n + m)?

Xây dựng LPS mất O(m). Quá trình tìm kiếm mất O(n) vì chỉ số duyệt text không quay lùi và số bước fallback được giới hạn tuyến tính.

## 4. Vì sao Naive có thể đạt O(n × m)?

Ở mỗi vị trí bắt đầu, Naive có thể phải kiểm tra gần toàn bộ pattern trước khi phát hiện mismatch. Có tối đa n − m + 1 vị trí bắt đầu.

## 5. Vì sao KMP không luôn nhanh hơn Naive?

KMP có chi phí tiền xử lý và điều khiển thuật toán. Với dữ liệu dễ phân biệt ký tự, Naive thường phát hiện mismatch rất sớm nên có thể nhanh hơn.

## 6. Giải thích kết quả 175,5 lần

Với n = 100.000 và m = 1.000, dữ liệu đối kháng khiến Naive phải so sánh lặp lại nhiều lần.

- Naive: 42.249,980 µs.
- KMP: 240,690 µs.

Tỷ lệ thời gian xấp xỉ 175,5 lần, chỉ áp dụng cho phép đo này.

## 7. Vì sao chênh lệch phép so sánh là 492,5 lần nhưng thời gian chỉ 175,5 lần?

Vì thời gian thực thi còn phụ thuộc vào truy cập bộ nhớ, các phép gán, điều kiện rẽ nhánh, tối ưu hóa của trình biên dịch và chi phí xây dựng LPS.

## 8. Làm sao bảo đảm thuật toán đúng?

Nhóm sử dụng automated tests với kết quả mong đợi độc lập, benchmark validation và đối chiếu kết quả với `std::string::find()`.

## 9. Phân công khi bảo vệ

**Lương Anh Hào:** Giới thiệu thuật toán, LPS, phân tích độ phức tạp, kiểm thử và kết luận.

**Nguyễn Quốc Hào:** Trình bày thiết kế Benchmark, dữ liệu Natural/Adversarial, kết quả CSV và giải thích các biểu đồ.

Cả hai thành viên cần hiểu toàn bộ chương trình và có khả năng giải thích code khi được hỏi.