set(project_name BitManipulation)
project(${project_name})

set(headers 
    BitManipulation.h
)

set(sources_file
    BitManipulation.cpp
    main.cpp
)


add_executable(${project_name} 
               ${sources_file}
               ${headers}
)
