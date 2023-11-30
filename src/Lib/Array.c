#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr)  (sizeof arr / sizeof *arr)

int ArrayToString(int *arr, int arrLen, char *sep, char *str) {
    int offset = 0;
    for (int i = 0; i < arrLen; i++) {
        int charsWritten = sprintf(str + offset, "%d%s", arr[i], sep);
        offset += charsWritten;
    }

    str[offset] = '\0';

    return offset + 1;
}

_Bool ArrayEquals(int *first, int *second, int size) {
    for (int i = 0; i < size; i++) {
        if (first[i] != second[i]) {
            return false;
        }
    }
    return true;
}
