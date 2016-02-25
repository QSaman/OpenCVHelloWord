project(HelloOpenCV)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

################################################################################

include_directories(${PROJECT_SOURCE_DIR}/lib)
add_subdirectory(${PROJECT_SOURCE_DIR}/lib)

################################################################################

#Adding header files recursively. aux_source_directory doesn't do that very well
file(GLOB_RECURSE headerFilesList "${PROJECT_SOURCE_DIR}/src/*.h" "${PROJECT_SOURCE_DIR}/src/*.hpp")
add_custom_target(headerFiles SOURCES ${headerFilesList})

################################################################################

add_executable(${PROJECT_NAME} ${SRC_LIST})

################################################################################
# Enabling C++11. Add these two lines after add_executable
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

################################################################################

set(ExternalLibs SamanCVLib)
find_package(OpenCV REQUIRED)
set(ExternalLibs ${ExternalLibs} ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} ${ExternalLibs})
file(COPY ${PROJECT_SOURCE_DIR}/img/ DESTINATION ${PROJECT_BINARY_DIR}/img)
