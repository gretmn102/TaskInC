#ifndef PROCESS_H_
#define PROCESS_H_

int ProcessCreateWriteAndRead(
    char *programPath,
    char *inputData,
    int inputDataLength,
    char *outputData,
    int outputDataLength);

#endif // PROCESS_H_
