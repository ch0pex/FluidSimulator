add_executable(fluid simulator.cpp
        main.cpp
        simulator.hpp)
target_link_libraries (fluid sim)
target_include_directories(fluid PUBLIC ../common)