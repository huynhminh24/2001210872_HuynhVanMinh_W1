#include <stdio.h>

int main() {
    int a, b, c;

    printf("Nhap so nguyen a: ");
    scanf_s("%d", &a);

    printf("Nhap so nguyen b: ");
    scanf_s("%d", &b);

    printf("Nhap so nguyen c: ");
    scanf_s("%d", &c);

    if (a == b) {
        printf("Loi: a bang b, khong the chia cho 0\n");
    }
    else {
        float result = (float)c / (a - b);
        printf("Ket qua cua c/(a-b) la: %.2f\n", result);
    }

    return 0;
}
