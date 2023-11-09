cmake_minimum_required(VERSION 3.26) # Compile with 3.26 in Avignon
project(fluid LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS_OFF)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native -O3 -flto -ffast-math -ftree-vectorize -fprefetch-loop-arrays")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# Enable GSL Library
FetchContent_Declare(GSL
        GIT_REPOSITORY "https://github.com/microsoft/GSL"
        GIT_TAG v4.0.0
        GIT_SHALLOW ON
)
FetchContent_MakeAvailable(GSL)

#set(CMAKE_CXX_CLANG_TIDY -clang-tidy -header-filter=.*)

include_directories(PUBLIC .)

add_subdirectory(sim)
add_subdirectory(fluid)

enable_testing()
add_subdirectory(utest)
add_subdirectory(ftest)

