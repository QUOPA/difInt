# difInt
Header-only compile-time template library for representing algebraic expressions, deriving differential and integral of the expression, and evaluating them by values.

# Motivation
An algebraic expression is composition of variables and constants connected with arithmetic operations and functions. 
Before we evaluate expression with values, **the expression is just a representation retaining arithmetic structures among variables and constants**.

These characteristic of algebraic expression well suits with **expression template pattern** in C++ generic coding. 
Using expression template pattern and its relevants, we can construct relations of variables and constants, then evaluate them at exact timing we want.

# How to Use
Download all header files in [(REPOSITORY)/src/difint](https://github.com/QUOPA/difInt/tree/main/src/difint), then include [difint.h](https://github.com/QUOPA/difInt/blob/main/src/difint/difint.h)

# Variables and Constants
* Variables

A varible is a placeholder to get input value, and defined as follows.
```c++
DIFINT_VAR(C2);
DIFINT_VAR_4(x, x2, x3, x4);
std::cout << C2 << ", " << x << ", "  << x2 << ", "  << x3 << ", "  << x4 << std::endl;
```
Output Result
```
C2, x, x2, x3, x4
```
Since variables should be distinguished eachother, each variable has its own constexpr key value in it. The key value is derived by encoding its name (above example :'C2, x, x2, x3, x4'), and when we need the string name, the key value is decoded to string. By this reason, the length of variable name is limited by at most 10 characters.
* Constants

A constant object needs to be initialized by number. The constants can be initialized explicitely as follows.
```c++
di::C<double> Num(3.5);
di::C<double> N1(1);
di::C<double> N2(2);
di::C<double> N3(3);
```
However, there will be few cases of the explicit initialize in a common usage. Rather we can omit the explicit definition of the constants because of the implicit type conversion from default (double compatible) types to constants as follows. 
```c++
auto y = x4 + 3 + x1.e(2);
```
[more examples...](https://github.com/QUOPA/difInt/blob/main/src/difintTest/TestCasesBasicExpression.h)

# Expression
Expressions are generated by arithmetic operations and functions. The expression is made, but not evaluated by actual values.
```c++
DIFINT_VAR_6(C1, C2, x, x2, x3, x4);
auto y1 = x.e(C1) + ((x + x2 - x3)* C1 * C2.e(x)).e(C1); // expression is generated
std::cout << y1 << std::endl;
auto y2 = x4.e(y1);
std::cout << y2 << std::endl;
```
Output Result
```
x^C1+((x+x2-x3)*C1*C2^x)^C1
x4^(x^C1+((x+x2-x3)*C1*C2^x)^C1)
```

# Derivative
Using **derivative** member function, partial derivative can be derived. The derivation is generated by type estimation in compile-time. 
* An example
```c++
DIFINT_VAR_4(x1, x2, x3, x4);
auto y = 2 * x1.e(2) + 3 * x2.e(2) + 4 * x3.e(2);
std::cout << y.derivative(x1) << std::endl;
std::cout << y.derivative(x2) << std::endl;
std::cout << y.derivative(x3) << std::endl;
std::cout << y.derivative(x4) << std::endl;
```
Output Result
```
2.000000*2.000000*x1^(2.000000-1.000000)*1.000000
3.000000*2.000000*x2^(2.000000-1.000000)*1.000000
4.000000*2.000000*x3^(2.000000-1.000000)*1.000000
0.000000
```
The Result is dirty, we need reduction ...

* Another example
```c++
auto expn = x.e(x2.e(x3.e(x4.e(x.e(x2.e(x3.e(x4.e(x.e(x)))))))));
std::cout << expn << std::endl;
std::cout << expn.derivative(x) << std::endl;
```
Output Result
```
C4^x^x2^x3^x4^x^x2^x3^x4^x^x
C4^x^x2^x3^x4^x^x2^x3^x4^x^x*x^x2^x3^x4^x^x2^x3^x4^x^x*(x2^x3^x4^x^x2^x3^x4^x^x*x3^x4^x^x2^x3^x4^x^x*x4^x^x2^x3^x4^x^x*x^x2^x3^x4^x^x*(x2^x3^x4^x^x*x3^x4^x^x*x4^x^x*x^x*(1.000000*lnx+1.000000*x/x)*lnx4*lnx3*lnx2*lnx+1.000000*x2^x3^x4^x^x/x)*lnx4*lnx3*lnx2*lnx+1.000000*x2^x3^x4^x^x2^x3^x4^x^x/x)*lnC4
```

[more examples on simple derivatives](https://github.com/QUOPA/difInt/blob/main/src/difintTest/TestCasesDerivative.h)

[more examples on complicated derivatives](https://github.com/QUOPA/difInt/blob/main/src/difintTest/TestCasesDerivativeComplicated.h)

# Evaluation
By input the numeric values into variables, we can evaluate the expression. Inputing values to variables and evaluation of expression is runtime features.
* Evaluation Example
```c++
DIFINT_VAR(x);
auto y1 = x + 3;
auto y2 = 3 - x;
auto y3 = 3 * x;

x = 4;

std::cout << y1.eval() << std::endl;
std::cout << y2.eval() << std::endl;
std::cout << y3.eval() << std::endl;
```
Output Result
```
7
-1
12
```
* Evaluation Exception Example
When there is at least one variables which are not input with numeric value, the expression cannot be evaluated, then throw except. 
```c++
DIFINT_VAR_2(x, x2);
auto y4 = 3 / x + x2;
x = 4;
double resultVal =  y3.eval(); //throw exception
```
Output Result (need to be decorated)
```
Exception : x2
```
* Plotting Graph Example
```c++
DIFINT_VAR(x);
auto y = x.e(2);
for (int idx = 0; idx < 100; ++idx)
{
    x = idx / 10.0;
    std::cout << "(" << x.eval() << "," <<  y.eval() << "," << y.derivative(x).eval() << ")" << std::endl;
}
```
Output Result
```
(0,0,0)
(0.1,0.01,0.2)
(0.2,0.04,0.4)
(0.3,0.09,0.6)
(0.4,0.16,0.8)
(0.5,0.25,1)
...
(9.5,90.25,19)
(9.6,92.16,19.2)
(9.7,94.09,19.4)
(9.8,96.04,19.6)
(9.9,98.01,19.8)
```

# Further Works...
Moved to Issues.
