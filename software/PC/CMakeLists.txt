# sets the minimum CMake version you need to compile the project
cmake_minimum_required(VERSION "3.21")

# starts the project; giv basic information
project("afanci" VERSION "1.0.0")

#tells CMake to create exe with sourcfiles 
add_executable("${PROJECT_NAME}" WIN32 main.cpp)

#install
install(TARGETS "${PROJECT_NAME}" DESTINATION bin) #%{CMAKE_INSTALL_PREFIX}/bin
install(FILES "afanci.cpp" DESTINATION src) #%{CMAKE_INSTALL_PREFIX}/src

set_target_properties("afanci" PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# spezififies version of c++; force you to use it
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED True)


#Testting
#include (CTest)
#add_test("test1_1" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}") #points to the current build tree

#CPack
#include(CPack)

