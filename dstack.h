#ifndef __DSTACK_H__
#define __DSTACK_H__

#include <stdlib.h>
#include <string.h>
#include "sllnode.h"


typedef struct {
    long size;
    struct sllnode *iter;
} dstack_ctx;


/*create stack*/
#define DSTACK_CREATE(context) \
    do {                                                       \
        context = (dstack_ctx *)calloc(1, sizeof(dstack_ctx)); \
        if(context != NULL) {                                  \
            context->size = 0;                                 \
            context->iter = NULL;                              \
        }                                                      \
    } while(0)

#define DSTACK_PUSH(context, datain) \
    do {                                                                         \
        if (context->size == 0) {                                                \
            context->iter = (struct sllnode *)calloc(1, sizeof(struct sllnode)); \
            if(context != NULL) {                                                \
                context->iter->data = datain;                                    \
                context->iter->next = NULL;                                      \
            }                                                                    \
        } else {                                                                 \
            struct sllnode *temp = context->iter;                                \
            context->iter = (struct sllnode *)calloc(1, sizeof(struct sllnode)); \
            if(context != NULL) {                                                \
                context->iter->data = datain;                                    \
                context->iter->next = temp;                                      \
            }                                                                    \
        }                                                                        \
        if(context != NULL)                                                      \
            context->size++;                                                     \
    } while(0)

#define DSTACK_POP(context) \
    do {                                                \
        if (context->size >= 1) {                       \
            struct sllnode *temp = context->iter->next; \
            free(context->iter);                        \
            context->iter = temp;                       \
            context->size--;                            \
        }                                               \
    } while(0)


#define DSTACK_PEEK(context, dataout) \
    do {                                                \
        if (context->size >= 1) {                       \
            struct sllnode *temp = context->iter->next; \
            dataout = context->iter->data;              \
            free(context->iter);                        \
            context->iter = temp;                       \
            context->size--;                            \
        }                                               \
    } while(0)

#define DSTACK_SIZE(context, size) \
    size = context->size;

/*free stack*/
#define DSTACK_FREE(context) \
    do {                                                     \
        while(context->iter != NULL) {                       \
            struct sllnode *next_node = context->iter->next; \
            free(context->iter);                             \
            context->iter = next_node;                       \
        }                                                    \
        context->size = 0;                                   \
    } while(0)

/*destroy stack*/
#define DSTACK_DESTROY(context) \
    do {                                                     \
        while(context->iter != NULL) {                       \
            struct sllnode *next_node = context->iter->next; \
            free(context->iter);                             \
            context->iter = next_node;                       \
        }                                                    \
        free(context);                                       \
        context = NULL;                                      \
    } while(0)

    
#endif

