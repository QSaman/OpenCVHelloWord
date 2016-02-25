set(LIBRARY_NAME SamanCVLib)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
add_library(${LIBRARY_NAME} ${SRC_LIST})

################################################################################
# Enabling C++11. Add these two lines after add_executable
set_property(TARGET ${LIBRARY_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${LIBRARY_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

################################################################################

find_package(OpenCV REQUIRED)
target_link_libraries(${LIBRARY_NAME} ${OpenCV_LIBS})
