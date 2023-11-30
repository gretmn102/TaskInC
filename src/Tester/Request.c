typedef struct Request {
    int *numbers;
    int numbersLength;
    int multipleOfIndex;
} Request;

int RequestToString(Request *request, char *buff) {
    int stringNumbersLength = ArrayToString(
        request->numbers,
        request->numbersLength,
        "\n",
        buff
    );
    int offset = stringNumbersLength - 1;

    int charsWritten = sprintf(buff + offset, "%d", request->multipleOfIndex);
    offset += charsWritten;

    buff[offset] = '\0';

    return offset + 1;
}
