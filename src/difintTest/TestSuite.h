#pragma once

#include "TestCasesBasicExpression.h"
#include "testcommon/testmacros.h"

namespace basicexpression 
{
	void TestSuite()
	{
		REGISTERTESTCASE(basicBinaryExpression)
		REGISTERTESTCASE(ComplexBinaryExpression)
	}

}
