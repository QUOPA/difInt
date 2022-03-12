#pragma once

#include "difint/ExpressionBase.h"
#include <string>

#define GENERATE_EXPRESSION_UNARY_HAT(OpName)\
template <typename _E>\
class OpName : public _B <OpName<_E>>{\
public:\
	explicit OpName(_E && E) : m_E(E){}//\
	//template <unsigned long long keyin >\
	//static constexpr bool findvar() { return _E::findvar<keyin>();}

#define GENERATE_EXPRESSION_UNARY_SHOE(OpName)\
private:\
	_E m_E; };\
template <typename _E>\
inline decltype(auto) create##OpName(_E&& E) {\
	return OpName<_E>(std::forward<_E>(E));}

namespace di {
template <unsigned long long keystr>
class V;

template <typename T>
class C;

template<typename OtherDerived>
class _B;

GENERATE_EXPRESSION_UNARY_HAT(Neg)
public:
	inline std::string strExpr() const { return "-" + this->fmtparenth(m_E); }
	inline constexpr int precedence() const{ return 2; }
GENERATE_EXPRESSION_UNARY_SHOE(Neg)

GENERATE_EXPRESSION_UNARY_HAT(Ln)
public:
	inline std::string strExpr() const { return "ln" + this->fmtparenth(m_E); }
	inline constexpr int precedence() const { return 11; }
GENERATE_EXPRESSION_UNARY_SHOE(Ln)

}



