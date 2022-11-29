#define ARRAY_LENGTH 50
#define MATRIX_X 6
#define MATRIX_Y 7
#define ELEM_FROM -50
#define ELEM_TO 50
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcs.h"
#include "load.h"

int main()
{
    setlocale(LC_ALL, "rus");
    void* lib = NULL;
    int inputType = 0;
    printf("1. Матрица\n2. Массив\n");
    scanf("%d", &inputType);
    switch (inputType) {
        case 1: {
            lib = loadLib(inputType);
            if (lib == NULL) {
                return 1;
            }
            int** mtr = createMatrix(MATRIX_X, MATRIX_Y, ELEM_FROM, ELEM_TO);
            printf("Исходная матрица:\n");
            printMatrix(mtr, MATRIX_X, MATRIX_Y);
            sortMatrix(mtr, MATRIX_X, MATRIX_Y);
            printf("Обработанная матрица:\n");
            printMatrix(mtr, MATRIX_X, MATRIX_Y);
            deleteMatrix(mtr, MATRIX_X);
            unloadLib(lib);
            break;
        }
        case 2: {
            lib = loadLib(inputType);
            if (lib == NULL) {
                return 1;
            }
            int* arr = createArray(ARRAY_LENGTH, ELEM_FROM, ELEM_TO);
            printf("Исходный массив:\n");
            printArray(arr, ARRAY_LENGTH);
            sortArray(arr, ARRAY_LENGTH);
            printf("Обработанный массив:\n");
            printArray(arr, ARRAY_LENGTH);
            deleteArray(arr);
            unloadLib(lib);
            break;
        }
        default: {
            printf("[!] Неверно выбран тип входных данных");
        }
    }
    return 0;
}
