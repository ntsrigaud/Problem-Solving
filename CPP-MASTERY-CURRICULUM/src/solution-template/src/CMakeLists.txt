# ---- PPP (std_lib_faciliities) ----
file(GLOB PPP_HEADERS "${PROJECT_SOURCE_DIR}/include/PPP/*.h")

add_library(ppp_lib INTERFACE)
target_include_directories(ppp_lib INTERFACE ${PROJECT_SOURCE_DIR}/include)

# ---- Solution library ----
add_library(solution_lib
  solution.cpp
  helper.cpp
)
target_include_directories(solution_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(solution_lib PUBLIC ppp_lib)

# ---- Main executable ----
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE solution_lib)
