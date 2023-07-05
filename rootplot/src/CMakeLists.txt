include_directories (${CMAKE_SOURCE_DIR}/rootplot/inc/)
include_directories ( ${CMAKE_SOURCE_DIR}/tinyxml/)
#include_directories ( ${CMAKE_SOURCE_DIR}/root_linkdefs/)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/xgboost/include/)

add_library (hiveLib gadget.cxx hive.cxx load_mva_param.cxx)
target_link_libraries (hiveLib tinyxmllib ${ROOT_LIBRARIES})

message(STATUS "ROOT_LIBRARIES @: ${ROOT_LIBRARIES}")


add_executable (hive hive.cxx)
target_link_libraries (hive tinyxmllib  hiveLib ${ROOT_LIBRARIES})

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# CMAKE_SOURCE_DIR is the directory where you have run cmake command
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
