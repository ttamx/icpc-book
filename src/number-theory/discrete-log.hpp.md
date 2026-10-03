---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/number-theory/discrete-log/discrete_logarithm_mod.test.cpp
    title: verify/number-theory/discrete-log/discrete_logarithm_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/number-theory/discrete-log.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Description: Baby-step giant-step. Returns the smallest\n *  $x\
    \ \\ge 0$ such that $a^x \\equiv b \\pmod m$, or $-1$ if none.\n *  Works for\
    \ any $m \\ge 1$ (non-coprime $a,m$ allowed).\n *  Assumes $m^2$ fits in \\texttt{ll}.\n\
    \ * Usage: discrete_log(2,3,5); // 3\n * Time: $O(\\sqrt m)$\n */\n\nll discrete_log(ll\
    \ a,ll b,ll m){\n    a%=m,b%=m;\n    ll k=1,add=0,g;\n    while((g=gcd(a,m))>1){\n\
    \        if(b==k)return add;\n        if(b%g)return -1;\n        b/=g,m/=g,add++,k=k*a/g%m;\n\
    \    }\n    ll n=sqrtl(m)+1,an=1;\n    for(int i=0;i<n;i++)an=an*a%m;\n    unordered_map<ll,ll>\
    \ vals;\n    for(ll q=0,cur=b;q<=n;q++)vals[cur]=q,cur=cur*a%m;\n    for(ll p=1,cur=k;p<=n;p++){\n\
    \        cur=cur*an%m;\n        if(vals.count(cur))return n*p-vals[cur]+add;\n\
    \    }\n    return -1;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Baby-step giant-step.\
    \ Returns the smallest\n *  $x \\ge 0$ such that $a^x \\equiv b \\pmod m$, or\
    \ $-1$ if none.\n *  Works for any $m \\ge 1$ (non-coprime $a,m$ allowed).\n *\
    \  Assumes $m^2$ fits in \\texttt{ll}.\n * Usage: discrete_log(2,3,5); // 3\n\
    \ * Time: $O(\\sqrt m)$\n */\n\nll discrete_log(ll a,ll b,ll m){\n    a%=m,b%=m;\n\
    \    ll k=1,add=0,g;\n    while((g=gcd(a,m))>1){\n        if(b==k)return add;\n\
    \        if(b%g)return -1;\n        b/=g,m/=g,add++,k=k*a/g%m;\n    }\n    ll\
    \ n=sqrtl(m)+1,an=1;\n    for(int i=0;i<n;i++)an=an*a%m;\n    unordered_map<ll,ll>\
    \ vals;\n    for(ll q=0,cur=b;q<=n;q++)vals[cur]=q,cur=cur*a%m;\n    for(ll p=1,cur=k;p<=n;p++){\n\
    \        cur=cur*an%m;\n        if(vals.count(cur))return n*p-vals[cur]+add;\n\
    \    }\n    return -1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/number-theory/discrete-log.hpp
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/number-theory/discrete-log/discrete_logarithm_mod.test.cpp
documentation_of: src/number-theory/discrete-log.hpp
layout: document
redirect_from:
- /library/src/number-theory/discrete-log.hpp
- /library/src/number-theory/discrete-log.hpp.html
title: src/number-theory/discrete-log.hpp
---
