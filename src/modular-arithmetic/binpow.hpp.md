---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/polynomials/formal-power-series.hpp
    title: src/polynomials/formal-power-series.hpp
  - icon: ':heavy_check_mark:'
    path: src/polynomials/multipoint-evaluation.hpp
    title: src/polynomials/multipoint-evaluation.hpp
  - icon: ':heavy_check_mark:'
    path: src/polynomials/ntt.hpp
    title: src/polynomials/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: src/polynomials/polynomial-interpolation.hpp
    title: src/polynomials/polynomial-interpolation.hpp
  - icon: ':heavy_check_mark:'
    path: src/polynomials/subproduct-tree.hpp
    title: src/polynomials/subproduct-tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/polynomials/multipoint-evaluation/multipoint_evaluation.test.cpp
    title: verify/polynomials/multipoint-evaluation/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
    title: verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - src/polynomials/polynomial-interpolation.hpp
  - src/polynomials/subproduct-tree.hpp
  - src/polynomials/ntt.hpp
  - src/polynomials/formal-power-series.hpp
  - src/polynomials/multipoint-evaluation.hpp
  timestamp: '2025-07-19 15:28:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
  - verify/polynomials/multipoint-evaluation/multipoint_evaluation.test.cpp
documentation_of: src/modular-arithmetic/binpow.hpp
layout: document
redirect_from:
- /library/src/modular-arithmetic/binpow.hpp
- /library/src/modular-arithmetic/binpow.hpp.html
title: src/modular-arithmetic/binpow.hpp
---
