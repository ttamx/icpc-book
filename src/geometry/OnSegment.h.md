---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/Point.h
    title: src/geometry/Point.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/InsidePolygon.h
    title: src/geometry/InsidePolygon.h
  - icon: ':warning:'
    path: src/geometry/PointInsideHull.h
    title: src/geometry/PointInsideHull.h
  - icon: ':warning:'
    path: src/geometry/SegmentIntersection.h
    title: src/geometry/SegmentIntersection.h
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://vlecomte.github.io/cp-geo.pdf
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/OnSegment.h: line 10: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Victor Lecomte, chilli\n * Date: 2019-04-26\n * License:\
    \ CC0\n * Source: https://vlecomte.github.io/cp-geo.pdf\n * Description: Returns\
    \ true iff p lies on the line segment from s to e.\n * Use \\texttt{(segDist(s,e,p)<=epsilon)}\
    \ instead when using Point<double>.\n * Status:\n */\n#pragma once\n\n#include\
    \ \"src/geometry/Point.h\"\n\ntemplate<class P> bool onSegment(P s, P e, P p)\
    \ {\n\treturn p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/OnSegment.h
  requiredBy:
  - src/geometry/InsidePolygon.h
  - src/geometry/PointInsideHull.h
  - src/geometry/SegmentIntersection.h
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/OnSegment.h
layout: document
redirect_from:
- /library/src/geometry/OnSegment.h
- /library/src/geometry/OnSegment.h.html
title: src/geometry/OnSegment.h
---
