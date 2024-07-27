#include <math.h>

#include "../src/Lib/Array.c"
#include "../src/Lib/String.h"
#include "../src/Main/Implemented.c"

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

void TestArrayPtrAverage() {
    {
        printf("TestArrayPtrAverage.test1\n");
        int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        float act = ArrayPtrAverage((int *)&arr, ARRAY_SIZE(arr), 0);
        float exp = 0.0;
        if (fabs(exp - act) > 0.1) {
            printf("Expected %f but %f!\n", exp, act);
            exit(EXIT_FAILURE);
        }
    }
    {
        printf("TestArrayPtrAverage.test2\n");
        int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
        float act = ArrayPtrAverage((int *)&arr, ARRAY_SIZE(arr), 10);
        float exp = 6.333333;
        if (fabs(exp - act) > 0.1) {
            printf("Expected %f but %f!\n", exp, act);
            exit(EXIT_FAILURE);
        }
    }
    {
        printf("TestArrayPtrAverage.test3\n");
        int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        float act = ArrayPtrAverage((int *)&arr, ARRAY_SIZE(arr), 10);
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

void TestArrayPtrGreaterThan() {
    {
        printf("TestArrayPtrGreaterThan.test1\n");
        int arr[] = { 1, 1, 0, 3, 5, 3, 2, 2 };
        GreaterThan act = ArrayPtrGreaterThan((int *)&arr, ARRAY_SIZE(arr), 2);
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
        printf("TestArrayPtrGreaterThan.test2\n");
        int arr[] = { 0 };
        GreaterThan act = ArrayPtrGreaterThan((int *)&arr, ARRAY_SIZE(arr), 2);
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
        printf("TestArrayPtrGreaterThan.test3\n");
        int arr[] = { -32, 19, 28, 95, 88, 48, -13, 6, -14, 6, 54 };
        GreaterThan act = ArrayPtrGreaterThan((int *)&arr, ARRAY_SIZE(arr), 0);
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

void TestArrayToString() {
    {
        printf("TestArrayToString.test1\n");
        int arr[] = { 1, 2, 3 };
        char actStr[80];
        int actStrLength = ArrayToString((int *)arr, ARRAY_SIZE(arr), ",", actStr);

        int expStrLength = 7;
        if (expStrLength != actStrLength) {
            printf("Expected: %d\nActual: %d\n", expStrLength, actStrLength);
            exit(EXIT_FAILURE);
        }

        char expStr[] = "1,2,3,";
        if (!StringEquals((char *)expStr, ARRAY_SIZE(expStr), (char *)actStr)) {
            printf("Expected: %s\n Actual: %s!\n", expStr, actStr);
            exit(EXIT_FAILURE);
        }
    }
}

void TestStringEquals() {
    {
        printf("StringEquals.test1\n");
        char arr1[] = "1,2,3";
        char arr2[] = "1,2,3";
        bool act = StringEquals((char *)arr1, ARRAY_SIZE(arr1), (char *)arr2);
        bool exp = true;
        if (exp != act) {
            printf("Error!\n");
            exit(EXIT_FAILURE);
        }
    }
}

void RunTests() {
    TestArrayAverage();
    TestArrayPtrAverage();
    TestArrayGreaterThan();
    TestArrayPtrGreaterThan();
    TestArrayToString();
    TestStringEquals();
}

int main(void) {
    RunTests();
    return 0;
}