#pragma once
#include "difint/Constant.h"
#include "difint/Variable.h"

#define DIFINT_CONST(c) di::C c(#c)
//#define DIFINT_CONSTS(c, ...) DIFINT_CONST(c); DIFINT_CONSTS(##__VA_ARGS__)

#define DIFINT_VAR(v) di::V v(#v)
#define DIFINT_VAR_2(v1, v2) DIFINT_VAR(v1); DIFINT_VAR(v2)
#define DIFINT_VAR_3(v1, ...) DIFINT_VAR(v1); DIFINT_VAR_2(##__VA_ARGS__)
#define DIFINT_VAR_4(v1, ...) DIFINT_VAR(v1); DIFINT_VAR_3(##__VA_ARGS__)
#define DIFINT_VAR_5(v1, ...) DIFINT_VAR(v1); DIFINT_VAR_4(##__VA_ARGS__)
#define DIFINT_VAR_6(v1, ...) DIFINT_VAR(v1); DIFINT_VAR_5(##__VA_ARGS__)
#define DIFINT_VAR_7(v1, ...) DIFINT_VAR(v1); DIFINT_VAR_6(##__VA_ARGS__)
#define DIFINT_VAR_8(v1, ...) DIFINT_VAR(v1); DIFINT_VAR_7(##__VA_ARGS__)
#define DIFINT_VAR_9(v1, ...) DIFINT_VAR(v1); DIFINT_VAR_8(##__VA_ARGS__)
#define DIFINT_VAR_10(v1, ...) DIFINT_VAR(v1); DIFINT_VAR_9(##__VA_ARGS__)

template <typename... VarArgsIn>
inline constexpr int CountVarArgs(VarArgsIn... InVars) 
{ 
	return sizeof...(InVars); 
}