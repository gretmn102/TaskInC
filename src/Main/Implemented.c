#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <limits.h>
#include <wchar.h>
#include <stdbool.h>

typedef struct Range {
    int from;
    int to;
} Range;

/**
 * @brief Интерактивно создает диапазон.
 * @return @p Range
 */
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

/**
 * @brief Генерирует случайное значение в пределах указанного @p range
 * @param[in] range диапазон возможных значений от и до. К примеру, при @p range равном <tt>{1, 5}</tt> функция будет генерировать числа 1, 2, 3 и 4.
 * @return Случайное число в заданном диапазоне.
 */
int RandomRange(Range *range)
{
    int diff = range->to - range->from;
    return rand() % diff + range->from;
}

/**
 * @brief Выводит элементы массива.
 *
 * К примеру, <tt>ArrayPrint([-10, 40, 100, -1234], 4)</tt> выдаст следующее:
 *
 * @code{.txt}
 * Индекс Значение
 *      0      -10
 *      1       40
 *      2      100
 *      3    -1234
 * @endcode
 *
 * @param array
 * @param arrayLength
 */
void ArrayPrint(int *array, int arrayLength) {
    wprintf(L"Индекс Значение\n");
    for (int i = 0; i < arrayLength; i++) {
        wprintf(L"%6d %8d\n", i, array[i]);
    }
    printf("\n");
}

/**
 * @brief Заполняет массив числами из стандартного ввода, разделенными через символ переноса.
 * @param array
 * @param arrayLength
 */
void ArrayFillFromInput(int *array, int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        scanf("%d", &array[i]);
    }
}

/**
 * @brief Заполняет массив случайными числами, которые генерируются из указанного диапазона.
 * @param array
 * @param arrayLength
 * @param range диапазон возможных чисел, @see RandomRange
 */
void ArrayFillRandomNumbers(int *array, int arrayLength, Range *range) {
    srand(time(NULL));

    for (int i = 0; i < arrayLength; i++) {
        int j = RandomRange(range);
        array[i] = j;
    }
}

/**
 * @brief Находит средне арифметическое значение элементов массива, индексы которых кратны @p multipleOfIndex
 * @param[in] array входной массив
 * @param size длина массива
 * @param multipleOfIndex
 */
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

/**
 * @brief То же, что и `ArrayAverage`, но доступ к массиву реализован с помощью указателей.
 * @see ArrayAverage
 * @param array указатель на массив
 * @param size длина массива
 * @param multipleOfIndex
 */
float ArrayPtrAverage(int *array, int size, int multipleOfIndex) {
    int len = 0;
    int sum = 0;
    int *arrayFirst = array;
    int *arrayLast = array + size;
    int *multipleOfIndexLast = array + multipleOfIndex;

    array++;

    for (; array < arrayLast && array <= multipleOfIndexLast; array++) {
        if (multipleOfIndex % (array - arrayFirst) == 0) {
            sum += *array;
            len++;
        }
    }
    if (len > 0) {
        return (float)sum / (float)len;
    }

    return 0;
}

/**
 * @param count
 * @param min
 * @param minCount
 */
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

/**
 * @brief Считает кол-во чисел, которые больше указанного @p exclusiveMin .
 *        Находит среди них минимальное число.
 *        Подсчитывает, сколько раз встречается это минимальное число.
 * @param array
 * @param arrayLength
 * @param exclusiveMin считаются числа больше этого числа
 */
GreaterThan ArrayGreaterThan(int *array, int arrayLength, int exclusiveMin)
{
    int count = 0;
    int min = INT_MAX;
    int minCount = -1;
    int current;
    for (int i = 0; i < arrayLength; i++)
    {
        current = array[i];
        if (current > exclusiveMin)
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

/**
 * @brief То же, что и @p ArrayGreaterThan, но доступ к массиву реализован с помощью указателей.
 * @see ArrayGreaterThan()
 */
GreaterThan ArrayPtrGreaterThan(int *array, int arraySize, int exclusiveMin)
{
    int count = 0;
    int min = INT_MAX;
    int minCount = -1;
    int current;
    for (int *arrayLast = array + arraySize; array < arrayLast; array++)
    {
        current = *array;
        if (current > exclusiveMin)
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
