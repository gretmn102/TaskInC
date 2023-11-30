#include <math.h>

typedef struct Response {
    float average;
    int count;
    int min;
    int minCount;
} Response;

Response ResponseParse(char *receiveData, int receiveDataLength) {
    float average;
    int resultCount, resultMin, resultMinCount;
    sscanf(receiveData,
        "%f\n%d\n%d %d\n",
        &average,
        &resultCount,
        &resultMin, &resultMinCount
    );

    Response response = { average, resultCount, resultMin, resultMinCount };

    return response;
}

int ResponseToString(Response *response, char *str) {
    return sprintf(
        str,
        "{ average = %f, count = %d, min = %d, minCount = %d }",
        response->average,
        response->count,
        response->min,
        response->minCount
    );
}

_Bool ResponseEquals(Response *response1, Response *response2, float accuracy) {
    return fabs(response1->average - response2->average) < accuracy
        && (response1->count == response2->count)
        && (response1->min == response2->min)
        && (response1->minCount == response2->minCount);
}
