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
  bundledCode: "#line 2 \"src/convolution/max-plus-convolution.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-09-01\n * Description: Max Plus Convolution. Find $C[k]=\\\
    max_{i+j=k}\\{A[i]+B[j]\\}$\n * for arbitrary $A$ and concave $B$ ($B[i]-B[i-1]\\\
    ge B[i+1]-B[i]$).\n * smawck is the SMAWK algorithm for row-wise maxima of a totally\n\
    \ * monotone matrix; f(i,j,k) is true if $M[i][j]\\le M[i][k]$\n * (i.e. column\
    \ k is at least as good as j, higher is better).\n * Time: $O(N+M)$.\n */\n\n\
    template<class F>\nvector<int> smawck(const F &f,const vector<int> &rows,\n  \
    \                 const vector<int> &cols){\n    int n=SZ(rows),m=SZ(cols);\n\
    \    if(max(n,m)<=2){\n        vector<int> ans(n,-1);\n        for(int i=0;i<n;i++)for(int\
    \ j:cols)\n            if(ans[i]==-1||f(rows[i],ans[i],j))ans[i]=j;\n        return\
    \ ans;\n    }\n    if(n<m){\n        vector<int> st;\n        for(int j:cols){\n\
    \            while(SZ(st)&&f(rows[SZ(st)-1],st.back(),j))\n                st.pop_back();\n\
    \            if(SZ(st)<n)st.emplace_back(j);\n        }\n        return smawck(f,rows,st);\n\
    \    }\n    vector<int> ans(n,-1),nr;\n    for(int i=1;i<n;i+=2)nr.emplace_back(rows[i]);\n\
    \    auto res=smawck(f,nr,cols);\n    for(int i=0;i<SZ(nr);i++)ans[2*i+1]=res[i];\n\
    \    for(int i=0,l=0,r=0;i<n;i+=2){\n        if(i+1==n)r=m;\n        while(r<m&&cols[r]<=ans[i+1])r++;\n\
    \        for(ans[i]=cols[l];l+1<r;)\n            if(f(rows[i],ans[i],cols[++l]))ans[i]=cols[l];\n\
    \    }\n    return ans;\n}\ntemplate<class F>\nvector<int> smawck(const F &f,int\
    \ n,int m){\n    vector<int> r(n),c(m);iota(ALL(r),0);iota(ALL(c),0);\n    return\
    \ smawck(f,r,c);\n}\ntemplate<class T>\nvector<T> max_plus_convolution_arbitary_convex(vector<T>\
    \ a,\n        const vector<T> &b){\n    int n=SZ(a),m=SZ(b);if(!n||!m)return {};\n\
    \    if(m==1){for(auto &x:a)x+=b[0];return a;}\n    auto f=[&](int i,int j){return\
    \ a[j]+b[i-j];};\n    auto cmp=[&](int i,int j,int k){\n        return i>=k&&(i-j>=m||f(i,j)<=f(i,k));};\n\
    \    auto best=smawck(cmp,n+m-1,n);vector<T> ans(n+m-1);\n    for(int i=0;i<n+m-1;i++)ans[i]=f(i,best[i]);\n\
    \    return ans;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-09-01\n * Description:\
    \ Max Plus Convolution. Find $C[k]=\\max_{i+j=k}\\{A[i]+B[j]\\}$\n * for arbitrary\
    \ $A$ and concave $B$ ($B[i]-B[i-1]\\ge B[i+1]-B[i]$).\n * smawck is the SMAWK\
    \ algorithm for row-wise maxima of a totally\n * monotone matrix; f(i,j,k) is\
    \ true if $M[i][j]\\le M[i][k]$\n * (i.e. column k is at least as good as j, higher\
    \ is better).\n * Time: $O(N+M)$.\n */\n\ntemplate<class F>\nvector<int> smawck(const\
    \ F &f,const vector<int> &rows,\n                   const vector<int> &cols){\n\
    \    int n=SZ(rows),m=SZ(cols);\n    if(max(n,m)<=2){\n        vector<int> ans(n,-1);\n\
    \        for(int i=0;i<n;i++)for(int j:cols)\n            if(ans[i]==-1||f(rows[i],ans[i],j))ans[i]=j;\n\
    \        return ans;\n    }\n    if(n<m){\n        vector<int> st;\n        for(int\
    \ j:cols){\n            while(SZ(st)&&f(rows[SZ(st)-1],st.back(),j))\n       \
    \         st.pop_back();\n            if(SZ(st)<n)st.emplace_back(j);\n      \
    \  }\n        return smawck(f,rows,st);\n    }\n    vector<int> ans(n,-1),nr;\n\
    \    for(int i=1;i<n;i+=2)nr.emplace_back(rows[i]);\n    auto res=smawck(f,nr,cols);\n\
    \    for(int i=0;i<SZ(nr);i++)ans[2*i+1]=res[i];\n    for(int i=0,l=0,r=0;i<n;i+=2){\n\
    \        if(i+1==n)r=m;\n        while(r<m&&cols[r]<=ans[i+1])r++;\n        for(ans[i]=cols[l];l+1<r;)\n\
    \            if(f(rows[i],ans[i],cols[++l]))ans[i]=cols[l];\n    }\n    return\
    \ ans;\n}\ntemplate<class F>\nvector<int> smawck(const F &f,int n,int m){\n  \
    \  vector<int> r(n),c(m);iota(ALL(r),0);iota(ALL(c),0);\n    return smawck(f,r,c);\n\
    }\ntemplate<class T>\nvector<T> max_plus_convolution_arbitary_convex(vector<T>\
    \ a,\n        const vector<T> &b){\n    int n=SZ(a),m=SZ(b);if(!n||!m)return {};\n\
    \    if(m==1){for(auto &x:a)x+=b[0];return a;}\n    auto f=[&](int i,int j){return\
    \ a[j]+b[i-j];};\n    auto cmp=[&](int i,int j,int k){\n        return i>=k&&(i-j>=m||f(i,j)<=f(i,k));};\n\
    \    auto best=smawck(cmp,n+m-1,n);vector<T> ans(n+m-1);\n    for(int i=0;i<n+m-1;i++)ans[i]=f(i,best[i]);\n\
    \    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/max-plus-convolution.hpp
  requiredBy: []
  timestamp: '2026-10-04 01:45:10+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/convolution/max-plus-convolution.hpp
layout: document
redirect_from:
- /library/src/convolution/max-plus-convolution.hpp
- /library/src/convolution/max-plus-convolution.hpp.html
title: src/convolution/max-plus-convolution.hpp
---
