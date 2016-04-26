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
#define Darr_Create(context, data, ssize, cap)      \
    context = (darr_ctx *)malloc(sizeof(darr_ctx)); \
    memset(context, 0, sizeof(darr_ctx));           \
    context->datasize = ssize;                      \
    context->step = cap;                            \
    data = malloc(context->datasize * cap);         \
    memset(data ,0 ,context->datasize * cap);       \
    context->capacity = cap;                        \
    context->size = 0;

/*realloc array capacity*/
#define Darr_Resize(context, data, cap)            \
    data = realloc(data, cap * context->datasize); \
    context->capacity = cap;                                    

/*get array entry*/
#define Darr_Get(context, data, out, index)  \
    if(index >= 0 && index < context->size)  \
        out = &data[index];                  \
    else                                     \
        out = NULL;

/*set array entry*/
#define Darr_Set(context, data, datain, index) \
    data[index] = *datain;

/*add entry and realloc twice the size if necessary*/
#define Darr_Add(context, data, datain)                              \
    context->size++;                                                 \
    if (context->size > context->capacity) {                         \
        context->capacity = context->capacity * context->step;       \
        data = realloc(data, context->capacity * context->datasize); \
    }                                                                \
    data[context->size - 1] = *datain; 

/*get array current size*/
#define Darr_Size(context, data, sz) \
    sz = context->size;
                    
#define Darr_Free(context, data) \
    context->size = 0;           \
    context->capacity = 0;             

/*destroy array*/
#define Darr_Destroy(context, data) \
    free(data);                     \
    data = NULL;                    \
    free(context);                  \
    context = NULL;
    
	
#endif

