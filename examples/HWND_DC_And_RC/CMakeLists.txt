SET(target_ win32windows)

SET(headers
        Win32WindowsManager.h
        )

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
        ${target_}  PRIVATE opengl32 glad::glad
)

