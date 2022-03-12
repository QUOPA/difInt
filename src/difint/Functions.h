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

}