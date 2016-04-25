#include <stdio.h>
#include "../darr.h"


typedef struct {
    int i;
} tdat;

int tc_1(void) {

    darr_ctx *ctx1 = NULL;
    tdat *arrd = NULL;
    tdat *arrd1 = NULL;

    tdat *data1 = (tdat *)malloc(sizeof(tdat));
    data1->i = 10;

    Darr_Create(ctx1, arrd, sizeof(tdat), 2);
    Darr_Add(ctx1, arrd, data1);
    Darr_Add(ctx1, arrd, data1);
    Darr_Add(ctx1, arrd, data1);
    Darr_Destroy(ctx1, arrd);

    free(data1);

    return 0;
}

int main(int argc, char *argv[]) {
    tc_1();
}
