SET(target_ win32windows)

set(CMAKE_CXX_STANDARD 17)

SET(headers
        Win32WindowsManager.h
        triangle.h)

SET(sources
        main.cpp
        )


FIND_PACKAGE(glad CONFIG REQUIRED)

ADD_EXECUTABLE(
        ${target_}
        ${headers}
        ${sources}
)

target_link_libraries(
        ${target_}  PRIVATE  opengl32 glad::glad
)

