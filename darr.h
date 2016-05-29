#ifndef __DARR_H__
#define __DARR_H__

#include <stdlib.h>
#include <string.h>


typedef struct {
    unsigned int size;
    size_t datasize;
    unsigned int capacity;
    unsigned int step;
} darr_ctx;


/*create array with given capacity
context - type darr_ctx
data - whatever data
ssize - datasize
cap - capacity*/
#define DARR_CREATE(context, data, ssize, cap) \
    do {                                                   \
        context = (darr_ctx *)calloc(1, sizeof(darr_ctx)); \
        if(context != NULL) {                              \
            context->datasize = ssize;                     \
            context->step = cap;                           \
            data = calloc(1, context->datasize * cap);     \
            if(data != NULL) {                             \
                context->capacity = cap;                   \
                context->size = 0;                         \
            }                                              \
        }                                                  \
    } while(0)

/*realloc array capacity*/
#define DARR_RESIZE(context, data, cap) \
    do {                                               \
        data = realloc(data, cap * context->datasize); \
        if(data != NULL)                               \
            context->capacity = cap;                   \
    } while(0)                                    

/*get array entry*/
#define DARR_GET(context, data, out, index) \
    do {                                         \
        if(index >= 0 && index < context->size)  \
            out = &data[index];                  \
        else                                     \
            out = NULL;                          \
    } while(0)
    
/*set array entry*/
#define DARR_SET(context, data, datain, index) \
    do {                                       \
        if(data != NULL)                       \
            data[index] = *datain;             \
    } while(0)

/*add entry and realloc twice the size if necessary*/
#define DARR_ADD(context, data, datain) \
    do {                                                                 \
        context->size++;                                                 \
        if(context->size > context->capacity) {                          \
            context->capacity = context->capacity * context->step;       \
            data = realloc(data, context->capacity * context->datasize); \
        }                                                                \
        if(data != NULL)                                                 \
            data[context->size - 1] = *datain;                           \
    } while(0)

/*get array current size*/
#define DARR_SIZE(context, data, sz) \
    do {                             \
        sz = context->size;          \
    } while(0)
                    
#define DARR_FREE(context, data) \
    do {                         \
        if(data != NULL) {       \
            free(data);          \
            data = NULL;         \
        }                        \
        context->size = 0;       \
        context->capacity = 0;   \
    } while(0)         
    
/*destroy array*/
#define DARR_DESTROY(context, data) \
    do {                            \
        if(data != NULL) {          \
            free(data);             \
            data = NULL;            \
        }                           \
        if(context != NULL) {       \
            free(context);          \
            context = NULL;         \
        }                           \
    } while(0)
    
    
#endif

