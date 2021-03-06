#include <stdio.h>
#include "../dstack.h"
#include "../sut.h"


typedef struct {
    int i;
} tdat;

int tc_1(void) {
    dstack_ctx *ctx1 = NULL;
    tdat *data1 = (tdat *)malloc(sizeof(tdat));
    data1->i = 10;
    tdat *data2 = (tdat *)malloc(sizeof(tdat));
    data2->i = 11;
    int size = 0;
    tdat *dataout = NULL; 

    DSTACK_CREATE(ctx1);
    DSTACK_PUSH(ctx1, data1);
    DSTACK_PUSH(ctx1, data2);
    DSTACK_PEEK(ctx1, dataout);
    SUT_ASSERT_VAR_EQUAL("check peek", dataout->i, 11);

    DSTACK_POP(ctx1);
    DSTACK_POP(ctx1);
    DSTACK_POP(ctx1);
    DSTACK_SIZE(ctx1, size);
    SUT_ASSERT_VAR_EQUAL("check size", size, 0);
    
    DSTACK_DESTROY(ctx1);
    free(data1);
    free(data2);

    return 0;
}

int tc_2(void) {
    dstack_ctx *ctx1 = NULL;
    tdat *data1 = (tdat *)malloc(sizeof(tdat));
    data1->i = 10;
    tdat *data2 = (tdat *)malloc(sizeof(tdat));
    data2->i = 11;
    int size = 0;

    DSTACK_CREATE(ctx1);
    DSTACK_PUSH(ctx1, data1);
    DSTACK_SIZE(ctx1, size);
    SUT_ASSERT_VAR_EQUAL("check push", size, 1);
    
    DSTACK_PUSH(ctx1, data1);
    DSTACK_FREE(ctx1);
    DSTACK_SIZE(ctx1, size);
    SUT_ASSERT_VAR_EQUAL("check free", size, 0);
    
    DSTACK_DESTROY(ctx1);
    free(data1);
    free(data2);

    return 0;
}

int tc_3(void) {
    dstack_ctx *ctx1 = NULL;
    tdat *data1 = (tdat *)malloc(sizeof(tdat));
    data1->i = 10;
    int size = 0;
    int nr_items = 10000;
    int i;

    DSTACK_CREATE(ctx1);
    for(i=0;i<nr_items;i++) {
        DSTACK_PUSH(ctx1, data1);
    }
    DSTACK_SIZE(ctx1, size);
    SUT_ASSERT_VAR_EQUAL("check multiple push", size, nr_items);
    
    DSTACK_DESTROY(ctx1);
    free(data1);

    return 0;
}



int main(int argc, char *argv[]) {
    tc_1();
    tc_2();
    tc_3();

    return 0;
}
