#include <stdio.h>
#include "../darr.h"
#include "../logm.h"

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

    Logm_Open(ctx1, arrd, sizeof(struct memlog));
    Logm_Print(ctx1, arrd, entry);
    Logm_Print(ctx1, arrd, entry);
    Logm_Print(ctx1, arrd, entry);
    Darr_Size(ctx1, arrd, s);
    printf("size: %d\n", s);
    Logm_Close(ctx1, arrd);
    free(entry);

    return 0;
}

int main(int argc, char *argv[]) {
    tc_1();
}
