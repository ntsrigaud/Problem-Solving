# Separate test binary output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/tests)

# GoogleTest setup (assumes gtest installed via system or vcpkg)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# ---- Test executable ----
add_executable(solution_tests test.cpp)
target_link_libraries(solution_tests
    PRIVATE solution_lib
            GTest::GTest
            GTest::Main
)

# Add test
add_test(NAME solution_tests COMMAND solution_tests)
