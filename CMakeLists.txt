cmake_minimum_required(VERSION 3.10)

# Define the project
project(BusManager)

# Add Google Test (assuming it's already installed)
find_package(GTest REQUIRED)

# Include directories
include_directories(${GTEST_INCLUDE_DIRS})

# Add the source files
set(SOURCES 
    src/Data.cpp
    src/Onibus.cpp
    src/Parada.cpp
    src/Reserva.cpp
    src/Viagem.cpp
    tests/Testes.cpp
)

# Create the test executable (this doesn't require a main explicitly)
add_executable(TesteCoverage ${SOURCES})

# Link GTest and pthread
target_link_libraries(TesteCoverage ${GTEST_LIBRARIES} pthread)

# Enable testing
enable_testing()

# Add the test
add_test(NAME TesteCoverage COMMAND TesteCoverage)
