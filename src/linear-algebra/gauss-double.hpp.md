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
  bundledCode: "#line 2 \"src/linear-algebra/gauss-double.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Description: Gauss-Jordan elimination over reals with partial\n\
    \ * pivoting (max $|a_{ij}|$ in column). \\texttt{solve\\_db} solves\n * $Ax=b$\
    \ ($A$ is $n\\times m$), returns rank or $-1$ if inconsistent;\n * free variables\
    \ are set to $0$. \\texttt{det\\_db} returns $\\det A$.\n * Beware, entries with\
    \ $|a|<$ EPS are treated as $0$, so scale\n * the input to magnitude $\\approx\
    \ 1$ (EPS is absolute). Ill-conditioned\n * systems (e.g. Hilbert matrices) give\
    \ garbage; for integer data use\n * the mod-$p$ version (\\texttt{db} has a 64-bit\
    \ mantissa, so exact\n * integers beyond $\\approx 10^{18}$ are lost). Check residual\
    \ $|Ax-b|$.\n * Time: $O(nm\\cdot\\min(n,m))$\n */\n\nusing vd=vector<db>;\n\n\
    int gauss_db(vector<vd> &a,int c,db &d,vector<int> &piv){\n    int n=SZ(a),r=0;d=1,piv.clear();\n\
    \    for(int j=0;j<c&&r<n;j++){\n        int p=r;\n        for(int i=r;i<n;i++)\n\
    \            if(fabsl(a[i][j])>fabsl(a[p][j]))p=i;\n        if(fabsl(a[p][j])<EPS)continue;\n\
    \        if(p!=r)swap(a[p],a[r]),d=-d;\n        auto &ar=a[r];db v=ar[j];d*=v;\n\
    \        for(int k=j;k<SZ(ar);k++)ar[k]/=v;\n        for(int i=0;i<n;i++)if(i!=r&&fabsl(a[i][j])>0){\n\
    \            db f=a[i][j];\n            for(int k=j;k<SZ(ar);k++)a[i][k]-=f*ar[k];\n\
    \        }\n        piv.pb(j),r++;\n    }\n    if(r<c)d=0;\n    return r;\n}\n\
    db det_db(vector<vd> a){\n    db d;vector<int> p;gauss_db(a,SZ(a),d,p);return\
    \ d;\n}\nint solve_db(vector<vd> a,const vd &b,int m,vd &x){\n    int n=SZ(a);db\
    \ d;vector<int> p;\n    for(int i=0;i<n;i++)a[i].pb(b[i]);\n    int r=gauss_db(a,m,d,p);\n\
    \    for(int i=r;i<n;i++)if(fabsl(a[i][m])>EPS)return -1;\n    x.assign(m,0);\n\
    \    for(int i=0;i<r;i++)x[p[i]]=a[i][m];\n    return r;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Gauss-Jordan elimination\
    \ over reals with partial\n * pivoting (max $|a_{ij}|$ in column). \\texttt{solve\\\
    _db} solves\n * $Ax=b$ ($A$ is $n\\times m$), returns rank or $-1$ if inconsistent;\n\
    \ * free variables are set to $0$. \\texttt{det\\_db} returns $\\det A$.\n * Beware,\
    \ entries with $|a|<$ EPS are treated as $0$, so scale\n * the input to magnitude\
    \ $\\approx 1$ (EPS is absolute). Ill-conditioned\n * systems (e.g. Hilbert matrices)\
    \ give garbage; for integer data use\n * the mod-$p$ version (\\texttt{db} has\
    \ a 64-bit mantissa, so exact\n * integers beyond $\\approx 10^{18}$ are lost).\
    \ Check residual $|Ax-b|$.\n * Time: $O(nm\\cdot\\min(n,m))$\n */\n\nusing vd=vector<db>;\n\
    \nint gauss_db(vector<vd> &a,int c,db &d,vector<int> &piv){\n    int n=SZ(a),r=0;d=1,piv.clear();\n\
    \    for(int j=0;j<c&&r<n;j++){\n        int p=r;\n        for(int i=r;i<n;i++)\n\
    \            if(fabsl(a[i][j])>fabsl(a[p][j]))p=i;\n        if(fabsl(a[p][j])<EPS)continue;\n\
    \        if(p!=r)swap(a[p],a[r]),d=-d;\n        auto &ar=a[r];db v=ar[j];d*=v;\n\
    \        for(int k=j;k<SZ(ar);k++)ar[k]/=v;\n        for(int i=0;i<n;i++)if(i!=r&&fabsl(a[i][j])>0){\n\
    \            db f=a[i][j];\n            for(int k=j;k<SZ(ar);k++)a[i][k]-=f*ar[k];\n\
    \        }\n        piv.pb(j),r++;\n    }\n    if(r<c)d=0;\n    return r;\n}\n\
    db det_db(vector<vd> a){\n    db d;vector<int> p;gauss_db(a,SZ(a),d,p);return\
    \ d;\n}\nint solve_db(vector<vd> a,const vd &b,int m,vd &x){\n    int n=SZ(a);db\
    \ d;vector<int> p;\n    for(int i=0;i<n;i++)a[i].pb(b[i]);\n    int r=gauss_db(a,m,d,p);\n\
    \    for(int i=r;i<n;i++)if(fabsl(a[i][m])>EPS)return -1;\n    x.assign(m,0);\n\
    \    for(int i=0;i<r;i++)x[p[i]]=a[i][m];\n    return r;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/linear-algebra/gauss-double.hpp
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/linear-algebra/gauss-double.hpp
layout: document
redirect_from:
- /library/src/linear-algebra/gauss-double.hpp
- /library/src/linear-algebra/gauss-double.hpp.html
title: src/linear-algebra/gauss-double.hpp
---
