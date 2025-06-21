cmake_minimum_required(VERSION 3.20)
project(Logger)

set(CMAKE_CXX_STANDARD 17)

add_executable(Logger
    main.cpp
)

if (WIN32)
  set_target_properties(Logger PROPERTIES WIN32_EXECUTABLE TRUE)
endif()


find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

target_link_libraries(Logger PRIVATE glfw imgui)