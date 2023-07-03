/*!
\file
\brief Patch file for correct work of smake

Without this file cmake throws error:
>> CMake Error: CMake can not determine linker language for target: print_ip_lib
This is due to missing of implementation files (*.cpp) in the library
*/
