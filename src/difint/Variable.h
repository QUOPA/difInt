#pragma once

#include "difint/StringLiteral.h"
#include "difint/ExpressionBase.h"
#include "difint/Constant.h"
#include "difint/BooleanTemplate.h"
#include "difint/Exceptions.h"
#include <string>

namespace di
{
template<typename T>
class C;

template<typename OtherDerived>
class _B;

template <typename T, unsigned long long strkey>
class V : public _B< V<T, strkey > >
{
public:
	V() : m_useData(false){}

	inline std::string strExpr() const { return m_strkey.getString(); }
	inline constexpr int precedence() const { return 0; }

	template < unsigned long long keyother >
	auto derivative(const V<T, keyother>& con) const { return C<T>(0); }
	
	auto derivative(const V<T, strkey>& var) const { return C<T>(1); }

	//template <typename T2, unsigned long long keyother>
	//auto derivative(const V<T2, keyother>& con) const { return C<T2>(0); }
	//
	//// derivative by this variable
	//template<typename T2>
	//auto derivative(const V<T2, strkey>& var) const { return C<T2>(1); }

	template<unsigned long long strOtherKey>
	constexpr auto findvar() const { return _FALSE(); }

	template<>
	constexpr auto findvar<strkey>() const { return _TRUE(); }

	inline void operator=(const T& rhs) { m_useData = true;  m_data = rhs;}

	inline T eval() const { 
		if (!m_useData)
			throw diUninitialized(m_strkey.getString());
		return m_data;
	}

private:
	LiteralKey<strkey> m_strkey;
	T m_data;
	bool m_useData;

	inline decltype(auto) _ref() const { return *this; }
	inline decltype(auto) _ref() { return *this; }
	
	template <typename OtherDerived>
	friend class _B;
};

}
