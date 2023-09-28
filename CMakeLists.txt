cmake_minimum_required(VERSION 3.22) # Compile with 3.26 in Avignon
project(fluid LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS_OFF)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

#set(CMAKE_CXX_FLAGS_RELEASE "−march=native")

add_subdirectory(sim)
add_subdirectory(fluid)

enable_testing()
add_subdirectory(test)