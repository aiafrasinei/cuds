#include <stdio.h>
#include "../darr.h"
#include "../logm.h"
#include "../sut.h"


#define LOG_STRING_SIZE 512

struct memlog {
    char text[LOG_STRING_SIZE];
};

int tc_1(void) {

    darr_ctx *ctx1 = NULL;
    struct memlog *arrd = NULL;
    struct memlog *entry = NULL;
    int s;

    entry = (struct memlog *)malloc(sizeof(struct memlog));
    snprintf(entry->text, LOG_STRING_SIZE,  "bla bla");

    LOGM_OPEN(ctx1, arrd, sizeof(struct memlog));
    LOGM_PRINT(ctx1, arrd, entry);
    LOGM_PRINT(ctx1, arrd, entry);
    LOGM_PRINT(ctx1, arrd, entry);
    DARR_SIZE(ctx1, arrd, s);
    SUT_ASSERT_VAR_EQUAL("check log size", s, 3);
    LOGM_CLOSE(ctx1, arrd);
    free(entry);

    return 0;
}

int main(int argc, char *argv[]) {
    tc_1();

    return 0;
}
