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
  bundledCode: "#line 2 \"src/convolution/gcd-convolution.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-07-29\n * Description: GCD Convolution.\n * Multiple\
    \ Zeta Transform: $A^\\prime[n]=\\sum_{n|m}A[m]$.\n * Multiple Mobius Transform:\
    \ $A[n]=\\sum_{n|m}\\mu(m/n)A^\\prime[m]$.\n * Time: $O(N\\log\\log N)$.\n */\n\
    \ntemplate<class T>\nvoid multiple_zeta(vector<T> &a){\n    int n=(int)a.size();\n\
    \    vector<bool> is_prime(n,true);\n    for(int p=2;p<n;p++){\n        if(!is_prime[p])continue;\n\
    \        for(int i=(n-1)/p;i>=1;i--){\n            is_prime[i*p]=false;\n    \
    \        a[i]+=a[i*p];\n        }\n    }\n}\n\ntemplate<class T>\nvoid multiple_mobius(vector<T>\
    \ &a){\n    int n=(int)a.size();\n    vector<bool> is_prime(n,true);\n    for(int\
    \ p=2;p<n;p++){\n        if(!is_prime[p])continue;\n        for(int i=1;i*p<n;i++){\n\
    \            is_prime[i*p]=false;\n            a[i]-=a[i*p];\n        }\n    }\n\
    }\n\ntemplate<class T>\nvector<T> gcd_convolution(vector<T> a,vector<T> b){\n\
    \    multiple_zeta(a);\n    multiple_zeta(b);\n    for(int i=0;i<(int)a.size();i++)a[i]*=b[i];\n\
    \    multiple_mobius(a);\n    return a;\n}\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-07-29\n * Description:\
    \ GCD Convolution.\n * Multiple Zeta Transform: $A^\\prime[n]=\\sum_{n|m}A[m]$.\n\
    \ * Multiple Mobius Transform: $A[n]=\\sum_{n|m}\\mu(m/n)A^\\prime[m]$.\n * Time:\
    \ $O(N\\log\\log N)$.\n */\n\ntemplate<class T>\nvoid multiple_zeta(vector<T>\
    \ &a){\n    int n=(int)a.size();\n    vector<bool> is_prime(n,true);\n    for(int\
    \ p=2;p<n;p++){\n        if(!is_prime[p])continue;\n        for(int i=(n-1)/p;i>=1;i--){\n\
    \            is_prime[i*p]=false;\n            a[i]+=a[i*p];\n        }\n    }\n\
    }\n\ntemplate<class T>\nvoid multiple_mobius(vector<T> &a){\n    int n=(int)a.size();\n\
    \    vector<bool> is_prime(n,true);\n    for(int p=2;p<n;p++){\n        if(!is_prime[p])continue;\n\
    \        for(int i=1;i*p<n;i++){\n            is_prime[i*p]=false;\n         \
    \   a[i]-=a[i*p];\n        }\n    }\n}\n\ntemplate<class T>\nvector<T> gcd_convolution(vector<T>\
    \ a,vector<T> b){\n    multiple_zeta(a);\n    multiple_zeta(b);\n    for(int i=0;i<(int)a.size();i++)a[i]*=b[i];\n\
    \    multiple_mobius(a);\n    return a;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/gcd-convolution.hpp
  requiredBy: []
  timestamp: '2025-07-19 14:58:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/convolution/gcd-convolution.hpp
layout: document
redirect_from:
- /library/src/convolution/gcd-convolution.hpp
- /library/src/convolution/gcd-convolution.hpp.html
title: src/convolution/gcd-convolution.hpp
---
