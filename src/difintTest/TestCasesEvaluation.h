#pragma once


namespace evaluationtest
{
	void evaluationbasic()
	{
		DIFINT_VAR_4(x, x2, x3, x4);

		auto y1 = x + 3;
		auto y2 = 3 - x;
		auto y3 = 3 * x;
		auto y4 = 3 / x;
		
		//std::cout << ScalarSum.eval() << std::endl;
		//std::cout << ScalarSum2.eval() << std::endl;

		x = 4;

		std::cout << y1.eval() << std::endl;
		std::cout << y2.eval() << std::endl;
		std::cout << y3.eval() << std::endl;
		std::cout << y4.eval() << std::endl;

	}

	void evaluationexception()
	{
		DIFINT_VAR_4(x, x2, x3, x4);

		auto y1 = x + 3;
		auto y2 = 3 - x;
		auto y3 = 3 * x;
		auto y4 = 3 / x + x2;

		//std::cout << ScalarSum.eval() << std::endl;
		//std::cout << ScalarSum2.eval() << std::endl;

		x = 4;

		std::cout << y1.eval() << std::endl;
		std::cout << y2.eval() << std::endl;
		std::cout << y3.eval() << std::endl;
		std::cout << y4.eval() << std::endl;

	}


	void evaluationcomplicated()
	{

		DIFINT_VAR_4(x, x2, x3, x4);

		auto expn = x.e(x2.e(x3.e(x4.e(x.e(x2.e(x3.e(x4.e(x.e(x)))))))));
		
		x = 2;
		x2 = 1.03;
		x3 = 1.03;
		x4 = 1.03;

		std::cout << expn.eval() << std::endl;

	}

	void evaluationfunctiongraph()
	{
		DIFINT_VAR_4(x, x2, x3, x4);
		
		auto y = x.e(2);

		for (int idx = 0; idx < 100; ++idx)
		{
			x = idx / 10.0;
			std::cout << "(" << x.eval() << "," <<  y.eval() << "," << y.derivative(x).eval() << ")" << std::endl;
		}
		
	}

}