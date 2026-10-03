---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/modular-arithmetic/barrett.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Description: Barrett reduction, used for fast division / modulo.\n\
    \ */\n\nstruct Barrett{\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \    using u128 = __uint128_t;\n    u32 m;\n    u64 im;\n    explicit Barrett(u32\
    \ m=1):m(m),im((u64)(-1)/m+1){}\n    u32 umod()const{return m;}\n    u32 modulo(u64\
    \ z){\n        if(m==1)return 0;\n        u64 x=(u64)(((u128)(z)*im)>>64);\n \
    \       u64 y=x*m;\n        return (z-y+(z<y?m:0));\n    }\n    u64 floor(u64\
    \ z){\n        if(m==1)return z;\n        u64 x=(u64)(((u128)(z)*im)>>64);\n \
    \       u64 y=x*m;\n        return (z<y?x-1:x);\n    }\n    pair<u64,u32> divmod(u64\
    \ z){\n        if (m==1)return {z,0};\n        u64 x=(u64)(((u128)(z)*im)>>64);\n\
    \        u64 y=x*m;\n        if (z<y)return {x-1,z-y+m};\n        return {x,z-y};\n\
    \    }\n    u32 mul(u32 a,u32 b){return modulo(u64(a)*b);}\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Barrett reduction,\
    \ used for fast division / modulo.\n */\n\nstruct Barrett{\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n    using u128 = __uint128_t;\n    u32 m;\n    u64\
    \ im;\n    explicit Barrett(u32 m=1):m(m),im((u64)(-1)/m+1){}\n    u32 umod()const{return\
    \ m;}\n    u32 modulo(u64 z){\n        if(m==1)return 0;\n        u64 x=(u64)(((u128)(z)*im)>>64);\n\
    \        u64 y=x*m;\n        return (z-y+(z<y?m:0));\n    }\n    u64 floor(u64\
    \ z){\n        if(m==1)return z;\n        u64 x=(u64)(((u128)(z)*im)>>64);\n \
    \       u64 y=x*m;\n        return (z<y?x-1:x);\n    }\n    pair<u64,u32> divmod(u64\
    \ z){\n        if (m==1)return {z,0};\n        u64 x=(u64)(((u128)(z)*im)>>64);\n\
    \        u64 y=x*m;\n        if (z<y)return {x-1,z-y+m};\n        return {x,z-y};\n\
    \    }\n    u32 mul(u32 a,u32 b){return modulo(u64(a)*b);}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/modular-arithmetic/barrett.hpp
  requiredBy: []
  timestamp: '2026-10-03 21:31:01+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/modular-arithmetic/barrett.hpp
layout: document
redirect_from:
- /library/src/modular-arithmetic/barrett.hpp
- /library/src/modular-arithmetic/barrett.hpp.html
title: src/modular-arithmetic/barrett.hpp
---
