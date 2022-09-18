set(project_name Singleton)
project(${project_name})

set(headers 

     "Singleton.h")

set(sources_file
    main.cpp
)


add_executable(${project_name} 
               ${sources_file}
               ${headers}
)
