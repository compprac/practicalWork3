#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp(const void* a, const void* b) {
   return (*(int*)b - *(int*)a);
}

int* createArray(int len, int a, int b) {
    srand(time(NULL));
    int* arr = NULL;
    int i = 0;

    arr = calloc(len, sizeof(int));
    if (arr == NULL) {
        printf("Failed to allocate memory for array");
        return arr;
    }
    for (i = 0; i < len; i++) {
        arr[i] = a + rand() % (b - a + 1);
    }
    return arr;
}

void sortArray(int* arr, int len) {
    qsort(arr, len, sizeof (int), comp);
}

void printArray(int* arr, int len) {
    int i = 0;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deleteArray(int* arr) {
    free(arr);
}
