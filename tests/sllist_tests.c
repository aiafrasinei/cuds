#include <stdio.h>
#include "../sllist.h"


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

    Sllist_Create(ctx1);

    Sllist_Add(ctx1, data1);
    Sllist_Add(ctx1, data1);
    Sllist_Add(ctx1, data1);
    Sllist_Get(ctx1, 1, dataout);
    Sllist_Add(ctx1, data2);

    Sllist_Size(ctx1, s);
    printf("size: %d", s);
    Sllist_Get(ctx1, 0, dataout);
    printf("i: %d\n", dataout->i);
    Sllist_Set(ctx1, 0, data3);
    Sllist_Get(ctx1, 0, dataout);
    printf("i: %d\n", dataout->i);


    Sllist_Add(ctx1, data1);
    Sllist_Add(ctx1, data2);
    Sllist_Size(ctx1, s);
    printf("intereasting size: %d\n", s);

    Sllist_Insert(ctx1, 0, data3);
    Sllist_Size(ctx1, s);
    printf("intereasting size: %d\n", s);
    Sllist_Insert(ctx1, 2, data3);
    Sllist_Size(ctx1, s);
    printf("intereasting size: %d\n", s);
   
    ctx1->iter = ctx1->start;
    int i;
    for(i=0;i<ctx1->size;i++) {
        printf("i: %d ", ((tdat *)ctx1->iter->data)->i);
        ctx1->iter = ctx1->iter->next;
    }
    printf("\n");

    Sllist_Free(ctx1);
    Sllist_Size(ctx1, s);
    printf("size: %d\n", s);

    Sllist_Destroy(ctx1);
    free(data1);
    free(data2);
    free(data3);

    return 0;
}

int main(int argc, char *argv[]) {
    tc_1();
}
