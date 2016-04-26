#ifndef __LOGM_H__
#define __LOGM_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "darr.h"


#define ALLOC_STEP 256


#define Logm_Open(ctx1, arrdata, datasize)            \
    Darr_Create(ctx1, arrdata, datasize, ALLOC_STEP);

/*add entry to darr arrdata, entry must be malloc of type arrdata*/
#define Logm_Print(ctx1, arrdata, entry) \
    Darr_Add(ctx1, arrdata, entry);

#define Logm_Close(ctx1, arrdata) \
    Darr_Destroy(ctx1, arrdata); 

	
#endif
