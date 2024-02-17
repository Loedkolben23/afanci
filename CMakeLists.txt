cmake_minimum_required(VERSION 3.27.6)

#sets project name
project(afanci)

if (WIN32)
    project(${PROJECT_NAME} LANGUAGES CXX)
elseif(UNIX)
    project(${PROJECT_NAME})
endif()

set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)

#INCLUSION OF Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)

#INCLUSION OF Project Files
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${FORMS_DIR}/*.qrc"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

#SETUP EXECTUABLE
#Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

#Add the executable
if (WIN32) 
    add_executable(${PROJECT_NAME} WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(${PROJECT_NAME} ${SOURCES})
endif()

#Add the target includes for ${PROJECT_NAME} 
target_include_directories(${PROJECT_NAME} PRIVATE ${FORMS_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${SOURCE_DIR})

#LINKING LIBRARIES
target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
