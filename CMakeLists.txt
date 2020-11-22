cmake_minimum_required(VERSION 3.10)
project(printComplex)

# main funcionality

set(MAIN
    main.cpp
)

set(SRC
    printComplex.cpp
)

set(TESTS
    printComplex.ut.cpp
)

add_executable(${PROJECT_NAME} ${MAIN})