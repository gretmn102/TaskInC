#include "Implemented.c"

int userFriendlySolution() {
    int *numberArray;
    int numberArraySize;
    int multipleOfIndex;
    float average;

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
    wprintf(L"Среднее арифметическое: %f\n", average);

    GreaterThan result = ArrayGreaterThan(numberArray, numberArraySize, average);

    // char buff[80];
    // GreaterThanString(&result, (char *)buff);
    // printf("%s\n", buff);
    wprintf(L"Кол-во чисел больше средне арифметического: %d\n", result.count);
    wprintf(L"Минимальное число больше средне арифметического: %d\n", result.min);
    wprintf(L"Кол-во таких чисел: %d\n", result.minCount);

    free(numberArray);

    return 0;
}

int automaticSolution() {
    int numberArray[40];
    int numberArraySize = 40;
    int multipleOfIndex;
    float average;

    ArrayFillFromInput(numberArray, numberArraySize);

    scanf("%d", &multipleOfIndex);

    average = ArrayAverage(numberArray, numberArraySize, multipleOfIndex);

    GreaterThan result = ArrayGreaterThan(numberArray, numberArraySize, average);

    printf("%.4f\n%d\n%d %d\n", average, result.count, result.min, result.minCount);

    return 0;
}

int main(void) {
    return userFriendlySolution();
    // return automaticSolution();
}
