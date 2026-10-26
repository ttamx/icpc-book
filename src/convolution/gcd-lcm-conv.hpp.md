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
  bundledCode: "#line 2 \"src/convolution/gcd-lcm-conv.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-07-29\n * Description: GCD/LCM convolution on indices $1..n-1$\
    \ (index 0\n * is ignored).\n * Multiple zeta: $A^\\prime[n]=\\sum_{n|m}A[m]$\
    \ (GCD).\n * Divisor zeta: $A^\\prime[n]=\\sum_{d|n}A[d]$ (LCM).\n * Mobius transforms\
    \ are their inverses.\n * Time: $O(N\\log\\log N)$.\n */\n\ntemplate<class T>\
    \ void multiple_zeta(vector<T> &a){\n    int n=SZ(a);vector<bool> pr(n,1);\n \
    \   for(int p=2;p<n;p++)if(pr[p])\n        for(int i=(n-1)/p;i>0;i--)pr[i*p]=0,a[i]+=a[i*p];\n\
    }\ntemplate<class T> void multiple_mobius(vector<T> &a){\n    int n=SZ(a);vector<bool>\
    \ pr(n,1);\n    for(int p=2;p<n;p++)if(pr[p])\n        for(int i=1;i*p<n;i++)pr[i*p]=0,a[i]-=a[i*p];\n\
    }\ntemplate<class T> void divisor_zeta(vector<T> &a){\n    int n=SZ(a);vector<bool>\
    \ pr(n,1);\n    for(int p=2;p<n;p++)if(pr[p])\n        for(int i=1;i*p<n;i++)pr[i*p]=0,a[i*p]+=a[i];\n\
    }\ntemplate<class T> void divisor_mobius(vector<T> &a){\n    int n=SZ(a);vector<bool>\
    \ pr(n,1);\n    for(int p=2;p<n;p++)if(pr[p])\n        for(int i=(n-1)/p;i>0;i--)pr[i*p]=0,a[i*p]-=a[i];\n\
    }\ntemplate<class T> vector<T> gcd_conv(vector<T> a,vector<T> b){\n    multiple_zeta(a);multiple_zeta(b);\n\
    \    for(int i=0;i<SZ(a);i++)a[i]*=b[i];\n    multiple_mobius(a);return a;\n}\n\
    template<class T> vector<T> lcm_conv(vector<T> a,vector<T> b){\n    divisor_zeta(a);divisor_zeta(b);\n\
    \    for(int i=0;i<SZ(a);i++)a[i]*=b[i];\n    divisor_mobius(a);return a;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-07-29\n * Description:\
    \ GCD/LCM convolution on indices $1..n-1$ (index 0\n * is ignored).\n * Multiple\
    \ zeta: $A^\\prime[n]=\\sum_{n|m}A[m]$ (GCD).\n * Divisor zeta: $A^\\prime[n]=\\\
    sum_{d|n}A[d]$ (LCM).\n * Mobius transforms are their inverses.\n * Time: $O(N\\\
    log\\log N)$.\n */\n\ntemplate<class T> void multiple_zeta(vector<T> &a){\n  \
    \  int n=SZ(a);vector<bool> pr(n,1);\n    for(int p=2;p<n;p++)if(pr[p])\n    \
    \    for(int i=(n-1)/p;i>0;i--)pr[i*p]=0,a[i]+=a[i*p];\n}\ntemplate<class T> void\
    \ multiple_mobius(vector<T> &a){\n    int n=SZ(a);vector<bool> pr(n,1);\n    for(int\
    \ p=2;p<n;p++)if(pr[p])\n        for(int i=1;i*p<n;i++)pr[i*p]=0,a[i]-=a[i*p];\n\
    }\ntemplate<class T> void divisor_zeta(vector<T> &a){\n    int n=SZ(a);vector<bool>\
    \ pr(n,1);\n    for(int p=2;p<n;p++)if(pr[p])\n        for(int i=1;i*p<n;i++)pr[i*p]=0,a[i*p]+=a[i];\n\
    }\ntemplate<class T> void divisor_mobius(vector<T> &a){\n    int n=SZ(a);vector<bool>\
    \ pr(n,1);\n    for(int p=2;p<n;p++)if(pr[p])\n        for(int i=(n-1)/p;i>0;i--)pr[i*p]=0,a[i*p]-=a[i];\n\
    }\ntemplate<class T> vector<T> gcd_conv(vector<T> a,vector<T> b){\n    multiple_zeta(a);multiple_zeta(b);\n\
    \    for(int i=0;i<SZ(a);i++)a[i]*=b[i];\n    multiple_mobius(a);return a;\n}\n\
    template<class T> vector<T> lcm_conv(vector<T> a,vector<T> b){\n    divisor_zeta(a);divisor_zeta(b);\n\
    \    for(int i=0;i<SZ(a);i++)a[i]*=b[i];\n    divisor_mobius(a);return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/gcd-lcm-conv.hpp
  requiredBy: []
  timestamp: '2026-10-26 18:23:08+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/convolution/gcd-lcm-conv.hpp
layout: document
redirect_from:
- /library/src/convolution/gcd-lcm-conv.hpp
- /library/src/convolution/gcd-lcm-conv.hpp.html
title: src/convolution/gcd-lcm-conv.hpp
---
