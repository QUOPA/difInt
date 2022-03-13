#pragma once

#include "TestCasesBasicExpression.h"
#include "TestCasesCharLiteral.h"
#include "TestCasesDerivative.h"
#include "TestCasesFunctions.h"
#include "TestCasesDerivativeComplicated.h"

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
		REGISTERTESTCASE(basicLogDerivative)
		REGISTERTESTCASE(basicSubDerivative)
		REGISTERTESTCASE(basicDivDerivative)
		REGISTERTESTCASE(basicUnaryDerivative)
	}
}

namespace functiontests
{
	void TestSuite()
	{
		REGISTERTESTCASE(basicFunctionExpression)
	}

}


namespace derivativecomplicated
{
	void TestSuite()
	{
		REGISTERTESTCASE(complicatedExpr1)
		REGISTERTESTCASE(complicatedExpr2)
	}

}