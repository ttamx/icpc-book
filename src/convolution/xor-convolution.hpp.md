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
    \ Teetat T.\n * Date: 2024-07-29\n * Description: Bitwise XOR Convolution. $|A|=|B|$\
    \ must be a power of 2.\n * Fast Walsh-Hadamard Transform: $A^\\prime[S]=\\sum_T(-1)^{|S\\\
    &T|}A[T]$.\n * Time: $O(N\\log N)$.\n */\n\ntemplate<class T>\nvoid fwht(vector<T>\
    \ &a){\n    int n=SZ(a);assert(n==(n&-n));\n    for(int i=1;i<n;i<<=1)for(int\
    \ j=n;j--;)if(j&i){\n        T &u=a[j^i],&v=a[j];tie(u,v)=make_pair(u+v,u-v);\n\
    \    }\n}\ntemplate<class T>\nvector<T> xor_convolution(vector<T> a,vector<T>\
    \ b){\n    int n=SZ(a);fwht(a);fwht(b);\n    for(int i=0;i<n;i++)a[i]*=b[i];\n\
    \    fwht(a);T d=T(1)/T(n);\n    if(d==T(0))for(auto &x:a)x/=n;else for(auto &x:a)x*=d;\n\
    \    return a;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-07-29\n * Description:\
    \ Bitwise XOR Convolution. $|A|=|B|$ must be a power of 2.\n * Fast Walsh-Hadamard\
    \ Transform: $A^\\prime[S]=\\sum_T(-1)^{|S\\&T|}A[T]$.\n * Time: $O(N\\log N)$.\n\
    \ */\n\ntemplate<class T>\nvoid fwht(vector<T> &a){\n    int n=SZ(a);assert(n==(n&-n));\n\
    \    for(int i=1;i<n;i<<=1)for(int j=n;j--;)if(j&i){\n        T &u=a[j^i],&v=a[j];tie(u,v)=make_pair(u+v,u-v);\n\
    \    }\n}\ntemplate<class T>\nvector<T> xor_convolution(vector<T> a,vector<T>\
    \ b){\n    int n=SZ(a);fwht(a);fwht(b);\n    for(int i=0;i<n;i++)a[i]*=b[i];\n\
    \    fwht(a);T d=T(1)/T(n);\n    if(d==T(0))for(auto &x:a)x/=n;else for(auto &x:a)x*=d;\n\
    \    return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/xor-convolution.hpp
  requiredBy: []
  timestamp: '2026-10-04 01:45:10+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/convolution/xor-convolution.hpp
layout: document
redirect_from:
- /library/src/convolution/xor-convolution.hpp
- /library/src/convolution/xor-convolution.hpp.html
title: src/convolution/xor-convolution.hpp
---
