#include <stdio.h>
#include <windows.h>
#include "funcs.h"

void* loadLib(int libNumber) {
    void* lib;
    switch (libNumber) {
        case 1: {
            lib = LoadLibrary("matrix.dll");
            if (!lib) {
                printf("cannot open library 'matrix.dll'\n");
                return NULL;
            }
            break;
        }
        case 2: {
            lib = LoadLibrary("array.dll");
            if (!lib) {
                printf("cannot open library 'array.dll'\n");
                return NULL;
            }
            break;
        }
        default: {
            printf("undefined library\n");
            return NULL;
        }
    }

    switch (libNumber) {
        case 1: {
            createMatrix = (int** (*)(int, int, int, int))GetProcAddress((HINSTANCE)lib, "createMatrix");
            if (createMatrix == NULL) {
                printf("cannot load function createMatrix\n");
            }
            sortMatrix = (void (*)(int**, int, int))GetProcAddress((HINSTANCE)lib, "sortMatrix");
            if (sortMatrix == NULL) {
                printf("cannot load function sortMatrix\n");
            }
            printMatrix = (void (*)(int**, int, int))GetProcAddress((HINSTANCE)lib, "printMatrix");
            if (printMatrix == NULL) {
                printf("cannot load function printMatrix\n");
            }
            deleteMatrix = (void (*)(int**, int))GetProcAddress((HINSTANCE)lib, "deleteMatrix");
            if (deleteMatrix == NULL) {
                printf("cannot load function deleteMatrix\n");
            }
            break;
        }
        case 2: {
            createArray = (int* (*)(int, int, int))GetProcAddress((HINSTANCE)lib, "createArray");
            if (createArray == NULL) {
                printf("cannot load function createArray\n");
            }
            sortArray = (void (*)(int*, int))GetProcAddress((HINSTANCE)lib, "sortArray");
            if (sortArray == NULL) {
                printf("cannot load function sortArray\n");
            }
            printArray = (void (*)(int*, int))GetProcAddress((HINSTANCE)lib, "printArray");
            if (printArray == NULL) {
                printf("cannot load function printArray\n");
            }
            deleteArray = (void (*)(int*))GetProcAddress((HINSTANCE)lib, "deleteArray");
            if (deleteArray == NULL) {
                printf("cannot load function deleteArray\n");
            }
            break;
        }
    }
    return lib;
}

void unloadLib(void* lib) {
    FreeLibrary((HINSTANCE)lib);
}
