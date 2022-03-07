#pragma once

#include <iostream>
#include <algorithm>
#include <array>

//#define MACRO_ENCODE_KEY(c, order)\
//(c >= 48 && c <= 57 ? ((c + 5) << (order * 6))\
//	: (c >= 97 && c <= 122 ? ((c - 96) << (order * 6))\
//		: (c >= 65 && c <= 90 ? ((c - 38) << (order * 6))\
//			: (c == 95 ? (63 << (order * 6)) : 0))));
//
//#define E(L,I) ((I < sizeof(L)) ? (EncodeKey(L[I],I)) : 0)

#define E(L,I) ((I < sizeof(L)) ? (EncodeKey(L[I],I)) : 0UL)

#define STR(L) \
E(L,0)+E(L,1)+E(L,2)+E(L,3)+E(L,4)+E(L,5)+\
E(L,6)+E(L,7)+E(L,8)+E(L,9)

#define DEF_STR_LITERAL(VARNAME) constexprchecker<STR(#VARNAME)> VARNAME;

constexpr unsigned long long EncodeKey(char c, int order)
{
	return c >= 48 && c <= 57 ? (static_cast<unsigned long long>(c + 5) << (order * 6))
		: (c >= 97 && c <= 122 ? (static_cast<unsigned long long>(c - 96) << (order * 6))
			: (c >= 65 && c <= 90 ? (static_cast<unsigned long long>(c - 38) << (order * 6))
				: (c == 95 ? (static_cast < unsigned long long>(63) << (order * 6)) : 0UL)));
}

template <unsigned long long strKey>
std::string DecodeKey()
{
	unsigned long long CurrKey = strKey;
	std::string retStr;
	while (CurrKey)
	{
		char inspectval = CurrKey & 63;
		if (inspectval >= 1 && inspectval <= 26)
			retStr += static_cast<char>(inspectval + 96);
		else if (inspectval >= 27 && inspectval <= 52)
			retStr += static_cast<char>(inspectval + 38);
		else if (inspectval >= 53 && inspectval <= 62)
			retStr += static_cast<char>(inspectval - 5);
		else if (inspectval == 63)
			retStr += '_';
		CurrKey >>= 6;
	}
	return retStr;

}


template<unsigned long long a>
struct constexprchecker
{
	std::string getString() { return DecodeKey<a>(); }
};


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



