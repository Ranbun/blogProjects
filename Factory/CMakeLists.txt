set(project_name factory)
project(${project_name})

set(headers 
    Product.h
    Factory.h
    concreteFactory.h
)

set(sources_file
    main.cpp
)


add_executable(${project_name} 
               ${sources_file}
#              ${headers}
)
