---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/number-theory/crt.hpp
    title: src/number-theory/crt.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/number-theory/euclid.hpp\"\n\n/**\n * Author: Unknown\n\
    \ * Date: 2002-09-15\n * Source: predates tinyKACTL\n * Description: Finds two\
    \ integers $x$ and $y$,such that $ax+by=\\gcd(a,b)$. If\n * you just need gcd,\
    \ use the built in \\texttt{\\_\\_gcd} instead.\n * If $a$ and $b$ are coprime,\
    \ then $x$ is the inverse of $a \\pmod{b}$.\n * $x = x_0 + k * (b / g)$\n * $y\
    \ = y_0 - k * (a / g)$\n */\n\nll euclid(ll a,ll b,ll &x,ll &y){\n\tif(!b)return\
    \ x=1,y=0,a;\n\tll d=euclid(b,a%b,y,x);\n\treturn y-=a/b*x,d;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Unknown\n * Date: 2002-09-15\n * Source:\
    \ predates tinyKACTL\n * Description: Finds two integers $x$ and $y$,such that\
    \ $ax+by=\\gcd(a,b)$. If\n * you just need gcd, use the built in \\texttt{\\_\\\
    _gcd} instead.\n * If $a$ and $b$ are coprime, then $x$ is the inverse of $a \\\
    pmod{b}$.\n * $x = x_0 + k * (b / g)$\n * $y = y_0 - k * (a / g)$\n */\n\nll euclid(ll\
    \ a,ll b,ll &x,ll &y){\n\tif(!b)return x=1,y=0,a;\n\tll d=euclid(b,a%b,y,x);\n\
    \treturn y-=a/b*x,d;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/number-theory/euclid.hpp
  requiredBy:
  - src/number-theory/crt.hpp
  timestamp: '2025-07-19 14:29:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/number-theory/euclid.hpp
layout: document
redirect_from:
- /library/src/number-theory/euclid.hpp
- /library/src/number-theory/euclid.hpp.html
title: src/number-theory/euclid.hpp
---
