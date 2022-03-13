#pragma once


#include "difint/Unexpected.h"
#include "difint/ExpressionBase.h"
#include "difint/Variable.h"
#include "difint/Constant.h"
#include "difint/Functions.h"
#include "difint/BooleanTemplate.h"
#include <string>


#define GENERATE_EXPRESSION_BINARY_HAT(OpName)\
template <typename _L, typename _R>\
class OpName : public _B <OpName<_L, _R>>{\
public:\
	explicit OpName(_L&& L, _R&& R) : m_L(L), m_R(R) {} \
	template<unsigned long long keyIn>\
	constexpr auto findvar() const { return BoolORFunc(m_L.findvar<keyIn>(), m_R.findvar<keyIn>()); }

#define GENERATE_EXPRESSION_BINARY_SHOE(OpName)\
private:\
	_L m_L; _R m_R; };\
template <typename _L, typename _R> \
inline decltype(auto) create##OpName (_L&& L, _R&& R) {\
	return OpName<_L, _R>(std::forward<_L>(L), std::forward<_R>(R));} 
//return OpName<_L, _R>(std::forward<_L>(L), std::forward<_R>(R));} 



namespace di
{
template <unsigned long long keystr>
class V;

template <typename T>
class C;

template<typename T>
struct C1;

template<typename T>
struct C0;

class Unexpected;

template<typename OtherDerived>
class _B;


// Exp 
template <typename T, typename LBOOL, typename RBOOL, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createExpDerivative(LBOOL lIn, RBOOL rIn, _L L, _R R, const V<keylhs>& var) {
	return Unexpected();
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createExpDerivative(_TRUE lIn, _TRUE rIn, _L L, _R R, const V<keylhs>& var) {
	return L.e(R) * (R.derivative<T>(var) * fnLn(L) + L.derivative<T>(var) * R / L);
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createExpDerivative(_TRUE lIn, _FALSE rIn, _L L, _R R, const V<keylhs>& var) {
	return R * L.e(R - C1<T>()) * L.derivative<T>(var);
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createExpDerivative(_FALSE lIn, _TRUE rIn, _L L, _R R, const V<keylhs>& var) {
	return L.e(R) * R.derivative<T>(var) * fnLn(L);
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createExpDerivative(_FALSE lIn, _FALSE rIn, _L L, _R R, const V<keylhs>& con) {
	return C0<T>();
}

// Sum
template <typename T, typename LBOOL, typename RBOOL, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createSumDerivative(LBOOL lIn, RBOOL rIn, _L L, _R R, const V<keylhs>& con) {
	return Unexpected();
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createSumDerivative(_TRUE lIn, _TRUE rIn, _L L, _R R, const V<keylhs>& con) {
	return L.derivative<T>(con) + R.derivative<T>(con);
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createSumDerivative(_TRUE lIn, _FALSE rIn, _L L, _R R, const V<keylhs>& con) {
	return L.derivative<T>(con);
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createSumDerivative(_FALSE lIn, _TRUE rIn, _L L, _R R, const V<keylhs>& con) {
	return R.derivative<T>(con);
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createSumDerivative(_FALSE lIn, _FALSE rIn, _L L, _R R, const V<keylhs>& con) {
	return C0<T>();
}

// Dif
template <typename T, typename LBOOL, typename RBOOL, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createDifDerivative(LBOOL lIn, RBOOL rIn, _L L, _R R, const V<keylhs>& con) {
	return Unexpected();
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createDifDerivative(_TRUE lIn, _TRUE rIn, _L L, _R R, const V<keylhs>& con) {
	return L.derivative<T>(con) - R.derivative<T>(con);
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createDifDerivative(_TRUE lIn, _FALSE rIn, _L L, _R R, const V<keylhs>& con) {
	return L.derivative<T>(con);
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createDifDerivative(_FALSE lIn, _TRUE rIn, _L L, _R R, const V<keylhs>& con) {
	return -R.derivative<T>(con);
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createDifDerivative(_FALSE lIn, _FALSE rIn, _L L, _R R, const V<keylhs>& con) {
	return C0<T>();
}

// Mul
template <typename T, typename LBOOL, typename RBOOL, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createMulDerivative(LBOOL lIn, RBOOL rIn, _L L, _R R, const V<keylhs>& con) {
	return Unexpected();
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createMulDerivative(_TRUE lIn, _TRUE rIn, _L L, _R R, const V<keylhs>& con) {
	return L.derivative<T>(con) * R + L * R.derivative<T>(con);
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createMulDerivative(_TRUE lIn, _FALSE rIn, _L L, _R R, const V<keylhs>& con) {
	return L.derivative<T>(con) * R;
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createMulDerivative(_FALSE lIn, _TRUE rIn, _L L, _R R, const V<keylhs>& con) {
	return L * R.derivative<T>(con);
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createMulDerivative(_FALSE lIn, _FALSE rIn, _L L, _R R, const V<keylhs>& con) {
	return C0<T>();
}

// Div
template <typename T, typename LBOOL, typename RBOOL, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createDivDerivative(LBOOL lIn, RBOOL rIn, _L L, _R R, const V<keylhs>& con) {
	return Unexpected();
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createDivDerivative(_TRUE lIn, _TRUE rIn, _L L, _R R, const V<keylhs>& con) {
	return L.derivative<T>(con)/R - L * R.derivative<T>(con)*R.e(C<T>(-2));
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createDivDerivative(_TRUE lIn, _FALSE rIn, _L L, _R R, const V<keylhs>& con) {
	return L.derivative<T>(con)/R;
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createDivDerivative(_FALSE lIn, _TRUE rIn, _L L, _R R, const V<keylhs>& con) {
	return -L * R.derivative<T>(con) * R.e(C<T>(-2));
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createDivDerivative(_FALSE lIn, _FALSE rIn, _L L, _R R, const V<keylhs>& con) {
	return C0<T>();
}


// Log
template <typename T, typename LBOOL, typename RBOOL, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createLogDerivative(LBOOL lIn, RBOOL rIn, _L L, _R R, const V<keylhs>& con) {
	return Unexpected();
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createLogDerivative(_TRUE lIn, _TRUE rIn, _L L, _R R, const V<keylhs>& con) {
	return R.derivative<T>(con) / (R * fnLn(L)) - L.derivative<T>(con) / (L * fnLn(L)) * fnLog(L, R);
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createLogDerivative(_TRUE lIn, _FALSE rIn, _L L, _R R, const V<keylhs>& con) {
	return -L.derivative<T>(con) / (L * fnLn(L)) * fnLog(L, R);
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createLogDerivative(_FALSE lIn, _TRUE rIn, _L L, _R R, const V<keylhs>& con) {
	return R.derivative<T>(con) / (R * fnLn(L));
}

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createLogDerivative(_FALSE lIn, _FALSE rIn, _L L, _R R, const V<keylhs>& con) {
	return C0<T>();
}

GENERATE_EXPRESSION_BINARY_HAT(Exp)
public:	
	inline std::string strExpr() const { return this->fmtparenth(m_L) +"^"+ this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 10; }

	template <typename T, unsigned long long keyIn>
	auto derivative(const V<keyIn>& con) const {
		return createExpDerivative<T>(m_L.findvar<keyIn>(), m_R.findvar<keyIn>(), m_L, m_R, con); 
	}

GENERATE_EXPRESSION_BINARY_SHOE(Exp)


GENERATE_EXPRESSION_BINARY_HAT(Sum)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "+" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 30; }

	template <typename T, unsigned long long keyIn>
	auto derivative(const V<keyIn>& var) const {
		return createSumDerivative<T>(m_L.findvar<keyIn>(), m_R.findvar<keyIn>(), m_L, m_R, var);
	}

GENERATE_EXPRESSION_BINARY_SHOE(Sum)


GENERATE_EXPRESSION_BINARY_HAT(Dif)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "-" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 30; }

	template <typename T, unsigned long long keyIn>
		auto derivative(const V<keyIn>& con) const {
		return createDifDerivative<T>(m_L.findvar<keyIn>(), m_R.findvar<keyIn>(), m_L, m_R, con);
	}

GENERATE_EXPRESSION_BINARY_SHOE(Dif)

GENERATE_EXPRESSION_BINARY_HAT(Mul)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "*" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 20; }

	template <typename T, unsigned long long keyIn>
	auto derivative(const V<keyIn>& con) const {
		return createMulDerivative<T>(m_L.findvar<keyIn>(), m_R.findvar<keyIn>(), m_L, m_R, con);
	}
GENERATE_EXPRESSION_BINARY_SHOE(Mul)

GENERATE_EXPRESSION_BINARY_HAT(Div)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "/" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 20; }
	
	template <typename T, unsigned long long keyIn>
	auto derivative(const V<keyIn>& con) const {
		return createDivDerivative<T>(m_L.findvar<keyIn>(), m_R.findvar<keyIn>(), m_L, m_R, con);
	}

GENERATE_EXPRESSION_BINARY_SHOE(Div)


GENERATE_EXPRESSION_BINARY_HAT(Log)
public:
	inline std::string strExpr() const { return "log_" + this->fmtparenth(m_L) + "_" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const { return 11; }

	template <typename T, unsigned long long keyIn>
	auto derivative(const V<keyIn>& con) const {
		return createLogDerivative<T>(m_L.findvar<keyIn>(), m_R.findvar<keyIn>(), m_L, m_R, con);
	}

GENERATE_EXPRESSION_BINARY_SHOE(Log)


}



