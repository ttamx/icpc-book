---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/polynomials/formal-power-series.hpp
    title: src/polynomials/formal-power-series.hpp
  - icon: ':heavy_check_mark:'
    path: src/polynomials/linear-recurrence.hpp
    title: src/polynomials/linear-recurrence.hpp
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
  - icon: ':heavy_check_mark:'
    path: src/polynomials/taylor-shift.hpp
    title: src/polynomials/taylor-shift.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/polynomials/linear-recurrence/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: verify/polynomials/linear-recurrence/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomials/multipoint-evaluation/multipoint_evaluation.test.cpp
    title: verify/polynomials/multipoint-evaluation/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
    title: verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomials/taylor-shift/polynomial_taylor_shift.test.cpp
    title: verify/polynomials/taylor-shift/polynomial_taylor_shift.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/number-theory/binpow.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-01-15\n * Description: n-th power using divide and conquer\n\
    \ * Time: $O(\\log b)$\n */\n\ntemplate<class T>\nconstexpr T binpow(T a,ll b){\n\
    \    T res=1;\n    for(;b>0;b>>=1,a*=a)if(b&1)res*=a;\n    return res;\n}\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-01-15\n * Description:\
    \ n-th power using divide and conquer\n * Time: $O(\\log b)$\n */\n\ntemplate<class\
    \ T>\nconstexpr T binpow(T a,ll b){\n    T res=1;\n    for(;b>0;b>>=1,a*=a)if(b&1)res*=a;\n\
    \    return res;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: src/number-theory/binpow.hpp
  requiredBy:
  - src/polynomials/taylor-shift.hpp
  - src/polynomials/polynomial-interpolation.hpp
  - src/polynomials/subproduct-tree.hpp
  - src/polynomials/ntt.hpp
  - src/polynomials/formal-power-series.hpp
  - src/polynomials/linear-recurrence.hpp
  - src/polynomials/multipoint-evaluation.hpp
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/polynomials/taylor-shift/polynomial_taylor_shift.test.cpp
  - verify/polynomials/linear-recurrence/kth_term_of_linearly_recurrent_sequence.test.cpp
  - verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
  - verify/polynomials/multipoint-evaluation/multipoint_evaluation.test.cpp
documentation_of: src/number-theory/binpow.hpp
layout: document
redirect_from:
- /library/src/number-theory/binpow.hpp
- /library/src/number-theory/binpow.hpp.html
title: src/number-theory/binpow.hpp
---
