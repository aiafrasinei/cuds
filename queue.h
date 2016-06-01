#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdlib.h>
#include <string.h>
#include "sllnode.h"


typedef struct {
    long size;
    struct sllnode *start;
    struct sllnode *end;
    struct sllnode *temp;
} queue_ctx;


#define QUEUE_CREATE(context) \
    do {                                                       \
        context = (queue_ctx *)calloc(1, sizeof(queue_ctx)); \
        if(context != NULL) {                                  \
            context->size = 0;                                 \
            context->start = NULL;                             \
            context->end = NULL;                               \
            context->temp = NULL;                              \
        }                                                      \
    } while(0)

#define QUEUE_ENQUEUE(context, datain) \
    do {                                                                               \
        if (context->size == 0) {                                                      \
            context->temp = (struct sllnode *)calloc(1, sizeof(struct sllnode));       \
            if(context->temp != NULL) {                                                \
                context->temp->data = datain;                                          \
                context->temp->next = NULL;                                            \
                context->start = context->temp;                                        \
                context->end = context->temp;                                          \
                context->size++;                                                       \
            }                                                                          \
        } else {                                                                       \
            context->temp->next = (struct sllnode *)calloc(1, sizeof(struct sllnode)); \
            if(context->temp->next != NULL) {                                          \
                context->temp = context->temp->next;                                   \
                context->temp->data = datain;                                          \
                context->temp->next = NULL;                                            \
                context->end = context->temp;                                          \
                context->size++;                                                       \
            }                                                                          \
        }                                                                              \
    } while(0)

#define QUEUE_DEQUEUE(context) \
    do {                                           \
        if (context->size == 1) {                  \
            free(context->temp);                   \
            context->start = NULL;                 \
            context->end = NULL;                   \
            context->temp = NULL;                  \
            context->size = 0;                     \
        }                                          \
        else if (context->size > 1) {              \
            context->temp = context->start;        \
            context->start = context->start->next; \
            free(context->temp);                   \
            context->temp = context->start;        \
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
        context->temp = context->start;      \
        while(context->temp != NULL) {       \
            next_node = context->temp->next; \
            free(context->temp);             \
            context->temp = next_node;       \
        }                                    \
        context->size = 0;                   \
    } while(0)
    

#define QUEUE_DESTROY(context)                  \
    do {                                         \
        if(context->temp != NULL) {              \
            struct sllnode *next_node = NULL;    \
            context->temp = context->start;      \
            while(context->temp != NULL) {       \
                next_node = context->temp->next; \
                free(context->temp);             \
                context->temp = next_node;       \
            }                                    \
        }                                        \
        free(context);                           \
        context = NULL;                          \
    } while(0)
    
#endif

