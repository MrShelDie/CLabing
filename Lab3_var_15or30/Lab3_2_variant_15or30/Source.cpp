#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "looping.h"

#define ARRAY_SIZE 10
#define LIMIT_RANDOM 100


void fillArrayRandomNumber(int arr[ARRAY_SIZE][ARRAY_SIZE], int arrSize);
void printArray(int arr[ARRAY_SIZE][ARRAY_SIZE], int arrSize);
int findMinInRow(int arr[ARRAY_SIZE][ARRAY_SIZE], int rowIdx);



int main()
{
    bool isProgramFinish = false;

    srand(time(NULL));
    setConsoleLanguageRus();

    int arr[ARRAY_SIZE][ARRAY_SIZE];

    do
    {
        fillArrayRandomNumber(arr, ARRAY_SIZE);
        printf("Случайно сгенерированная матрица:\n\n");
        printArray(arr, ARRAY_SIZE);

        printf("\nМинимальный элемент в каждой строке в соответствии с заданной областью:\n\n");

        for (int i = 0; i < ARRAY_SIZE; i++)
            printf("%d\n", findMinInRow(arr, i));

        if (userWantToFinishProgram())
            isProgramFinish = true;

    } while (!isProgramFinish);

    return 0;
}



void fillArrayRandomNumber(int arr[ARRAY_SIZE][ARRAY_SIZE], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
            arr[i][j] = rand() % LIMIT_RANDOM;
    }
}



void printArray(int arr[ARRAY_SIZE][ARRAY_SIZE], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
            printf("%-5d", arr[i][j]);
        printf("\n");
    }
}



int findMinInRow(int arr[ARRAY_SIZE][ARRAY_SIZE], int rowIdx)
{
    int min = _CRT_INT_MAX;
    for (int j = 0; j <= rowIdx; j++)
    {
        if (arr[rowIdx][j] < min)
            min = arr[rowIdx][j];
    }

    return min;
}