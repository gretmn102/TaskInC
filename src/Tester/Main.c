#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#include "../Lib/Array.c"
#include "Request.c"
#include "Response.c"
#include "Process.h"

int main(int argc, char *argv[]) {
    setlocale(LC_CTYPE, "Russian");

    if (argc != 2) {
        printf("Usage: %s <path-to-program>\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }

    char *programPath = argv[1];

    int numbers[] = { -8, 8, 4, 6, 3, 0, -4, 3, 10, -7, -4, -8, 3, 7, 0, 5, -3, -6, 1, 9, 5, -4, 9, 0, 3, 2, 1, 1, -5, -2, -5, -6, 10, 5, 7, -9, 4, -4, -7, 4 };
    int multipleOfIndex = 4;
    Request request;
    request.numbers = (int *)numbers;
    request.numbersLength = ARRAY_SIZE(numbers);
    request.multipleOfIndex = multipleOfIndex;

    Response expResponse;
    expResponse.average = 5.0;
    expResponse.count = 8;
    expResponse.min = 6;
    expResponse.minCount = 1;

    char stringRequest[256];
    int stringRequestLength = RequestToString(&request, stringRequest);

    wprintf(L"Ввожу в программу следующие числа:\n");
    for (int i = 0; i < request.numbersLength; i++) {
        wprintf(L"%d\n", request.numbers[i]);
    }

    wprintf(L"Ввожу средне арифметическое:\n");
    printf("%d\n", request.multipleOfIndex);
    printf("\n");

    char stringResponse[256];
    int stringResponseLengthMax = ARRAY_SIZE(stringResponse);

    wprintf(L"Проверяю...\n");
    printf("\n");

    int stringResponseLength = ProcessCreateWriteAndRead(
        programPath,
        stringRequest,
        stringRequestLength,
        stringResponse,
        stringResponseLengthMax
    );

    Response actResponse = ResponseParse(stringResponse, stringResponseLength);

    if (!ResponseEquals(&expResponse, &actResponse, 0.01)) {
        wprintf(L"Результаты не совпадают:\n");

        char stringExpResponse[256];
        ResponseToString(&expResponse, (char *)stringExpResponse);
        wprintf(L"Ожидается: %s\n", stringExpResponse);

        char stringActResponse[256];
        ResponseToString(&actResponse, (char *)stringActResponse);
        wprintf(L"По факту: %s\n", stringActResponse);

        return EXIT_FAILURE;
    }

    wprintf(L"Программа работает корректно.\n");

    return EXIT_SUCCESS;
}
