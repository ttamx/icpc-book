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
  bundledCode: "#line 2 \"src/convolution/or-convolution.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-07-29\n * Description: Bitwise OR Convolution. $|A|=|B|$\
    \ must be a power of 2.\n * Subset Zeta Transform: $A^\\prime[S]=\\sum_{T\\subseteq\
    \ S}A[T]$.\n * Subset Mobius Transform: $A[T]=\\sum_{S\\subseteq T}(-1)^{|T-S|}A^\\\
    prime[S]$.\n * Time: $O(N\\log N)$.\n */\n\ntemplate<class T>\nvoid subset_zeta(vector<T>\
    \ &a){\n    int n=SZ(a);assert(n==(n&-n));\n    for(int i=1;i<n;i<<=1)for(int\
    \ j=n;j--;)if(j&i)a[j]+=a[j^i];\n}\ntemplate<class T>\nvoid subset_mobius(vector<T>\
    \ &a){\n    int n=SZ(a);assert(n==(n&-n));\n    for(int i=n;i>>=1;)for(int j=n;j--;)if(j&i)a[j]-=a[j^i];\n\
    }\ntemplate<class T>\nvector<T> or_convolution(vector<T> a,vector<T> b){\n   \
    \ subset_zeta(a);subset_zeta(b);\n    for(int i=0;i<SZ(a);i++)a[i]*=b[i];\n  \
    \  subset_mobius(a);return a;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-07-29\n * Description:\
    \ Bitwise OR Convolution. $|A|=|B|$ must be a power of 2.\n * Subset Zeta Transform:\
    \ $A^\\prime[S]=\\sum_{T\\subseteq S}A[T]$.\n * Subset Mobius Transform: $A[T]=\\\
    sum_{S\\subseteq T}(-1)^{|T-S|}A^\\prime[S]$.\n * Time: $O(N\\log N)$.\n */\n\n\
    template<class T>\nvoid subset_zeta(vector<T> &a){\n    int n=SZ(a);assert(n==(n&-n));\n\
    \    for(int i=1;i<n;i<<=1)for(int j=n;j--;)if(j&i)a[j]+=a[j^i];\n}\ntemplate<class\
    \ T>\nvoid subset_mobius(vector<T> &a){\n    int n=SZ(a);assert(n==(n&-n));\n\
    \    for(int i=n;i>>=1;)for(int j=n;j--;)if(j&i)a[j]-=a[j^i];\n}\ntemplate<class\
    \ T>\nvector<T> or_convolution(vector<T> a,vector<T> b){\n    subset_zeta(a);subset_zeta(b);\n\
    \    for(int i=0;i<SZ(a);i++)a[i]*=b[i];\n    subset_mobius(a);return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/or-convolution.hpp
  requiredBy: []
  timestamp: '2026-10-04 01:45:10+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/convolution/or-convolution.hpp
layout: document
redirect_from:
- /library/src/convolution/or-convolution.hpp
- /library/src/convolution/or-convolution.hpp.html
title: src/convolution/or-convolution.hpp
---
