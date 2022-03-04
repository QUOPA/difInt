#pragma once

#include <string>
#include <iostream>
#include "difint/ExpressionBinary.h"


namespace di
{

template <typename _L, typename _R>
class Exp;

template <typename Derived>
class _B
{
public:
	inline std::string strExpr() const { return derived()->strExpr(); }
	

	template <typename OtherDerived>
	inline const auto e(const _B<OtherDerived>& rhs) const { return createExp(this->ref(), rhs.ref()); }

	template <typename OtherDerived>
	inline const auto operator+(const _B<OtherDerived>& rhs) const { return createSum(this->ref(), rhs.ref()); }

	template <typename OtherDerived>
	inline const auto operator-(const _B<OtherDerived>& rhs) const { return createDif(this->ref(), rhs.ref()); }

	template <typename OtherDerived>
	inline const auto operator*(const _B<OtherDerived>& rhs) const { return createMul(this->ref(), rhs.ref()); }

	template <typename OtherDerived>
	inline const auto operator/(const _B<OtherDerived>& rhs) const { return createDiv(this->ref(), rhs.ref()); }

	inline constexpr int precedence() const { return derived()->precedence(); }

	inline decltype(auto) ref() const { return derived()->_ref(); }
	inline decltype(auto) ref() { return derived()->_ref(); }

	template <typename OtherDerived>
	inline std::string fmtparenth(const _B<OtherDerived>& inexpr) const
	{ return precedence() < inexpr.precedence() ? ("(" + inexpr.strExpr() + ")") : inexpr.strExpr(); }

private:

	inline const auto _ref() const { return *derived(); }
	inline auto _ref() { return *derived(); }


	const Derived* derived() const { return static_cast<const Derived*> (this); }
	Derived* derived() { return static_cast<Derived*> (this); }

	//template <typename Derived2> inline 
	//friend std::ostream& operator<<(std::ostream& o, const _B<Derived2>& inexpr);
};


}
