#ifndef __sllist_h
#define __sllist_h

#include <stdlib.h>
#include <string.h>
#include "sllnode.h"


typedef struct {
    unsigned int size;
    struct sllnode *start;
    struct sllnode *end;
    struct sllnode *iter;
} sllist_ctx;


/*create sllist*/
#define Sllist_Create(context)                          \
    context = (sllist_ctx *)malloc(sizeof(sllist_ctx)); \
    memset(context, 0, sizeof(sllist_ctx));             \
    context->size = 0;                                  \
    context->start = NULL;                              \
    context->end = NULL;                                \
    context->iter = NULL

#define Sllist_Add(context, datain)                                             \
    if (context->size == 0) {                                                   \
        context->iter = (struct sllnode *)malloc(sizeof(struct sllnode));       \
        memset(context->iter, 0, sizeof(struct sllnode));                       \
        context->iter->data = datain;                                           \
        context->iter->next = NULL;                                             \
        context->start = context->iter;                                         \
        context->end = context->iter;                                           \
    } else {                                                                    \
        context->iter->next = (struct sllnode *)malloc(sizeof(struct sllnode)); \
        memset(context->iter->next, 0, sizeof(struct sllnode));                 \
        context->iter = context->iter->next;                                    \
        context->iter->data = datain;                                           \
        context->iter->next = NULL;                                             \
        context->end = context->iter;                                           \
    }                                                                           \
    context->size++;                                                 

#define Sllist_Get(context, index, dataout)      \
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
    context->iter = context->end;

#define Sllist_Set(context, index, datain)        \
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
    context->iter = context->end;

#define Sllist_Insert(context, index, datain)            \
    if (context->iter != NULL) {                         \
        int prev_index;                                  \
        if (index == 0) {                                \
            prev_index = 0;                              \
        } else if (index == (context->size-1)) {         \
            prev_index = index;                          \
        } else {                                         \
            prev_index = (index-1);                      \
        }                                                \
        struct sllnode *temp = NULL;                     \
        context->iter = context->start;                  \
                                                         \
        int i = 0;                                       \
        struct sllnode *nexttemp = NULL;                 \
        for(i = 0;i<context->size;i++) {                 \
            if (i == prev_index) {                       \
                temp = malloc(sizeof(struct sllnode));   \
                memset(temp, 0, sizeof(struct sllnode)); \
                                                         \
                if (index == 0 && prev_index == 0) {     \
                    temp->data = datain;                 \
                    nexttemp = context->iter;            \
                    context->iter = temp;                \
                    context->iter->next = nexttemp;      \
                    context->start = context->iter;      \
                }                                        \
                else if (index == (context->size-1)) {   \
                    context->iter->next = temp;          \
                    context->iter = context->iter->next; \
                    context->iter->data = datain;        \
                    context->iter->next = NULL;          \
                }                                        \
                else {                                   \
                    temp->data = datain;                 \
                    nexttemp = context->iter->next;      \
                    context->iter->next = temp;          \
                    context->iter = context->iter->next; \
                    context->iter->next = nexttemp;      \
                }                                        \
                context->size++;                         \
                break;                                   \
            }                                            \
            context->iter = context->iter->next;         \
        }                                                \
    }                                                    \
    context->iter = context->end;

#define Sllist_Remove(context, index)                       \
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
    }

#define Sllist_Size(context, sz) \
    sz = context->size;                                          

/*free all the list*/
#define Sllist_Free(context)             \
    struct sllnode *next_node = NULL;    \
    context->iter = context->start;      \
    while(context->iter != NULL) {       \
        next_node = context->iter->next; \
        free(context->iter);             \
        context->iter = next_node;       \
    }                                    \
    context->size = 0;                                            
    

/*destroy sllist*/
#define Sllist_Destroy(context)              \
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
    context = NULL;                                

	
#endif

