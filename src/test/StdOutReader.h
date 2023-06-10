#pragma once

#include <sstream>
#include <iostream>



class StdOutReader
{
public:
	StdOutReader();
	~StdOutReader();

	std::string readOut();

private:
	std::ostringstream _oss;
	std::streambuf *_cout_buf{ nullptr };
};