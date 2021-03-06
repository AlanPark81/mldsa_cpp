cmake_minimum_required(VERSION 3.12)
project(mldsa_cpp)

add_definitions(-std=gnu++17)
SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crst ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

add_executable(mldsa_cpp tests/main.cpp tests/queue.cpp tests/stack.cpp src/stack.h src/linkedlist.h tests/linkedlist.cpp tests/heap.cpp src/heap.h src/visitor.h tests/binary_search_tree.cpp src/binary_search_tree.h src/avl_tree.h tests/avl_tree.cpp src/set.h tests/set.cpp src/trie.h tests/trie.cpp src/merkle_tree.h tests/merkle_tree.cpp src/hash_table.h tests/hash_table.cpp src/binary_search.h tests/binary_search.cpp src/sort.h tests/sort.cpp src/bitset.h tests/bitset.cpp src/array.h tests/array.cpp src/common.h)
add_executable(mldsa_cpp_benchmark benchmark/queue.cpp benchmark/main.cpp benchmark/main.cpp benchmark/linkedlist.cpp benchmark/array.cpp)
target_link_libraries(mldsa_cpp_benchmark benchmark pthread)
target_link_libraries(mldsa_cpp gtest_main)
add_test(NAME mldsa_cpp_test COMMAND mldsa_cpp)