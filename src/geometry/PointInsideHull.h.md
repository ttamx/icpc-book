---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/OnSegment.h
    title: src/geometry/OnSegment.h
  - icon: ':warning:'
    path: src/geometry/Point.h
    title: src/geometry/Point.h
  - icon: ':warning:'
    path: src/geometry/sideOf.h
    title: src/geometry/sideOf.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/ngthanhtrung23/ACM_Notebook_new
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/PointInsideHull.h: line 13: #pragma once found in a non-first line\n"
  code: "/**\n * Author: chilli\n * Date: 2019-05-17\n * License: CC0\n * Source:\
    \ https://github.com/ngthanhtrung23/ACM_Notebook_new\n * Description: Determine\
    \ whether a point t lies inside a convex hull (CCW\n * order, with no collinear\
    \ points). Returns true if point lies within\n * the hull. If strict is true,\
    \ points on the boundary aren't included.\n * Usage:\n * Status: stress-tested\n\
    \ * Time: O(\\log N)\n */\n#pragma once\n\n#include \"src/geometry/Point.h\"\n\
    #include \"src/geometry/sideOf.h\"\n#include \"src/geometry/OnSegment.h\"\n\n\
    typedef Point<ll> P;\n\nbool inHull(const vector<P>& l, P p, bool strict = true)\
    \ {\n\tint a = 1, b = sz(l) - 1, r = !strict;\n\tif (sz(l) < 3) return r && onSegment(l[0],\
    \ l.back(), p);\n\tif (sideOf(l[0], l[a], l[b]) > 0) swap(a, b);\n\tif (sideOf(l[0],\
    \ l[a], p) >= r || sideOf(l[0], l[b], p)<= -r)\n\t\treturn false;\n\twhile (abs(a\
    \ - b) > 1) {\n\t\tint c = (a + b) / 2;\n\t\t(sideOf(l[0], l[c], p) > 0 ? b :\
    \ a) = c;\n\t}\n\treturn sgn(l[a].cross(l[b], p)) < r;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  - src/geometry/sideOf.h
  - src/geometry/OnSegment.h
  isVerificationFile: false
  path: src/geometry/PointInsideHull.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/PointInsideHull.h
layout: document
redirect_from:
- /library/src/geometry/PointInsideHull.h
- /library/src/geometry/PointInsideHull.h.html
title: src/geometry/PointInsideHull.h
---
