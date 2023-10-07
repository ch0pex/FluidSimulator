add_executable(fluid ../sim/simulator.cpp
        fluid.cpp
        ../sim/simulator.hpp
        ../sim/utils/error.hpp)
target_link_libraries (fluid sim)
target_include_directories(fluid PUBLIC ../common)