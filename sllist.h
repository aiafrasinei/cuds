#ifndef __SLLIST_H__
#define __SLLIST_H__

#include <stdlib.h>
#include <string.h>
#include "sllnode.h"


typedef struct {
    long size;
    struct sllnode *start;
    struct sllnode *end;
    struct sllnode *iter;
} sllist_ctx;


/*create sllist*/
#define SLLIST_CREATE(context) \
    do {                                                       \
        context = (sllist_ctx *)calloc(1, sizeof(sllist_ctx)); \
        if(context != NULL) {                                  \
            context->size = 0;                                 \
            context->start = NULL;                             \
            context->end = NULL;                               \
            context->iter = NULL;                              \
        }                                                      \
    } while(0)

#define SLLIST_ADD(context, datain) \
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

#define SLLIST_GET(context, index, dataout) \
    do {                                             \
        if (context->size >= 1) {                    \
            int i;                                   \
            context->iter = context->start;          \
            for(i = 0;i<context->size;i++) {         \
                if(i == index) {                     \
                    dataout = context->iter->data;   \
                    break;                           \
                }                                    \
                context->iter = context->iter->next; \
            }                                        \
        }                                            \
        context->iter = context->end;                \
    } while(0)

#define SLLIST_SET(context, index, datain) \
    do {                                              \
        if (context->size >= 1) {                     \
            if (context->iter != NULL) {              \
                struct sllnode *temp = NULL;          \
                int i;                                \
                context->iter = context->start;       \
                for(i = 0;i<context->size;i++) {      \
                    if(i == index) {                  \
                        context->iter->data = datain; \
                        break;                        \
                    }                                 \
                }                                     \
            }                                         \
        }                                             \
        context->iter = context->end;                 \
    } while(0)

#define SLLIST_INSERT(context, index, datain) \
    do {                                                          \
        if (context->iter != NULL) {                              \
            int prev_index;                                       \
            if (index == 0) {                                     \
                prev_index = 0;                                   \
            } else if (index == (context->size-1)) {              \
                prev_index = index;                               \
            } else {                                              \
                prev_index = (index-1);                           \
            }                                                     \
            struct sllnode *temp = NULL;                          \
            context->iter = context->start;                       \
                                                                  \
            int i = 0;                                            \
            struct sllnode *nexttemp = NULL;                      \
            for(i = 0;i<context->size;i++) {                      \
                if (i == prev_index) {                            \
                    temp = calloc(1, sizeof(struct sllnode));     \
                                                                  \
                    if(temp != NULL) {                            \
                        if (index == 0 && prev_index == 0) {      \
                            temp->data = datain;                  \
                            nexttemp = context->iter;             \
                            context->iter = temp;                 \
                            context->iter->next = nexttemp;       \
                            context->start = context->iter;       \
                        }                                         \
                        else if (index == (context->size-1)) {    \
                            context->iter->next = temp;           \
                            context->iter = context->iter->next;  \
                            context->iter->data = datain;         \
                            context->iter->next = NULL;           \
                        }                                         \
                        else {                                    \
                            temp->data = datain;                  \
                            nexttemp = context->iter->next;       \
                            context->iter->next = temp;           \
                            context->iter = context->iter->next;  \
                            context->iter->next = nexttemp;       \
                        }                                         \
                        context->size++;                          \
                    }                                             \
                    break;                                        \
                }                                                 \
                context->iter = context->iter->next;              \
            }                                                     \
        }                                                         \
        context->iter = context->end;                             \
    } while(0)

#define SLLIST_REMOVE(context, index) \
    do {                                                        \
        if (context->iter != NULL) {                            \
            int prev_index;                                     \
            if (index == 0) {                                   \
                prev_index = 0;                                 \
            } else {                                            \
                prev_index = index-1;                           \
            }                                                   \
            struct sllnode *temp = NULL;                        \
            context->iter = context->start;                     \
            if (index == 0) {                                   \
                free(context->iter);                            \
                context->iter = NULL;                           \
                context->start = NULL;                          \
                context->size = 0;                              \
            } else {                                            \
                int i;                                          \
                for(i = 0;i<context->size;i++) {                \
                    if (i == prev_index) {                      \
                        if ((index+1) == context->size) {       \
                            free(context->iter->next);          \
                            context->iter->next = NULL;         \
                            context->size--;                    \
                            break;                              \
                        } else {                                \
                            temp = (context->iter->next)->next; \
                            free(context->iter->next);          \
                            context->iter->next = temp;         \
                            context->size--;                    \
                            break;                              \
                        }                                       \
                    }                                           \
                    temp = context->iter->next;                 \
                    context->iter = temp;                       \
                }                                               \
            }                                                   \
        } else {                                                \
            free(context->start);                               \
            context->start = NULL;                              \
            context->size = 0;                                  \
        }                                                       \
    } while(0)

#define SLLIST_SIZE(context, sz) \
    sz = context->size;                                          

/*free all the list*/
#define SLLIST_FREE(context) \
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
    

/*destroy sllist*/
#define SLLIST_DESTROY(context)                  \
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

