cmake_minimum_required(VERSION 3.15)
project(real)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Homebrew include/library paths
set(HOME_BREW_PREFIX /opt/homebrew)

# Pre Apple - explicitne nastavenie správneho kompajlera a SDK
if(APPLE)
    # Nastavenie správnej C++ knižnice
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

    # Získanie cesty k SDK
    execute_process(
            COMMAND xcrun --show-sdk-path
            OUTPUT_VARIABLE SDK_PATH
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    # Nastavenie SDK root
    set(CMAKE_OSX_SYSROOT ${SDK_PATH})

    # Explicitne nastavenie poradia include ciest - systémové hlavičky NAJPRV
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -isystem ${SDK_PATH}/usr/include/c++/v1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -isystem ${SDK_PATH}/usr/include")
endif()

# Homebrew cesty - pridať AŽ PO systémových hlavičkách
include_directories(SYSTEM ${HOME_BREW_PREFIX}/include)
link_directories(${HOME_BREW_PREFIX}/lib)

# Executable
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
        Quad.h)

# Link knihovny
target_link_libraries(real
        GLEW
        glfw
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework OpenGL"
)

# Povolit warningy na Mac a potlačit deprecated
if(APPLE)
    target_compile_options(real PRIVATE
            "-Wno-deprecated-declarations"
            "-DGL_SILENCE_DEPRECATION"
    )

    # Nastavenie vlastností pre macOS
    set_target_properties(real PROPERTIES
            MACOSX_RPATH TRUE
    )
endif()
