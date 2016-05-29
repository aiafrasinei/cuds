/*simple unit tests*/
#ifndef __SUT_H__
#define __SUT_H__

#include <stdio.h>


#define SUT_RUN_TEST(test, ret) \
    do {                        \
        ret = test();           \
    } while (0)

#define SUT_ASSERT_FUNC_EXITCODE(tinfo, ret, exit_code) \
    do {                                                                                                          \
        if(ret != exit_code)                                                                                      \
            printf("%s - %s ......... FAIL (exit code %d) (expected %d)\n", __FUNCTION__, tinfo, ret, exit_code); \
        else                                                                                                      \
            printf("%s - %s  ......... OK\n", __FUNCTION__, tinfo);                                               \
    } while(0)

#define SUT_ASSERT_VAR_EQUAL(tinfo, var, value) \
    do {                                                                                                  \
        if(var != value)                                                                                  \
            printf("%s - %s ......... FAIL (value %d) (expected %d)\n", __FUNCTION__, tinfo, var, value); \
        else                                                                                              \
            printf("%s - %s ......... OK\n", __FUNCTION__, tinfo);                                        \
    } while(0)

#define SUT_ASSERT_VAR_NOT_EQUAL(tinfo, var, value) \
    do {                                                                                                \
        if(var != value)                                                                                \
            printf("%s - %s ......... OK\n", __FUNCTION__, tinfo);                                      \
        else                                                                                            \
            printf("%s - %s ......... FAIL (value %d) (equals %d)\n", __FUNCTION__, tinfo, var, value); \
    } while(0)
    
#define SUT_FAIL(tinfo) \
    do {                                                         \
        printf("%s - %s ......... FAIL\n", __FUNCTION__, tinfo); \
    } while(0)
    
#define SUT_OK(tinfo) \
    do {                                                      \
        printf("%s - %s ......... OK\n", __FUNCTION__, tinfo); \
    } while(0)

#endif
