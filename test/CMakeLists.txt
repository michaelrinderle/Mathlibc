cmake_minimum_required (VERSION 3.8)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(UNITY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../external/unity)

include_directories(${UNITY_DIR})

add_library(unity STATIC
	${UNITY_DIR}/unity.c
	${UNITY_DIR}/unity.h
)

include_directories("../include")

set(BINARY ${CMAKE_PROJECT_NAME})
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.c)
set(SOURCES ${SOURCES})
add_executable(${BINARY}_test_run ${SOURCES})
target_link_libraries(${BINARY}_test_run mathlibc_lib unity)
