#include <stdio.h>
#include "../queue.h"
#include "../sut.h"


typedef struct {
    int i;
} tdat;

int tc_1(void) {
    queue_ctx *ctx1 = NULL;
    tdat *data1 = (tdat *)malloc(sizeof(tdat));
    data1->i = 13;
    tdat *data2 = (tdat *)malloc(sizeof(tdat));
    data2->i = 11;
    tdat *data3 = (tdat *)malloc(sizeof(tdat));
    data3->i = 100;
    int s;
    tdat *dataout = NULL;

    QUEUE_CREATE(ctx1);

    QUEUE_PEEK(ctx1, dataout);

    QUEUE_ENQUEUE(ctx1, data1);
    QUEUE_ENQUEUE(ctx1, data1);
    QUEUE_ENQUEUE(ctx1, data1);
    QUEUE_PEEK(ctx1, dataout);
    SUT_ASSERT_VAR_EQUAL("check peek", dataout->i, 13);
    
    QUEUE_ENQUEUE(ctx1, data2);
    QUEUE_ENQUEUE(ctx1, data3);
    QUEUE_SIZE(ctx1, s);
    SUT_ASSERT_VAR_EQUAL("check size", s, 5);

    QUEUE_DEQUEUE(ctx1);
    QUEUE_DEQUEUE(ctx1);
    QUEUE_DEQUEUE(ctx1);
    QUEUE_SIZE(ctx1, s);
    SUT_ASSERT_VAR_EQUAL("check dequeue", s, 2);

    QUEUE_PEEK(ctx1, dataout);
    SUT_ASSERT_VAR_EQUAL("check dequeue peek", dataout->i, 11);

    QUEUE_DEQUEUE(ctx1);
    QUEUE_DEQUEUE(ctx1);
    QUEUE_DEQUEUE(ctx1);
    QUEUE_SIZE(ctx1, s);
    SUT_ASSERT_VAR_EQUAL("empty queue by deque", s, 0);

    QUEUE_ENQUEUE(ctx1, data3);
    QUEUE_FREE(ctx1);
    QUEUE_SIZE(ctx1, s);
    SUT_ASSERT_VAR_EQUAL("empty queue by free", s, 0);

    QUEUE_ENQUEUE(ctx1, data3);
    QUEUE_ENQUEUE(ctx1, data3);
    QUEUE_DESTROY(ctx1);
    free(data1);
    free(data2);
    free(data3);

    return 0;
}

int main(int argc, char *argv[]) {
    tc_1();

    return 0;
}
