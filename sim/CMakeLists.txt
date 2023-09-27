add_library(sim block.cpp grid.cpp proargs.cpp
        constants.hpp
        fld.cpp
        fld.hpp)
target_include_directories(sim PUBLIC ..)
