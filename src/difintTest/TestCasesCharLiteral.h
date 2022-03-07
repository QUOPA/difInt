#pragma once

#include "difint/difint.h"
#include "difint/StringLiteral.h"

namespace charliteral
{
	void charliteraltest()
	{
		LiteralKey<LKEY_STR_ENCODER("abc")> abc;

		DEF_STRDEF_VAR(ABCDEFG);
		auto retVal = abc.getString();

		std::cout  << abc.getString() << std::endl;
		std::cout << ABCDEFG.getString() << std::endl;
	}
}
