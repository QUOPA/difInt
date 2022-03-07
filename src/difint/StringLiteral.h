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
//#define LKEY_DIGIT_ENCODER(L,I) ((I < sizeof(L)) ? (EncodeKey(L[I],I)) : 0)

#define LKEY_DIGIT_ENCODER(L,I) ((I < sizeof(L)) ? (EncodeKey(L[I],I)) : 0UL)

#define LKEY_STR_ENCODER(L)\
LKEY_DIGIT_ENCODER(L,0)+LKEY_DIGIT_ENCODER(L,1)+\
LKEY_DIGIT_ENCODER(L,2)+LKEY_DIGIT_ENCODER(L,3)+\
LKEY_DIGIT_ENCODER(L,4)+LKEY_DIGIT_ENCODER(L,5)+\
LKEY_DIGIT_ENCODER(L,6)+LKEY_DIGIT_ENCODER(L,7)+\
LKEY_DIGIT_ENCODER(L,8)+LKEY_DIGIT_ENCODER(L,9)

#define DEF_STRDEF_VAR(VARNAME) LiteralKey<LKEY_STR_ENCODER(#VARNAME)> VARNAME;

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
struct LiteralKey
{
	std::string getString() const { return DecodeKey<a>(); }
};

