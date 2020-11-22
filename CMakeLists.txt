cmake_minimum_required(VERSION 3.10)
project(printComplex)

# cpp standard settings

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add google tests

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
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

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

# Now simply link against gtest or gtest_main as needed. Eg

# initialize sets for main, src and tests

set(MAIN
    main.cpp
)

set(SRC
    src/printComplex.cpp
)

set(TESTS
    tests/testsMain.cpp
    tests/printComplex.ut.cpp
)

# main funcionality - executable main program

include_directories(headers)

add_executable(${PROJECT_NAME} ${MAIN})
add_library(${PROJECT_NAME}-lib ${SRC})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}-lib)

# main funcionality - executable tests

link_libraries(gmock)

add_executable(${PROJECT_NAME}-ut ${TESTS})
target_link_libraries(${PROJECT_NAME}-ut PRIVATE ${PROJECT_NAME}-lib)

add_test(${PROJECT_NAME}-tests ${PROJECT_NAME}-ut)
enable_testing()

