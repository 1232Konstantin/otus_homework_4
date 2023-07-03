/*!
\file
\brief StdOutReader class header file

This file contains the definition of the StdOutReader class used to intercept messages sent 
to standard output.
*/

#pragma once

#include <sstream>
#include <iostream>



/*!
	\brief Class for intercepting the standard output stream
	\author dilog
	\version 1.0
	\date 2023.06.11
	\warning This class can only be instantiated once

	When an instance of this class is created, the standard output stream buffer is replaced. 
	When the object is destroyed, the standard buffer is returned. The information printed to 
	the standard output stream can be considered as the readOut function.
*/
class StdOutReader
{
public:
	StdOutReader();
	~StdOutReader();

	/// \brief Get printed text
	/// \details Reads the text output to the dummy buffer
	/// \return text of messages sent to standard output
	std::string readOut();

private:
	std::ostringstream _oss;
	std::streambuf *_cout_buf{ nullptr };
};