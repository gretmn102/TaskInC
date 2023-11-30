#include <stdio.h>
#include <windows.h>

int ProcessCreateWriteAndRead(char *programPath, char *inputData, int inputDataLength, char *outputData, int outputDataLength) {
    HANDLE childInputReadPipe, childInputWritePipe;
    HANDLE childOutputReadPipe, childOutputWritePipe;
    SECURITY_ATTRIBUTES securityAttributes;
    PROCESS_INFORMATION processInformation;
    STARTUPINFO startupInfo;

    DWORD bytesWritten, bytesRead;

    securityAttributes.nLength = sizeof(SECURITY_ATTRIBUTES);
    securityAttributes.bInheritHandle = TRUE;
    securityAttributes.lpSecurityDescriptor = NULL;

    if (!CreatePipe(&childInputReadPipe, &childInputWritePipe, &securityAttributes, 0)) {
        fprintf(stderr, "CreatePipe failed (%d)\n", GetLastError());
        exit(EXIT_FAILURE);
    }

    if (!CreatePipe(&childOutputReadPipe, &childOutputWritePipe, &securityAttributes, 0)) {
        fprintf(stderr, "CreatePipe failed (%d)\n", GetLastError());
        exit(EXIT_FAILURE);
    }

    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    startupInfo.hStdInput = childInputReadPipe;
    startupInfo.hStdOutput = childOutputWritePipe;
    startupInfo.dwFlags |= STARTF_USESTDHANDLES;

    ZeroMemory(&processInformation, sizeof(processInformation));

    if (!CreateProcess(NULL, programPath, NULL, NULL, TRUE, 0, NULL, NULL, &startupInfo, &processInformation)) {
        fprintf(stderr, "CreateProcess failed (%d)\n", GetLastError());
        exit(EXIT_FAILURE);
    }

    if (!WriteFile(childInputWritePipe, inputData, inputDataLength, &bytesWritten, NULL)) {
        fprintf(stderr, "WriteFile failed (%d)\n", GetLastError());
        exit(EXIT_FAILURE);
    }

    CloseHandle(childInputWritePipe);
    CloseHandle(childInputReadPipe);

    if (!ReadFile(childOutputReadPipe, outputData, outputDataLength, &bytesRead, NULL)) {
        fprintf(stderr, "ReadFile failed (%d)\n", GetLastError());
        exit(EXIT_FAILURE);
    }

    CloseHandle(childOutputReadPipe);
    CloseHandle(childOutputWritePipe);

    WaitForSingleObject(processInformation.hProcess, INFINITE);

    CloseHandle(processInformation.hProcess);
    CloseHandle(processInformation.hThread);

    return bytesRead;
}
