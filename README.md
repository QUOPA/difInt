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
A varible is a placeholder to get input value, and devined as follows.
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
A constant object needs type and value.
```c++
di::C<double> Num(3.5);
di::C<double> N1(1);
di::C<double> N2(2);
di::C<double> N3(3);
```
[more examples...](https://github.com/QUOPA/difInt/blob/main/src/difintTest/TestCasesBasicExpression.h)

# Expression
Expressions are generated by arithmetic operations and functions. The expression is made, but not evaluated by actual values.
```c++
DIFINT_VAR_6(C1, C2, x, x2, x3, x4);
auto expr1 = x.e(C1) + ((x + x2 - x3)* C1 * C2.e(x)).e(C1); // expression is generated
std::cout << expr1.strExpr() << std::endl;
auto expr2 = x4.e(expr1);
std::cout << expr2.strExpr() << std::endl;
```
Output Result
```
x^C1+((x+x2-x3)*C1*C2^x)^C1
x4^(x^C1+((x+x2-x3)*C1*C2^x)^C1)
```

# Derivative
Using **derivative** member function, partial derivative can be derived. The derivation is generated by type estimation in compile-time.
```c++
auto expn = C1*x.e(N2) + C2*x2.e(N2) + C3*x3.e(N2);
auto exprTest = C4.e(expn);
std::cout << exprTest.strExpr() << std::endl;
auto derivedExpr = exprTest.derivative<double>(x);
std::cout << derivedExpr.strExpr() << std::endl;
```
Output Result
```
C4^(C1*x^2.000000+C2*x2^2.000000+C3*x3^2.000000)
C4^(C1*x^2.000000+C2*x2^2.000000+C3*x3^2.000000)*C1*2.000000*x^(2.000000-1.000000)*1.000000*lnC4
```
Another example
```c++
auto expn = x.e(x2.e(x3.e(x4.e(x.e(x2.e(x3.e(x4.e(x.e(x)))))))));
std::cout << expn.strExpr() << std::endl;
std::cout << expn.derivative<double>(x).strExpr() << std::endl;
```
Output Result
```
C4^x^x2^x3^x4^x^x2^x3^x4^x^x
C4^x^x2^x3^x4^x^x2^x3^x4^x^x*x^x2^x3^x4^x^x2^x3^x4^x^x*(x2^x3^x4^x^x2^x3^x4^x^x*x3^x4^x^x2^x3^x4^x^x*x4^x^x2^x3^x4^x^x*x^x2^x3^x4^x^x*(x2^x3^x4^x^x*x3^x4^x^x*x4^x^x*x^x*(1.000000*lnx+1.000000*x/x)*lnx4*lnx3*lnx2*lnx+1.000000*x2^x3^x4^x^x/x)*lnx4*lnx3*lnx2*lnx+1.000000*x2^x3^x4^x^x2^x3^x4^x^x/x)*lnC4
```

[more examples on simple derivatives](https://github.com/QUOPA/difInt/blob/main/src/difintTest/TestCasesDerivative.h)

[more examples on complicated derivatives](https://github.com/QUOPA/difInt/blob/main/src/difintTest/TestCasesDerivativeComplicated.h)


# Further Works...
## Generating expression by Variable - Number operations
```c++
auto expn = (x + 2).e(x2)
```
## Expression Reduction
If there is redundant terms, it should be reduced to show cleaner expression. For example
```
x1-x1+x2 -->  x2
2.0000 - 1.0000 --> 1.0000
1.0000 * x1 --> x1
... 
```
## Evaluation by value
Need to define interface and implement it.
## Integration algorithm
Study and implement it
## Number formatting
Double numbers are too long to see.
```
2.53000 --> 2.53 
... 
```
## Change implementation of constant' value to be constexpr.
So that we can exploit the trait depending on the number
