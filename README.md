# KMP String Matching — Đồ án cuối kỳ DSA

Cài đặt và so sánh thuật toán tìm kiếm chuỗi **Naive Search** và **Knuth–Morris–Pratt (KMP)** bằng C++17.

## 1. Thông tin chung

| Nội dung | Thông tin |
|---|---|
| Môn học | Cấu trúc dữ liệu và giải thuật (DASA230179) |
| Giảng viên | Huỳnh Xuân Phụng |
| Đề tài | Knuth–Morris–Pratt String Matching |
| Ngôn ngữ | C++17 |
| Repository | https://github.com/tobyasteria/KMP-String-Matching |

### Thành viên và phân công Tuần 1

| Thành viên | MSSV | GitHub | Công việc |
|---|---|---|---|
| Lương Anh Hào | 25110017 | `tobyasteria` | Cấu trúc project, triển khai Naive/LPS/KMP, tích hợp Console, chạy thử và quản lý repo |
| Nguyễn Quốc Hào | 25110018 | `haonguyen457` | Rà soát logic code, biên dịch và chạy kiểm tra độc lập trên máy cá nhân |

Phân công Tuần 2–4 sẽ được cập nhật theo công việc thực tế.

## 2. Cấu trúc thư mục

```text
KMP_Project/
├── .vscode/                 # Cấu hình VS Code
├── src/
│   ├── main.cpp             # Nhập dữ liệu, in kết quả, đối chiếu
│   ├── naive.cpp            # NaiveSearch()
│   ├── kmp.cpp              # buildLPS(), KMPSearch()
│   └── benchmark.cpp        # Chưa triển khai (Tuần 2)
├── include/
│   └── search.h             # Khai báo hàm
├── tests/
│   └── test_cases.cpp       # Chưa triển khai (Tuần 2)
├── evidence/
│   └── 01_basic_string_matching.png
├── report/
│   ├── week1_hand_trace.md
│   ├── week1_self_explanation.md
│   └── weekly_report_01.md
├── results/                 # Dành cho dữ liệu benchmark
├── README.md
├── AI_USAGE_LOG.md
└── .gitignore
```

## 3. Biên dịch và chạy

Yêu cầu: G++ hỗ trợ C++17. Mở Terminal tại thư mục gốc project:

```powershell
g++ -std=c++17 -Wall -Wextra -Iinclude src/main.cpp src/naive.cpp src/kmp.cpp -o main.exe
.\main.exe
```

Ví dụ:

```text
Text: ABABABAC
Pattern: ABABAC
LPS: 0 0 1 2 3 0
Naive matches: 2
KMP matches: 2
Verification: PASS
```

Vị trí tìm thấy được đánh số từ **0**. Chương trình trả về danh sách rỗng khi pattern rỗng. `PASS` chỉ cho biết hai thuật toán cho kết quả giống nhau với đầu vào đang thử; chưa phải bằng chứng kiểm thử đầy đủ.

## 4. Thuật toán và tiến độ

| Nội dung | Trạng thái |
|---|---|
| Naive Search | Đã triển khai |
| Xây dựng LPS | Đã triển khai |
| KMP Search | Đã triển khai |
| Console và đối chiếu kết quả | Đã triển khai |
| Hand Trace | Đã có tài liệu |
| Kiểm thử tự động | Dự kiến Tuần 2 |
| Benchmark tự nhiên / chuỗi lặp | Dự kiến Tuần 2 |

Naive Search có độ phức tạp xấu nhất **O(n × m)**. Xây dựng LPS cần **O(m)**; KMP Search cần **O(n)** sau tiền xử lý, tổng cộng **O(n + m)**.

## 5. Tài liệu và minh chứng

- [Báo cáo Tuần 1](report/weekly_report_01.md)
- [Hand Trace KMP](report/week1_hand_trace.md)
- [Ghi chú giải thích thuật toán](report/week1_self_explanation.md)
- [AI Usage Log](AI_USAGE_LOG.md)
- [Ảnh kết quả Console](evidence/01_basic_string_matching.png)
- [Lịch sử commit](https://github.com/tobyasteria/KMP-String-Matching/commits/main)

## 6. Minh bạch sử dụng AI

Nhóm sử dụng ChatGPT (OpenAI) để hỗ trợ tìm hiểu khái niệm thuật toán, gợi ý cấu trúc code C++, rà soát lỗi logic và xử lý lỗi môi trường (G++, VS Code). Toàn bộ nội dung báo cáo, mã nguồn tích hợp, tài liệu hướng dẫn và các file ghi chú đều do các thành viên tự viết và kiểm duyệt. Thông tin chi tiết được ghi trong [AI_USAGE_LOG.md](AI_USAGE_LOG.md).