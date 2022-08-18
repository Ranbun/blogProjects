set(target_name keyWordsExtern)
project(${target_name})


set(CPPFiles
    main.cpp
    KeyWordsExtern.cpp
)

set(HeaderFiles
    KeyWordsExtern.h
    TestExtern.h

)

add_executable(${target_name}  ${CPPFiles} ${HeaderFiles})

