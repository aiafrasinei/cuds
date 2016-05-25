#ifndef __LOGF_H__
#define __LOGF_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    FILE *file;
} logf_ctx;


#define LOGF_CREATE(context) \
    do {                                                \
        context = (logf_ctx *)malloc(sizeof(logf_ctx)); \
        memset(context, 0, sizeof(logf_ctx));           \
    } while(0)

#define LOGF_OPEN(context, path, open_type) \
    do {                                        \
        context->file = fopen(path, open_type); \
    } while(0)

#define LOGF_PRINT(context, message, ...) \
    do {                                                                                  \
        fprintf(context->file, "%s:%d - " message ,  __FILE__, __LINE__ , ##__VA_ARGS__); \
        fflush(context->file);                                                            \
    } while(0)

#define LOGF_CLOSE(context) \
    do {                       \
        fclose(context->file); \
    } while(0)
    
#define LOGF_DESTROY(context) \
    do {                      \
        free(context);        \
        context = NULL;       \
    } while(0)
    
#endif
