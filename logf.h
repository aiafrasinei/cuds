#ifndef __LOGF_H__
#define __LOGF_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    FILE *file;
} logf_ctx;


#define Logf_Create(context)                        \
    context = (logf_ctx *)malloc(sizeof(logf_ctx)); \
    memset(context, 0, sizeof(logf_ctx));

#define Logf_Open(context, path, open_type) \
    context->file = fopen(path, open_type);

#define Logf_Print(context, message, ...)                                             \
    fprintf(context->file, "%s:%d - " message ,  __FILE__, __LINE__ , ##__VA_ARGS__); \
    fflush(context->file);

#define Logf_Close(context) \
    fclose(context->file);

#define Logf_Destroy(context) \
    free(context);            \
    context = NULL;

#endif
