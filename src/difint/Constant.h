#pragma once

#include "difint/ExpressionBase.h"
#include "difint/Variable.h"
#include <string>

namespace di
{
template <unsigned long long strKey>
class V;

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
	auto derivative(const V<keyother>& con) const { return C(0); }

	template <typename T2,  unsigned long long keyother>
	auto derivative(const V<keyother>& con) const { return C<T2>(0); }

private:
	T m_data;

	inline const auto& _ref() const { return *this; }
	inline auto& _ref() { return *this; }

	template <typename OtherDerived>
	friend class _B;
};

}