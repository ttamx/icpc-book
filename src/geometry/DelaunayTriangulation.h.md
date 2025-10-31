---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/3dHull.h
    title: src/geometry/3dHull.h
  - icon: ':warning:'
    path: src/geometry/Point.h
    title: src/geometry/Point.h
  - icon: ':warning:'
    path: src/geometry/Point3D.h
    title: src/geometry/Point3D.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/DelaunayTriangulation.h: line 11: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * Author: Mattias de Zalenski\n * Date: Unknown\n * Source: Geometry\
    \ in C\n * Description: Computes the Delaunay triangulation of a set of points.\n\
    \ *  Each circumcircle contains none of the input points.\n *  If any three points\
    \ are collinear or any four are on the same circle, behavior is undefined.\n *\
    \ Time: O(n^2)\n * Status: stress-tested\n */\n#pragma once\n\n#include \"src/geometry/Point.h\"\
    \n#include \"src/geometry/3dHull.h\"\n\ntemplate<class P, class F>\nvoid delaunay(vector<P>&\
    \ ps, F trifun) {\n\tif (sz(ps) == 3) { int d = (ps[0].cross(ps[1], ps[2]) < 0);\n\
    \t\ttrifun(0,1+d,2-d); }\n\tvector<P3> p3;\n\tfor (P p : ps) p3.emplace_back(p.x,\
    \ p.y, p.dist2());\n\tif (sz(ps) > 3) for(auto t:hull3d(p3)) if ((p3[t.b]-p3[t.a]).\n\
    \t\t\tcross(p3[t.c]-p3[t.a]).dot(P3(0,0,1)) < 0)\n\t\ttrifun(t.a, t.c, t.b);\n\
    }\n"
  dependsOn:
  - src/geometry/Point.h
  - src/geometry/3dHull.h
  - src/geometry/Point3D.h
  isVerificationFile: false
  path: src/geometry/DelaunayTriangulation.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/DelaunayTriangulation.h
layout: document
redirect_from:
- /library/src/geometry/DelaunayTriangulation.h
- /library/src/geometry/DelaunayTriangulation.h.html
title: src/geometry/DelaunayTriangulation.h
---
