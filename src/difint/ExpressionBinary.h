#pragma once


#include "difint/ExpressionBase.h"
#include "difint/Variable.h"
#include "difint/Constant.h"
#include <string>

#define GENERATE_EXPRESSION_BINARY_HAT(OpName)\
template <typename _L, typename _R>\
class OpName : public _B <OpName<_L, _R>>{\
public:\
	explicit OpName(_L&& L, _R&& R) : m_L(L), m_R(R) {}

#define GENERATE_EXPRESSION_BINARY_SHOE(OpName)\
private:\
	_L m_L; _R m_R; };\
template <typename _L, typename _R> \
inline decltype(auto) create##OpName (_L&& L, _R&& R) {\
	return OpName<_L, _R>(std::forward<_L>(L), std::forward<_R>(R));} \



namespace di
{
template <unsigned long long keystr>
class V;

template <typename T>
class C;

template<typename OtherDerived>
class _B;

//template <typename T, typename _L, typename _R, unsigned long long keylhs>
//inline decltype(auto) createExpDerivative(_L L, _R R, const V<keylhs>& con);

template <typename T, typename _L, unsigned long long keylhs>
inline decltype(auto) createExpDerivative(_L L, const C<T> & R, const V<keylhs>& con) {
	return R * L.e( C<T> ( R.val()-1 ) );
}

// need to implement log first
//template <typename T, typename _R, unsigned long long keylhs>
//inline decltype(auto) createExpDerivative(const C<T>& L, _R R, const V<keylhs>& con) {
//	return L.e(C<T>(R.val() - 1));
//}


GENERATE_EXPRESSION_BINARY_HAT(Exp)
public:	
	inline std::string strExpr() const { return this->fmtparenth(m_L) +"^"+ this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 1; }

	template <typename T, unsigned long long keylhs>
	auto derivative(const V<keylhs>& con) const { return createExpDerivative<T>(m_L, m_R, con); }
GENERATE_EXPRESSION_BINARY_SHOE(Exp)


template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createSumDerivative(_L L, _R R, const V<keylhs>& con) {
	return L.derivative<T>(con) + R.derivative<T>(con);
}

GENERATE_EXPRESSION_BINARY_HAT(Sum)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "+" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 3; }

	template <typename T, unsigned long long keylhs>
	auto derivative(const V<keylhs>& con) const { return createSumDerivative<T>(m_L, m_R, con) ; }
GENERATE_EXPRESSION_BINARY_SHOE(Sum)

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createDifDerivative(_L L, _R R, const V<keylhs>& con) {
	return L.derivative<T>(con) - R.derivative<T>(con);
}

GENERATE_EXPRESSION_BINARY_HAT(Dif)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "-" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 3; }

	template <typename T, unsigned long long keylhs>
	auto derivative(const V<keylhs>& con) const { return m_L.derivative<T>(con) - m_R.derivative<T>(con); }
GENERATE_EXPRESSION_BINARY_SHOE(Dif)

GENERATE_EXPRESSION_BINARY_HAT(Mul)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "*" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 2; }

	template <typename T, unsigned long long keylhs>
	auto derivative(const V<keylhs>& con) const { return m_L.derivative<T>(con)*m_R + m_L*m_R.derivative<T>(con); }
GENERATE_EXPRESSION_BINARY_SHOE(Mul)

GENERATE_EXPRESSION_BINARY_HAT(Div)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "/" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 2; }
GENERATE_EXPRESSION_BINARY_SHOE(Div)

}



