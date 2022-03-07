#pragma once

#include "difint/difint.h"

namespace basicexpression 
{
	void basicBinaryExpression()
	{
		DIFINT_VAR(C1);
		DIFINT_VAR(x);

		auto expexpr = x.e(C1);
		std::cout << expexpr.strExpr() << std::endl;
	}

	void ComplexBinaryExpression()
	{
		DIFINT_VAR(C1);
		DIFINT_VAR(C2);

		DIFINT_VAR(x);
		DIFINT_VAR(x2);
		DIFINT_VAR(x3);
		DIFINT_VAR(x4);
		
		auto expexpr = x.e(C1) + x + x2 - x3 * C1 * C2.e(x);
		std::cout << expexpr.strExpr() << std::endl;

		DIFINT_VAR_2(a,b);
		std::cout << a.strExpr() << std::endl;
	}


	void ComplexExpressionsWithParenthesis()
	{
		DIFINT_VAR(C1);
		DIFINT_VAR(C2);

		DIFINT_VAR(x);
		DIFINT_VAR(x2);
		DIFINT_VAR(x3);
		DIFINT_VAR(x4);

		auto expexpr = x.e(C1) + ((x + x2 - x3)* C1 * C2.e(x)).e(C1);
		std::cout << expexpr.strExpr() << std::endl;
	}

	void ComplexExpressionsWithConstants()
	{
		DIFINT_VAR(C1);
		DIFINT_VAR(C2);

		DIFINT_VAR_4(x, x2, x3, x4);
		di::C<double> Num(3.5);

		auto expexpr = x.e(C1) + (Num*(x + x2 - x3+ Num) * C1 * C2.e(x* Num)).e(C1);
		std::cout << expexpr.strExpr() << std::endl;
	}
}