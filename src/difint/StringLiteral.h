#pragma once

#include <iostream>
#include <algorithm>
#include <array>

template<char...>
class StringLiteral;

template<>
struct StringLiteral<>
{
	StringLiteral() {}

	static std::string getLiteral() { return std::string(); }
};

template <char firstchar, char... charelem>
class StringLiteral<firstchar, charelem...>
{
public:
	StringLiteral() {}

	static std::string getLiteral() { return firstchar + StringLiteral<charelem...>::getLiteral(); }
};



