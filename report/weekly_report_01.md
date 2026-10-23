# BÁO CÁO TIẾN ĐỘ TUẦN 1 – ĐỒ ÁN CUỐI KỲ

**Môn học:** Cấu trúc dữ liệu và giải thuật (DASA230179)  
**Giảng viên hướng dẫn:** Huỳnh Xuân Phụng  
**Đề tài:** Knuth–Morris–Pratt (KMP) String Matching  
**Ngôn ngữ lập trình:** C++17  
**GitHub:** https://github.com/tobyasteria/KMP-String-Matching

## 1. Thông tin nhóm và phân công công việc (C2)

**Thành viên 1: Lương Anh Hào**
- MSSV: **25110017**; GitHub: **tobyasteria** (quản lý repository).
- Thiết lập project C++17, triển khai và tích hợp `NaiveSearch()`, `buildLPS()` và `KMPSearch()` với sự hướng dẫn và rà soát của AI.
- Tích hợp chương trình Console, kiểm tra thực thi thủ công, xử lý vấn đề môi trường, quản lý commit và tổ chức tài liệu/minh chứng.

**Thành viên 2: Nguyễn Quốc Hào**
- MSSV: **25110018**; GitHub: **haonguyen457**.
- Rà soát source code và logic thuật toán; biên dịch và chạy chương trình độc lập trên máy cá nhân; kiểm tra kết quả và góp ý.

**Tình hình phân công:** Lương Anh Hào phụ trách lập trình và tích hợp chính, Nguyễn Quốc Hào tham gia review và xác minh độc lập. Các công việc Tuần 2–4 chưa chia cố định và sẽ được cập nhật theo thực tế. GitHub chủ yếu được push từ tài khoản `tobyasteria`, nhưng việc đóng góp của từng người được mô tả riêng, không suy đoán từ tài khoản commit.

## 2. Công việc đã thực hiện

- Phân tích đề tài: cần Naive Search, LPS/failure function, KMP Search, kiểm thử và benchmarking.
- Khởi tạo cấu trúc `src/`, `include/`, `tests/`, `results/`, `report/`, `evidence/` và môi trường VS Code/G++.
- **`src/naive.cpp`:** triển khai Naive Search để tìm tất cả vị trí xuất hiện của pattern.
- **`src/kmp.cpp`:** triển khai `buildLPS()` và `KMPSearch()`, dùng LPS để xử lý mismatch mà không lùi vị trí text.
- **`include/search.h`:** khai báo các hàm để dùng xuyên suốt các file nguồn.
- **`src/main.cpp`:** nhập text/pattern, in LPS, kết quả Naive và KMP, đối chiếu bằng `Verification: PASS/FAIL`.
- Biên dịch/chạy chương trình thủ công bằng G++; bổ sung ảnh output vào repository.
- Chuẩn bị Hand Trace cho `Text = ABABABAC`, `Pattern = ABABAC`; giải thích tại sao `j` từ 5 quay về 3 khi `i` giữ ở 5.
- Soạn tài liệu README, AI Usage Log, Self-Explanation và báo cáo tiến độ; kiểm tra nội dung trước khi push.

`tests/test_cases.cpp` và `src/benchmark.cpp` hiện vẫn là file dự phòng cho Tuần 2, **chưa triển khai**.

## 3. Kết quả đạt được

- Đã hoàn thành code nền tảng của cả Naive Search, LPS và KMP Search.
- Chương trình Console đã có khả năng nhận dữ liệu, in các vị trí khớp (chỉ số bắt đầu từ 0) và kiểm tra hai thuật toán có trả cùng kết quả.
- Đã có minh chứng một lần chạy chương trình trên GitHub, và thành viên thứ hai đã chạy thử độc lập trên máy của mình.
- Hiểu thêm mối liên hệ giữa LPS và việc tránh lặp lại phép so sánh trong KMP.
- **Giới hạn:** đối chiếu Naive–KMP không phải bằng chứng đầy đủ về tính đúng đắn; chưa có bộ test tự động hoặc kết quả đo hiệu suất.

### 3.1. Minh chứng source code (C3)

- **Naive Search:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/src/naive.cpp
- **KMP và LPS:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/src/kmp.cpp
- **Main Program:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/src/main.cpp
- **Header:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/include/search.h
- **README:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/README.md
- **AI Usage Log:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/AI_USAGE_LOG.md
- **Hand Trace:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/report/week1_hand_trace.md
- **Self-Explanation:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/report/week1_self_explanation.md

**Lưu ý:** Những link tài liệu bổ sung chỉ hiển thị nội dung mới sau khi commit/push gói tài liệu Tuần 1.

### 3.2. Minh chứng kiểm thử

Biên dịch từ thư mục gốc:

```powershell
g++ -std=c++17 -Wall -Wextra -Iinclude src/main.cpp src/naive.cpp src/kmp.cpp -o main.exe
.\main.exe
```

Ví dụ dùng để mô phỏng và đối chiếu:

| Nội dung | Kết quả mong đợi |
|---|---|
| Text | `ABABABAC` |
| Pattern | `ABABAC` |
| LPS | `[0, 0, 1, 2, 3, 0]` |
| Naive matches | `[2]` |
| KMP matches | `[2]` |
| Verification | `PASS` |

Đây là **kết quả mong đợi của ví dụ**. Không ghi nhận là bộ kiểm thử tự động đã đạt PASS. Bộ test có dữ liệu đầu vào và expected result sẽ được bổ sung ở Tuần 2.

**Ảnh Console hiện đã có trên GitHub:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/evidence/01_basic_string_matching.png

Thành viên Nguyễn Quốc Hào đã chạy chương trình trên máy riêng. Nhóm sẽ bổ sung ảnh riêng cho hoạt động kiểm tra độc lập nếu thu thập được, không tuyên bố ảnh đó đã có khi chưa tải lên.

### 3.3. Minh chứng lịch sử commit (C6)

1. **Triển khai Naive và KMP ban đầu:** https://github.com/tobyasteria/KMP-String-Matching/commit/4a2fe8b92f87982f1c895bb501e94f513fb637c1
2. **Sửa khai báo KMP:** https://github.com/tobyasteria/KMP-String-Matching/commit/a310f75eb8635ec6616e85d6555c4995d2f7ecf5
3. **Hoàn thiện code Tuần 1:** https://github.com/tobyasteria/KMP-String-Matching/commit/ee9eee8ae3d123e3aec20c481f7bceac0d0e6631
4. **Đưa ảnh minh chứng lên repository:** https://github.com/tobyasteria/KMP-String-Matching/commit/997a1a53be35621cb8ee15e82d09e855b9bf9b05

Lịch sử đầy đủ: https://github.com/tobyasteria/KMP-String-Matching/commits/main

**Commit tài liệu cuối Tuần 1:** sẽ bổ sung đường dẫn `/commit/<SHA>` sau khi thực hiện commit/push.

### 3.4. Hand Trace KMP

Với `Text = ABABABAC` và `Pattern = ABABAC`, tính được `LPS = [0,0,1,2,3,0]`. Sau khi khớp `ABABA`, so sánh tại `i=5, j=5` thất bại (`B` khác `C`). KMP dùng `lps[4]=3` để đưa `j` về 3, giữ `i=5`. Phép so sánh tiếp theo khớp `B`, và cuối cùng tìm thấy pattern ở vị trí **2**. Chi tiết từng bước nằm ở `report/week1_hand_trace.md`.

## 4. Khó khăn gặp phải

- Ban đầu chưa hiểu rõ ý nghĩa LPS và lý do dùng `len = lps[len-1]`.
- Phải phân biệt rõ hai chỉ số `i` (text) và `j` (pattern) khi mismatch.
- IntelliSense của VS Code từng báo sai về `std::vector`/khai báo hàm; cần kiểm tra `includePath` và `compilerPath`.
- Cần học thêm cách biên dịch nhiều file C++ bằng Terminal và ý nghĩa các tùy chọn của G++.
- Cấu hình build mặc định của VS Code chưa khớp với lệnh compile đầy đủ; nhóm đã chuẩn bị bản cập nhật.
- Chưa có test tự động, phép đo thời gian thực tế hoặc số phép so sánh ký tự.
- Cần bảo đảm các tài liệu và ảnh minh chứng tồn tại thật trên GitHub khi nộp.

## 5. Kế hoạch Tuần 2

1. Triển khai `tests/test_cases.cpp` với đầu vào và kết quả mong đợi cụ thể.
2. Kiểm thử text/pattern rỗng, pattern dài hơn text, không tìm thấy, nhiều lần xuất hiện, chồng lấp và chuỗi lặp.
3. Đối chiếu Naive và KMP trên nhiều input, không chỉ một ví dụ.
4. Bổ sung bộ đếm số phép so sánh ký tự theo quy tắc đo thống nhất.
5. Triển khai `src/benchmark.cpp` đo thời gian với văn bản tự nhiên và dữ liệu đối kháng `aaaa...ab`.
6. Lưu dữ liệu vào `results/`, chụp ảnh Console và giải thích kết quả.
7. Phân công trách nhiệm cụ thể giữa hai thành viên, cập nhật AI log/README và commit đều theo từng phần thực hiện.

## 6. Sử dụng AI trong Tuần 1 (C7)

Nhóm sử dụng **ChatGPT (OpenAI)** để hỗ trợ giải thích Naive Search, LPS và KMP; gợi ý cách triển khai, ví dụ, cấu trúc project; rà soát code; khắc phục lỗi VS Code/G++; soạn Hand Trace, README và báo cáo.

**Lương Anh Hào** triển khai/tích hợp và chạy code trong project, điều chỉnh cấu hình và quản lý GitHub. **Nguyễn Quốc Hào** rà soát code và chạy chương trình độc lập. Các thành viên cần hiểu được nội dung nộp và đối chiếu các gợi ý AI với kết quả thực tế. Nhóm không tuyên bố phần code hoặc tài liệu đã được tạo hoàn toàn không có AI hỗ trợ.

Chi tiết: https://github.com/tobyasteria/KMP-String-Matching/blob/main/AI_USAGE_LOG.md (cập nhật sau khi push gói tài liệu).

## 7. Tự đánh giá

Tuần 1 hoàn thành phần code nền tảng của đề tài và có bước chạy thử thủ công. Nhóm đã phân biệt được hoạt động của Naive và KMP, cũng như lý do LPS giúp giảm thao tác lặp khi mismatch. Tuy nhiên, chưa có đủ bằng chứng để đánh giá toàn diện tính đúng đắn và hiệu suất. Tuần 2 sẽ tập trung kiểm thử có expected result và benchmark có số liệu, đồng thời duy trì commit theo tiến độ thực tế.
