---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/linear-algebra/gauss-mod/inverse_matrix.test.cpp
    title: verify/linear-algebra/gauss-mod/inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/linear-algebra/gauss-mod/matrix_det.test.cpp
    title: verify/linear-algebra/gauss-mod/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/linear-algebra/gauss-mod/matrix_rank.test.cpp
    title: verify/linear-algebra/gauss-mod/matrix_rank.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/linear-algebra/gauss-mod/system_of_linear_equations.test.cpp
    title: verify/linear-algebra/gauss-mod/system_of_linear_equations.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/linear-algebra/gauss-mod.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Description: Gauss-Jordan elimination over a field $\\mathbb{Z}_p$.\n\
    \ * \\texttt{gauss(a,c,d)} reduces $a$ to RREF on its first $c$ columns\n * (later\
    \ columns are carried along), returns pivot columns and sets\n * $d=\\det$ of\
    \ the left $c\\times c$ block (for square use).\n * \\texttt{solve} returns rank\
    \ or $-1$ if inconsistent, a solution $x$\n * (free vars $=0$) and a basis $K$\
    \ of $\\{x : Ax=0\\}$ ($|K|=m-$rank).\n * \\texttt{mat\\_inv} returns false if\
    \ singular (then $a$ is garbage).\n * Usage: Mat<mint> A(n,vector<mint>(m)); int\
    \ r=solve(A,b,m,x,K);\n * Time: $O(nm\\cdot\\min(n,m))$; $500\\times 500$ det\
    \ takes 60ms.\n */\n\ntemplate<class T>\nusing Mat=vector<vector<T>>;\n\ntemplate<class\
    \ T>\nvector<int> gauss(Mat<T> &a,int c,T &d){\n    int n=SZ(a),r=0;\n    vector<int>\
    \ piv;d=1;\n    for(int j=0;j<c&&r<n;j++){\n        int p=r;\n        while(p<n&&a[p][j]==0)p++;\n\
    \        if(p==n)continue;\n        if(p!=r)swap(a[p],a[r]),d=-d;\n        auto\
    \ &ar=a[r];\n        d*=ar[j];T iv=ar[j].inv();\n        for(int k=j;k<SZ(ar);k++)ar[k]*=iv;\n\
    \        for(int i=0;i<n;i++)if(i!=r&&!(a[i][j]==0)){\n            T f=a[i][j];\n\
    \            for(int k=j;k<SZ(ar);k++)a[i][k]-=f*ar[k];\n        }\n        piv.pb(j),r++;\n\
    \    }\n    if(r<c)d=0;\n    return piv;\n}\ntemplate<class T>\nT mat_det(Mat<T>\
    \ a){T d;gauss(a,SZ(a),d);return d;}\ntemplate<class T>\nint mat_rank(Mat<T> a,int\
    \ m){T d;return SZ(gauss(a,m,d));}\ntemplate<class T>\nbool mat_inv(Mat<T> &a){\n\
    \    int n=SZ(a);T d;\n    for(int i=0;i<n;i++)a[i].resize(2*n),a[i][n+i]=1;\n\
    \    if(SZ(gauss(a,n,d))<n)return 0;\n    for(auto &r:a)r.erase(r.begin(),r.begin()+n);\n\
    \    return 1;\n}\ntemplate<class T>\nint solve(Mat<T> a,const vector<T> &b,int\
    \ m,\n          vector<T> &x,Mat<T> &K){\n    int n=SZ(a);T d;\n    for(int i=0;i<n;i++)a[i].pb(b[i]);\n\
    \    auto piv=gauss(a,m,d);\n    int r=SZ(piv);\n    for(int i=r;i<n;i++)if(!(a[i][m]==0))return\
    \ -1;\n    x=vector<T>(m),K.clear();\n    vector<int> fr(m,1);\n    for(int i=0;i<r;i++)x[piv[i]]=a[i][m],fr[piv[i]]=0;\n\
    \    for(int j=0;j<m;j++)if(fr[j]){\n        vector<T> v(m);v[j]=1;\n        for(int\
    \ i=0;i<r;i++)v[piv[i]]=-a[i][j];\n        K.pb(v);\n    }\n    return r;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Gauss-Jordan elimination\
    \ over a field $\\mathbb{Z}_p$.\n * \\texttt{gauss(a,c,d)} reduces $a$ to RREF\
    \ on its first $c$ columns\n * (later columns are carried along), returns pivot\
    \ columns and sets\n * $d=\\det$ of the left $c\\times c$ block (for square use).\n\
    \ * \\texttt{solve} returns rank or $-1$ if inconsistent, a solution $x$\n * (free\
    \ vars $=0$) and a basis $K$ of $\\{x : Ax=0\\}$ ($|K|=m-$rank).\n * \\texttt{mat\\\
    _inv} returns false if singular (then $a$ is garbage).\n * Usage: Mat<mint> A(n,vector<mint>(m));\
    \ int r=solve(A,b,m,x,K);\n * Time: $O(nm\\cdot\\min(n,m))$; $500\\times 500$\
    \ det takes 60ms.\n */\n\ntemplate<class T>\nusing Mat=vector<vector<T>>;\n\n\
    template<class T>\nvector<int> gauss(Mat<T> &a,int c,T &d){\n    int n=SZ(a),r=0;\n\
    \    vector<int> piv;d=1;\n    for(int j=0;j<c&&r<n;j++){\n        int p=r;\n\
    \        while(p<n&&a[p][j]==0)p++;\n        if(p==n)continue;\n        if(p!=r)swap(a[p],a[r]),d=-d;\n\
    \        auto &ar=a[r];\n        d*=ar[j];T iv=ar[j].inv();\n        for(int k=j;k<SZ(ar);k++)ar[k]*=iv;\n\
    \        for(int i=0;i<n;i++)if(i!=r&&!(a[i][j]==0)){\n            T f=a[i][j];\n\
    \            for(int k=j;k<SZ(ar);k++)a[i][k]-=f*ar[k];\n        }\n        piv.pb(j),r++;\n\
    \    }\n    if(r<c)d=0;\n    return piv;\n}\ntemplate<class T>\nT mat_det(Mat<T>\
    \ a){T d;gauss(a,SZ(a),d);return d;}\ntemplate<class T>\nint mat_rank(Mat<T> a,int\
    \ m){T d;return SZ(gauss(a,m,d));}\ntemplate<class T>\nbool mat_inv(Mat<T> &a){\n\
    \    int n=SZ(a);T d;\n    for(int i=0;i<n;i++)a[i].resize(2*n),a[i][n+i]=1;\n\
    \    if(SZ(gauss(a,n,d))<n)return 0;\n    for(auto &r:a)r.erase(r.begin(),r.begin()+n);\n\
    \    return 1;\n}\ntemplate<class T>\nint solve(Mat<T> a,const vector<T> &b,int\
    \ m,\n          vector<T> &x,Mat<T> &K){\n    int n=SZ(a);T d;\n    for(int i=0;i<n;i++)a[i].pb(b[i]);\n\
    \    auto piv=gauss(a,m,d);\n    int r=SZ(piv);\n    for(int i=r;i<n;i++)if(!(a[i][m]==0))return\
    \ -1;\n    x=vector<T>(m),K.clear();\n    vector<int> fr(m,1);\n    for(int i=0;i<r;i++)x[piv[i]]=a[i][m],fr[piv[i]]=0;\n\
    \    for(int j=0;j<m;j++)if(fr[j]){\n        vector<T> v(m);v[j]=1;\n        for(int\
    \ i=0;i<r;i++)v[piv[i]]=-a[i][j];\n        K.pb(v);\n    }\n    return r;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/linear-algebra/gauss-mod.hpp
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/linear-algebra/gauss-mod/system_of_linear_equations.test.cpp
  - verify/linear-algebra/gauss-mod/inverse_matrix.test.cpp
  - verify/linear-algebra/gauss-mod/matrix_rank.test.cpp
  - verify/linear-algebra/gauss-mod/matrix_det.test.cpp
documentation_of: src/linear-algebra/gauss-mod.hpp
layout: document
redirect_from:
- /library/src/linear-algebra/gauss-mod.hpp
- /library/src/linear-algebra/gauss-mod.hpp.html
title: src/linear-algebra/gauss-mod.hpp
---
