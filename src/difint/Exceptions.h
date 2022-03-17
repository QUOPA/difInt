#pragma once

#include <stdexcept>

namespace di
{
	class diException : public std::exception
	{
	public: 
		diException(const std::string & strIn) : std::exception(strIn.c_str()){}
		diException(const char * strIn) : std::exception(strIn) {}
	};

	class diUninitialized : public diException
	{
	public:
		diUninitialized(const std::string& strIn) : diException( strIn.c_str() ) {}
		diUninitialized(const char* strIn) : diException(strIn) {}
	};

}