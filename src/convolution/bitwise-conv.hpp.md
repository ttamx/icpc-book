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
  bundledCode: "#line 2 \"src/convolution/bitwise-conv.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-07-29\n * Description: Bitwise AND/OR/XOR convolution. $|A|=|B|$\
    \ must be\n * equal and a power of 2.\n * Superset zeta: $A^\\prime[S]=\\sum_{T\\\
    supseteq S}A[T]$ (AND).\n * Subset zeta: $A^\\prime[S]=\\sum_{T\\subseteq S}A[T]$\
    \ (OR).\n * Mobius transforms are their inverses.\n * XOR FWHT: $A^\\prime[S]=\\\
    sum_T(-1)^{|S\\&T|}A[T]$.\n * Time: $O(N\\log N)$.\n */\n\ntemplate<class T> void\
    \ superset_zeta(vector<T> &a){\n    int n=SZ(a);assert(n==(n&-n));\n    for(int\
    \ i=1;i<n;i<<=1)for(int j=n;j--;)if(j&i)a[j^i]+=a[j];\n}\ntemplate<class T> void\
    \ superset_mobius(vector<T> &a){\n    int n=SZ(a);assert(n==(n&-n));\n    for(int\
    \ i=n;i>>=1;)for(int j=n;j--;)if(j&i)a[j^i]-=a[j];\n}\ntemplate<class T> void\
    \ subset_zeta(vector<T> &a){\n    int n=SZ(a);assert(n==(n&-n));\n    for(int\
    \ i=1;i<n;i<<=1)for(int j=n;j--;)if(j&i)a[j]+=a[j^i];\n}\ntemplate<class T> void\
    \ subset_mobius(vector<T> &a){\n    int n=SZ(a);assert(n==(n&-n));\n    for(int\
    \ i=n;i>>=1;)for(int j=n;j--;)if(j&i)a[j]-=a[j^i];\n}\ntemplate<class T> void\
    \ fwht(vector<T> &a){\n    int n=SZ(a);assert(n==(n&-n));\n    for(int i=1;i<n;i<<=1)for(int\
    \ j=n;j--;)if(j&i){\n        T &u=a[j^i],&v=a[j];tie(u,v)=make_pair(u+v,u-v);\n\
    \    }\n}\ntemplate<class T> vector<T> and_conv(vector<T> a,vector<T> b){\n  \
    \  superset_zeta(a);superset_zeta(b);\n    for(int i=0;i<SZ(a);i++)a[i]*=b[i];\n\
    \    superset_mobius(a);return a;\n}\ntemplate<class T> vector<T> or_conv(vector<T>\
    \ a,vector<T> b){\n    subset_zeta(a);subset_zeta(b);\n    for(int i=0;i<SZ(a);i++)a[i]*=b[i];\n\
    \    subset_mobius(a);return a;\n}\ntemplate<class T> vector<T> xor_conv(vector<T>\
    \ a,vector<T> b){\n    int n=SZ(a);fwht(a);fwht(b);\n    for(int i=0;i<n;i++)a[i]*=b[i];\n\
    \    fwht(a);T d=T(1)/T(n);\n    if(d==T(0))for(auto &x:a)x/=n;else for(auto &x:a)x*=d;\n\
    \    return a;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-07-29\n * Description:\
    \ Bitwise AND/OR/XOR convolution. $|A|=|B|$ must be\n * equal and a power of 2.\n\
    \ * Superset zeta: $A^\\prime[S]=\\sum_{T\\supseteq S}A[T]$ (AND).\n * Subset\
    \ zeta: $A^\\prime[S]=\\sum_{T\\subseteq S}A[T]$ (OR).\n * Mobius transforms are\
    \ their inverses.\n * XOR FWHT: $A^\\prime[S]=\\sum_T(-1)^{|S\\&T|}A[T]$.\n *\
    \ Time: $O(N\\log N)$.\n */\n\ntemplate<class T> void superset_zeta(vector<T>\
    \ &a){\n    int n=SZ(a);assert(n==(n&-n));\n    for(int i=1;i<n;i<<=1)for(int\
    \ j=n;j--;)if(j&i)a[j^i]+=a[j];\n}\ntemplate<class T> void superset_mobius(vector<T>\
    \ &a){\n    int n=SZ(a);assert(n==(n&-n));\n    for(int i=n;i>>=1;)for(int j=n;j--;)if(j&i)a[j^i]-=a[j];\n\
    }\ntemplate<class T> void subset_zeta(vector<T> &a){\n    int n=SZ(a);assert(n==(n&-n));\n\
    \    for(int i=1;i<n;i<<=1)for(int j=n;j--;)if(j&i)a[j]+=a[j^i];\n}\ntemplate<class\
    \ T> void subset_mobius(vector<T> &a){\n    int n=SZ(a);assert(n==(n&-n));\n \
    \   for(int i=n;i>>=1;)for(int j=n;j--;)if(j&i)a[j]-=a[j^i];\n}\ntemplate<class\
    \ T> void fwht(vector<T> &a){\n    int n=SZ(a);assert(n==(n&-n));\n    for(int\
    \ i=1;i<n;i<<=1)for(int j=n;j--;)if(j&i){\n        T &u=a[j^i],&v=a[j];tie(u,v)=make_pair(u+v,u-v);\n\
    \    }\n}\ntemplate<class T> vector<T> and_conv(vector<T> a,vector<T> b){\n  \
    \  superset_zeta(a);superset_zeta(b);\n    for(int i=0;i<SZ(a);i++)a[i]*=b[i];\n\
    \    superset_mobius(a);return a;\n}\ntemplate<class T> vector<T> or_conv(vector<T>\
    \ a,vector<T> b){\n    subset_zeta(a);subset_zeta(b);\n    for(int i=0;i<SZ(a);i++)a[i]*=b[i];\n\
    \    subset_mobius(a);return a;\n}\ntemplate<class T> vector<T> xor_conv(vector<T>\
    \ a,vector<T> b){\n    int n=SZ(a);fwht(a);fwht(b);\n    for(int i=0;i<n;i++)a[i]*=b[i];\n\
    \    fwht(a);T d=T(1)/T(n);\n    if(d==T(0))for(auto &x:a)x/=n;else for(auto &x:a)x*=d;\n\
    \    return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/bitwise-conv.hpp
  requiredBy: []
  timestamp: '2026-10-26 18:23:08+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/convolution/bitwise-conv.hpp
layout: document
redirect_from:
- /library/src/convolution/bitwise-conv.hpp
- /library/src/convolution/bitwise-conv.hpp.html
title: src/convolution/bitwise-conv.hpp
---
