---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/polynomials/formal-power-series.hpp
    title: src/polynomials/formal-power-series.hpp
  - icon: ':warning:'
    path: src/polynomials/ntt.hpp
    title: src/polynomials/ntt.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/modular-arithmetic/binpow.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-01-15\n * Description: n-th power using divide and conquer\n\
    \ * Time: $O(\\log b)$\n */\n\ntemplate<class T>\nconstexpr T binpow(T a,ll b){\n\
    \    T res=1;\n    for(;b>0;b>>=1,a*=a)if(b&1)res*=a;\n    return res;\n}\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description:\
    \ n-th power using divide and conquer\n * Time: $O(\\log b)$\n */\n\ntemplate<class\
    \ T>\nconstexpr T binpow(T a,ll b){\n    T res=1;\n    for(;b>0;b>>=1,a*=a)if(b&1)res*=a;\n\
    \    return res;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: src/modular-arithmetic/binpow.hpp
  requiredBy:
  - src/polynomials/ntt.hpp
  - src/polynomials/formal-power-series.hpp
  timestamp: '2025-07-19 15:28:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/modular-arithmetic/binpow.hpp
layout: document
redirect_from:
- /library/src/modular-arithmetic/binpow.hpp
- /library/src/modular-arithmetic/binpow.hpp.html
title: src/modular-arithmetic/binpow.hpp
---
