function(add_task TASK_NUM)
    cmake_parse_arguments(ARG "" "" "SOURCES" ${ARGN})

    set(TASK${TASK_NUM}_SOURCES)
    foreach(SOURCE ${ARG_SOURCES})
        list(APPEND
                TASK${TASK_NUM}_SOURCES
                ${SOURCE_DIR}/task${TASK_NUM}/${SOURCE}
        )
    endforeach()

    add_library(task${TASK_NUM}_lib
            ${TASK${TASK_NUM}_SOURCES}
    )

    target_include_directories(task${TASK_NUM}_lib
            PRIVATE
            ${INCLUDE_DIR}
    )

    add_executable(task${TASK_NUM}
            ${CLI_DIR}/task${TASK_NUM}.c
    )

    target_include_directories(task${TASK_NUM}
            PRIVATE
            ${INCLUDE_DIR}
    )

    target_link_libraries(task${TASK_NUM}
            PRIVATE
            task${TASK_NUM}_lib
    )
endfunction()

function(add_task_test TASK_NUM)
    add_executable(task${TASK_NUM}_test
            task${TASK_NUM}_test.cpp
    )

    target_include_directories(task${TASK_NUM}_test
            PRIVATE
            GTest::GTest
            ${INCLUDE_DIR}
    )

    target_link_libraries(task${TASK_NUM}_test
            PRIVATE
            GTest::GTest
            task${TASK_NUM}_lib
    )

    add_test(
            NAME task${TASK_NUM}_tests
            COMMAND task${TASK_NUM}_test
    )
endfunction()
