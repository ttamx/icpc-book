---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/number-theory/mod-sqrt/sqrt_mod.test.cpp
    title: verify/number-theory/mod-sqrt/sqrt_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/number-theory/mod-sqrt.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Description: Tonelli-Shanks. Returns $x$ with\n *  $x^2 \\equiv a \\\
    pmod p$ for prime $p$ (the other root is $p-x$),\n *  or $-1$ if $a$ is not a\
    \ quadratic residue.\n * Usage: mod_sqrt(2,7); // 3 or 4\n * Time: $O(\\log^2\
    \ p)$\n */\n\nll mod_sqrt(ll a,ll p){\n    auto mul=[&](ll x,ll y){return ll(i128(x)*y%p);};\n\
    \    auto pw=[&](ll b,ll e){\n        ll r=1;\n        for(;e;b=mul(b,b),e>>=1)if(e&1)r=mul(r,b);\n\
    \        return r;\n    };\n    a%=p;\n    if(a<0)a+=p;\n    if(a==0||p==2)return\
    \ a;\n    if(pw(a,(p-1)/2)!=1)return -1;\n    ll s=p-1,r=0,z=2;\n    while(s%2==0)s/=2,r++;\n\
    \    while(pw(z,(p-1)/2)!=p-1)z++;\n    ll x=pw(a,(s+1)/2),b=pw(a,s),g=pw(z,s);\n\
    \    while(b!=1){\n        ll t=b,m=0;\n        while(t!=1)t=mul(t,t),m++;\n \
    \       ll gs=pw(g,1LL<<(r-m-1));\n        g=mul(gs,gs),x=mul(x,gs),b=mul(b,g),r=m;\n\
    \    }\n    return x;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Tonelli-Shanks.\
    \ Returns $x$ with\n *  $x^2 \\equiv a \\pmod p$ for prime $p$ (the other root\
    \ is $p-x$),\n *  or $-1$ if $a$ is not a quadratic residue.\n * Usage: mod_sqrt(2,7);\
    \ // 3 or 4\n * Time: $O(\\log^2 p)$\n */\n\nll mod_sqrt(ll a,ll p){\n    auto\
    \ mul=[&](ll x,ll y){return ll(i128(x)*y%p);};\n    auto pw=[&](ll b,ll e){\n\
    \        ll r=1;\n        for(;e;b=mul(b,b),e>>=1)if(e&1)r=mul(r,b);\n       \
    \ return r;\n    };\n    a%=p;\n    if(a<0)a+=p;\n    if(a==0||p==2)return a;\n\
    \    if(pw(a,(p-1)/2)!=1)return -1;\n    ll s=p-1,r=0,z=2;\n    while(s%2==0)s/=2,r++;\n\
    \    while(pw(z,(p-1)/2)!=p-1)z++;\n    ll x=pw(a,(s+1)/2),b=pw(a,s),g=pw(z,s);\n\
    \    while(b!=1){\n        ll t=b,m=0;\n        while(t!=1)t=mul(t,t),m++;\n \
    \       ll gs=pw(g,1LL<<(r-m-1));\n        g=mul(gs,gs),x=mul(x,gs),b=mul(b,g),r=m;\n\
    \    }\n    return x;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/number-theory/mod-sqrt.hpp
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/number-theory/mod-sqrt/sqrt_mod.test.cpp
documentation_of: src/number-theory/mod-sqrt.hpp
layout: document
redirect_from:
- /library/src/number-theory/mod-sqrt.hpp
- /library/src/number-theory/mod-sqrt.hpp.html
title: src/number-theory/mod-sqrt.hpp
---
