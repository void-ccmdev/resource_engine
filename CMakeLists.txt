cmake_minimum_required(VERSION 3.20)

cmake_policy(SET CMP0072 NEW)

project(resource_engine LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_DIR "${CMAKE_SOURCE_DIR}/dependencies/lib")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/dependencies/include")

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

set(ENGINE_DIR "${SRC_DIR}/engine")
set(EDITOR_DIR "${SRC_DIR}/tools/editor")
set(MAPPER_DIR "${SRC_DIR}/tools/mapper")

#------------------------
# DEPENDENCIES
#------------------------

#--GLFW--

if(WIN32)
    add_library(glfw STATIC IMPORTED)

    set_target_properties(glfw PROPERTIES 
        IMPORTED_LOCATION
            "${LIB_DIR}/glfw3.lib"
        INTERFACE_INCLUDE_DIRECTORIES 
            "${INCLUDE_DIR}"
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

#--ImGui--

add_library(imgui STATIC
    ${INCLUDE_DIR}/imgui/imgui.cpp
    ${INCLUDE_DIR}/imgui/imgui_draw.cpp
    ${INCLUDE_DIR}/imgui/imgui_tables.cpp
    ${INCLUDE_DIR}/imgui/imgui_widgets.cpp
    ${INCLUDE_DIR}/imgui/imgui_demo.cpp

    ${INCLUDE_DIR}/imgui/imgui_impl_glfw.cpp
    ${INCLUDE_DIR}/imgui/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
    ${INCLUDE_DIR}/imgui
)
target_compile_definitions(imgui PRIVATE
    IMGUI_IMPL_OPENGL_LOADER_GLAD
)
target_link_libraries(imgui PUBLIC ${OPENGL_GLFW_TARGET})

#--Glad--

if(EXISTS "${ENGINE_DIR}/core/glad.c")
    add_library(glad STATIC "${ENGINE_DIR}/core/glad.c")
else()
    message(FATAL_ERROR "Could not find glad.c in 'src/engine/core/glad.c', please make sure glad.c is located there :]")
endif()

target_include_directories(glad
    PUBLIC
        "${INCLUDE_DIR}"
)

#------------------------
# ENGINE
#------------------------

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    "${ENGINE_DIR}/*.cpp"
)

add_library(engine STATIC
    ${ENGINE_SOURCES}
)

target_include_directories(engine
    PUBLIC
        "${SRC_DIR}"
        "${ENGINE_DIR}"
)

target_link_libraries(engine
    PUBLIC
        imgui
        glad
        glfw
)

#------------------------
# EXECUTABLES
#------------------------

#--Editor

file(GLOB_RECURSE EDITOR_SOURCES CONFIGURE_DEPENDS
    "${EDITOR_DIR}/*.cpp"
)

add_executable(resource_editor
    ${EDITOR_SOURCES}
)

target_include_directories(resource_editor
    PRIVATE
        "${SRC_DIR}"
)

target_link_libraries(resource_editor
    PRIVATE
        engine
)

#--Mapper