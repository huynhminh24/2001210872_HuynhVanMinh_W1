#include <stdio.h>
#include <conio.h>

// Hàm xuất mảng
void xuatMang(int* a, int n) {
    printf("Mang duoc khoi tao la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Hàm xuất các số cực tiểu trong mảng
void xuatSoCucTieu(int* a, int n) {
    if (n < 3) {
        printf("Khong co so cuc tieu trong mang.\n");
        return;
    }

    printf("Cac so cuc tieu trong mang: ");
    for (int i = 1; i < n - 1; i++) {
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// Hàm xóa phần tử tại vị trí k
void xoaPhanTu(int* a, int* n, int k) {
    if (k < 0 || k >= *n) {
        printf("Vi tri %d khong hop le.\n", k);
        return;
    }

    // Dịch chuyển các phần tử từ k+1 đến n-1 sang trái để ghi đè phần tử k
    for (int i = k; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }

    // Giảm số lượng phần tử đi 1 sau khi xóa
    (*n)--;
}

// Hàm thêm phần tử x vào vị trí k trong mảng
void themPhanTu(int* a, int* n, int k, int x) {
    if (k < 0 || k > *n) {
        printf("Vi tri %d khong hop le.\n", k);
        return;
    }

    // Dịch chuyển các phần tử từ n-1 đến k sang phải để tạo khoảng trống cho phần tử mới
    for (int i = *n; i > k; i--) {
        a[i] = a[i - 1];
    }

    // Gán giá trị x vào vị trí k
    a[k] = x;

    // Tăng số lượng phần tử lên 1 sau khi thêm
    (*n)++;
}

// Hàm chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng
void chuyenChanLe(int* a, int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        // Tìm số lẻ từ bên trái
        while (left < n && a[left] % 2 == 0) {
            left++;
        }

        // Tìm số chẵn từ bên phải
        while (right >= 0 && a[right] % 2 != 0) {
            right--;
        }

        // Nếu left < right thì hoán đổi
        if (left < right) {
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
            left++;
            right--;
        }
    }
}

// Hàm kiểm tra mảng có chứa chẵn lẻ xen kẻ không
int kiemTraChanLeXenKe(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        if ((a[i] % 2 == 0 && a[i + 1] % 2 == 0) || (a[i] % 2 != 0 && a[i + 1] % 2 != 0)) {
            return 0; // Không xen kẻ
        }
    }
    return 1; // Xen kẻ
}

void main() {
    int a[] = { 3, 0, 2, 7, 9, 5, 0, 6 };
    int n = 8;

    xuatMang(a, n);

    // a. Xuất các số cực tiểu trong mảng
    xuatSoCucTieu(a, n);

    // b. Xóa phần tử tại vị trí k
    int k = 2;
    xoaPhanTu(a, &n, k);
    printf("Sau khi xoa phan tu tai vi tri %d:\n", k);
    xuatMang(a, n);

    // c. Thêm phần tử x vào vị trí k
    int x = 8;
    k = 3;
    themPhanTu(a, &n, k, x);
    printf("Sau khi them phan tu %d vao vi tri %d:\n", x, k);
    xuatMang(a, n);

    // d. Chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng
    chuyenChanLe(a, n);
    printf("Sau khi chuyen so chan len dau, so le xuong cuoi:\n");
    xuatMang(a, n);

    // e. Kiểm tra mảng có chứa chẵn lẻ xen kẻ không
    if (kiemTraChanLeXenKe(a, n)) {
        printf("Mang chua chua chan le xen ke.\n");
    }
    else {
        printf("Mang khong chua chan le xen ke.\n");
    }

    getch();
}