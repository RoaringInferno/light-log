cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(light-log)

add_library(${PROJECT_NAME} STATIC)
file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES src/*.cpp)
target_sources(${PROJECT_NAME} PUBLIC ${${PROJECT_NAME}_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC
    include/
)
target_include_directories(${PROJECT_NAME} PRIVATE
    include/light-log_bits/
)

enable_testing()
add_executable(${PROJECT_NAME}_tests)
file(GLOB_RECURSE ${PROJECT_NAME}_TEST_SOURCES test/*.cpp)
target_sources(${PROJECT_NAME}_tests PRIVATE ${${PROJECT_NAME}_TEST_SOURCES})
target_link_libraries(${PROJECT_NAME}_tests PRIVATE ${PROJECT_NAME})