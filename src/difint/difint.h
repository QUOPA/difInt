#pragma once
#include "difint/Constant.h"
#include "difint/Variable.h"
#include "difint/Functions.h"
#include "difint/Unexpected.h"

// okay... i tried using variadic but failed - VS builder 17.1
// And by some reason, the cascading way does not work, the last resort is below...

#define DIFINT_VAR(v) di::V<LKEY_STR_ENCODER(#v)> v

#define DIFINT_VAR_2(v1, v2) DIFINT_VAR(v1); DIFINT_VAR(v2)

#define DIFINT_VAR_3(v1, v2, v3) DIFINT_VAR(v1); DIFINT_VAR(v2); DIFINT_VAR(v3)

#define DIFINT_VAR_4(v1, v2, v3, v4) \
DIFINT_VAR(v1); DIFINT_VAR(v2);DIFINT_VAR(v3); DIFINT_VAR(v4)

#define DIFINT_VAR_5(v1, v2, v3, v4, v5) \
DIFINT_VAR(v1); DIFINT_VAR(v2); DIFINT_VAR(v3); DIFINT_VAR(v4); DIFINT_VAR(v5)

#define DIFINT_VAR_6(v1, v2, v3, v4, v5, v6) \
DIFINT_VAR(v1); DIFINT_VAR(v2); DIFINT_VAR(v3); DIFINT_VAR(v4); DIFINT_VAR(v5); DIFINT_VAR(v6)

#define DIFINT_VAR_7(v1, v2, v3, v4, v5, v6, v7) \
DIFINT_VAR(v1); DIFINT_VAR(v2); DIFINT_VAR(v3); DIFINT_VAR(v4); DIFINT_VAR(v5); \
DIFINT_VAR(v6); DIFINT_VAR(v7)

#define DIFINT_VAR_8(v1, v2, v3, v4, v5, v6, v7, v8) \
DIFINT_VAR(v1); DIFINT_VAR(v2); DIFINT_VAR(v3); DIFINT_VAR(v4); DIFINT_VAR(v5);\
DIFINT_VAR(v6); DIFINT_VAR(v7); DIFINT_VAR(v8)

#define DIFINT_VAR_9(v1, v2, v3, v4, v5, v6, v7, v8, v9) \
DIFINT_VAR(v1); DIFINT_VAR(v2); DIFINT_VAR(v3); DIFINT_VAR(v4); DIFINT_VAR(v5);\
DIFINT_VAR(v6); DIFINT_VAR(v7); DIFINT_VAR(v8); DIFINT_VAR(v9)

#define DIFINT_VAR_10(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) \
DIFINT_VAR(v1); DIFINT_VAR(v2); DIFINT_VAR(v3); DIFINT_VAR(v4); DIFINT_VAR(v5);\
DIFINT_VAR(v6); DIFINT_VAR(v7); DIFINT_VAR(v8); DIFINT_VAR(v9); DIFINT_VAR(v10)
