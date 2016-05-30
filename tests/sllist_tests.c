#include <stdio.h>
#include "../sllist.h"
#include "../sut.h"


typedef struct {
    int i;
} tdat;

int tc_1(void) {
    sllist_ctx *ctx1 = NULL;
    tdat *data1 = (tdat *)malloc(sizeof(tdat));
    data1->i = 13;
    tdat *data2 = (tdat *)malloc(sizeof(tdat));
    data2->i = 11;
    tdat *data3 = (tdat *)malloc(sizeof(tdat));
    data3->i = 100;
    int s;
    tdat *dataout = NULL;

    SLLIST_CREATE(ctx1);

    SLLIST_ADD(ctx1, data1);
    SLLIST_ADD(ctx1, data1);
    SLLIST_ADD(ctx1, data1);
    SLLIST_GET(ctx1, 1, dataout);
    SUT_ASSERT_VAR_EQUAL("check get", dataout->i, 13);
    
    SLLIST_ADD(ctx1, data2);
    SLLIST_SIZE(ctx1, s);
    SUT_ASSERT_VAR_EQUAL("check size", s, 4);

    SLLIST_GET(ctx1, 0, dataout);
    SUT_ASSERT_VAR_EQUAL("check get again", dataout->i, 13);
        
    SLLIST_SET(ctx1, 0, data3);
    SLLIST_GET(ctx1, 0, dataout);
    SUT_ASSERT_VAR_EQUAL("check set", dataout->i, 100);


    SLLIST_ADD(ctx1, data1);
    SLLIST_ADD(ctx1, data2);
    SLLIST_SIZE(ctx1, s);
    SUT_ASSERT_VAR_EQUAL("check add", s, 6);

    SLLIST_INSERT(ctx1, 0, data3);
    SLLIST_SIZE(ctx1, s);
    SUT_ASSERT_VAR_EQUAL("check insert", s, 7);
        
    SLLIST_INSERT(ctx1, 2, data3);
    SLLIST_SIZE(ctx1, s);
    SUT_ASSERT_VAR_EQUAL("check size after insert", s, 8);
   
    ctx1->iter = ctx1->start;
    int i;
    for(i=0;i<ctx1->size;i++) {
        printf("i: %d ", ((tdat *)ctx1->iter->data)->i);
        ctx1->iter = ctx1->iter->next;
    }
    printf("\n");

    SLLIST_FREE(ctx1);
    SLLIST_SIZE(ctx1, s);
    SUT_ASSERT_VAR_EQUAL("check free", s, 0);

    SLLIST_DESTROY(ctx1);
    free(data1);
    free(data2);
    free(data3);

    return 0;
}

int main(int argc, char *argv[]) {
    tc_1();

    return 0;
}
