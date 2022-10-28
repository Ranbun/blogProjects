SET(target_ win32windows)

SET(headers
        Win32WindowsManager.h
        )

SET(sources
        main.cpp
        )


ADD_EXECUTABLE(
        ${target_}
        ${headers}
        ${sources}
)


