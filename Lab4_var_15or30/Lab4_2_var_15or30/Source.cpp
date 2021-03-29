#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


#define MATRIX_ROW_COUNT 5
#define MATRIX_COL_COUNT 5
#define RAND_LIMIT_NUM  2


void setConsoleLanguageRus();
void fillMatrixRandomNums(int* matrix[], int rowCount, int colCount);
int** createMatrix(int rowCount, int colCount);
void freeMatrix(int* matrix[], int rowCount);
void printMatrix(int* matrix[], int rowCount, int colCount);
void printArray(int arr[], int length);
int numberOfZerosInArray(int arr[], int startIndex, int endIndex);
void numberOfZerosInArea(int* matrix[], int rowCount, int colCount, int output[2]);



int main() {
    srand(time(NULL));
    setConsoleLanguageRus();

    int** matrix = createMatrix(MATRIX_ROW_COUNT, MATRIX_COL_COUNT);
    //int matrix[MATRIX_ROW_COUNT][MATRIX_COL_COUNT];

    fillMatrixRandomNums(matrix, MATRIX_ROW_COUNT, MATRIX_COL_COUNT);

    printf("Случайно сгенерированная матрица:\n");
    printMatrix(matrix, MATRIX_ROW_COUNT, MATRIX_COL_COUNT);

    int resultArray[2] = { 0 };

    numberOfZerosInArea(matrix, MATRIX_ROW_COUNT, MATRIX_COL_COUNT, resultArray);

    printf("Количество нулей в закрашенных областях:\n");
    printArray(resultArray, 2);

    freeMatrix(matrix, MATRIX_ROW_COUNT);

    return 0;
}



void setConsoleLanguageRus()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}



void fillMatrixRandomNums(int* matrix[], int rowCount, int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            matrix[i][j] = rand() % RAND_LIMIT_NUM;
        }
    }
}



int** createMatrix(int rowCount, int colCount) {
    int** matrix = (int**)malloc(sizeof(int*) * MATRIX_ROW_COUNT);
    for (int i = 0; i < MATRIX_ROW_COUNT; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * MATRIX_COL_COUNT);
    }

    return matrix;
}



void freeMatrix(int* matrix[], int rowCount) {
    for (int i = 0; i < rowCount; i++)
        free(matrix[i]);
    free(matrix);
}



void printMatrix(int* matrix[], int rowCount, int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            printf("%3d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}



void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++)
        printf("%3d\t", arr[i]);
    printf("\n");
}



int numberOfZerosInArray(int arr[], int startIndex, int endIndex) {
    int numberOfZeros = 0;
    for (int i = startIndex; i <= endIndex; i++) {
        if (arr[i] == 0)
            numberOfZeros++;
    }
    return numberOfZeros;
}



void numberOfZerosInArea(int* matrix[], int rowCount, int colCount, int output[2]) {
    int numberOfZeros = 0;

    for (int i = 0; i < (rowCount + 1) / 2; i++)
        numberOfZeros += numberOfZerosInArray(matrix[i], i, colCount - i - 1);

    output[0] = numberOfZeros;

    numberOfZeros = 0;

    for (int i = rowCount / 2; i < rowCount; i++)
        numberOfZeros += numberOfZerosInArray(matrix[i], colCount - i - 1, i);

    output[1] = numberOfZeros;
}