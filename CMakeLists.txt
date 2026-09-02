cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0072 NEW)
project(resource_engine C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_subdirectory(src/engine REQUIRED)

find_package(glfw3 REQUIRED)

add_executable(
      ${CMAKE_PROJECT_NAME}
      src/main.cpp  #MAIN
      src/glad.c #GLAD

      src/engine/engine.cpp #ENGINE
      src/engine/core/window.cpp #WINDOW
      )

target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/dependencies/lib)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/dependencies/include)

target_link_libraries(${CMAKE_PROJECT_NAME} glfw)
