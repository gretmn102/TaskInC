#include <stdbool.h>

_Bool StringEquals(char *first, int firstLength, char *second) {
    for (int i = 0; i < firstLength; i++) {
        if (first[i] != second[i]) {
            return false;
        }
    }
    return true;
}
