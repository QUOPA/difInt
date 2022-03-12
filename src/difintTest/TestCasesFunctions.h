#pragma once

#include "difint/difint.h"

namespace functiontests
{	
void basicFunctionExpression()
{
	DIFINT_VAR(C1);
	DIFINT_VAR(C2);

	DIFINT_VAR_4(x, x2, x3, x4);
	di::C<double> Num(3.5);

	auto LogExpr = di::fnLog(x2, Num);
	std::cout << LogExpr.strExpr() << std::endl;
	auto LnExpr = di::fnLn(Num);
	std::cout << LnExpr.strExpr() << std::endl;
}



}