#pragma once

#include "difint/ExpressionBase.h"
#include "difint/Variable.h"
#include <string>

namespace di
{
template <unsigned long long strKey>
class V;

template <typename T>
class C0;

template <typename T>
class C1;

template <typename T>
std::string to_string_wrapper(const T& inData) { return std::to_string(inData); }

// write here for specialization

template <typename T>
class C : public _B<C<T>>
{
public:
	C(const T & inData ) : m_data(inData) {}

	inline std::string strExpr() const { return to_string_wrapper(m_data); }
	inline constexpr int precedence() const { return 0; }

	template <unsigned long long keyother>
	auto derivative(const V<keyother>& con) const { return C0<T>(); }

	template <typename T2,  unsigned long long keyother>
	auto derivative(const V<keyother>& con) const { return C0<T2>(); }

	T& val() { return m_data; }
	const T& val() const { return m_data; }

	template<unsigned long long strOtherKey>
	constexpr bool findvar() const;
	
	//static constexpr bool findvar(const V<strOtherKey>& con) { return false; }

// 	template <unsigned long long otherKey>
// 	struct IsSameKey
// 	{
// 		typedef _FALSE Type;
// 	};

private:
	T m_data;

	//inline const auto& _ref() const { return *this; }
	//inline auto& _ref() { return *this; }

	template <typename OtherDerived>
	friend class _B;
};

// special case: 0
template<typename T>
struct C0 : public C<T> { C0() : C<T>(0) {} };

// special case: 0
template<typename T>
struct C1 : public C<T> { C1() : C<T>(1) {} };

//// special case: 0
//template<typename T>
//struct Cp : public C<T> { Cp(const T inData) : C<T>(inData) {} };
//
//// special case: negative
//template<typename T>
//struct Cn : public C<T> { Cn(const T inData) : C<T>(inData) {} };

template<typename T>
template<unsigned long long strOtherKey>
constexpr bool C<T>::findvar() const
{
	return false;
}

}