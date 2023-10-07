add_library(sim grid/block.cpp grid/grid.cpp args/proargs.cpp
        utils/constants.hpp
        file/fld.cpp
        file/fld.hpp
        utils/vector.hpp
        utils/vector.cpp)
target_include_directories(sim PUBLIC ..)
