#pragma once

#include "difint/difint.h"
#include "difint/StringLiteral.h"

//#define MACRO_ENCODE_KEY(c, order)\
//(c >= 48 && c <= 57 ? ((c + 5) << (order * 6))\
//	: (c >= 97 && c <= 122 ? ((c - 96) << (order * 6))\
//		: (c >= 65 && c <= 90 ? ((c - 38) << (order * 6))\
//			: (c == 95 ? (63 << (order * 6)) : 0))));
//
//#define E(L,I) ((I < sizeof(L)) ? (EncodeKey(L[I],I)) : 0)
#define E(L,I) ((I < sizeof(L)) ? (EncodeKey(L[I],I)) : 0)

#define STR(L) \
E(L,0)+E(L,1)+E(L,2)+E(L,3)+E(L,4)+E(L,5)+\
E(L,6)+E(L,7)+E(L,8)+E(L,9)


constexpr unsigned long long EncodeKey(char c, int order)
{
	return c >= 48 && c <= 57 ? ((c + 5) << (order * 6)) 
		: (c >= 97 && c <= 122 ? ((c - 96) << (order * 6))
			:(c >= 65 && c <= 90 ? ((c - 38) << (order * 6))
				: (c == 95 ? (63 << (order * 6)):0) ) );
}

template<unsigned long long a>
struct constexprchecker
{

};

namespace charliteral
{
	void charliteraltest()
	{
		StringLiteral<'a', 'b', 'c', 'd'> a;
		std::cout << a.getLiteral() <<std::endl;

		constexpr auto resultval = STR("___");
		std::cout << resultval << std::endl;
		constexprchecker<resultval> abc;
	}
}
