#include <stdio.h>
#include <time.h>
#include "../../sllist.h"


int tc_1(void) {
    sllist_ctx *ctx1 = NULL;
    int i = 0;
    int t = 1;

    Sllist_Create(ctx1);
    for(i=0;i<10000000;i++) {
        Sllist_Add(ctx1, &t);
    }
    Sllist_Destroy(ctx1);

    return EXIT_SUCCESS;

    error:
        printf("error: %s %s %d\n", global_err_ctx.module, global_err_ctx.func, global_err_ctx.ret);
        Sllist_Destroy(ctx1);

        return EXIT_FAILURE;
}

int main(int argc, int *argv[]) {
    tc_1();
}
