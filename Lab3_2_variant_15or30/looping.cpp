#include <stdio.h>
#include <windows.h>
#include "looping.h"


char requestUserToInputChar();


void setConsoleLanguageRus()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}



bool userWantToFinishProgram()
{
    printf("Хотите ли вы заверишить программу (д/н)\n");

    while (true)
    {
        switch (requestUserToInputChar())
        {
        case 'н':
        case 'Н':
            return CONTINUE_PROGRAM;
        case 'д':
        case 'Д':
            return FINISH_PROGRAM;
        default:
            printf("Ввод не распознан. Повторите попытку ввода (д/н)\n");
        }
    }

    printf("\n\n");
}



char requestUserToInputChar()
{
    char c;

    printf("-------------------------------\n");
    scanf_s("%c", &c);
    printf("-------------------------------\n");
    scanf_s("%*[^\n]");
    scanf_s("%*c");

    return c;
}