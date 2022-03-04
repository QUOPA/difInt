#pragma once

#include "difint/ExpressionBase.h"
#include <string>

namespace di
{
class V : public _B<V>
{
public:
	explicit V(const std::string& inname) :m_name(inname) {}

	inline std::string strExpr() const { return m_name; }
	inline constexpr int precedence() const { return 0; }

private:
	std::string m_name;
	inline const auto& _ref() const { return *this; }
	inline auto& _ref() { return *this; }
	
	template <typename OtherDerived>
	friend class _B;
};

}
