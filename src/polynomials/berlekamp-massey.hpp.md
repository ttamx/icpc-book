---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp
    title: verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/polynomials/berlekamp-massey.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Description: Finds the shortest recurrence $c$ of length $L$ with\n\
    \ * $s_i = \\sum_{j=1}^{L} c_{j-1} s_{i-j}$ for all $L \\le i < n$.\n * Needs\
    \ $2L$ terms to recover a recurrence of order $L$.\n * Usage: berlekamp_massey(vector<mint>{0,1,1,3,5,11})\
    \ // {1,2}\n * Time: $O(N^2)$\n */\n\ntemplate<class mint>\nvector<mint> berlekamp_massey(const\
    \ vector<mint> &s){\n    int n=SZ(s),L=0,m=0;\n    vector<mint> C(n+1),B(n+1),T;\n\
    \    C[0]=B[0]=1;\n    mint b=1;\n    for(int i=0;i<n;i++){\n        m++;\n  \
    \      mint d=s[i];\n        for(int j=1;j<=L;j++)d+=C[j]*s[i-j];\n        if(d==mint(0))continue;\n\
    \        T=C;\n        mint coef=d/b;\n        for(int j=m;j<=n;j++)C[j]-=coef*B[j-m];\n\
    \        if(2*L>i)continue;\n        L=i+1-L,B=T,b=d,m=0;\n    }\n    vector<mint>\
    \ c(L);\n    for(int i=0;i<L;i++)c[i]=-C[i+1];\n    return c;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Finds the shortest\
    \ recurrence $c$ of length $L$ with\n * $s_i = \\sum_{j=1}^{L} c_{j-1} s_{i-j}$\
    \ for all $L \\le i < n$.\n * Needs $2L$ terms to recover a recurrence of order\
    \ $L$.\n * Usage: berlekamp_massey(vector<mint>{0,1,1,3,5,11}) // {1,2}\n * Time:\
    \ $O(N^2)$\n */\n\ntemplate<class mint>\nvector<mint> berlekamp_massey(const vector<mint>\
    \ &s){\n    int n=SZ(s),L=0,m=0;\n    vector<mint> C(n+1),B(n+1),T;\n    C[0]=B[0]=1;\n\
    \    mint b=1;\n    for(int i=0;i<n;i++){\n        m++;\n        mint d=s[i];\n\
    \        for(int j=1;j<=L;j++)d+=C[j]*s[i-j];\n        if(d==mint(0))continue;\n\
    \        T=C;\n        mint coef=d/b;\n        for(int j=m;j<=n;j++)C[j]-=coef*B[j-m];\n\
    \        if(2*L>i)continue;\n        L=i+1-L,B=T,b=d,m=0;\n    }\n    vector<mint>\
    \ c(L);\n    for(int i=0;i<L;i++)c[i]=-C[i+1];\n    return c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/polynomials/berlekamp-massey.hpp
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp
documentation_of: src/polynomials/berlekamp-massey.hpp
layout: document
redirect_from:
- /library/src/polynomials/berlekamp-massey.hpp
- /library/src/polynomials/berlekamp-massey.hpp.html
title: src/polynomials/berlekamp-massey.hpp
---
