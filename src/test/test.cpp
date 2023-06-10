/*!
\file
\brief Library test file

The file contains tests for the correctness of the output of template functions 
for printing an IP address
*/

#include <gtest/gtest.h>

#include <list>
#include <vector>

#include <print_ip.hpp>

#include "StdOutReader.h"



/// \brief Checking the output of the IP address in int8_t format
TEST(test_print_ip, print_int8_t)
{
	StdOutReader reader;

	print_ip(int8_t{ -1 }); // 255
	auto result = reader.readOut();
	
	EXPECT_TRUE(result == "255\n");
}



/// \brief Checking the output of the IP address in int16_t format
TEST(test_print_ip, print_int16_t)
{
	StdOutReader reader;

	print_ip(int16_t{ 0 }); // 0.0
	auto result = reader.readOut();
	
	EXPECT_TRUE(result == "0.0\n");
}



/// \brief Checking the output of the IP address in int32_t format
TEST(test_print_ip, print_int32_t)
{
	StdOutReader reader;

	print_ip(int32_t{ 2130706433 }); // 127.0.0.1
	auto result = reader.readOut();
	
	EXPECT_TRUE(result == "127.0.0.1\n");
}



/// \brief Checking the output of the IP address in int64_t format
TEST(test_print_ip, print_int64_t)
{
	StdOutReader reader;

	print_ip(int64_t{ 8875824491850138409 }); // 123.45.67.89.101.112.131.41
	auto result = reader.readOut();
	
	EXPECT_TRUE(result == "123.45.67.89.101.112.131.41\n");
}



/// \brief Checking the output of the IP address in std::string format
TEST(test_print_ip, print_string)
{
	StdOutReader reader;

	print_ip(std::string{ "Hello, World!" }); // Hello, World!
	auto result = reader.readOut();
	
	EXPECT_TRUE(result == "Hello, World!\n");
}



/// \brief Checking the output of the IP address in std::vector format
TEST(test_print_ip, print_vector)
{
	StdOutReader reader;

	print_ip(std::vector<int>{100, 200, 300, 400}); // 100.200.300.400
	auto result = reader.readOut();
	
	EXPECT_TRUE(result == "100.200.300.400\n");
}



/// \brief Checking the output of the IP address in std::list format
TEST(test_print_ip, print_list)
{
	StdOutReader reader;

	print_ip(std::list<short>{400, 300, 200, 100}); // 400.300.200.100
	auto result = reader.readOut();
	
	EXPECT_TRUE(result == "400.300.200.100\n");
}



/// \brief Checking the output of the IP address in std::tuple format
TEST(test_print_ip, print_tuple)
{
	StdOutReader reader;

	print_ip(std::make_tuple(123, 456, 789, 0)); // 123.456.789.0
	auto result = reader.readOut();
	
	EXPECT_TRUE(result == "123.456.789.0\n");
}



int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
