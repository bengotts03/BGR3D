cmake_minimum_required(VERSION 3.31)
project(BGR3D)

set(CMAKE_CXX_STANDARD 20)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
file(GLOB_RECURSE SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(BGR3D STATIC ${HEADERS} ${SOURCE})

target_include_directories(BGR3D PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/BGRCore/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/BGApp/include"
)

find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
target_link_libraries(BGR3D PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/BGRCore/lib/libBGRCore.a"
        "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/BGApp/lib/libBGApp.a"
        OpenGL::GL
        glfw
)

target_include_directories(BGR3D PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include/src>
)

install(TARGETS BGR3D
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
)

install(DIRECTORY src/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)

install(DIRECTORY assets/
        DESTINATION include/assets/
        FILES_MATCHING PATTERN "*.vert" PATTERN "*.frag"
)