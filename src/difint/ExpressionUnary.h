#pragma once

#include "difint/ExpressionBase.h"
#include "difint/BooleanTemplate.h"
#include "difint/Constant.h"
#include <string>

#define GENERATE_EXPRESSION_UNARY_HAT(OpName)\
template <typename _E>\
class OpName : public _B <OpName<_E>>{\
public:\
	explicit OpName(_E && E) : m_E(E){} \
	template<unsigned long long keyIn> \
	constexpr auto findvar() const { return m_E.findvar<keyIn>(); }

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

template <typename T>
class C0;

template <typename T>
class C1;

template<typename OtherDerived>
class _B;

class Unexpected;

template <typename T, typename EBOOL, typename _E, unsigned long long keylhs>
inline decltype(auto) createNegDerivative(EBOOL eIn, _E E, const V<keylhs>& con) {
	return Unexpected();
}

template <typename T, typename _E, unsigned long long keylhs>
inline decltype(auto) createNegDerivative(_TRUE eIn, _E E, const V<keylhs>& con) {
	return -E.derivative<T>(con);
}

template <typename T, typename _E, unsigned long long keylhs>
inline decltype(auto) createNegDerivative(_FALSE eIn, _E E, const V<keylhs>& con) {
	return C0<T>();
}

template <typename T, typename EBOOL, typename _E, unsigned long long keylhs>
inline decltype(auto) createLnDerivative(EBOOL eIn, _E E, const V<keylhs>& con) {
	return Unexpected();
}

template <typename T, typename _E, unsigned long long keylhs>
inline decltype(auto) createLnDerivative(_TRUE eIn, _E E, const V<keylhs>& con) {
	return E.derivative<T>(con)/E;
}

template <typename T, typename _E, unsigned long long keylhs>
inline decltype(auto) createLnDerivative(_FALSE eIn, _E E, const V<keylhs>& con) {
	return C0<T>();
}


GENERATE_EXPRESSION_UNARY_HAT(Neg)
public:
	inline std::string strExpr() const { return "-" + this->fmtparenth(m_E); }
	inline constexpr int precedence() const{ return 21; }

	template <typename T, unsigned long long keyIn>
	auto derivative(const V<keyIn>& con) const {
		return createNegDerivative<T>(m_E.findvar<keyIn>(), m_E, con);
	}

GENERATE_EXPRESSION_UNARY_SHOE(Neg)

GENERATE_EXPRESSION_UNARY_HAT(Ln)
public:
	inline std::string strExpr() const { return "ln" + this->fmtparenth(m_E); }
	inline constexpr int precedence() const { return 11; }

	template <typename T, unsigned long long keyIn>
	auto derivative(const V<keyIn>& con) const {
		return createLnDerivative<T>(m_E.findvar<keyIn>(),m_E, con);
	}
GENERATE_EXPRESSION_UNARY_SHOE(Ln)

}



