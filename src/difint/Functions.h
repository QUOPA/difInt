#pragma once

#include "difint/ExpressionBase.h"
#include "difint/ExpressionBinary.h"
#include "difint/ExpressionUnary.h"


namespace di
{

template <typename Derived>
inline const auto fnLn(const _B<Derived>& rhs) { return createLn(rhs.ref()); }

template <typename Derived1, typename Derived2>
inline const auto fnLog(const _B<Derived1>& lhs, const _B<Derived2>& rhs) { return createLog(lhs.ref(), rhs.ref()); }

inline const auto fnLn(double rhs) { return createLn(C<double>(rhs)); }

template <typename Derived1>
inline const auto fnLog(const _B<Derived1>& lhs, double rhs) { return createLog(lhs.ref(), C<double>(rhs)); }

template <typename Derived1>
inline const auto fnLog(double lhs, const _B<Derived1>& rhs) { return createLog(C<double>(lhs), rhs.ref()); }

template <typename Derived1, typename Derived2>
inline const auto fnExp(const _B<Derived1>& lhs, const _B<Derived2>& rhs) { return createExp(lhs.ref(), rhs.ref()); }

template <typename Derived1>
inline const auto fnExp(const _B<Derived1>& lhs, double rhs) { return createExp(lhs.ref(), C<double>(rhs)); }

template <typename Derived1>
inline const auto fnExp(double lhs, const _B<Derived1>& rhs) { return createExp(C<double>(lhs), rhs.ref()); }

template <typename Derived1>
inline const auto operator+(const _B<Derived1>& lhs, double rhs) { return createSum( lhs.ref(), C<double>(rhs)); }

template <typename Derived1>
inline const auto operator+(double lhs, const _B<Derived1>& rhs) { return createSum(C<double>(lhs), rhs.ref()); }


template <typename Derived1>
inline const auto operator-(const _B<Derived1>& lhs, double rhs) { return createDif(lhs.ref(), C<double>(rhs)); }

template <typename Derived1>
inline const auto operator-(double lhs, const _B<Derived1>& rhs) { return createDif(C<double>(lhs), rhs.ref()); }


template <typename Derived1>
inline const auto operator*(const _B<Derived1>& lhs, double rhs) { return createMul(lhs.ref(), C<double>(rhs)); }

template <typename Derived1>
inline const auto operator*(double lhs, const _B<Derived1>& rhs) { return createMul(C<double>(lhs), rhs.ref()); }


template <typename Derived1>
inline const auto operator/(const _B<Derived1>& lhs, double rhs) { return createDiv(lhs.ref(), C<double>(rhs)); }

template <typename Derived1>
inline const auto operator/(double lhs, const _B<Derived1>& rhs) { return createDiv(C<double>(lhs), rhs.ref()); }




}