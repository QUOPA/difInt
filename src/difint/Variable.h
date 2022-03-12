#pragma once

#include "difint/StringLiteral.h"
#include "difint/ExpressionBase.h"
#include "difint/Constant.h"
#include "difint/BooleanTemplate.h"
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

	template<unsigned long long strOtherKey>
	constexpr bool findvar() const { return false; }
	//static constexpr bool findvar(const V<strOtherKey>& var) { return false; }

	template<>
	constexpr bool findvar<strkey>() const { return true; }
	//static constexpr bool findvar<strkey> (const V& var) { return true; }

	//template<>
	//static constexpr bool findvar<strkey>() { return true; }
// 
// 	template <unsigned long long otherKey>
// 	struct IsSameKey 
// 	{
// 		typedef _FALSE Type;
// 	};
// 
// 	template <>
// 	struct IsSameKey<strkey>
// 	{
// 		typedef _TRUE Type;
// 	};




private:
	LiteralKey<strkey> m_strkey;

	//inline const auto& _ref() const { return *this; }
	//inline auto& _ref() { return *this; }
	
	template <typename OtherDerived>
	friend class _B;
};

}
