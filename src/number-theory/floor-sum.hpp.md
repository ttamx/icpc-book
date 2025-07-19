---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
    title: verify/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/number-theory/floor-sum.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-09-21\n * Description: Floor sum function.\n *  $f(a, b, c,\
    \ n) = \\sum_{x=0}^n \\lfloor \\frac{ax+b}{c} \\rfloor$\n *  becareful when a,b,c\
    \ are negetive (use custom floor division and mod instead)\n * Time: $O(\\log\
    \ a)$\n */\n\nll floor_sum(ll a,ll b,ll c,ll n){\n    ll res=n*(n+1)/2*(a/c)+(n+1)*(b/c);\n\
    \    a%=c,b%=c;\n    if(a==0)return res;\n    ll m=(a*n+b)/c;\n    return res+n*m-floor_sum(c,c-b-1,a,m-1);\n\
    }\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-09-21\n * Description:\
    \ Floor sum function.\n *  $f(a, b, c, n) = \\sum_{x=0}^n \\lfloor \\frac{ax+b}{c}\
    \ \\rfloor$\n *  becareful when a,b,c are negetive (use custom floor division\
    \ and mod instead)\n * Time: $O(\\log a)$\n */\n\nll floor_sum(ll a,ll b,ll c,ll\
    \ n){\n    ll res=n*(n+1)/2*(a/c)+(n+1)*(b/c);\n    a%=c,b%=c;\n    if(a==0)return\
    \ res;\n    ll m=(a*n+b)/c;\n    return res+n*m-floor_sum(c,c-b-1,a,m-1);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/number-theory/floor-sum.hpp
  requiredBy: []
  timestamp: '2025-07-19 14:29:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
documentation_of: src/number-theory/floor-sum.hpp
layout: document
redirect_from:
- /library/src/number-theory/floor-sum.hpp
- /library/src/number-theory/floor-sum.hpp.html
title: src/number-theory/floor-sum.hpp
---
