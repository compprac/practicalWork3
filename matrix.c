#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp(const void* a, const void* b) {
   return (*(int*)b - *(int*)a);
}

int** createMatrix(int lenX, int lenY, int a, int b) {
    srand(time(NULL));
    int** mtr = NULL;
    int i = 0, j = 0;

    mtr = calloc(lenX, sizeof(int));
    if (mtr == NULL) {
        printf("Failed to allocate memory for matrix");
        return mtr;
    }
    for (i = 0; i < lenX; i++) {
        mtr[i] = calloc(lenY, sizeof(int));
        for (j = 0; j < lenY; j++) {
            mtr[i][j] = a + rand() % (b - a + 1);
        }
    }
    return mtr;
}

void sortMatrix(int** mtr, int lenX, int lenY) {
    int i = 0;
    for (i = 0; i < lenX; i++) {
        qsort(mtr[i], lenY, sizeof (int), comp);
    }
}

void printMatrix(int** mtr, int lenX, int lenY) {
    int i = 0, j = 0;
    for (i = 0; i < lenX; i++) {
        for (j = 0; j < lenY; j++) {
            printf("%d ", mtr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void deleteMatrix(int** mtr, int lenX) {
    int i = 0;
    for (i = 0; i < lenX; i++) {
        free(mtr[i]);
    }
    free(mtr);
}
