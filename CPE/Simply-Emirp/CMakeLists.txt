cmake_minimum_required(VERSION 3.20)
project(simply_emirp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# ---- Library ----
add_library(solution_lib
    src/solution.cpp
    src/helper.cpp
)
target_include_directories(solution_lib
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# ---- Main executable ----
add_executable(solution_main
    src/main.cpp
)
target_link_libraries(solution_main PRIVATE solution_lib)

# ---- Enable testing ----
enable_testing()
add_subdirectory(tests)
