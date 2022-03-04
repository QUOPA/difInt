#pragma once

#include "difint/difint.h"

namespace basicexpression 
{
	void basicBinaryExpression()
	{
		DIFINT_CONST(C1);
		DIFINT_VAR(x);

		auto expexpr = x.e(C1);
		std::cout << expexpr.strExpr() << std::endl;
	}

	void ComplexBinaryExpression()
	{
		DIFINT_CONST(C1);
		DIFINT_CONST(C2);

		DIFINT_VAR(x);
		DIFINT_VAR(x2);
		DIFINT_VAR(x3);
		DIFINT_VAR(x4);
		

		auto expexpr = x.e(C1) + x + x2 - x3 * C1 * C2.e(x);
		std::cout << expexpr.strExpr() << std::endl;
	}


	void ComplexExpressionsWithParenthesis()
	{
		DIFINT_CONST(C1);
		DIFINT_CONST(C2);

		DIFINT_VAR(x);
		DIFINT_VAR(x2);
		DIFINT_VAR(x3);
		DIFINT_VAR(x4);

		auto expexpr = x.e(C1) + ((x + x2 - x3)* C1 * C2.e(x)).e(C1);
		std::cout << expexpr.strExpr() << std::endl;
	}

}