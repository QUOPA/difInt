#pragma once

#include <iostream>
#include "difint/difint.h"

namespace derivativecomplicated
{
	void complicatedExpr1()
	{
		DIFINT_VAR(C1);
		DIFINT_VAR(C2);
		DIFINT_VAR(C3);
		DIFINT_VAR(C4);

		DIFINT_VAR_4(x, x2, x3, x4);
		di::C<double> Num(3.5);
		
		di::C<double> N1(1);
		di::C<double> N2(2);
		di::C<double> N3(3);
		
		auto expn = C1*x.e(N2) + C2*x2.e(N2) + C3*x3.e(N2);

		auto exprTest = C4.e(expn);
		std::cout << exprTest.strExpr() << std::endl;
		auto derivedExpr = exprTest.derivative<double>(x);
		std::cout << derivedExpr.strExpr() << std::endl;

	}


	void complicatedExpr2()
	{
		DIFINT_VAR(C1);
		DIFINT_VAR(C2);
		DIFINT_VAR(C3);
		DIFINT_VAR(C4);

		DIFINT_VAR_4(x, x2, x3, x4);
		di::C<double> Num(3.5);

		di::C<double> N1(1);
		di::C<double> N2(2);
		di::C<double> N3(3);

		auto expn = x.e(x2.e(x3.e(x4.e(x.e(x2.e(x3.e(x4.e(x.e(x)))))))));

		auto exprTest = C4.e(expn);
		std::cout << exprTest.strExpr() << std::endl;
		auto derivedExpr = exprTest.derivative<double>(x);
		std::cout << derivedExpr.strExpr() << std::endl;

		auto expn2 = x.e(x2.e(x3));
		std::cout << expn2.strExpr() << std::endl;
		
		auto derivedExprx = expn2.derivative<double>(x);
		auto derivedExprx2 = expn2.derivative<double>(x2);
		auto derivedExprx3 = expn2.derivative<double>(x3);
		
		std::cout << derivedExprx.strExpr() << std::endl;
		std::cout << derivedExprx2.strExpr() << std::endl;
		std::cout << derivedExprx3.strExpr() << std::endl;
	}

}