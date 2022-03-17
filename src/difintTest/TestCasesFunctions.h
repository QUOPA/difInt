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

void scalarvariableExpression()
{

	DIFINT_VAR(C1);
	DIFINT_VAR(C2);

	DIFINT_VAR_4(x, x2, x3, x4);

	auto ScalarSum = x + 3;
	auto ScalarSum2 = 3 + x;
	std::cout << ScalarSum.strExpr() << std::endl;
	std::cout << ScalarSum2.strExpr() << std::endl;

	auto ScalarDif1 = x - 3;
	auto ScalarDif2 = 3 - x;

	std::cout << ScalarDif1.strExpr() << std::endl;
	std::cout << ScalarDif2.strExpr() << std::endl;

	auto ScalarDiv1 = x / 3;
	auto ScalarDiv2 = 3 / x;

	std::cout << ScalarDiv1.strExpr() << std::endl;
	std::cout << ScalarDiv2.strExpr() << std::endl;

	auto ScalarMul1 = x * 3;
	auto ScalarMul2 = 3 * x;

	std::cout << ScalarMul1 << std::endl;
	std::cout << ScalarMul2 << std::endl;
}




}