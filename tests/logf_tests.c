#include <stdio.h>
#include "../logf.h"


int tc_1(void) {

    logf_ctx *ctx1 = NULL;
    Logf_Create(ctx1);
    Logf_Open(ctx1, "test.log", "w");
    Logf_Print(ctx1, "test %d\n", 1);
    Logf_Close(ctx1);
    Logf_Destroy(ctx1);

    return 0;
}

int main(int argc, char *argv[]) {
    tc_1();
}
