cmake_minimum_required(VERSION 3.15)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:/Users/bogda/OneDrive/Desktop/Tetris/libs/SFML/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)


set(SOURCES
    src/main.cpp
    "src/game/core/forms.cpp"
    "src/game/game.cpp"
    "src/game/core/cell.cpp"
    "src/game/core/field.cpp"
 "src/game/core/gameLogic.cpp" "src/game/core/render.cpp" "src/game/core/window.cpp")

set(HEADERS
    "src/game/core/forms.h"
    src/game/game.h
    src/logger/log.h
    src/logger/logger.h
    "src/game/core/config.h"
    "src/game/core/cell.h"
    "src/game/core/field.h"
 "src/game/core/gameLogic.h"
 "src/game/core/render.h" "src/game/core/window.h")

add_executable(Tetris ${SOURCES} ${HEADERS} "src/game/core/window.h")

target_link_libraries(Tetris sfml-graphics sfml-window sfml-system)

if(WIN32)
    add_custom_command(TARGET Tetris POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/Users/bogda/OneDrive/Desktop/Tetris/bin/sfml-graphics-d-2.lib"
        "C:/Users/bogda/OneDrive/Desktop/Tetris/bin/sfml-window-d-2.lib"
        "C:/Users/bogda/OneDrive/Desktop/Tetris/bin/sfml-system-d-2.dll"
        "$<TARGET_FILE_DIR:Tetris>"
    )
endif()