---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/ConvexHull.h
    title: src/geometry/ConvexHull.h
  - icon: ':warning:'
    path: src/geometry/Point.h
    title: src/geometry/Point.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/MaxTriangle.h: line 15: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Teetat T.\n * Date: 2026-10-04\n * License: CC0\n * Description:\
    \ Returns twice the maximum area of a triangle with\n * vertices among the given\
    \ points, and the triangle (0 if $n<3$ or all\n * collinear). On the convex hull,\
    \ the best triangle rooted at $r$\n * (vertices $r<j<k$) interleaves with those\
    \ rooted at $a<r<b$, so\n * divide and conquer over roots, each rooted search\
    \ being a two-pointer\n * scan of the allowed ranges.\n * Usage: auto [a2,t]=maxTriangle(pts);\n\
    \ * Time: O(n \\log n)\n * Status: stress-tested\n */\n#pragma once\n#include\
    \ \"src/geometry/ConvexHull.h\"\n\npair<ll,array<P,3>> maxTriangle(vector<P> pts){\n\
    \tvector<P> h=convexHull(pts);\n\tint n=SZ(h);\n\tpair<ll,array<P,3>> res{};\n\
    \tif(n<3)return res;\n\ttypedef array<int,2> J;\n\tauto at=[&](int i){return h[i%n];};\n\
    \tauto A=[&](int a,int b,int c){\n\t\treturn at(a).cross(at(b),at(c));};\n\t//\
    \ best (r,j,k) with j in [jl,jr], k in [kl,kr], j<k\n\tauto rooted=[&](int r,int\
    \ jl,int jr,int kl,int kr){\n\t\tJ t{jl,kl};ll mx=-1;\n\t\tfor(int j=jl,k=kl;j<=jr;j++){\n\
    \t\t\tk=max(k,j+1);\n\t\t\tif(k>kr)break;\n\t\t\twhile(k<kr&&A(r,j,k+1)>=A(r,j,k))k++;\n\
    \t\t\tif(A(r,j,k)>mx)mx=A(r,j,k),t={j,k};\n\t\t}\n\t\tres=max(res,{mx,{at(r),at(t[0]),at(t[1])}});\n\
    \t\treturn t;\n\t};\n\tauto rec=[&](auto &&self,int a,int b,J L,J R)->void {\n\
    \t\tif(b-a<2)return;\n\t\tint m=(a+b)/2;\n\t\tJ M=rooted(m,max(L[0],m+1),min(R[0],m+n-2),\n\
    \t\t\tmax(L[1],m+2),min(R[1],m+n-1));\n\t\tself(self,a,m,L,M),self(self,m,b,M,R);\n\
    \t};\n\tJ t=rooted(0,1,n-2,2,n-1);\n\trec(rec,0,n,t,{t[0]+n,t[1]+n});\n\treturn\
    \ res;\n}\n"
  dependsOn:
  - src/geometry/ConvexHull.h
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/MaxTriangle.h
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/MaxTriangle.h
layout: document
redirect_from:
- /library/src/geometry/MaxTriangle.h
- /library/src/geometry/MaxTriangle.h.html
title: src/geometry/MaxTriangle.h
---
