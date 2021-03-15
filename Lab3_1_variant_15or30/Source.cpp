#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include "looping.h"

#define ERROR_INDEX_NOT_FOUND -1
#define ARRAY_SIZE_A 5
#define ARRAY_SIZE_B 5
#define LIMIT_RANDOM 50
#define FINISH_PROGRAM true
#define CONTINUE_PROGRAM false


void fillArrayRandomNumbers(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
int findFirstNegative(int arr[], int arrSize);
float avarage(int arr[], int startIndex, int endIndex);



int main() 
{
    bool isProgramFinish = false;

    srand(time(NULL));
    setConsoleLanguageRus();

    int A[ARRAY_SIZE_A];
    int B[ARRAY_SIZE_B];
    
    do
    {   
        fillArrayRandomNumbers(A, ARRAY_SIZE_A);
        fillArrayRandomNumbers(B, ARRAY_SIZE_B);

        printf("Сгенерированный массив A:");
        printArray(A, ARRAY_SIZE_A);
        printf("Сгенерированный массив B:");
        printArray(B, ARRAY_SIZE_B);

        int firstNegativeNumberIndexA = findFirstNegative(A, ARRAY_SIZE_A);
        printf("Индекс первого отрицательного элеммента массива А: %d\n", firstNegativeNumberIndexA);
        int firstNegativeNumberIndexB = findFirstNegative(B, ARRAY_SIZE_B);
        printf("Индекс первого отрицательного элеммента массива B: %d\n", firstNegativeNumberIndexB);

        printf("Среднее арифметическое элементов массива A, стоящих после первого отрицательного элемента: %f\n", avarage(A, firstNegativeNumberIndexA + 1, ARRAY_SIZE_A - 1));
        printf("Среднее арифметическое элементов массива B, стоящих после первого отрицательного элемента: %f\n", avarage(B, firstNegativeNumberIndexB + 1, ARRAY_SIZE_B - 1));

        if (userWantToFinishProgram())
            isProgramFinish = true;

    } while (!isProgramFinish);


    return 0;
}



void fillArrayRandomNumbers(int arr[], int arrSize) 
{
    for (int i = 0; i < arrSize; i++)
        arr[i] = powf(-1, (rand()) % 2) * (rand() % LIMIT_RANDOM);
}



void printArray(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%7d", arr[i]);
    }

    printf("\n");
}



int findFirstNegative(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++) 
    {
        if (arr[i] < 0)
            return i;
    }

    return ERROR_INDEX_NOT_FOUND;
}



float avarage(int arr[], int startIndex, int endIndex) 
{
    if (startIndex <= endIndex)
    {
        int sum = 0;

        for (int i = startIndex; i <= endIndex; i++)
            sum += arr[i];

        return (float)sum / (endIndex - startIndex + 1);
    }

    else
        return 0;
}