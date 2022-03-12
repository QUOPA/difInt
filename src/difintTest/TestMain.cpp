
#include "TestSuite.h"


int main()
{
	REGISTERTESTSUITE(basicexpression)
	REGISTERTESTSUITE(charliteral)
	REGISTERTESTSUITE(derivativetest)
	REGISTERTESTSUITE(functiontests)


	char Buff[256];
	std::cin.getline(Buff, 256);

	return 0;
}