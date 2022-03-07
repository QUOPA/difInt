#pragma once

#include "difint/difint.h"
#include "difint/StringLiteral.h"




namespace charliteral
{
	void charliteraltest()
	{
		StringLiteral<'a', 'b', 'c', 'd'> a;
		std::cout << a.getLiteral() <<std::endl;

		constexpr auto resultval = STR("_as__");
		std::cout << resultval << std::endl;
		constexprchecker<resultval> abc;


		DEF_STR_LITERAL(ABCDEFG);
		auto retVal = abc.getString();

		std::cout  << abc.getString() << std::endl;
		std::cout << ABCDEFG.getString() << std::endl;
	}
}
