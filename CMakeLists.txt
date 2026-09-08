cmake_minimum_required(VERSION 3.5)

cmake_policy(SET CMP0072 NEW)

project(resource_engine VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --------------------------------------------------
# GLFW
# --------------------------------------------------

if(WIN32)
    add_library(glfw STATIC IMPORTED)

    set_target_properties(glfw PROPERTIES
        IMPORTED_LOCATION
            "${CMAKE_SOURCE_DIR}/dependencies/lib/glfw3.lib"

        INTERFACE_INCLUDE_DIRECTORIES
            "${CMAKE_SOURCE_DIR}/dependencies/include"
    )

    set(OPENGL_GLFW_TARGET glfw)
else()
    find_package(glfw3 REQUIRED)

    if(TARGET glfw)
        set(OPENGL_GLFW_TARGET glfw)
    else()
        set(OPENGL_GLFW_TARGET glfw3::glfw)
    endif()
endif()

# --------------------------------------------------
# Dear ImGui
# --------------------------------------------------

add_library(imgui STATIC
    dependencies/include/imgui/imgui.cpp
    dependencies/include/imgui/imgui_draw.cpp
    dependencies/include/imgui/imgui_tables.cpp
    dependencies/include/imgui/imgui_widgets.cpp
    dependencies/include/imgui/imgui_demo.cpp

    dependencies/include/imgui/imgui_impl_glfw.cpp
    dependencies/include/imgui/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
    ${CMAKE_SOURCE_DIR}/dependencies/include/imgui
    ${CMAKE_SOURCE_DIR}/dependencies/include
)

target_compile_definitions(imgui PRIVATE
    IMGUI_IMPL_OPENGL_LOADER_GLAD
)

target_link_libraries(imgui PUBLIC
    ${OPENGL_GLFW_TARGET}
)

# --------------------------------------------------
# Executable
# --------------------------------------------------

add_executable(${CMAKE_PROJECT_NAME}
    src/main.cpp
    src/glad.c

    src/editor/editor.cpp

    src/engine/engine.cpp
    src/engine/core/window.cpp
    src/engine/core/input.cpp

    src/engine/renderer/renderer.cpp
    src/engine/renderer/mesh/mesh.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/dependencies/include
    ${CMAKE_SOURCE_DIR}/include
)

target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/dependencies/lib
)

# This is required. It was commented out in your original file.
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    imgui
    ${OPENGL_GLFW_TARGET}
)

# Windows system libraries commonly required by static GLFW.
if(WIN32)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
        opengl32
        user32
        gdi32
        shell32
    )
endif()

if(APPLE)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
        GL_SILENCE_DEPRECATION
    )
endif()
