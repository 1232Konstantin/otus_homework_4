#include <iostream>
#include <type_traits>

#include <algorithm>
#include <list>
#include <string>
#include <vector>



template<typename T, std::enable_if_t<std::is_arithmetic_v<T>, int> = 0>
void print_ip(T value)
{
	int size = sizeof(T);
	for (int i = size - 1; i > 0; --i)
		std::cout << ((value >> i * 8) & 0xFF) << '.';

	std::cout << (value & 0xFF) << std::endl;
}



//template<typename T, std::enable_if_t<std::is_same_v<T, std::string>, int> = 0>
//void print_ip(T value)
//{
//	std::cout << value << std::endl;
//}



template<typename T, typename = typename T::iterator>
void print_ip(T value)
{
	auto lastIt = std::prev(value.end());
	for (auto it = value.begin(); it != lastIt; ++it)
		std::cout << *it << '.';

	std::cout << *lastIt << std::endl;
}



int main(int, char**)
{
	print_ip(int8_t{ -1 }); // 255
	print_ip(int16_t{ 0 }); // 0.0
	print_ip(int32_t{ 2130706433 }); // 127.0.0.1
	print_ip(int64_t{ 8875824491850138409 });// 123.45.67.89.101.112.131.41
	//	print_ip(std::string{ "Hello, World!" }); // Hello, World!
	print_ip(std::vector<int>{100, 200, 300, 400}); // 100.200.300.400
	print_ip(std::list<short>{400, 300, 200, 100}); // 400.300.200.100
	//	print_ip(std::make_tuple(123, 456, 789, 0)); // 123.456.789.0

	return 0;
}
