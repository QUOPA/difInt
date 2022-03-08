#pragma once

#include "TestCasesBasicExpression.h"
#include "TestCasesCharLiteral.h"
#include "TestCasesDerivative.h"

#include "testcommon/testmacros.h"

namespace basicexpression 
{
	void TestSuite()
	{
		REGISTERTESTCASE(basicBinaryExpression)
		REGISTERTESTCASE(ComplexBinaryExpression)
		REGISTERTESTCASE(ComplexExpressionsWithParenthesis)
		REGISTERTESTCASE(ComplexExpressionsWithConstants)
	}
}

namespace charliteral
{
	void TestSuite()
	{
		REGISTERTESTCASE(charliteraltest)
		
	}

}

namespace derivativetest
{
	void TestSuite()
	{
		REGISTERTESTCASE(basicOneVarDerivative)
		REGISTERTESTCASE(basicSumDerivative)
		REGISTERTESTCASE(basicExpDerivative)
	}
}