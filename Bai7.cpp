#include <stdio.h>
#include <math.h>
#include <conio.h>

#define MAX_SIZE 100

// Hàm xuất mảng
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm tìm phần tử lớn nhất
void findMaxElement(int* arr, int size) {
    int* maxPtr = arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > *maxPtr) {
            maxPtr = arr + i;
        }
    }
    printf("Phan tu lon nhat la: %d tai dia chi: %p\n", *maxPtr, maxPtr);
}

// Hàm tìm phần tử chẵn lớn nhất và phần tử lẻ nhỏ nhất
void findEvenOddElements(int* arr, int size) {
    int* maxEvenPtr = NULL, * minOddPtr = NULL;

    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 == 0) {
            if (maxEvenPtr == NULL || *(arr + i) > *maxEvenPtr) {
                maxEvenPtr = arr + i;
            }
        }
        else {
            if (minOddPtr == NULL || *(arr + i) < *minOddPtr) {
                minOddPtr = arr + i;
            }
        }
    }

    if (maxEvenPtr) {
        printf("Phan tu chan lon nhat la: %d tai dia chi: %p\n", *maxEvenPtr, maxEvenPtr);
    }
    else {
        printf("Khong co phan tu chan trong mang\n");
    }

    if (minOddPtr) {
        printf("Phan tu le nho nhat la: %d tai dia chi: %p\n", *minOddPtr, minOddPtr);
    }
    else {
        printf("Khong co phan tu le trong mang\n");
    }
}

// Hàm xóa phần tử có giá trị 0
void deleteZeroElements(int* arr, int* size) {
    int* writePtr = arr;
    for (int* readPtr = arr; readPtr < arr + *size; readPtr++) {
        if (*readPtr != 0) {
            *writePtr++ = *readPtr;
        }
    }
    *size = writePtr - arr;
}

// Hàm thêm phần tử x vào sau phần tử đầu tiên
void insertElementAfterFirst(int* arr, int* size, int x) {
    if (*size >= MAX_SIZE - 1) {
        printf("Mang da day, khong the them phan tu\n");
        return;
    }
    for (int i = *size; i > 1; i--) {
        arr[i] = arr[i - 1];
    }
    arr[1] = x;
    (*size)++;
}

// Hàm kiểm tra số chính phương
int isPerfectSquare(int n) {
    int sqrtN = sqrt(n);
    return (sqrtN * sqrtN == n);
}

// Hàm tính tổng các phần tử là số chính phương
int sumOfPerfectSquares(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (isPerfectSquare(*(arr + i))) {
            sum += *(arr + i);
        }
    }
    return sum;
}

// Hàm xuất các số cực đại trong mảng
void findPeakElements(int* arr, int size) {
    if (size == 1) {
        printf("%d ", arr[0]);
        return;
    }

    for (int i = 0; i < size; i++) {
        if ((i == 0 && arr[i] > arr[i + 1]) ||
            (i == size - 1 && arr[i] > arr[i - 1]) ||
            (i > 0 && i < size - 1 && arr[i] > arr[i - 1] && arr[i] > arr[i + 1])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void main() {
    int arr[MAX_SIZE] = { 3, 0, 2, 7, 9, 5, 0, 6 };
    int size = 8;
    printf("Mang duoc khoi tao la: \n");
    printArray(arr, size);
    // a. Tìm phần tử lớn nhất và xuất ra phần tử lớn nhất và địa chỉ của nó thông qua con trỏ mảng
    printf("------------\n");
    printf("a.\n");
    printf("------------\n");
    printf("\n");
    findMaxElement(arr, size);

    // b. Xuất địa chỉ của phần tử chẵn lớn nhất và phần tử lẻ nhỏ nhất
    printf("------------\n");
    printf("b.\n");
    printf("------------\n");
    printf("\n");
    findEvenOddElements(arr, size);

    // c. Xóa phần tử có giá trị 0
    printf("------------\n");
    printf("c.\n");
    printf("------------\n");
    printf("\n");
    deleteZeroElements(arr, &size);
    printf("Mang sau khi xoa cac phan tu co gia tri 0: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // d. Thêm phần tử x vào sau phần tử đầu tiên
    printf("------------\n");
    printf("d.\n");
    printf("------------\n");
    printf("\n");
    int x = 4;
    insertElementAfterFirst(arr, &size, x);
    printf("Mang sau khi them phan tu %d vao sau phan tu dau tien: ", x);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // e. Tính tổng các phần tử là số chính phương
    printf("------------\n");
    printf("e.\n");
    printf("------------\n");
    printf("\n");
    int sum = sumOfPerfectSquares(arr, size);
    printf("Tong cac phan tu la so chinh phuong: %d\n", sum);

    // f. Xuất các số cực đại trong mảng
    printf("------------\n");
    printf("f.\n");
    printf("------------\n");
    printf("\n");
    printf("Cac so cuc dai trong mang: ");
    findPeakElements(arr, size);

    getch();
}
