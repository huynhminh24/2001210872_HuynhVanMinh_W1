#include <stdio.h>
#include <string.h>
#include <conio.h>

#define ERR_CODE_AGE 101
#define ERR_CODE_GENDER "errcode"

void throwError(int code) {
    if (code == ERR_CODE_AGE) {
        printf("------------\n");
        printf("Error: Nguoi nay khong nam trong do tuoi lao dong (Code %d)\n", ERR_CODE_AGE);
    }
}

void throwGenderError() {
    printf("------------\n");
    printf("Error: Gioi tinh khong hop le! (Code %s)\n", ERR_CODE_GENDER);
}

int calculateAge(int birthYear, int currentYear) {
    return currentYear - birthYear;
}

void calculateRetirementDate(int birthYear, int birthMonth, int retirementAge) {
    int retirementYear = birthYear + retirementAge;
    printf("------------\n");
    printf("Thoi gian nghi huu la: thang %02d/%d\n", birthMonth, retirementYear);
}

void main() {
    char hoTen[100];
    int ngaySinh, thangSinh, namSinh;
    char gioiTinh[10];
    int currentYear = 2024;
    int tuoi;

    // Nhap ho ten
    printf("Nhap ho ten: ");
    gets_s(hoTen);

    // Nhap ngay sinh
    printf("Nhap ngay sinh (dd mm yyyy): ");
    scanf_s("%d %d %d", &ngaySinh, &thangSinh, &namSinh);

    // Nhap gioi tinh
    printf("Nhap gioi tinh (nam/nu): ");
    scanf_s("%s", gioiTinh);

    // Tinh tuoi
    tuoi = calculateAge(namSinh, currentYear);

    // Kiem tra tuoi va gioi tinh hop le
    if ((strcmp(gioiTinh, "nam") == 0 && (tuoi < 18 || tuoi > 62)) || (strcmp(gioiTinh, "nu") == 0 && (tuoi < 18 || tuoi > 60))) {
        throwError(ERR_CODE_AGE);
    }
    else if (strcmp(gioiTinh, "nam") != 0 && strcmp(gioiTinh, "nu") != 0) {
        throwGenderError();
    }
    else {
        // Tinh thoi gian nghi huu
        if (strcmp(gioiTinh, "nam") == 0) {
            calculateRetirementDate(namSinh, thangSinh, 62);
        }
        else if (strcmp(gioiTinh, "nu") == 0) {
            calculateRetirementDate(namSinh, thangSinh, 60);
        }
    }

    getch();
}
