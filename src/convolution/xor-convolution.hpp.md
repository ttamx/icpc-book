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
  bundledCode: "#line 2 \"src/convolution/xor-convolution.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-07-29\n * Description: Bitwise XOR Convolution.\n *\
    \ Fast Walsh-Hadamard Transform: $A^\\prime[S]=\\sum_T(-1)^{|S\\&T|}A[T]$.\n *\
    \ Time: $O(N\\log N)$.\n */\n\ntemplate<class T>\nvoid fwht(vector<T> &a){\n \
    \   int n=(int)a.size();\n    assert(n==(n&-n));\n    for(int i=1;i<n;i<<=1){\n\
    \        for(int j=0;j<n;j++){\n            if(j&i){\n                T &u=a[j^i],&v=a[j];\n\
    \                tie(u,v)=make_pair(u+v,u-v);\n            }\n        }\n    }\n\
    }\n\ntemplate<class T>\nvector<T> xor_convolution(vector<T> a,vector<T> b){\n\
    \    int n=(int)a.size();\n    fwht(a);\n    fwht(b);\n    for(int i=0;i<n;i++)a[i]*=b[i];\n\
    \    fwht(a);\n    T div=T(1)/T(n);\n    if(div==T(0)){\n        for(auto &x:a)x/=n;\n\
    \    }else{\n        for(auto &x:a)x*=div;\n    }\n    return a;\n}\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-07-29\n * Description:\
    \ Bitwise XOR Convolution.\n * Fast Walsh-Hadamard Transform: $A^\\prime[S]=\\\
    sum_T(-1)^{|S\\&T|}A[T]$.\n * Time: $O(N\\log N)$.\n */\n\ntemplate<class T>\n\
    void fwht(vector<T> &a){\n    int n=(int)a.size();\n    assert(n==(n&-n));\n \
    \   for(int i=1;i<n;i<<=1){\n        for(int j=0;j<n;j++){\n            if(j&i){\n\
    \                T &u=a[j^i],&v=a[j];\n                tie(u,v)=make_pair(u+v,u-v);\n\
    \            }\n        }\n    }\n}\n\ntemplate<class T>\nvector<T> xor_convolution(vector<T>\
    \ a,vector<T> b){\n    int n=(int)a.size();\n    fwht(a);\n    fwht(b);\n    for(int\
    \ i=0;i<n;i++)a[i]*=b[i];\n    fwht(a);\n    T div=T(1)/T(n);\n    if(div==T(0)){\n\
    \        for(auto &x:a)x/=n;\n    }else{\n        for(auto &x:a)x*=div;\n    }\n\
    \    return a;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/xor-convolution.hpp
  requiredBy: []
  timestamp: '2025-07-19 14:58:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/convolution/xor-convolution.hpp
layout: document
redirect_from:
- /library/src/convolution/xor-convolution.hpp
- /library/src/convolution/xor-convolution.hpp.html
title: src/convolution/xor-convolution.hpp
---
