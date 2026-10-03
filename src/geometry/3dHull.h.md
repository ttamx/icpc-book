---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/Point3D.h
    title: src/geometry/Point3D.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/DelaunayTriangulation.h
    title: src/geometry/DelaunayTriangulation.h
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://gist.github.com/msg555/4963794
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/3dHull.h: line 11: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Johan Sannemo\n * Date: 2017-04-18\n * Source: derived from\
    \ https://gist.github.com/msg555/4963794 by Mark Gordon\n * Description: Computes\
    \ all faces of the 3-dimension hull of a point set.\n *  *No four points must\
    \ be coplanar*, or else random results will be returned.\n *  All faces will point\
    \ outwards.\n * Time: O(n^2)\n * Status: tested on SPOJ CH3D\n */\n#pragma once\n\
    \n#include \"Point3D.h\"\n\ntypedef Point3D<double> P3;\n\nstruct PR{\n\tvoid\
    \ ins(int x){(a==-1?a:b)=x;}\n\tvoid rem(int x){(a==x?a:b)=-1;}\n\tint cnt(){return\
    \ (a!=-1)+(b!=-1);}\n\tint a,b;\n};\n\nstruct F{P3 q;int a,b,c;};\n\nvector<F>\
    \ hull3d(const vector<P3>& A){\n\tassert(SZ(A)>=4);\n\tvector<vector<PR>> E(SZ(A),vector<PR>(SZ(A),{-1,-1}));\n\
    #define E(x,y) E[f.x][f.y]\n\tvector<F> FS;\n\tauto mf=[&](int i,int j,int k,int\
    \ l){\n\t\tP3 q=(A[j]-A[i]).cross((A[k]-A[i]));\n\t\tif(q.dot(A[l])>q.dot(A[i]))q=q*-1;\n\
    \t\tF f{q,i,j,k};\n\t\tE(a,b).ins(k);E(a,c).ins(j);E(b,c).ins(i);\n\t\tFS.push_back(f);\n\
    \t};\n\tfor(int i=0;i<4;i++)for(int j=i+1;j<4;j++)\n\t\tfor(int k=j+1;k<4;k++)mf(i,j,k,6-i-j-k);\n\
    \tfor(int i=4;i<SZ(A);i++){\n\t\tfor(int j=0;j<SZ(FS);j++){\n\t\t\tF f=FS[j];\n\
    \t\t\tif(f.q.dot(A[i])>f.q.dot(A[f.a])){\n\t\t\t\tE(a,b).rem(f.c);E(a,c).rem(f.b);E(b,c).rem(f.a);\n\
    \t\t\t\tswap(FS[j--],FS.back());FS.pop_back();\n\t\t\t}\n\t\t}\n\t\tint nw=SZ(FS);\n\
    \t\tfor(int j=0;j<nw;j++){\n\t\t\tF f=FS[j];\n#define C(a,b,c) if(E(a,b).cnt()!=2)mf(f.a,f.b,i,f.c);\n\
    \t\t\tC(a,b,c);C(a,c,b);C(b,c,a);\n\t\t}\n\t}\n\tfor(F& it:FS)if((A[it.b]-A[it.a]).cross(\n\
    \t\tA[it.c]-A[it.a]).dot(it.q)<=0)swap(it.c,it.b);\n\treturn FS;\n}\n"
  dependsOn:
  - src/geometry/Point3D.h
  isVerificationFile: false
  path: src/geometry/3dHull.h
  requiredBy:
  - src/geometry/DelaunayTriangulation.h
  timestamp: '2026-10-03 23:15:31+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/3dHull.h
layout: document
redirect_from:
- /library/src/geometry/3dHull.h
- /library/src/geometry/3dHull.h.html
title: src/geometry/3dHull.h
---
