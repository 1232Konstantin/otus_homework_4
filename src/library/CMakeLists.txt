file(GLOB_RECURSE SRC *.h *.hpp *.cpp)

add_library(print_ip_lib ${SRC})

target_include_directories(print_ip_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
