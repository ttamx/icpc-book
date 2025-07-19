---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/Point.h
    title: src/geometry/Point.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/PointInsideHull.h
    title: src/geometry/PointInsideHull.h
  - icon: ':warning:'
    path: src/geometry/PolygonUnion.h
    title: src/geometry/PolygonUnion.h
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/sideOf.h: line 14: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Ulf Lundstrom\n * Date: 2009-03-21\n * License: CC0\n * Source:\n\
    \ * Description: Returns where $p$ is as seen from $s$ towards $e$. 1/0/-1 $\\\
    Leftrightarrow$ left/on line/right.\n * If the optional argument $eps$ is given\
    \ 0 is returned if $p$ is within distance $eps$ from the line.\n * P is supposed\
    \ to be Point<T> where T is e.g. double or long long.\n * It uses products in\
    \ intermediate steps so watch out for overflow if using int or long long.\n *\
    \ Usage:\n * \tbool left = sideOf(p1,p2,q)==1;\n * Status: tested\n */\n#pragma\
    \ once\n\n#include \"Point.h\"\n\ntemplate<class P>\nint sideOf(P s, P e, P p)\
    \ { return sgn(s.cross(e, p)); }\n\ntemplate<class P>\nint sideOf(const P& s,\
    \ const P& e, const P& p, double eps) {\n\tauto a = (e-s).cross(p-s);\n\tdouble\
    \ l = (e-s).dist()*eps;\n\treturn (a > l) - (a < -l);\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/sideOf.h
  requiredBy:
  - src/geometry/PolygonUnion.h
  - src/geometry/PointInsideHull.h
  timestamp: '2025-07-19 20:25:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/sideOf.h
layout: document
redirect_from:
- /library/src/geometry/sideOf.h
- /library/src/geometry/sideOf.h.html
title: src/geometry/sideOf.h
---
