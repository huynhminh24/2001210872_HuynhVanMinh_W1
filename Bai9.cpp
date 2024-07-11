#include <stdio.h>

int main() {
    float a, b;
    float* pa, * pb;

    // Nhập hai số thực a và b
    printf("Nhap so thuc a: ");
    scanf_s("%f", &a);
    printf("Nhap so thuc b: ");
    scanf_s("%f", &b);

    // Gán địa chỉ của a và b cho con trỏ pa và pb
    pa = &a;
    pb = &b;

    // Tính toán tổng, hiệu, tích, thương thông qua con trỏ
    float tong = *pa + *pb;
    float hieu = *pa - *pb;
    float tich = *pa * *pb;
    float thuong = *pa / *pb;

    // Xuất kết quả và địa chỉ ô nhớ
    printf("Tong: %.2f, Dia chi: %p\n", tong, (void*)&tong);
    printf("Hieu: %.2f, Dia chi: %p\n", hieu, (void*)&hieu);
    printf("Tich: %.2f, Dia chi: %p\n", tich, (void*)&tich);
    printf("Thuong: %.2f, Dia chi: %p\n", thuong, (void*)&thuong);

    return 0;
}
