---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.h
    title: src/geometry/Point.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/geometry/circle-line/circle_line_cross_points.test.cpp
    title: verify/geometry/circle-line/circle_line_cross_points.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://vlecomte.github.io/cp-geo.pdf
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/CircleLine.h: line 11: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Victor Lecomte, chilli\n * Date: 2019-10-29\n * License:\
    \ CC0\n * Source: https://vlecomte.github.io/cp-geo.pdf\n * Description: Finds\
    \ the intersection between a circle and a line.\n * Returns a vector of either\
    \ 0, 1, or 2 intersection points.\n * P is intended to be Point<double>.\n * Status:\
    \ unit tested\n */\n#pragma once\n\n#include \"src/geometry/Point.h\"\n\ntemplate<class\
    \ P> vector<P> circleLine(P c,double r,P a,P b){\n\tP ab=b-a,p=a+ab*(c-a).dot(ab)/ab.dist2();\n\
    \tdouble s=a.cross(b,c),h2=r*r-s*s/ab.dist2();\n\tif(h2<0)return {};\n\tif(h2==0)return\
    \ {p};\n\tP h=ab.unit()*sqrt(h2);\n\treturn {p-h,p+h};\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/CircleLine.h
  requiredBy: []
  timestamp: '2026-10-26 18:23:08+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/geometry/circle-line/circle_line_cross_points.test.cpp
documentation_of: src/geometry/CircleLine.h
layout: document
redirect_from:
- /library/src/geometry/CircleLine.h
- /library/src/geometry/CircleLine.h.html
title: src/geometry/CircleLine.h
---
