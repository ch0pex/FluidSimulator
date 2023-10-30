add_library(sim grid/block.cpp grid/grid.cpp args/proargs.cpp
        utils/constants.hpp
        file/fld.cpp
        file/fld.hpp
        math/vector.hpp
        math/vector.cpp
        grid/particle.cpp
        grid/particle.hpp
        math/math.cpp
        math/math.hpp)
target_include_directories(sim PUBLIC ..)
