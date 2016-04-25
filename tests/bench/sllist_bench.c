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

    return 0;
}

int main(int argc, char *argv[]) {
    tc_1();
}
