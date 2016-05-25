#include <stdio.h>
#include "../logf.h"


int tc_1(void) {

    logf_ctx *ctx1 = NULL;
    LOGF_CREATE(ctx1);
    LOGF_OPEN(ctx1, "test.log", "w");
    LOGF_PRINT(ctx1, "test %d\n", 1);
    LOGF_CLOSE(ctx1);
    LOGF_DESTROY(ctx1);

    return 0;
}

int main(int argc, char *argv[]) {
    tc_1();
}
