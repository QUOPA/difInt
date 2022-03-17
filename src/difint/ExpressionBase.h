#pragma once

#include <string>
#include <iostream>
#include "difint/Variable.h"

namespace di
{

template <typename Derived>
class _B
{
public:
	inline std::string strExpr() const { return derived()->strExpr(); }

	template <typename OtherDerived>
	inline const auto e(const _B<OtherDerived>& rhs) const { return createExp(this->ref(), rhs.ref()); }

	inline const auto e(double rhs) const { return createExp(this->ref(), C<double>(rhs) ); }

	template <typename OtherDerived>
	inline const auto operator+(const _B<OtherDerived>& rhs) const { return createSum(this->ref(), rhs.ref()); }

	template <typename OtherDerived>
	inline const auto operator-(const _B<OtherDerived>& rhs) const { return createDif(this->ref(), rhs.ref()); }

	template <typename OtherDerived>
	inline const auto operator*(const _B<OtherDerived>& rhs) const { return createMul(this->ref(), rhs.ref()); }

	template <typename OtherDerived>
	inline const auto operator/(const _B<OtherDerived>& rhs) const { return createDiv(this->ref(), rhs.ref()); }


	inline const auto operator-() const { return createNeg(this->ref()); }

	inline constexpr int precedence() const { return derived()->precedence(); }

	inline decltype(auto) ref() const { return derived()->_ref(); }
	inline decltype(auto) ref() { return derived()->_ref(); }

	template <typename OtherDerived>
	inline std::string fmtparenth(const _B<OtherDerived>& inexpr) const
	{ return precedence() < inexpr.precedence() ? ("(" + inexpr.strExpr() + ")") : inexpr.strExpr(); }

	//template<unsigned long long strOtherKey>
	//static constexpr bool findvar() { return Derived::findvar<strOtherKey>(); }

private:

	inline auto _ref() const { return *derived(); }
	inline auto _ref() { return *derived(); }

	const Derived* derived() const { return static_cast<const Derived*> (this); }
	Derived* derived() { return static_cast<Derived*> (this); }

	template <typename Derived2> inline 
	friend std::ostream& operator<<(std::ostream& o, const _B<Derived2>& inexpr);
};


class Unexpected : public _B<Unexpected>
{
public:

	inline std::string strExpr() const { return "<unexpected>"; }
	inline constexpr int precedence() const { return 0; }

	template <typename T, unsigned long long keyother>
	auto derivative(const V<T, keyother>& con) const { return Unexpected(); }

	template<unsigned long long strOtherKey>
	constexpr auto findvar() const { return _FALSE(); }

private:

	//inline const auto& _ref() const { return *this; }
	//inline auto& _ref() { return *this; }

	template <typename OtherDerived>
	friend class _B;
};

template<typename Derived2>
std::ostream& operator<<(std::ostream& o, const _B<Derived2>& inexpr)
{
	return o << inexpr.strExpr();
}

}
