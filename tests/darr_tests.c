#include <stdio.h>
#include "../darr.h"
#include "../sut.h"


typedef struct {
    int i;
} tdat;

int tc_1(void) {
    darr_ctx *ctx1 = NULL;
    tdat *arrd = NULL;
    tdat *arrd1 = NULL;
    int size;

    tdat *data1 = (tdat *)malloc(sizeof(tdat));
    data1->i = 10;

    DARR_CREATE(ctx1, arrd, sizeof(tdat), 2);
    DARR_ADD(ctx1, arrd, data1);
    DARR_ADD(ctx1, arrd, data1);
    DARR_ADD(ctx1, arrd, data1);
    DARR_SIZE(ctx1, arrd, size);
    SUT_ASSERT_VAR_EQUAL(size, 3);
    
    DARR_DESTROY(ctx1, arrd);
    free(data1);

    return 0;
}

int tc_2(void) {
    darr_ctx *ctx1 = NULL;
    tdat *arrd = NULL;
    tdat *arrd1 = NULL;
    int size;

    tdat *data1 = (tdat *)malloc(sizeof(tdat));
    data1->i = 10;
    tdat *data2 = (tdat *)malloc(sizeof(tdat));
    data2->i = 11;
    tdat *data3 = (tdat *)malloc(sizeof(tdat));
    data3->i = 12;
    tdat *dataout = NULL;

    DARR_CREATE(ctx1, arrd, sizeof(tdat), 2);
    DARR_ADD(ctx1, arrd, data1);
    DARR_ADD(ctx1, arrd, data1);
    DARR_GET(ctx1, arrd, dataout, 1);
    SUT_ASSERT_VAR_EQUAL(dataout->i, 10);
    
    DARR_SET(ctx1, arrd, data3, 1);
    DARR_SIZE(ctx1, arrd, size);
    SUT_ASSERT_VAR_EQUAL(size, 2);
    
    DARR_GET(ctx1, arrd, dataout, 1);
    SUT_ASSERT_VAR_EQUAL(dataout->i, 12);
    
    DARR_DESTROY(ctx1, arrd);

    free(data1);
    free(data2);
    free(data3);

    return 0;
}

int main(int argc, char *argv[]) {
    int ret = 0;
    
    SUT_RUN_TEST(tc_1, ret);
    SUT_RUN_TEST(tc_2, ret);

    return ret;
}
