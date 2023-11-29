#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct Range {
    int from;
    int to;
} Range;

Range RangeCreateFromInput()
{
    int to, from;
    wprintf(L"Введите число от: ");
    scanf("%d", &from);
    wprintf(L"Введите число до: ");
    scanf("%d", &to);

    if (!(from < to)) {
        wprintf(L"Значение \"до\" должно быть меньше, чем \"от\"!\n");
        exit(EXIT_FAILURE);
    }

    wprintf(L"Выбранный диапазон случайных чисел — от %d до %d.\n", from, to);

    struct Range range = { from, to };
    return range;
}

int RandomRange(Range *range)
{
    int diff = range->to - range->from;
    return rand() % diff + range->from;
}

void ArrayPrint(int *arr, int size) {
    wprintf(L"Индекс Значение\n");
    for (int i = 0; i < size; i++) {
        wprintf(L"%6d %8d\n", i, arr[i]);
    }
    printf("\n");
}

void ArrayFillFromInput(int *array, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

void ArrayFillRandomNumbers(int *array, int size, Range *range) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        int j = RandomRange(range);
        array[i] = j;
    }
}

float ArrayAverage(int *array, int size, int multipleOfIndex) {
    int len = 0;
    int sum = 0;
    for (int i = 1; i < size && i <= multipleOfIndex; i++) {
        if (multipleOfIndex % i == 0) {
            sum += array[i];
            len++;
        }
    }
    if (len > 0) {
        return (float)sum / (float)len;
    }

    return 0;
}

typedef struct GreaterThan {
    int count;
    int min;
    int minCount;
} GreaterThan;

_Bool GreaterThanEquals(GreaterThan *first, GreaterThan *second) {
    return first->count == second->count && first->min == second->min && first->minCount == second->minCount;
}

void GreaterThanString(GreaterThan *this, char *buffer) {
    sprintf(buffer, "{ count = %d, min = %d, minCount = %d }", this->count, this->min, this->minCount);
}

GreaterThan ArrayGreaterThan(int *array, int size, int number)
{
    int count = 0;
    int min = INT_MAX;
    int minCount = -1;
    int current;
    for (int i = 0; i < size; i++)
    {
        current = array[i];
        if (current > number)
        {
            if (current < min) {
                min = current;
                minCount = 1;
            } else if (current == min) {
                minCount++;
            }
            count++;
        }
    }
    struct GreaterThan greaterThan = { count, min, minCount };
    return greaterThan;
}
