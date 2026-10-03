---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/number-theory/factorization/factorize.test.cpp
    title: verify/number-theory/factorization/factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/number-theory/factorization.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Description: Deterministic Miller-Rabin primality test for\n *\
    \  all 64-bit $n$ and Pollard rho factorization.\n *  \\texttt{factor(n)} returns\
    \ the prime factors of $n$ sorted,\n *  with multiplicity (empty for $n=1$).\n\
    \ * Usage: factor(360); // {2,2,2,3,3,5}\n * Time: $O(n^{1/4})$ gcd/mulmod for\
    \ factor, $O(7\\log n)$ for is\\_prime.\n */\n\nu64 mulmod(u64 a,u64 b,u64 m){return\
    \ (unsigned __int128)a*b%m;}\nu64 powmod(u64 b,u64 e,u64 m){\n    u64 r=1;\n \
    \   for(;e;b=mulmod(b,b,m),e>>=1)if(e&1)r=mulmod(r,b,m);\n    return r;\n}\nbool\
    \ is_prime(u64 n){\n    if(n<2||n%6%4!=1)return (n|1)==3;\n    u64 s=__builtin_ctzll(n-1),d=n>>s;\n\
    \    for(u64 a:{2,325,9375,28178,450775,9780504,1795265022}){\n        u64 p=powmod(a%n,d,n),i=s;\n\
    \        while(p!=1&&p!=n-1&&a%n&&i--)p=mulmod(p,p,n);\n        if(p!=n-1&&i!=s)return\
    \ 0;\n    }\n    return 1;\n}\nu64 pollard(u64 n){\n    u64 x=0,y=0,t=30,prd=2,i=1,q;\n\
    \    auto f=[&](u64 x){return mulmod(x,x,n)+i;};\n    while(t++%40||__gcd(prd,n)==1){\n\
    \        if(x==y)x=++i,y=f(x);\n        if((q=mulmod(prd,max(x,y)-min(x,y),n)))prd=q;\n\
    \        x=f(x),y=f(f(y));\n    }\n    return __gcd(prd,n);\n}\nvector<u64> factor(u64\
    \ n){\n    if(n==1)return {};\n    if(is_prime(n))return {n};\n    u64 x=n%2?pollard(n):2;\n\
    \    auto l=factor(x),r=factor(n/x);\n    l.insert(l.end(),ALL(r));\n    sort(ALL(l));\n\
    \    return l;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Deterministic\
    \ Miller-Rabin primality test for\n *  all 64-bit $n$ and Pollard rho factorization.\n\
    \ *  \\texttt{factor(n)} returns the prime factors of $n$ sorted,\n *  with multiplicity\
    \ (empty for $n=1$).\n * Usage: factor(360); // {2,2,2,3,3,5}\n * Time: $O(n^{1/4})$\
    \ gcd/mulmod for factor, $O(7\\log n)$ for is\\_prime.\n */\n\nu64 mulmod(u64\
    \ a,u64 b,u64 m){return (unsigned __int128)a*b%m;}\nu64 powmod(u64 b,u64 e,u64\
    \ m){\n    u64 r=1;\n    for(;e;b=mulmod(b,b,m),e>>=1)if(e&1)r=mulmod(r,b,m);\n\
    \    return r;\n}\nbool is_prime(u64 n){\n    if(n<2||n%6%4!=1)return (n|1)==3;\n\
    \    u64 s=__builtin_ctzll(n-1),d=n>>s;\n    for(u64 a:{2,325,9375,28178,450775,9780504,1795265022}){\n\
    \        u64 p=powmod(a%n,d,n),i=s;\n        while(p!=1&&p!=n-1&&a%n&&i--)p=mulmod(p,p,n);\n\
    \        if(p!=n-1&&i!=s)return 0;\n    }\n    return 1;\n}\nu64 pollard(u64 n){\n\
    \    u64 x=0,y=0,t=30,prd=2,i=1,q;\n    auto f=[&](u64 x){return mulmod(x,x,n)+i;};\n\
    \    while(t++%40||__gcd(prd,n)==1){\n        if(x==y)x=++i,y=f(x);\n        if((q=mulmod(prd,max(x,y)-min(x,y),n)))prd=q;\n\
    \        x=f(x),y=f(f(y));\n    }\n    return __gcd(prd,n);\n}\nvector<u64> factor(u64\
    \ n){\n    if(n==1)return {};\n    if(is_prime(n))return {n};\n    u64 x=n%2?pollard(n):2;\n\
    \    auto l=factor(x),r=factor(n/x);\n    l.insert(l.end(),ALL(r));\n    sort(ALL(l));\n\
    \    return l;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/number-theory/factorization.hpp
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/number-theory/factorization/factorize.test.cpp
documentation_of: src/number-theory/factorization.hpp
layout: document
redirect_from:
- /library/src/number-theory/factorization.hpp
- /library/src/number-theory/factorization.hpp.html
title: src/number-theory/factorization.hpp
---
