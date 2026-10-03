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
  bundledCode: "#line 2 \"src/convolution/lcm-convolution.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-07-29\n * Description: LCM Convolution.\n * Divisor\
    \ Zeta Transform: $A^\\prime[n]=\\sum_{d|n}A[d]$.\n * Divisor Mobius Transform:\
    \ $A[n]=\\sum_{d|n}\\mu(n/d)A^\\prime[d]$.\n * Time: $O(N\\log\\log N)$.\n */\n\
    \ntemplate<class T>\nvoid divisor_zeta(vector<T> &a){\n    int n=SZ(a);vector<bool>\
    \ pr(n,1);\n    for(int p=2;p<n;p++)if(pr[p])\n        for(int i=1;i*p<n;i++)pr[i*p]=0,a[i*p]+=a[i];\n\
    }\ntemplate<class T>\nvoid divisor_mobius(vector<T> &a){\n    int n=SZ(a);vector<bool>\
    \ pr(n,1);\n    for(int p=2;p<n;p++)if(pr[p])\n        for(int i=(n-1)/p;i>0;i--)pr[i*p]=0,a[i*p]-=a[i];\n\
    }\ntemplate<class T>\nvector<T> lcm_convolution(vector<T> a,vector<T> b){\n  \
    \  divisor_zeta(a);divisor_zeta(b);\n    for(int i=0;i<SZ(a);i++)a[i]*=b[i];\n\
    \    divisor_mobius(a);return a;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-07-29\n * Description:\
    \ LCM Convolution.\n * Divisor Zeta Transform: $A^\\prime[n]=\\sum_{d|n}A[d]$.\n\
    \ * Divisor Mobius Transform: $A[n]=\\sum_{d|n}\\mu(n/d)A^\\prime[d]$.\n * Time:\
    \ $O(N\\log\\log N)$.\n */\n\ntemplate<class T>\nvoid divisor_zeta(vector<T> &a){\n\
    \    int n=SZ(a);vector<bool> pr(n,1);\n    for(int p=2;p<n;p++)if(pr[p])\n  \
    \      for(int i=1;i*p<n;i++)pr[i*p]=0,a[i*p]+=a[i];\n}\ntemplate<class T>\nvoid\
    \ divisor_mobius(vector<T> &a){\n    int n=SZ(a);vector<bool> pr(n,1);\n    for(int\
    \ p=2;p<n;p++)if(pr[p])\n        for(int i=(n-1)/p;i>0;i--)pr[i*p]=0,a[i*p]-=a[i];\n\
    }\ntemplate<class T>\nvector<T> lcm_convolution(vector<T> a,vector<T> b){\n  \
    \  divisor_zeta(a);divisor_zeta(b);\n    for(int i=0;i<SZ(a);i++)a[i]*=b[i];\n\
    \    divisor_mobius(a);return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/lcm-convolution.hpp
  requiredBy: []
  timestamp: '2026-10-04 01:45:10+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/convolution/lcm-convolution.hpp
layout: document
redirect_from:
- /library/src/convolution/lcm-convolution.hpp
- /library/src/convolution/lcm-convolution.hpp.html
title: src/convolution/lcm-convolution.hpp
---
