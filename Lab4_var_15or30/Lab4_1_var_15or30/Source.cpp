#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


#define MATRIX_ROW_COUNT 5
#define MATRIX_COL_COUNT 5
#define RAND_LIMIT_NUM  10
#define NUMBER_OF_EVEN_ROWS MATRIX_ROW_COUNT / 2


void setConsoleLanguageRus();
void fillMatrixRandomNums(int* matrix[], int rowCount, int colCount);
int** createMatrix(int rowCount, int colCount);
void freeMatrix(int* matrix[], int rowCount);
void printMatrix(int* matrix[], int rowCount, int colCount);
void printArray(int arr[], int length);
int sumElementsInRow(int* matrix[], int colCount, int rowIndex);
void forMatrixEvenRowsDo(int* matrix[], int rowCount, int colCount, int (*func)(int* matrix[], int rowIndex, int colCount), int output[]);


int main() {
    srand(time(NULL));
    setConsoleLanguageRus();

    int** matrix = createMatrix(MATRIX_ROW_COUNT, MATRIX_COL_COUNT);
    //int matrix[MATRIX_ROW_COUNT][MATRIX_COL_COUNT];

    fillMatrixRandomNums(matrix, MATRIX_ROW_COUNT, MATRIX_COL_COUNT);

    printf("Случайно сгенерированная матрица:\n");
    printMatrix(matrix, MATRIX_ROW_COUNT, MATRIX_COL_COUNT);

    int sumsOfEvenRows[NUMBER_OF_EVEN_ROWS];

    forMatrixEvenRowsDo(matrix, MATRIX_ROW_COUNT, MATRIX_COL_COUNT, sumElementsInRow, sumsOfEvenRows);

    printf("Массив, состоящий из сумм элементов четных строк матрицы:\n");
    printArray(sumsOfEvenRows, NUMBER_OF_EVEN_ROWS);

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
            matrix[i][j] = rand() % RAND_LIMIT_NUM + 1;
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



int sumElementsInRow(int* matrix[], int rowIndex, int colCount) {
    int sum = 0;
    for (int i = 0; i < colCount; i++)
        sum += matrix[rowIndex][i];
    return sum;
}



void forMatrixEvenRowsDo (
    int* matrix[], int rowCount, int colCount, 
    int (*func)(int* matrix[], int rowIndex, int colCount), 
    int output[]
) {
    for (int rowIndex = 1, outputArrayIndex = 0; rowIndex < rowCount; rowIndex += 2, outputArrayIndex++) {
        output[outputArrayIndex] = func(matrix, rowIndex, colCount);
    }
}