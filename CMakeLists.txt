cmake_minimum_required(VERSION 3.10)
project(TesteCoverage)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCES
    src/Data.cpp
    src/Onibus.cpp
    src/Parada.cpp
    src/Reserva.cpp
    src/Viagem.cpp
)

set(TEST_SOURCES
    tests/Testes.cpp
)

add_executable(TesteCoverage ${SOURCES} ${TEST_SOURCES})

target_link_libraries(TesteCoverage ${GTEST_LIBRARIES} pthread)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

enable_testing()
add_test(NAME TesteCoverage COMMAND TesteCoverage)
