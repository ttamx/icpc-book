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
    \ src/geometry/SegmentDistance.h: line 19: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Ulf Lundstrom\n * Date: 2009-03-21\n * License: CC0\n * Source:\n\
    \ * Description:\\\\\n\\begin{minipage}{75mm}\nReturns the shortest distance between\
    \ point p and the line segment from point s to e.\n\\end{minipage}\n\\begin{minipage}{15mm}\n\
    \\vspace{-10mm}\n\\includegraphics[width=\\textwidth]{src/geometry/SegmentDistance}\n\
    \\end{minipage}\n * Usage: \n * \tPoint<double> a, b(2,2), p(1,1);\n * \tbool\
    \ onSegment = segDist(a,b,p) < 1e-10;\n * Status: tested\n */\n#pragma once\n\n\
    #include \"src/geometry/Point.h\"\n\ntypedef Point<double> P;\ndouble segDist(P&\
    \ s, P& e, P& p) {\n\tif (s==e) return (p-s).dist();\n\tauto d = (e-s).dist2(),\
    \ t = min(d,max(.0,(p-s).dot(e-s)));\n\treturn ((p-s)*d-(e-s)*t).dist()/d;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/SegmentDistance.h
  requiredBy:
  - src/geometry/InsidePolygon.h
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/SegmentDistance.h
layout: document
redirect_from:
- /library/src/geometry/SegmentDistance.h
- /library/src/geometry/SegmentDistance.h.html
title: src/geometry/SegmentDistance.h
---
