#pragma once


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

template<typename OtherDerived>
class _B;

//template <typename T, typename _L, typename _R, unsigned long long keylhs>
//inline decltype(auto) createExpDerivative(_L L, _R R, const V<keylhs>& con);

template <typename T, typename _L, unsigned long long keylhs>
inline decltype(auto) createExpDerivative(const _B<_L> & L, const C<T>& R, const V<keylhs>& con) {
	return R * L.e( C<T> ( R.val()-1 ) );
}

template <typename T, typename _R, unsigned long long keylhs>
inline decltype(auto) createExpDerivative(const C<T>& L, const _B<_R>& R, const V<keylhs>& con) {
	return *this * fnLn(L);
}

template <typename T, typename _R, unsigned long long keylhs>
inline decltype(auto) createExpDerivative(const C<T>& L, _R R, const V<keylhs>& con) {
	return *this * fnLn(L);
}

template <bool LBOOL, bool RBOOL, typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createSumDerivative(_L L, _R R, const V<keylhs>& con) {
	return L.derivative<T>(con) + R.derivative<T>(con);
}

// need to implement log first
//template <typename T, typename _R, unsigned long long keylhs>
//inline decltype(auto) createExpDerivative(const C<T>& L, _R R, const V<keylhs>& con) {
//	return L.e(C<T>(R.val() - 1));
//}

GENERATE_EXPRESSION_BINARY_HAT(Exp)
public:	
	inline std::string strExpr() const { return this->fmtparenth(m_L) +"^"+ this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 10; }

	template <typename T, unsigned long long keylhs>
	auto derivative(const V<keylhs>& con) const { return createExpDerivative<T>(m_L, m_R, con); }
GENERATE_EXPRESSION_BINARY_SHOE(Exp)

template <bool inVal>
void funcTEstFunc()
{
	std::cout << "test test" << std::endl;
}

// 
// template <typename BoolTF>
// void funcTEstFunc()
// {
// 	std::cout << "test test" << std::endl;
// }
// 
// template <>
// void funcTEstFunc<_TRUE>()
// {
// 	std::cout << "TRUE" << std::endl;
// }
// 
// template <>
// void funcTEstFunc<_FALSE>()
// {
// 	std::cout << "FALSE" << std::endl;
// }

GENERATE_EXPRESSION_BINARY_HAT(Sum)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "+" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 30; }

	template <unsigned long long keyin>
	static constexpr bool findvar(const V<keyin>& var) {
		constexpr bool testest = _L::findvar(var) || _R::findvar(var);
		return  testest;
	}

	template <typename T, unsigned long long keylhs>
	//auto derivative(const V<keylhs>& con) const { return createSumDerivative<typename _L::find<keylhs>()::Type, typename _R::find<keylhs>()::Type, T>(m_L, m_R, con); }
	auto derivative(const V<keylhs>& var) const {
		constexpr bool Booltest = m_L.findvar<keylhs>() || m_R.findvar<keylhs>();
		//funcTEstFunc<Booltest>();
		return m_L.derivative<T>(var) + m_R.derivative<T>(var);
	}
	
	template <typename T, unsigned long long keylhs>
	static auto testSTatic(const V<keylhs>& var) {
		//bool Booltest = m_L.findvar<keylhs>() || m_R.findvar< keylhs>();
		//funcTEstFunc<Booltest>();
		return true;
	}
	
	

	//template <unsigned long long keyin>
	//void testhere() const { funcTEstFunc<typename _L::IsSameKey<keyin>::Type> (); }

// 	template <unsigned long long otherKey>
// 	struct IsSameKey
// 	{
// 		typedef typename _L::IsSameKey<otherKey>::Type Type;
// 		//typedef typename BoolOR< typename _L::IsSameKey<otherKey>::Type, typename _R::IsSameKey<otherKey>::Type >::Type Type;
// 	};


GENERATE_EXPRESSION_BINARY_SHOE(Sum)

template <typename T, typename _L, typename _R, unsigned long long keylhs>
inline decltype(auto) createDifDerivative(_L L, _R R, const V<keylhs>& con) {
	return L.derivative<T>(con) - R.derivative<T>(con);
}

GENERATE_EXPRESSION_BINARY_HAT(Dif)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "-" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 30; }

	template <typename T, unsigned long long keylhs>
	auto derivative(const V<keylhs>& con) const { return m_L.derivative<T>(con) - m_R.derivative<T>(con); }
GENERATE_EXPRESSION_BINARY_SHOE(Dif)

GENERATE_EXPRESSION_BINARY_HAT(Mul)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "*" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 20; }

	template <typename T, unsigned long long keylhs>
	auto derivative(const V<keylhs>& con) const { return m_L.derivative<T>(con)*m_R + m_L*m_R.derivative<T>(con); }
GENERATE_EXPRESSION_BINARY_SHOE(Mul)

GENERATE_EXPRESSION_BINARY_HAT(Div)
public:
	inline std::string strExpr() const { return this->fmtparenth(m_L) + "/" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const{ return 20; }
GENERATE_EXPRESSION_BINARY_SHOE(Div)


GENERATE_EXPRESSION_BINARY_HAT(Log)
public:
	inline std::string strExpr() const { return "log_" + this->fmtparenth(m_L) + "_" + this->fmtparenth(m_R); }
	inline constexpr int precedence() const { return 11; }

GENERATE_EXPRESSION_BINARY_SHOE(Log)


}



