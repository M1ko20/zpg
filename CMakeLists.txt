cmake_minimum_required(VERSION 3.15)
project(real)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HOME_BREW_PREFIX /opt/homebrew)

if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

    execute_process(
            COMMAND xcrun --show-sdk-path
            OUTPUT_VARIABLE SDK_PATH
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    set(CMAKE_OSX_SYSROOT ${SDK_PATH})

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -isystem ${SDK_PATH}/usr/include/c++/v1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -isystem ${SDK_PATH}/usr/include")
endif()

include_directories(SYSTEM ${HOME_BREW_PREFIX}/include)
link_directories(${HOME_BREW_PREFIX}/lib)

add_executable(real main.cpp
        main.cpp
        ShaderProgram.cpp
        ShaderProgram.h
        Model.cpp
        Model.h
        App.cpp
        App.h
        Triangle.cpp
        Triangle.h
        Quad.cpp
        Quad.h
        Cube.cpp
        Cube.h)

target_link_libraries(real
        GLEW
        glfw
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework OpenGL"
)

if(APPLE)
    target_compile_options(real PRIVATE
            "-Wno-deprecated-declarations"
            "-DGL_SILENCE_DEPRECATION"
    )

    set_target_properties(real PROPERTIES
            MACOSX_RPATH TRUE
    )
endif()
