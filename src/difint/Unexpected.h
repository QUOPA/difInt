#pragma once


#include "difint/Variable.h"
#include "difint/BooleanTemplate.h"
#include "difint/ExpressionBase.h"
#include <string>

// 
// namespace di 
// {
// 	template <typename Derived>
// 	class _B;
// 
// 	template <unsigned long long keystr>
// 	class V;
// 
// 	class Unexpected : public _B<Unexpected>
// 	{
// 	public:
// 
// 		inline std::string strExpr() const { return "<unexpected>"; }
// 		inline constexpr int precedence() const { return 0; }
// 
// 		template <unsigned long long keyother>
// 		auto derivative(const V<keyother>& con) const { return Unexpected(); }
// 
// 		template<unsigned long long strOtherKey>
// 		constexpr auto findvar() const { return _FALSE(); }
// 
// 	private:
// 
// 		//inline const auto& _ref() const { return *this; }
// 		//inline auto& _ref() { return *this; }
// 
// 		template <typename OtherDerived>
// 		friend class _B;
// 	};
// }
