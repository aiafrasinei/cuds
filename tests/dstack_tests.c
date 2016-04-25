#include <stdio.h>
#include "../dstack.h"


typedef struct {
    int i;
} tdat;

int tc_1(void) {
    dstack_ctx *ctx1 = NULL;
    tdat *data1 = (tdat *)malloc(sizeof(tdat));
    data1->i = 10;
    tdat *data2 = (tdat *)malloc(sizeof(tdat));
    data2->i = 11;

    tdat *dataout = NULL;

    Dstack_Create(ctx1);
    Dstack_Push(ctx1, data1);
    Dstack_Push(ctx1, data2);
    Dstack_Pop(ctx1,  dataout);
    Dstack_Pop(ctx1, dataout);
    Dstack_Pop(ctx1, dataout);
    Dstack_Destroy(ctx1);
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
    tdat *dataout = NULL;
    unsigned int size = 0;

    Dstack_Create(ctx1);
    Dstack_Push(ctx1, data1);
    Dstack_Size(ctx1, size);
    printf("size: %d", size);
    Dstack_Push(ctx1, data1);
    Dstack_Free(ctx1);
    Dstack_Size(ctx1, size);
    printf("size: %d", size);
    Dstack_Destroy(ctx1);
    free(data1);
    free(data2);

    return 0;
}

int tc_3(void) {
    dstack_ctx *ctx1 = NULL;
    tdat *data1 = (tdat *)malloc(sizeof(tdat));
    data1->i = 10;
    tdat *dataout = NULL;
    unsigned int size = 0;
    int i;

    Dstack_Create(ctx1);
    for(i=0;i<10000;i++) {
        Dstack_Push(ctx1, data1);
    }
    Dstack_Size(ctx1, size);
    printf("size: %d\n", size);
    Dstack_Destroy(ctx1);
    free(data1);

    return 0;
}



int main(int argc, char *argv[]) {
    tc_1();
    tc_2();
    tc_3();
}
