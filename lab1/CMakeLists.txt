project(lab1
        LANGUAGES C)

set(CLI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cli)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

# PASS!!
add_task(1
        CLI_SOURCES task1.c
        LIB_SOURCES actions.c cli.c
        TEST_SOURCES task1_test.cpp
)
# PASS!!
add_task(2
        CLI_SOURCES task2.c
        LIB_SOURCES cli.c sieve.c
        TEST_SOURCES task2_test.cpp
)
# PASS!!
add_task(3
        CLI_SOURCES task3.c
        LIB_SOURCES actions.c cli.c
        TEST_SOURCES task3_test.cpp
)
add_task(4
        CLI_SOURCES task4.c
        LIB_SOURCES constants.c
        TEST_SOURCES task4_test.cpp
)
# PASS!!
add_task(5
        CLI_SOURCES task5.c
        LIB_SOURCES actions.c cli.c
        TEST_SOURCES task5_test.cpp
)
# PASS!!
add_task(6
        CLI_SOURCES task6.c
        LIB_SOURCES cli.c integrals.c numerical.c
        TEST_SOURCES task6_test.cpp
)
# PASS!!
add_task(7
        CLI_SOURCES task7.c
        LIB_SOURCES bases.c cli.c
        TEST_SOURCES task7_test.cpp
)
# PASS!!
add_task(8
        CLI_SOURCES task8.c
        LIB_SOURCES cli.c convert.c
        TEST_SOURCES task8_test.cpp
)
