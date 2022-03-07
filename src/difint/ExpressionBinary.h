#pragma once


#include "difint/ExpressionBase.h"
#include "difint/Variable.h"
#include <string>

#define GENERATE_EXPRESSION_BINARY_HAT(OpName)\
template <typename _L, typename _R>\
class OpName : public _B <OpName<_L, _R>>{\
public:\
	explicit OpName(_L&& L, _R&& R) : m_L(L), m_R(R) {}

#define GENERATE_EXPRESSION_BINARY_SHOE(OpName)\
private:\
	_L m_L; _R m_R; };\
template <typename _L, typename _R>\
inline decltype(auto) create##OpName(_L&& L, _R&& R) {\
	return OpName<_L, _R>(std::forward<_L>(L), std::forward<_R>(R));}


namespace di
{
template <unsigned long long keystr>
class V;

template<typename OtherDerived>
class _B;

GENERATE_EXPRESSION_BINARY_HAT(Exp)
public:	
	inline std::string strExpr() const { return this->fmtparenth(m_L) +"^"+ this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 1; }
GENERATE_EXPRESSION_BINARY_SHOE(Exp)

GENERATE_EXPRESSION_BINARY_HAT(Sum)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "+" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 3; }

	template <typename T, unsigned long long keylhs>
	auto derivative(const V<keylhs>& con) const { return m_L.derivative<T>(con) + m_R.derivative<T>(con); }
GENERATE_EXPRESSION_BINARY_SHOE(Sum)

GENERATE_EXPRESSION_BINARY_HAT(Dif)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "-" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 3; }
GENERATE_EXPRESSION_BINARY_SHOE(Dif)

GENERATE_EXPRESSION_BINARY_HAT(Mul)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "*" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 2; }
GENERATE_EXPRESSION_BINARY_SHOE(Mul)

GENERATE_EXPRESSION_BINARY_HAT(Div)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "/" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 2; }
GENERATE_EXPRESSION_BINARY_SHOE(Div)

}