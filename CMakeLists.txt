cmake_minimum_required(VERSION 3.5)

project(test)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(SRC_DIR  ${PROJECT_SOURCE_DIR})
set(SRC_FILES   ${SRC_DIR}/test/main.c
                ${SRC_DIR}/test/cutils_math.c
                ${SRC_DIR}/src/cutils_base.c
                ${SRC_DIR}/src/log.c
                ${SRC_DIR}/src/volk.c
                ${SRC_DIR}/src/vk_mem_alloc.cpp
                ${SRC_DIR}/src/core.c
                ${SRC_DIR}/src/common.c
                ${SRC_DIR}/src/automaton.c
                ${SRC_DIR}/src/mesh_pack.c
                ${SRC_DIR}/src/subbuffer.c
                ${SRC_DIR}/src/pipeline_3d.c
                ${SRC_DIR}/src/asset.c
                ${SRC_DIR}/src/math.c)

find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})

find_package(assimp REQUIRED)
include_directories(${ASSIMP_INCLUDE_DIRS})

set(BUILD_SHARED_LIBS_SAVED "${BUILD_SHARED_LIBS}")
set(BUILD_STATIC_LIBS_SAVED "${BUILD_STATIC_LIBS}")

add_executable(test ${SRC_FILES})
target_link_libraries(test m X11 glfw assimp ${GLFW3_LIBRARY})

file(COPY ${PROJECT_SOURCE_DIR}/test/res DESTINATION ${CMAKE_BINARY_DIR})
