file(GLOB_RECURSE SRC *.h *.hpp *.cpp)

add_library(print_ip_lib ${SRC})

target_include_directories(print_ip_lib PRIVATE
	"${CMAKE_CURRENT_BINARY_DIR}"
)

configure_file(version.h.in version.h)
