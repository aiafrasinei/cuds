#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdlib.h>
#include <string.h>
#include "sllnode.h"


typedef struct {
    long size;
    struct sllnode *start;
    struct sllnode *end;
    struct sllnode *iter;
} queue_ctx;


#define QUEUE_CREATE(context) \
    do {                                                       \
        context = (queue_ctx *)calloc(1, sizeof(queue_ctx)); \
        if(context != NULL) {                                  \
            context->size = 0;                                 \
            context->start = NULL;                             \
            context->end = NULL;                               \
            context->iter = NULL;                              \
        }                                                      \
    } while(0)

#define QUEUE_ENQUEUE(context, datain) \
    do {                                                                               \
        if (context->size == 0) {                                                      \
            context->iter = (struct sllnode *)calloc(1, sizeof(struct sllnode));       \
            if(context->iter != NULL) {                                                \
                context->iter->data = datain;                                          \
                context->iter->next = NULL;                                            \
                context->start = context->iter;                                        \
                context->end = context->iter;                                          \
                context->size++;                                                       \
            }                                                                          \
        } else {                                                                       \
            context->iter->next = (struct sllnode *)calloc(1, sizeof(struct sllnode)); \
            if(context->iter->next != NULL) {                                          \
                context->iter = context->iter->next;                                   \
                context->iter->data = datain;                                          \
                context->iter->next = NULL;                                            \
                context->end = context->iter;                                          \
                context->size++;                                                       \
            }                                                                          \
        }                                                                              \
    } while(0)

#define QUEUE_DEQUEUE(context) \
    do {                                           \
        if (context->size == 1) {                  \
            free(context->iter);                   \
            context->start = NULL;                 \
            context->end = NULL;                   \
            context->iter = NULL;                  \
            context->size = 0;                     \
        }                                          \
        else if (context->size > 1) {              \
            context->iter = context->start;        \
            context->start = context->start->next; \
            free(context->iter);                   \
            context->iter = context->start;        \
            context->size--;                       \
        }                                          \
    } while(0)

#define QUEUE_PEEK(context, dataout) \
    do {                                             \
        if (context->size >= 1)                      \
            dataout = context->start->data;          \
    } while(0)

#define QUEUE_SIZE(context, sz) \
    sz = context->size;                                          

#define QUEUE_FREE(context) \
    do {                                     \
        struct sllnode *next_node = NULL;    \
        context->iter = context->start;      \
        while(context->iter != NULL) {       \
            next_node = context->iter->next; \
            free(context->iter);             \
            context->iter = next_node;       \
        }                                    \
        context->size = 0;                   \
    } while(0)
    

#define QUEUE_DESTROY(context)                  \
    do {                                         \
        if(context->iter != NULL) {              \
            struct sllnode *next_node = NULL;    \
            context->iter = context->start;      \
            while(context->iter != NULL) {       \
                next_node = context->iter->next; \
                free(context->iter);             \
                context->iter = next_node;       \
            }                                    \
        }                                        \
        free(context);                           \
        context = NULL;                          \
    } while(0)
    
#endif

