#ifndef __LOGM_H__
#define __LOGM_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "darr.h"


#define ALLOC_STEP 256


#define LOGM_OPEN(ctx1, arrdata, datasize)  \
    do {                                                  \
        DARR_CREATE(ctx1, arrdata, datasize, ALLOC_STEP); \
    } while(0)
    
/*add entry to darr arrdata, entry must be malloc of type arrdata*/
#define LOGM_PRINT(ctx1, arrdata, entry) \
    do {                                 \
        DARR_ADD(ctx1, arrdata, entry);  \
    } while(0)
    
#define LOGM_CLOSE(ctx1, arrdata) \
    do {                             \
        DARR_DESTROY(ctx1, arrdata); \
    } while(0) 

    
#endif
