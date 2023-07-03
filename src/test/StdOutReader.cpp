#include "StdOutReader.h"



StdOutReader::StdOutReader()
{
	_cout_buf = std::cout.rdbuf(); // save origin
	std::cout.rdbuf(_oss.rdbuf()); // replace
}



StdOutReader::~StdOutReader()
{
	std::cout.rdbuf(_cout_buf); // restore
}



std::string StdOutReader::readOut()
{
	if (!_oss)
		return {};

	return _oss.str();
}
