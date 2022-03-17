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

		auto dx_dx = x.derivative(x);
		std::cout << dx_dx.strExpr() << std::endl;
		auto dx_dxdx = dx_dx.derivative(x);
		std::cout << dx_dxdx.strExpr() << std::endl;
		std::cout << dx_dxdx.derivative(x).strExpr() << std::endl;

		auto dx_dx2 = x.derivative(x2);
		std::cout << dx_dx2.strExpr() << std::endl;

		//auto sumexpr = x + x2 + x3 + Num;
	}

	void basicSumDerivative()
	{
		DIFINT_VAR(C1);
		DIFINT_VAR(C2);

		DIFINT_VAR_4(x, x2, x3, x4);
		di::C<double> Num(3);

		auto sumexpr = x + x2 + x3+ x4;// +Num + x3;
		std::cout << sumexpr.strExpr() << std::endl;
		auto Dsumexpr = sumexpr.derivative(x3);
		std::cout << Dsumexpr.strExpr() << std::endl;
	}

	void basicExpDerivative()
	{
		DIFINT_VAR(C1);
		DIFINT_VAR(C2);

		DIFINT_VAR_4(x, x2, x3, x4);
		di::C<double> Num(3.5);

		auto Expr = x2.e(Num);
		std::cout << Expr.strExpr() << std::endl;
		auto ResExpr = Expr.derivative(x2);
		std::cout << ResExpr.strExpr() << std::endl << std::endl;

		auto Expr2 = Num.e(x2);
		std::cout << Expr2.strExpr() << std::endl;
		auto ResExpr2 = Expr2.derivative(x2);
		std::cout << ResExpr2.strExpr() << std::endl << std::endl;

		auto Expr3 = x2.e(x2);
		std::cout << Expr3.strExpr() << std::endl;
		auto ResExpr3 = Expr3.derivative(x2);
		std::cout << ResExpr3.strExpr() << std::endl << std::endl;


	}

	void basicLogDerivative()
	{
		DIFINT_VAR(C1);
		DIFINT_VAR(C2);

		DIFINT_VAR_4(x, x2, x3, x4);
		di::C<double> Num(3.5);

		auto Expr = fnLog(x2, Num);
		std::cout << Expr.strExpr() << std::endl;
		auto DerExpr = Expr.derivative(x2);
		std::cout << DerExpr.strExpr() << std::endl << std::endl;

		auto Expr2 = fnLog(Num, x2);
		std::cout << Expr2.strExpr() << std::endl;
		auto DerExpr2 = Expr2.derivative(x2);
		std::cout << DerExpr2.strExpr() << std::endl << std::endl;

		auto Expr3 = fnLog(x2, x2);
		std::cout << Expr3.strExpr() << std::endl;
		auto DerExpr3 = Expr3.derivative(x2);
		std::cout << DerExpr3.strExpr() << std::endl << std::endl;
	}

	void basicSubDerivative()
	{
		DIFINT_VAR(C1);
		DIFINT_VAR(C2);

		DIFINT_VAR_4(x, x2, x3, x4);
		di::C<double> Num(3.5);

		auto Expr = x2 - Num;
		std::cout << Expr.strExpr() << std::endl;
		auto DerExpr = Expr.derivative(x2);
		std::cout << DerExpr.strExpr() << std::endl << std::endl;

		auto Expr2 = Num - x2;
		std::cout << Expr2.strExpr() << std::endl;
		auto DerExpr2 = Expr2.derivative(x2);
		std::cout << DerExpr2.strExpr() << std::endl << std::endl;

		auto Expr3 = x2 - x2;
		std::cout << Expr3.strExpr() << std::endl;
		auto DerExpr3 = Expr3.derivative(x2);
		std::cout << DerExpr3.strExpr() << std::endl << std::endl;
	}

	void basicMulDerivative()
	{
		DIFINT_VAR(C1);
		DIFINT_VAR(C2);

		DIFINT_VAR_4(x, x2, x3, x4);
		di::C<double> Num(3.5);

		auto Expr = x2 * Num;
		std::cout << Expr.strExpr() << std::endl;
		auto DerExpr = Expr.derivative(x2);
		std::cout << DerExpr.strExpr() << std::endl << std::endl;

		auto Expr2 = Num * x2;
		std::cout << Expr2.strExpr() << std::endl;
		auto DerExpr2 = Expr2.derivative(x2);
		std::cout << DerExpr2.strExpr() << std::endl << std::endl;

		auto Expr3 = x2 * x2;
		std::cout << Expr3.strExpr() << std::endl;
		auto DerExpr3 = Expr3.derivative(x2);
		std::cout << DerExpr3.strExpr() << std::endl << std::endl;
	}


	void basicDivDerivative()
	{
		DIFINT_VAR(C1);
		DIFINT_VAR(C2);

		DIFINT_VAR_4(x, x2, x3, x4);
		di::C<double> Num(3.5);

		auto Expr = x2/Num;
		std::cout << Expr.strExpr() << std::endl;
		auto DerExpr = Expr.derivative(x2);
		std::cout << DerExpr.strExpr() << std::endl << std::endl;

		auto Expr2 = Num/x2;
		std::cout << Expr2.strExpr() << std::endl;
		auto DerExpr2 = Expr2.derivative(x2);
		std::cout << DerExpr2.strExpr() << std::endl << std::endl;

		auto Expr3 = x2/x2;
		std::cout << Expr3.strExpr() << std::endl;
		auto DerExpr3 = Expr3.derivative(x2);
		std::cout << DerExpr3.strExpr() << std::endl << std::endl;
	}

	void basicUnaryDerivative()
	{
		DIFINT_VAR(C1);
		DIFINT_VAR(C2);

		DIFINT_VAR_4(x, x2, x3, x4);
		di::C<double> Num(3.5);

		auto Expr = -x2;
		std::cout << Expr.strExpr() << std::endl;
		auto DerExpr = Expr.derivative(x2);
		std::cout << DerExpr.strExpr() << std::endl << std::endl;

		auto Expr2 = -Num;
		std::cout << Expr2.strExpr() << std::endl;
		auto DerExpr2 = Expr2.derivative(x2);
		std::cout << DerExpr2.strExpr() << std::endl << std::endl;

		auto Expr3 = fnLn(x2);
		std::cout << Expr3.strExpr() << std::endl;
		auto DerExpr3 = Expr3.derivative(x2);
		std::cout << DerExpr3.strExpr() << std::endl <<std::endl;

		auto Expr4 = fnLn(Num);
		std::cout << Expr4.strExpr() << std::endl;
		auto DerExpr4 = Expr4.derivative(x2);
		std::cout << DerExpr4.strExpr() << std::endl;

	}



}