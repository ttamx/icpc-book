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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/3dHull.h: line 11: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Johan Sannemo\n * Date: 2017-04-18\n * Source: derived from\
    \ https://gist.github.com/msg555/4963794 by Mark Gordon\n * Description: Computes\
    \ all faces of the 3-dimension hull of a point set.\n *  *No four points must\
    \ be coplanar*, or else random results will be returned.\n *  All faces will point\
    \ outwards.\n * Time: O(n^2)\n * Status: tested on SPOJ CH3D\n */\n#pragma once\n\
    \n#include \"Point3D.h\"\n\ntypedef Point3D<double> P3;\n\nstruct PR {\n\tvoid\
    \ ins(int x) { (a == -1 ? a : b) = x; }\n\tvoid rem(int x) { (a == x ? a : b)\
    \ = -1; }\n\tint cnt() { return (a != -1) + (b != -1); }\n\tint a, b;\n};\n\n\
    struct F { P3 q; int a, b, c; };\n\nvector<F> hull3d(const vector<P3>& A) {\n\t\
    assert(sz(A) >= 4);\n\tvector<vector<PR>> E(sz(A), vector<PR>(sz(A), {-1, -1}));\n\
    #define E(x,y) E[f.x][f.y]\n\tvector<F> FS;\n\tauto mf = [&](int i, int j, int\
    \ k, int l) {\n\t\tP3 q = (A[j] - A[i]).cross((A[k] - A[i]));\n\t\tif (q.dot(A[l])\
    \ > q.dot(A[i]))\n\t\t\tq = q * -1;\n\t\tF f{q, i, j, k};\n\t\tE(a,b).ins(k);\
    \ E(a,c).ins(j); E(b,c).ins(i);\n\t\tFS.push_back(f);\n\t};\n\trep(i,0,4) rep(j,i+1,4)\
    \ rep(k,j+1,4)\n\t\tmf(i, j, k, 6 - i - j - k);\n\n\trep(i,4,sz(A)) {\n\t\trep(j,0,sz(FS))\
    \ {\n\t\t\tF f = FS[j];\n\t\t\tif(f.q.dot(A[i]) > f.q.dot(A[f.a])) {\n\t\t\t\t\
    E(a,b).rem(f.c);\n\t\t\t\tE(a,c).rem(f.b);\n\t\t\t\tE(b,c).rem(f.a);\n\t\t\t\t\
    swap(FS[j--], FS.back());\n\t\t\t\tFS.pop_back();\n\t\t\t}\n\t\t}\n\t\tint nw\
    \ = sz(FS);\n\t\trep(j,0,nw) {\n\t\t\tF f = FS[j];\n#define C(a, b, c) if (E(a,b).cnt()\
    \ != 2) mf(f.a, f.b, i, f.c);\n\t\t\tC(a, b, c); C(a, c, b); C(b, c, a);\n\t\t\
    }\n\t}\n\tfor (F& it : FS) if ((A[it.b] - A[it.a]).cross(\n\t\tA[it.c] - A[it.a]).dot(it.q)\
    \ <= 0) swap(it.c, it.b);\n\treturn FS;\n};\n"
  dependsOn:
  - src/geometry/Point3D.h
  isVerificationFile: false
  path: src/geometry/3dHull.h
  requiredBy:
  - src/geometry/DelaunayTriangulation.h
  timestamp: '2025-07-19 20:25:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/3dHull.h
layout: document
redirect_from:
- /library/src/geometry/3dHull.h
- /library/src/geometry/3dHull.h.html
title: src/geometry/3dHull.h
---
