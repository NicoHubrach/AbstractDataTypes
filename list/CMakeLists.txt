# Set the project name
cmake_minimum_required(VERSION 3.23.1)
project (list VERSION 1.0)

# Add a library with the above sources
add_library(${PROJECT_NAME} src/list.c)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
