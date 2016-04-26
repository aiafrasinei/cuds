#ifndef __DSTACK_H__
#define __DSTACK_H__

#include <stdlib.h>
#include <string.h>
#include "sllnode.h"


typedef struct {
    unsigned int size;
    struct sllnode *iter;
} dstack_ctx;


/*create stack*/
#define Dstack_Create(context)                          \
    context = (dstack_ctx *)malloc(sizeof(dstack_ctx)); \
    memset(context, 0, sizeof(dstack_ctx));             \
    context->size = 0;                                  \
    context->iter = NULL

#define Dstack_Push(context, datain)                                      \
    if (context->size == 0) {                                             \
        context->iter = (struct sllnode *)malloc(sizeof(struct sllnode)); \
        memset(context->iter, 0, sizeof(struct sllnode));                 \
        context->iter->data = datain;                                     \
        context->iter->next = NULL;                                       \
    } else {                                                              \
        struct sllnode *temp = context->iter;                             \
        context->iter = (struct sllnode *)malloc(sizeof(struct sllnode)); \
        memset(context->iter, 0, sizeof(struct sllnode));                 \
        context->iter->data = datain;                                     \
        context->iter->next = temp;                                       \
    }                                                                     \
    context->size++;

#define Dstack_Pop(context, dataout)                \
    if (context->size >= 1) {                       \
        struct sllnode *temp = context->iter->next; \
        dataout = context->iter->data;              \
        free(context->iter);                        \
        context->iter = temp;                       \
        context->size--;                            \
    }

#define Dstack_Size(context, size) \
    size = context->size;

/*free stack*/
#define Dstack_Free(context) \
    context->size = 0;

/*destroy stack*/
#define Dstack_Destroy(context)                          \
    while(context->iter != NULL) {                       \
        struct sllnode *next_node = context->iter->next; \
        free(context->iter);                             \
        context->iter = next_node;                       \
    }                                                    \
    free(context);                                       \
    context = NULL;

	
#endif

