#include <type_traits>

#include "is_container.hpp"



template<typename T>
typename std::enable_if<std::is_arithmetic_v<T>, void>::type
print_ip(T value)
{
	int size = sizeof(T);
	for (int i = size - 1; i > 0; --i)
		std::cout << ((value >> i * 8) & 0xFF) << '.';

	std::cout << (value & 0xFF) << std::endl;
}



template<typename T>
typename std::enable_if<std::is_same_v<T, std::string>, void>::type
print_ip(T value)
{
	std::cout << value << std::endl;
}



template<typename T>
typename std::enable_if<is_container_v<T> & !std::is_same_v<T, std::string>, void>::type
print_ip(T value)
{
	auto lastIt = std::prev(value.end());
	for (auto it = value.begin(); it != lastIt; ++it)
		std::cout << *it << '.';

	std::cout << *lastIt << std::endl;
}
