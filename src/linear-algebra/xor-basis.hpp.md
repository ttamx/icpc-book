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
  bundledCode: "#line 2 \"src/linear-algebra/xor-basis.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Description: Linear basis over GF(2) of 64-bit integers.\n * \\texttt{b[i]}\
    \ has top bit $i$; \\texttt{r} = rank. \\texttt{ins}\n * returns false if $x$\
    \ was already representable (then some\n * nonempty subset xors to $0$). \\texttt{mx(x)}:\
    \ max of $x\\oplus s$,\n * \\texttt{red(x)}: min of $x\\oplus s$ over the span\
    \ $s$ (so $x$ is\n * representable iff \\texttt{red(x)==0}). \\texttt{mn()}: min\
    \ nonzero\n * span value. \\texttt{kth(k)}: $k$-th smallest ($0$-indexed, $k<2^r$,\n\
    \ * $0$ counts) span value.\n * \\texttt{gauss\\_xor}: solves $Ax=b$ over GF(2),\
    \ row $i$ = bits\n * $0..m-1$ of \\texttt{a[i]}, $b_i$ = bit $m$. Returns rank\
    \ or $-1$;\n * free variables $=0$.\n * Time: $O(64)$ per op, \\texttt{kth} $O(64^2)$;\
    \ \\texttt{gauss\\_xor}\n * $O(nm\\cdot\\min(n,m)/64)$.\n */\n\nstruct XorBasis{\n\
    \    u64 b[64]={};int r=0;\n    bool ins(u64 x){\n        for(int i=63;i>=0;i--)if(x>>i&1){\n\
    \            if(!b[i])return b[i]=x,++r;\n            x^=b[i];\n        }\n  \
    \      return 0;\n    }\n    u64 red(u64 x){\n        for(int i=63;i>=0;i--)chmin(x,x^b[i]);\n\
    \        return x;\n    }\n    u64 mx(u64 x=0){\n        for(int i=63;i>=0;i--)chmax(x,x^b[i]);\n\
    \        return x;\n    }\n    u64 mn(){\n        for(int i=0;i<64;i++)if(b[i])return\
    \ b[i];\n        return 0;\n    }\n    u64 kth(u64 k){\n        u64 res=0;int\
    \ t=0;\n        for(int i=0;i<64;i++)if(b[i]){\n            for(int j=i-1;j>=0;j--)if(b[i]>>j&1)b[i]^=b[j];\n\
    \            if(k>>t++&1)res^=b[i];\n        }\n        return res;\n    }\n};\n\
    \ntemplate<size_t N>\nint gauss_xor(vector<bitset<N>> a,int m,bitset<N> &x){\n\
    \    int n=SZ(a),r=0;vector<int> piv;\n    for(int j=0;j<m&&r<n;j++){\n      \
    \  int p=r;\n        while(p<n&&!a[p][j])p++;\n        if(p==n)continue;\n   \
    \     swap(a[p],a[r]);\n        for(int i=0;i<n;i++)if(i!=r&&a[i][j])a[i]^=a[r];\n\
    \        piv.pb(j),r++;\n    }\n    for(int i=r;i<n;i++)if(a[i][m])return -1;\n\
    \    x.reset();\n    for(int i=0;i<r;i++)x[piv[i]]=a[i][m];\n    return r;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Linear basis over\
    \ GF(2) of 64-bit integers.\n * \\texttt{b[i]} has top bit $i$; \\texttt{r} =\
    \ rank. \\texttt{ins}\n * returns false if $x$ was already representable (then\
    \ some\n * nonempty subset xors to $0$). \\texttt{mx(x)}: max of $x\\oplus s$,\n\
    \ * \\texttt{red(x)}: min of $x\\oplus s$ over the span $s$ (so $x$ is\n * representable\
    \ iff \\texttt{red(x)==0}). \\texttt{mn()}: min nonzero\n * span value. \\texttt{kth(k)}:\
    \ $k$-th smallest ($0$-indexed, $k<2^r$,\n * $0$ counts) span value.\n * \\texttt{gauss\\\
    _xor}: solves $Ax=b$ over GF(2), row $i$ = bits\n * $0..m-1$ of \\texttt{a[i]},\
    \ $b_i$ = bit $m$. Returns rank or $-1$;\n * free variables $=0$.\n * Time: $O(64)$\
    \ per op, \\texttt{kth} $O(64^2)$; \\texttt{gauss\\_xor}\n * $O(nm\\cdot\\min(n,m)/64)$.\n\
    \ */\n\nstruct XorBasis{\n    u64 b[64]={};int r=0;\n    bool ins(u64 x){\n  \
    \      for(int i=63;i>=0;i--)if(x>>i&1){\n            if(!b[i])return b[i]=x,++r;\n\
    \            x^=b[i];\n        }\n        return 0;\n    }\n    u64 red(u64 x){\n\
    \        for(int i=63;i>=0;i--)chmin(x,x^b[i]);\n        return x;\n    }\n  \
    \  u64 mx(u64 x=0){\n        for(int i=63;i>=0;i--)chmax(x,x^b[i]);\n        return\
    \ x;\n    }\n    u64 mn(){\n        for(int i=0;i<64;i++)if(b[i])return b[i];\n\
    \        return 0;\n    }\n    u64 kth(u64 k){\n        u64 res=0;int t=0;\n \
    \       for(int i=0;i<64;i++)if(b[i]){\n            for(int j=i-1;j>=0;j--)if(b[i]>>j&1)b[i]^=b[j];\n\
    \            if(k>>t++&1)res^=b[i];\n        }\n        return res;\n    }\n};\n\
    \ntemplate<size_t N>\nint gauss_xor(vector<bitset<N>> a,int m,bitset<N> &x){\n\
    \    int n=SZ(a),r=0;vector<int> piv;\n    for(int j=0;j<m&&r<n;j++){\n      \
    \  int p=r;\n        while(p<n&&!a[p][j])p++;\n        if(p==n)continue;\n   \
    \     swap(a[p],a[r]);\n        for(int i=0;i<n;i++)if(i!=r&&a[i][j])a[i]^=a[r];\n\
    \        piv.pb(j),r++;\n    }\n    for(int i=r;i<n;i++)if(a[i][m])return -1;\n\
    \    x.reset();\n    for(int i=0;i<r;i++)x[piv[i]]=a[i][m];\n    return r;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/linear-algebra/xor-basis.hpp
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/linear-algebra/xor-basis.hpp
layout: document
redirect_from:
- /library/src/linear-algebra/xor-basis.hpp
- /library/src/linear-algebra/xor-basis.hpp.html
title: src/linear-algebra/xor-basis.hpp
---
