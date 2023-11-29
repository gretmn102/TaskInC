#include "Implemented.c"

int main(void) {
    int *numberArray;
    int numberArraySize;
    int multipleOfIndex;
    float average;
    printf("%.4f", 73.0);
    setlocale(LC_CTYPE, "Russian");

    Range range = RangeCreateFromInput();

    wprintf(L"Введите размер массива: ");
    scanf("%d", &numberArraySize);

    numberArray = (int *)malloc(numberArraySize * sizeof(int));

    if (numberArray == NULL) {
        wprintf(L"Memory allocation failed. Exiting...\n");
        return 1;
    }

    ArrayFillRandomNumbers(numberArray, numberArraySize, &range);

    wprintf(L"Полученный массив случайных чисел:\n");
    ArrayPrint(numberArray, numberArraySize);

    wprintf(L"Введите a: ");
    scanf("%d", &multipleOfIndex);

    average = ArrayAverage(numberArray, numberArraySize, multipleOfIndex);
    wprintf(L"Среднее арифметическое — %f\n", average);

    GreaterThan result = ArrayGreaterThan(numberArray, numberArraySize, average);

    // char buff[80];
    // GreaterThanString(&result, (char *)buff);
    // printf("%s\n", buff);

    printf("%.4f\n%d\n%d %d\n", average, result.count, result.min, result.minCount);

    free(numberArray);

    return 0;
}
