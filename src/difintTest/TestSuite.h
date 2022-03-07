#pragma once

#include "TestCasesBasicExpression.h"
#include "TestCasesCharLiteral.h"
#include "testcommon/testmacros.h"

namespace basicexpression 
{
	void TestSuite()
	{
		REGISTERTESTCASE(basicBinaryExpression)
		REGISTERTESTCASE(ComplexBinaryExpression)
		REGISTERTESTCASE(ComplexExpressionsWithParenthesis)
	}
}



namespace charliteral
{
	void TestSuite()
	{
		REGISTERTESTCASE(charliteraltest)
	}

}