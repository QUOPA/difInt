#pragma once

#include "difint/StringLiteral.h"
#include "difint/ExpressionBase.h"
#include "difint/Constant.h"
#include <string>

namespace di
{
template<typename T>
class C;

template<typename OtherDerived>
class _B;

template <unsigned long long strkey>
class V : public _B< V< strkey > >
{
public:
	inline std::string strExpr() const { return m_strkey.getString(); }
	inline constexpr int precedence() const { return 0; }

	// derivative by other variable
	template <typename T, unsigned long long keyother>
	auto derivative(const V<keyother>& con) const { return C<T>(0); }

	// derivative by this variable
	template<typename T>
	auto derivative(const V<strkey>& var) const { return C<T>(1); }

private:
	LiteralKey<strkey> m_strkey;

	//inline const auto& _ref() const { return *this; }
	//inline auto& _ref() { return *this; }
	
	template <typename OtherDerived>
	friend class _B;
};

}
