#include <stdio.h>
#include "../darr.h"


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

    Darr_Create(ctx1, arrd, sizeof(tdat), 2);
    Darr_Add(ctx1, arrd, data1);
    Darr_Add(ctx1, arrd, data1);
    Darr_Add(ctx1, arrd, data1);
    Darr_Size(ctx1, arrd, size);
    printf("size: %i\n", size);
    Darr_Destroy(ctx1, arrd);

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

    Darr_Create(ctx1, arrd, sizeof(tdat), 2);
    Darr_Add(ctx1, arrd, data1);
    Darr_Add(ctx1, arrd, data1);
    Darr_Get(ctx1, arrd, dataout, 1);
    printf("dataout: %i\n", dataout->i);
    Darr_Set(ctx1, arrd, data3, 1);
    Darr_Size(ctx1, arrd, size);
    printf("size: %i\n", size);
    Darr_Get(ctx1, arrd, dataout, 1);
    printf("dataout: %i", dataout->i);
    Darr_Destroy(ctx1, arrd);

    free(data1);
    free(data2);
    free(data3);

    return 0;
}

int main(int argc, char *argv[]) {
    tc_1();
    tc_2();
}
