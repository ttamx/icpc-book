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
  bundledCode: "#line 2 \"src/polynomials/lagrange-interpolate.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Description: Given $f(0), \\dots, f(n-1)$ of a polynomial $f$\
    \ of degree $< n$, return $f(c)$. Requires $n \\le$ mod.\n * Time: $O(N)$\n */\n\
    \ntemplate<class mint>\nmint lagrange_interpolate(const vector<mint> &f,mint c){\n\
    \    int n=f.size();\n    if(n==0)return 0;\n    if(c.val()<n)return f[c.val()];\n\
    \    vector<mint> l(n+1),r(n+1),ifac(n);\n    l[0]=r[n]=ifac[0]=1;\n    for(int\
    \ i=0;i<n;i++)l[i+1]=l[i]*(c-i);\n    for(int i=n-1;i>=0;i--)r[i]=r[i+1]*(c-i);\n\
    \    for(int i=1;i<n;i++)ifac[i]=ifac[i-1]*i;\n    ifac[n-1]=ifac[n-1].inv();\n\
    \    for(int i=n-1;i>1;i--)ifac[i-1]=ifac[i]*i;\n    mint ans=0;\n    for(int\
    \ i=0;i<n;i++){\n        mint cur=f[i]*ifac[i]*ifac[n-i-1];\n        if((n-i-1)&1)cur*=-1;\n\
    \        ans+=cur*l[i]*r[i+1];\n    }\n    return ans;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Given $f(0), \\\
    dots, f(n-1)$ of a polynomial $f$ of degree $< n$, return $f(c)$. Requires $n\
    \ \\le$ mod.\n * Time: $O(N)$\n */\n\ntemplate<class mint>\nmint lagrange_interpolate(const\
    \ vector<mint> &f,mint c){\n    int n=f.size();\n    if(n==0)return 0;\n    if(c.val()<n)return\
    \ f[c.val()];\n    vector<mint> l(n+1),r(n+1),ifac(n);\n    l[0]=r[n]=ifac[0]=1;\n\
    \    for(int i=0;i<n;i++)l[i+1]=l[i]*(c-i);\n    for(int i=n-1;i>=0;i--)r[i]=r[i+1]*(c-i);\n\
    \    for(int i=1;i<n;i++)ifac[i]=ifac[i-1]*i;\n    ifac[n-1]=ifac[n-1].inv();\n\
    \    for(int i=n-1;i>1;i--)ifac[i-1]=ifac[i]*i;\n    mint ans=0;\n    for(int\
    \ i=0;i<n;i++){\n        mint cur=f[i]*ifac[i]*ifac[n-i-1];\n        if((n-i-1)&1)cur*=-1;\n\
    \        ans+=cur*l[i]*r[i+1];\n    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/polynomials/lagrange-interpolate.hpp
  requiredBy: []
  timestamp: '2026-10-03 23:15:31+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/polynomials/lagrange-interpolate.hpp
layout: document
redirect_from:
- /library/src/polynomials/lagrange-interpolate.hpp
- /library/src/polynomials/lagrange-interpolate.hpp.html
title: src/polynomials/lagrange-interpolate.hpp
---
