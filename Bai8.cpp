#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tu;
    int mau;
} PhanSo;

// Hàm nhập phân số
void nhapPhanSo(PhanSo* ps) {
    printf("Nhap tu so: ");
    scanf_s("%d", &ps->tu);
    do {
        printf("Nhap mau so (mau != 0): ");
        scanf_s("%d", &ps->mau);
        if (ps->mau == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (ps->mau == 0);
}

// Hàm nhập mảng phân số
void nhapMangPhanSo(PhanSo* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        nhapPhanSo(&arr[i]);
    }
}

// Hàm xuất phân số
void xuatPhanSo(PhanSo ps) {
    printf("%d/%d ", ps.tu, ps.mau);
}

// Hàm xuất mảng phân số
void xuatMangPhanSo(PhanSo* arr, int size) {
    for (int i = 0; i < size; i++) {
        xuatPhanSo(arr[i]);
    }
    printf("\n");
}

// Hàm xuất các phân số có mẫu > tử
void xuatPhanSoMauLonHonTu(PhanSo* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i].mau > arr[i].tu) {
            xuatPhanSo(arr[i]);
        }
    }
    printf("\n");
}

// Hàm đếm số phân số có mẫu và tử chẵn
int demPhanSoMauVaTuChan(PhanSo* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i].tu % 2 == 0 && arr[i].mau % 2 == 0) {
            count++;
        }
    }
    return count;
}

// Hàm tính UCLN
int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

// Hàm rút gọn phân số
PhanSo rutGonPhanSo(PhanSo ps) {
    int ucln = UCLN(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
    return ps;
}

// Hàm rút gọn mảng phân số
void rutGonMangPhanSo(PhanSo* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rutGonPhanSo(arr[i]);
    }
}

// Hàm tính tích các phần tử của mảng
PhanSo tinhTichMangPhanSo(PhanSo* arr, int size) {
    PhanSo tich = { 1, 1 };
    for (int i = 0; i < size; i++) {
        tich.tu *= arr[i].tu;
        tich.mau *= arr[i].mau;
    }
    return rutGonPhanSo(tich);
}

// Hàm so sánh phân số
float giaTriThuc(PhanSo ps) {
    return (float)ps.tu / ps.mau;
}

// Hàm tìm phân số lớn nhất
PhanSo timPhanSoLonNhat(PhanSo* arr, int size) {
    PhanSo max = arr[0];
    for (int i = 1; i < size; i++) {
        if (giaTriThuc(arr[i]) > giaTriThuc(max)) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int size;
    printf("Nhap so luong phan so: ");
    scanf_s("%d", &size);

    PhanSo* arr = (PhanSo*)malloc(size * sizeof(PhanSo));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    // a. Nhập mảng phân số
    nhapMangPhanSo(arr, size);

    // a. Xuất mảng phân số
    printf("\n------------\n");
    printf("Mang phan so: ");
    xuatMangPhanSo(arr, size);

    // b. Xuất các phân số có mẫu > tử
    printf("Cac phan so co mau > tu: ");
    xuatPhanSoMauLonHonTu(arr, size);

    // c. Đếm số phân số có mẫu và tử chẵn
    int count = demPhanSoMauVaTuChan(arr, size);
    printf("So phan so co mau va tu chan: %d\n", count);

    // d. Rút gọn các phân số trong mảng
    rutGonMangPhanSo(arr, size);
    printf("Mang phan so sau khi rut gon: ");
    xuatMangPhanSo(arr, size);

    // e. Tính tích các phần tử của mảng
    PhanSo tich = tinhTichMangPhanSo(arr, size);
    printf("Tich cac phan so trong mang: ");
    xuatPhanSo(tich);
    printf("\n");

    // f. Tìm phân số lớn nhất
    PhanSo max = timPhanSoLonNhat(arr, size);
    printf("Phan so lon nhat: ");
    xuatPhanSo(max);
    printf("\n");

    free(arr);
    return 0;
}
