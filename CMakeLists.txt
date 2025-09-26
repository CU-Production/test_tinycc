cmake_minimum_required(VERSION 4.0)
project(test_tinycc)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(3rd_party)

add_executable(test_tinycc1 test1.cpp)
target_link_libraries(test_tinycc1 PRIVATE libtcc)
add_custom_command(TARGET test_tinycc1 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/libtccbin" "${CMAKE_CURRENT_BINARY_DIR}"
        COMMAND_EXPAND_LISTS
)

add_executable(test_tinycc2 test2.cpp)
target_link_libraries(test_tinycc2 PRIVATE libtcc)
add_custom_command(TARGET test_tinycc2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/libtccbin" "${CMAKE_CURRENT_BINARY_DIR}"
        COMMAND_EXPAND_LISTS
)
