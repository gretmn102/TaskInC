#include <math.h>

#include <src/Implemented.c>

#define ARRAY_SIZE(arr)  (sizeof arr / sizeof *arr)

void TestArrayAverage() {
    {
        printf("TestArrayAverage.test1\n");
        int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        float act = ArrayAverage((int *)&arr, ARRAY_SIZE(arr), 0);
        float exp = 0.0;
        if (fabs(exp - act) > 0.1) {
            printf("Expected %f but %f!\n", exp, act);
            exit(EXIT_FAILURE);
        }
    }
    {
        printf("TestArrayAverage.test2\n");
        int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
        float act = ArrayAverage((int *)&arr, ARRAY_SIZE(arr), 10);
        float exp = 6.333333;
        if (fabs(exp - act) > 0.1) {
            printf("Expected %f but %f!\n", exp, act);
            exit(EXIT_FAILURE);
        }
    }
    {
        printf("TestArrayAverage.test3\n");
        int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        float act = ArrayAverage((int *)&arr, ARRAY_SIZE(arr), 10);
        float exp = 2.6666666;
        if (fabs(exp - act) > 0.1) {
            printf("Expected %f but %f!\n", exp, act);
            exit(EXIT_FAILURE);
        }
    }
}

void TestArrayGreaterThan() {
    {
        printf("TestArrayGreaterThan.test1\n");
        int arr[] = { 1, 1, 0, 3, 5, 3, 2, 2 };
        GreaterThan act = ArrayGreaterThan((int *)&arr, ARRAY_SIZE(arr), 2);
        GreaterThan exp = { 3, 3, 2 };
        if (!GreaterThanEquals(&act, &exp)) {
            char actStr[80];
            GreaterThanString(&act, actStr);
            char expStr[80];
            GreaterThanString(&exp, expStr);
            printf("Expected %s but %s!\n", expStr, actStr);
            exit(EXIT_FAILURE);
        }
    }
    {
        printf("TestArrayGreaterThan.test2\n");
        int arr[] = { 0 };
        GreaterThan act = ArrayGreaterThan((int *)&arr, ARRAY_SIZE(arr), 2);
        GreaterThan exp = { 0, INT_MAX, -1 };
        if (!GreaterThanEquals(&act, &exp)) {
            char actStr[80];
            GreaterThanString(&act, actStr);
            char expStr[80];
            GreaterThanString(&exp, expStr);
            printf("Expected %s but %s!\n", expStr, actStr);
            exit(EXIT_FAILURE);
        }
    }
    {
        printf("TestArrayGreaterThan.test3\n");
        int arr[] = { -32, 19, 28, 95, 88, 48, -13, 6, -14, 6, 54 };
        GreaterThan act = ArrayGreaterThan((int *)&arr, ARRAY_SIZE(arr), 0);
        GreaterThan exp = { 8, 6, 2 };
        if (!GreaterThanEquals(&act, &exp)) {
            char actStr[80];
            GreaterThanString(&act, actStr);
            char expStr[80];
            GreaterThanString(&exp, expStr);
            printf("Expected %s but %s!\n", expStr, actStr);
            exit(EXIT_FAILURE);
        }
    }
}

void RunTests() {
    TestArrayAverage();
    TestArrayGreaterThan();
}

int main(void) {
    RunTests();
    return 0;
}