
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct IndexedItem {
    int index;
    int value;
} IndexedItem;

void IndexedItemPairSwap(IndexedItem *a, IndexedItem *b) {
    IndexedItem temp = *a;
    *a = *b;
    *b = temp;
}

typedef IndexedItem *IndexedArray;

void IndexedArrayFromArray(int *sourceArray, int size, IndexedArray targetArray) {
    int i;
    for (i = 0; i < size; i++)
    {
        struct IndexedItem item = {i, sourceArray[i]};
        targetArray[i] = item;
    }
}

void IndexedArrayPrint(IndexedArray indexedArray, int size) {
    int i;
    IndexedItem *indexedItem;

    wprintf(L"Индекс  Значение\n");
    for (i = 0; i < size; i++) {
        indexedItem = &indexedArray[i];
        wprintf(L"%d%8d\n", indexedItem->index, indexedItem->value);
    }
    printf("\n");
}

void IndexArrayShuffle(IndexedArray indexedArray, int size) {
    srand(time(NULL));

    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        IndexedItemPairSwap(&indexedArray[i], &indexedArray[j]);
    }
}

void FillArray(int *array, int size) {
    int i;

    wprintf(L"Введите %d целых чисел:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

int main(void) {
    int *numberArray;
    int numberArraySize;
    IndexedArray indexedNumberArray;

    setlocale(LC_CTYPE, "Russian");

    wprintf(L"Введите количество чисел: ");
    scanf("%d", &numberArraySize);

    numberArray = (int *)malloc(numberArraySize * sizeof(int));

    if (numberArray == NULL) {
        wprintf(L"Memory allocation failed. Exiting...\n");
        return 1;
    }

    FillArray(numberArray, numberArraySize);
    printf("\n");

    indexedNumberArray = malloc(numberArraySize * sizeof(IndexedItem));

    IndexedArrayFromArray(numberArray, numberArraySize, indexedNumberArray);

    wprintf(L"Массив до случайного перемешивания:\n");
    IndexedArrayPrint(indexedNumberArray, numberArraySize);

    IndexArrayShuffle(indexedNumberArray, numberArraySize);

    wprintf(L"Массив после случайного перемешивания:\n");
    IndexedArrayPrint(indexedNumberArray, numberArraySize);

    free(numberArray);
    free(indexedNumberArray);

    return 0;
}
