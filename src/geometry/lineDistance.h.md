---
data:
  _extendedDependsOn:
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/lineDistance.h: line 19: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Ulf Lundstrom\n * Date: 2009-03-21\n * License: CC0\n * Source:\
    \ Basic math\n * Description:\\\\\n\\begin{minipage}{75mm}\nReturns the signed\
    \ distance between point p and the line containing points a and b.\nPositive value\
    \ on left side and negative on right as seen from a towards b. a==b gives nan.\n\
    P is supposed to be Point<T> or Point3D<T> where T is e.g. double or long long.\n\
    It uses products in intermediate steps so watch out for overflow if using int\
    \ or long long.\nUsing Point3D will always give a non-negative distance. For Point3D,\
    \ call .dist on the result of the cross product.\n\\end{minipage}\n\\begin{minipage}{15mm}\n\
    \\includegraphics[width=\\textwidth]{src/geometry/lineDistance}\n\\end{minipage}\n\
    \ * Status: tested\n */\n#pragma once\n\n#include \"src/geometry/Point.h\"\n\n\
    template<class P>\ndouble lineDist(const P& a, const P& b, const P& p) {\n\treturn\
    \ (double)(b-a).cross(p-a)/(b-a).dist();\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/lineDistance.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/lineDistance.h
layout: document
redirect_from:
- /library/src/geometry/lineDistance.h
- /library/src/geometry/lineDistance.h.html
title: src/geometry/lineDistance.h
---
