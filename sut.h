/*simple unit tests*/
#ifndef __SUT_H__
#define __SUT_H__

#include <stdio.h>


#define SUT_RUN_TEST(test, ret) \
	do {                        \
		ret = test();           \
	} while (0)

#define SUT_REPORT(ret)                                                      \
	do {                                                                     \
		if(ret == 0)                                                         \
			printf("%s ......... OK\n", __FUNCTION__);                       \
		else                                                                 \
			printf("%s ......... FAIL (exit code %d)\n", __FUNCTION__, ret); \
	} while(0)
	
#define SUT_ASSERT(ret, exit_code)                                                                    \
	do {                                                                                              \
		if(ret != exit_code)                                                                          \
			printf("%s ......... FAIL (exit code %d) (expected %d)\n", __FUNCTION__, ret, exit_code); \
		else                                                                                          \
			printf("%s ......... OK\n", __FUNCTION__);                                                \
	} while(0)
	
#define SUT_ASSERT_VAR_EQUAL(var, value)                                                      \
	do {                                                                                      \
		if(var != value)                                                                      \
			printf("%s ......... FAIL (value %d) (expected %d)\n", __FUNCTION__, var, value); \
		else                                                                                  \
			printf("%s ......... OK\n", __FUNCTION__);                                        \
	} while(0)

#define SUT_ASSERT_VAR_NOT_EQUAL(var, value)                                                \
	do {                                                                                    \
		if(var != value)                                                                    \
			printf("%s ......... OK\n", __FUNCTION__);                                      \
		else                                                                                \
			printf("%s ......... FAIL (value %d) (equals %d)\n", __FUNCTION__, var, value); \
	} while(0)
	
#define SUT_FAIL(info)                                          \
	do {                                                        \
		printf("%s ......... FAIL (%s)\n", __FUNCTION__, info); \
	} while(0)
	
#define SUT_OK(info)                                          \
	do {                                                      \
		printf("%s ......... OK (%s)\n", __FUNCTION__, info); \
	} while(0)

#endif
