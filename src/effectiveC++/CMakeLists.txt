set(target_name effective_cpp)
project(${target_name})


set(CPPFiles
        main.cpp
        
        )

set(HeaderFiles
        prue_virtual_class.h
)

add_executable(${target_name} ${CPPFiles} ${HeaderFiles})