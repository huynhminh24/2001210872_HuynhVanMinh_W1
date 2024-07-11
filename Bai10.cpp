#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hàm xuất giá trị từng ký tự của chuỗi thông qua con trỏ
void xuatKyTu(const char* st) {
    while (*st != '\0') {
        printf("%c ", *st);
        st++;
    }
    printf("\n");
}

// Hàm chuyển tất cả các ký tự của chuỗi về dạng chữ hoa sử dụng mã ASCII
void chuyenChuHoa(char* st) {
    while (*st != '\0') {
        if (*st >= 'a' && *st <= 'z') {
            *st = *st - 'a' + 'A';
        }
        st++;
    }
}

// Hàm chuyển ký tự đầu mỗi từ của chuỗi về dạng chữ hoa sử dụng mã ASCII
void chuyenKyTuDauChuHoa(char* st) {
    int i;
    int len = strlen(st);

    // Duyệt qua từng ký tự của chuỗi
    for (i = 0; i < len; i++) {
        // Nếu là ký tự đầu tiên của chuỗi hoặc ký tự trước đó là khoảng trắng
        if (i == 0 || st[i - 1] == ' ') {
            // Nếu ký tự hiện tại là chữ thường
            if (st[i] >= 'a' && st[i] <= 'z') {
                st[i] = st[i] - 'a' + 'A';
            }
        }
        else {
            // Nếu ký tự hiện tại là chữ hoa
            if (st[i] >= 'A' && st[i] <= 'Z') {
                st[i] = st[i] - 'A' + 'a';
            }
        }
    }
}

int main() {
    char* st;
    st = (char*)malloc(100 * sizeof(char)); // Cấp phát bộ nhớ cho chuỗi

    if (st == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    // Nhập chuỗi
    printf("Nhap chuoi: ");
    fgets(st, 100, stdin);

    // Loại bỏ ký tự xuống dòng cuối chuỗi (nếu có)
    size_t len = strlen(st);
    if (len > 0 && st[len - 1] == '\n') {
        st[len - 1] = '\0';
    }

    // a. Xuất giá trị từng ký tự của st thông qua con trỏ
    printf("Cac ky tu cua chuoi: ");
    xuatKyTu(st);

    // b. Chuyển các ký tự của chuỗi về dạng chữ hoa
    chuyenChuHoa(st);
    printf("Chuoi sau khi chuyen ve chu hoa: %s\n", st);

    // c. Chuyển các ký tự đầu mỗi từ của chuỗi về dạng chữ hoa
    chuyenKyTuDauChuHoa(st);
    printf("Chuoi sau khi chuyen ky tu dau moi tu ve chu hoa: %s\n", st);

    free(st); // Giải phóng bộ nhớ
    return 0;
}
