cmake_minimum_required (VERSION 2.6)
project (tests)

enable_testing()

add_executable(darr_tests darr_tests.c)
target_link_libraries(darr_tests)
add_test(darr darr_tests)

add_executable(dstack_tests dstack_tests.c)
target_link_libraries(dstack_tests)
add_test(dstack dstack_tests)

add_executable(sllist_tests sllist_tests.c)
target_link_libraries(sllist_tests)
add_test(sllist sllist_tests)

add_executable(queue_tests queue_tests.c)
target_link_libraries(queue_tests)
add_test(queue queue_tests)

add_executable(logf_tests logf_tests.c)
target_link_libraries(logf_tests)
add_test(logf logf_tests)

add_executable(logm_tests logm_tests.c)
target_link_libraries(logm_tests)
add_test(logm logm_tests)

