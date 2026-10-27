# BÁO CÁO TIẾN ĐỘ TUẦN 1 – ĐỒ ÁN CUỐI KỲ

**Môn học:** Cấu trúc dữ liệu và giải thuật (DASA230179)  
**Giảng viên hướng dẫn:** Huỳnh Xuân Phụng  
**Đề tài:** Knuth–Morris–Pratt (KMP) String Matching  
**Ngôn ngữ lập trình:** C++17  
**GitHub Repository:** https://github.com/tobyasteria/KMP-String-Matching

---

## 1. Thông tin nhóm và phân công công việc

**Lương Anh Hào — MSSV: 25110017 — GitHub: `tobyasteria`**

- Tạo cấu trúc project C++17; triển khai và tích hợp Naive Search, LPS, KMP Search.
- Cấu hình VS Code/G++, chạy chương trình, quản lý GitHub và tập hợp minh chứng.

**Nguyễn Quốc Hào — MSSV: 25110018 — GitHub: `haonguyen457`**

- Rà soát code và logic thuật toán.
- Biên dịch, chạy thử độc lập trên máy cá nhân và đối chiếu kết quả.

Tuần 1, Lương Anh Hào thực hiện lập trình chính; Nguyễn Quốc Hào đảm nhiệm rà soát và xác minh độc lập. Các công việc Tuần 2 sẽ được phân công khi triển khai.

## 2. Công việc đã thực hiện

- Khởi tạo các thư mục `src/`, `include/`, `tests/`, `results/`, `report/`, `evidence/`.
- `src/naive.cpp`: triển khai `NaiveSearch()` tìm các vị trí khớp.
- `src/kmp.cpp`: triển khai `buildLPS()` và `KMPSearch()`.
- `include/search.h`: khai báo các hàm dùng chung.
- `src/main.cpp`: nhập text/pattern, in LPS và vị trí khớp; đối chiếu kết quả bằng `Verification: PASS/FAIL`.
- Biên dịch và chạy thử bằng G++; lưu ảnh kết quả trên GitHub.
- Chuẩn bị Hand Trace cho text `ABABABAC` và pattern `ABABAC`.

**Lưu ý:** `tests/test_cases.cpp` và `src/benchmark.cpp` vẫn là các file trống, dự kiến triển khai ở Tuần 2.

## 3. Kết quả và minh chứng

Nhóm đã triển khai các thuật toán nền tảng và chạy kiểm tra Console ở mức cơ bản. Kết quả trùng nhau giữa Naive và KMP trên một đầu vào chưa thay thế được kiểm thử tự động.

### 3.1. Link file nguồn (C3)

- **Naive Search:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/src/naive.cpp
- **KMP và LPS:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/src/kmp.cpp
- **Main:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/src/main.cpp
- **Header:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/include/search.h
- **README:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/README.md
- **AI Usage Log:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/AI_USAGE_LOG.md
- **Hand Trace:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/report/week1_hand_trace.md
- **Self-Explanation:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/report/week1_self_explanation.md
- **Báo cáo Tuần 1:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/report/weekly_report_01.md
- **Cấu hình build:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/.vscode/tasks.json

### 3.2. Cách biên dịch và ví dụ

```powershell
g++ -std=c++17 -Wall -Wextra -Iinclude src/main.cpp src/naive.cpp src/kmp.cpp -o main.exe
.\main.exe
```

Với `Text = ABABABAC`, `Pattern = ABABAC`, kết quả mong đợi:

| Nội dung | Kết quả |
|---|---|
| LPS | `0 0 1 2 3 0` |
| Naive Search | `2` |
| KMP Search | `2` |
| Verification | `PASS` |

**Ảnh Console:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/evidence/01_basic_string_matching.png

### 3.3. Hand Trace

Với pattern `ABABAC`, LPS là `[0, 0, 1, 2, 3, 0]`.

Khi đã khớp `ABABA` rồi gặp mismatch ở `j = 5`, thuật toán dùng `LPS[4] = 3` để giảm `j` về 3 trong khi giữ nguyên `i = 5`; kết quả khớp bắt đầu ở vị trí 2.

**Bảng trace:** https://github.com/tobyasteria/KMP-String-Matching/blob/main/report/week1_hand_trace.md

### 3.4. Lịch sử commit (C6)

1. **Triển khai thuật toán ban đầu:** https://github.com/tobyasteria/KMP-String-Matching/commit/4a2fe8b92f87982f1c895bb501e94f513fb637c1
2. **Sửa khai báo KMP:** https://github.com/tobyasteria/KMP-String-Matching/commit/a310f75eb8635ec6616e85d6555c4995d2f7ecf5
3. **Hoàn thiện chương trình Tuần 1:** https://github.com/tobyasteria/KMP-String-Matching/commit/ee9eee8ae3d123e3aec20c481f7bceac0d0e6631
4. **Bổ sung ảnh minh chứng:** https://github.com/tobyasteria/KMP-String-Matching/commit/997a1a53be35621cb8ee15e82d09e855b9bf9b05
5. **Bổ sung tài liệu Tuần 1:** https://github.com/tobyasteria/KMP-String-Matching/commit/ca63cddcbe978290cc136fa2a7a85749822d5190
6. **Cập nhật README:** https://github.com/tobyasteria/KMP-String-Matching/commit/2e4a2ebfd65f726c7b8d4b4575c3c845486d0c4e
7. **Hoàn thiện cấu hình build:** https://github.com/tobyasteria/KMP-String-Matching/commit/33576a740640d3beda995764301f4aed8355edbf

**Toàn bộ lịch sử:** https://github.com/tobyasteria/KMP-String-Matching/commits/main

## 4. Khó khăn gặp phải

- Ban đầu khó hiểu cách fallback `len = lps[len - 1]` khi tạo LPS.
- Mất thời gian phân biệt `i` (text) và `j` (pattern) trong KMP.
- VS Code báo lỗi IntelliSense với `vector` dù vẫn biên dịch được bằng G++.
- Chưa quen biên dịch nhiều file C++ trong Terminal.
- README từng được push rỗng; tên file Hand Trace chưa khớp link; task build từng thiếu `src/kmp.cpp` — các lỗi này đã được sửa.
- Tuần 1 chưa có kiểm thử tự động hoặc kết quả benchmark.

## 5. Kế hoạch Tuần 2

- Viết kiểm thử tự động trong `tests/test_cases.cpp` với trường hợp rỗng, không tìm thấy, pattern dài hơn text và khớp chồng lấp.
- Kiểm tra bằng đáp án mong đợi độc lập, không chỉ đối chiếu hai thuật toán.
- Thêm thống kê số lần so sánh ký tự.
- Xây dựng benchmark trong `src/benchmark.cpp` cho văn bản tự nhiên và chuỗi lặp như `aaaa...ab`.
- Lưu kết quả vào `results/`, bổ sung minh chứng, phân công nhiệm vụ và commit theo tiến độ.

## 6. Đánh giá tiến độ

Phần code Naive, LPS và KMP cùng chương trình Console đã được triển khai. Nhóm đã có ví dụ Hand Trace và minh chứng chạy thử.

Công việc kiểm thử tự động, benchmark và đánh giá số liệu sẽ tiếp tục trong Tuần 2.