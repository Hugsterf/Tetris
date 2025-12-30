cmake_minimum_required(VERSION 3.15)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:/Users/MKA/source/repos/Tetris/libs/SFML/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)


set(SOURCES
    "src/main.cpp"
    "src/game/core/forms.cpp"
    "src/game/game.cpp"
    "src/game/core/cell.cpp"
    "src/game/core/field.cpp"
 "src/game/core/gameLogic.cpp"
 "src/game/core/render.cpp"
 "src/game/core/window.cpp"
"src/game/core/random.cpp")

set(HEADERS
    "src/game/core/forms.h"
    "src/game/game.h"
    "src/game/core/config.h"
    "src/game/core/cell.h"
    "src/game/core/field.h"
 "src/game/core/gameLogic.h"
 "src/game/core/render.h" 
 "src/game/core/window.h" 
 "src/game/core/shapes.h"
 "src/game/core/random.h")

add_executable(Tetris ${SOURCES} ${HEADERS})

target_link_libraries(Tetris sfml-graphics sfml-window sfml-system)

if(WIN32)
    add_custom_command(TARGET Tetris POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "D:/SFML-2.5.1/bin/sfml-graphics-d-2.lib"
        "D:/SFML-2.5.1/bin/sfml-window-d-2.lib"
        "D:/SFML-2.5.1/bin/sfml-system-d-2.dll"
        "$<TARGET_FILE_DIR:Tetris>"
    )
endif()