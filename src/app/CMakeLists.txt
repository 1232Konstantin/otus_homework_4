file(GLOB_RECURSE SRC *.h *.hpp *.cpp)

add_executable(print_ip ${SRC})

target_include_directories(print_ip PRIVATE
	../library
)

target_link_libraries(print_ip PRIVATE
	print_ip_lib
)
