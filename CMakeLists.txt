cmake_minimum_required (VERSION 3.0.2)

set(PROJECT "GameOfLife")

project (${PROJECT})

set (${PROJECT}_VERSION_MAJOR 1)
set (${PROJECT}_VERSION_MINOR 0)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

configure_file (
  "${PROJECT_SOURCE_DIR}/${PROJECT}Config.h.in"
  "${PROJECT_BINARY_DIR}/${PROJECT}Config.h"
)

add_subdirectory(Source)

include_directories("${PROJECT_BINARY_DIR}")
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/3rdParty/Includes/)

add_executable(${PROJECT} WIN32
    ${SOURCES}
)

if(WIN32)
   set_target_properties(${PROJECT} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:CONSOLE")
endif(WIN32)

#source_group( Editor FILES ${EDITOR_SOURCES} ${EDITOR_HEADERS})

target_link_libraries(${PROJECT} ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/Libraries/glfw3.lib)

add_custom_command(TARGET ${PROJECT} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/3rdParty/Binaries/"
        ${CMAKE_BINARY_DIR}/Release)