set(target_name mul_inherit)
project(${target_name})


set(CPPFiles
    main.cpp
   
)

set(HeaderFiles
    Person.cpp
)

add_executable(${target_name} ${CPPFiles} ${HeaderFiles})