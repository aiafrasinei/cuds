cmake_minimum_required (VERSION 2.6)
project (tests)

add_executable(darr_tests darr_tests.c)
target_link_libraries(darr_tests)

add_executable(dstack_tests dstack_tests.c)
target_link_libraries(dstack_tests)

add_executable(sllist_tests sllist_tests.c)
target_link_libraries(sllist_tests)

add_executable(logf_tests logf_tests.c)
target_link_libraries(logf_tests)

add_executable(logm_tests logm_tests.c)
target_link_libraries(logm_tests)

