# WEEK 3 — COMPLEXITY ANALYSIS

**Đề tài:** Knuth–Morris–Pratt String Matching  
**Môn học:** DASA230179 — Cấu trúc dữ liệu và giải thuật  
**Nhóm:** Lương Anh Hào (25110017), Nguyễn Quốc Hào (25110018)

## 1. Mục tiêu

Phân tích độ phức tạp thời gian và không gian của Naive Search, LPS Construction và KMP Search, đồng thời đối chiếu với kết quả thống kê số phép so sánh ký tự đã thu được trong Tuần 2.

Ký hiệu:

- `n`: độ dài văn bản (text).
- `m`: độ dài mẫu tìm kiếm (pattern).
- `k`: số vị trí khớp được tìm thấy.

## 2. Naive Search

Naive Search thử pattern tại từng vị trí có thể bắt đầu trong text. Khi phát hiện ký tự không khớp, thuật toán chuyển sang vị trí tiếp theo.

Với `n >= m > 0`, có tối đa `n - m + 1` vị trí bắt đầu. Tại mỗi vị trí, thuật toán có thể thực hiện tối đa `m` phép so sánh.

Do đó:

**Worst-case Time Complexity: O(n × m).**

Trong các trường hợp ký tự đầu tiên thường xuyên không khớp, thuật toán chỉ cần một phép so sánh tại mỗi vị trí, dẫn đến thời gian gần O(n).

Bộ nhớ phụ của quá trình tìm kiếm là O(1), không tính danh sách vị trí khớp trả về.

## 3. LPS Construction

LPS (Longest Proper Prefix which is also Suffix) lưu độ dài tiền tố thực sự dài nhất đồng thời là hậu tố của từng phần pattern.

Khi gặp mismatch, thuật toán sử dụng `len = lps[len - 1]` để quay về độ dài tiền tố phù hợp mà không phải kiểm tra lại từ đầu.

Trong quá trình xây dựng, chỉ số `i` tăng tiến, còn `len` có thể giảm thông qua các giá trị LPS. Tổng số bước xử lý bị chặn tuyến tính theo độ dài pattern.

- **Time Complexity:** O(m).
- **Auxiliary Space Complexity:** O(m), dùng để lưu mảng LPS.

## 4. KMP Search

KMP Search sử dụng mảng LPS để xác định vị trí tiếp tục so sánh khi xảy ra mismatch.

Khác với Naive, chỉ số `i` của text không quay lùi. Khi xảy ra mismatch và `j > 0`, thuật toán giảm `j` theo `lps[j - 1]`, nhờ đó không cần bắt đầu so khớp lại từ vị trí text trước đó.

Trong quá trình tìm kiếm, mỗi bước làm `i` tăng hoặc làm `j` giảm theo LPS. Tổng số bước được giới hạn tuyến tính theo n.

- **Search Time Complexity:** O(n).
- **LPS Preprocessing:** O(m).
- **Total Time Complexity:** O(n + m).
- **Auxiliary Space:** O(m), không tính danh sách vị trí khớp trả về.

## 5. Đối chiếu với số liệu Tuần 2

### 5.1. Dữ liệu Adversarial

Nhóm sử dụng text gồm các ký tự `a` liên tiếp và pattern gồm 100 ký tự `a`, kết thúc bằng `b`.

Độ dài pattern được giữ cố định là `m = 101`.

| Text length (n) | Naive Comparisons | KMP Total Comparisons |
|---|---:|---:|
| 10.000 | 999.900 | 20.099 |
| 50.000 | 5.039.900 | 100.099 |
| 100.000 | 10.089.900 | 200.099 |

Đối với Naive, tại mỗi vị trí bắt đầu, 100 ký tự `a` đầu tiên khớp, sau đó ký tự `b` cuối cùng không khớp.

Do đó, số phép so sánh trong bộ dữ liệu này là:

`C_Naive = (n - m + 1) × m`

Với `n = 100000` và `m = 101`:

`C_Naive = (100000 - 101 + 1) × 101 = 10089900`

Kết quả trùng với `results/week2_comparison_counts.csv`.

Đối với phiên bản KMP có bộ đếm, ở các dữ liệu này:

`C_LPS = 199`

`C_KMP_Search = 2n - 100`

Suy ra:

`C_KMP_Total = 2n + 99`

Với `n = 100000`:

`C_KMP_Total = 200099`

Kết quả cũng trùng với file CSV.

Tỷ lệ số phép so sánh:

`10089900 / 200099 ≈ 50.4`

Như vậy, Naive thực hiện khoảng 50,4 lần số phép so sánh của KMP trong thí nghiệm này.

### 5.2. Liên hệ với thời gian chạy

| Dataset | Text Length | Naive Avg (µs) | KMP Avg (µs) |
|---|---:|---:|---:|
| Adversarial | 10.000 | 556,320 | 34,770 |
| Adversarial | 50.000 | 3.953,760 | 206,670 |
| Adversarial | 100.000 | 8.144,380 | 376,770 |

Ở kích thước 100.000 ký tự:

`8144.380 / 376.770 ≈ 21.6`

KMP chạy nhanh hơn khoảng 21,6 lần trong phép đo này.

Tỷ lệ thời gian chạy không bằng tỷ lệ số phép so sánh vì thời gian thực thi còn phụ thuộc vào các thao tác khác, quá trình tiền xử lý, cách triển khai và môi trường chạy.

### 5.3. Dữ liệu Natural

Trên dữ liệu Natural được tạo bằng cách lặp lại một câu tiếng Anh, Naive có thời gian chạy thấp hơn KMP trong cả ba kích thước đã thử nghiệm.

Điều này không mâu thuẫn với độ phức tạp lý thuyết. Big-O mô tả xu hướng tăng trưởng và giới hạn tiệm cận, không khẳng định KMP luôn nhanh hơn Naive ở mọi dữ liệu hoặc kích thước.

## 6. Giới hạn của thí nghiệm

- Pattern length được giữ cố định trong mỗi nhóm dữ liệu, chưa thể hiện đầy đủ ảnh hưởng của m.
- Natural Text hiện được mô phỏng từ một câu tiếng Anh lặp lại.
- Số phép so sánh được đo từ các phiên bản thuật toán có bổ sung bộ đếm riêng, không phải trực tiếp từ mọi biểu thức điều kiện trong source KMP gốc.
- Thời gian Benchmark có thể thay đổi theo trình biên dịch, mức tối ưu hóa và cấu hình máy.

## 7. Kết luận

Kết quả Tuần 2 phù hợp với phân tích lý thuyết: Naive Search có thể thực hiện nhiều phép so sánh lặp lại trong dữ liệu đối kháng, trong khi KMP tận dụng LPS để hạn chế các phép so sánh đó.

Tuy nhiên, dữ liệu hiện tại chưa khảo sát ảnh hưởng của độ dài pattern. Tuần 3 sẽ tiếp tục thực hiện các thí nghiệm thay đổi m trong khi giữ n cố định, đồng thời mở rộng bộ dữ liệu Natural.

## 8. Minh chứng

- [Naive Search](../src/naive.cpp)
- [KMP và LPS](../src/kmp.cpp)
- [Bộ đếm phép so sánh](../src/comparison_count.cpp)
- [Kết quả phép so sánh Tuần 2](../results/week2_comparison_counts.csv)
- [Kết quả Benchmark Tuần 2](../results/benchmark_week2.csv)
- [Báo cáo tiến độ Tuần 2](weekly_report_02.md)