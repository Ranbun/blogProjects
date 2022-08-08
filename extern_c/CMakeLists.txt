set(target_name extern_c)
project(${target_name})


set(cpp_files

    main.cpp 
    extern_test.cpp
)

set(header_files
    extern_test.h 
    test.h

)


add_executable(${target_name}  ${cpp_files} ${header_files})
