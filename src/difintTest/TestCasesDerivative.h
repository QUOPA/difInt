#pragma once

#include <iostream>
#include "difint/difint.h"

namespace derivativetest
{
	void basicOneVarDerivative()
	{
		DIFINT_VAR(C1);
		DIFINT_VAR(C2);

		DIFINT_VAR_4(x, x2, x3, x4);
		di::C<double> Num(3.5);

		auto dx_dx = x.derivative<double>(x);
		std::cout << dx_dx.strExpr() << std::endl;
		auto dx_dxdx = dx_dx.derivative(x);
		std::cout << dx_dxdx.strExpr() << std::endl;
		std::cout << dx_dxdx.derivative(x).strExpr() << std::endl;

		auto dx_dx2 = x.derivative<double>(x2);
		std::cout << dx_dx2.strExpr() << std::endl;

		//auto sumexpr = x + x2 + x3 + Num;
	}

	void basicSumDerivative()
	{
		DIFINT_VAR(C1);
		DIFINT_VAR(C2);

		DIFINT_VAR_4(x, x2, x3, x4);
		di::C<double> Num(3.5);

		auto sumexpr = x + x2 +Num + x3;
		std::cout << sumexpr.strExpr() << std::endl;
		auto Dsumexpr = sumexpr.derivative<double>(x2);
		std::cout << Dsumexpr.strExpr() << std::endl;

	}

}