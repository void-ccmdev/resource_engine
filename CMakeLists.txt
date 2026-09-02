cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0072 NEW)
project(resource_engine C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_subdirectory(src/engine REQUIRED)

find_package(OpenGL REQUIRED)

if(WIN32)
    add_library(glfw STATIC IMPORTED)
    set_target_properties(glfw PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/dependencies/lib/glfw3.lib"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/dependencies/include/glfw3.h"
    )
    set(OPENGL_GLFW_TARGET glfw)
else()
    find_package(glfw3 REQUIRED)
    if(TARGET glfw3)
        set(OPENGL_GLFW_TARGET glfw)
    else()
        set(OPENGL_GLFW_TARGET glfw3::glfw)
    endif()
endif()

##if(WIN32)
##    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE user32 gdi32 shell32)
##endif()

if(APPLE)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE GL_SILENCE_DEPRECATION)
endif()

add_executable(
      ${CMAKE_PROJECT_NAME}
      src/main.cpp  #MAIN
      src/glad.c #GLAD

      src/engine/engine.cpp #ENGINE
      src/engine/core/window.cpp #WINDOW

      src/input/input.cpp #INPUT
      )

target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/dependencies/lib)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/dependencies/include)

target_link_libraries(${CMAKE_PROJECT_NAME} glfw)
