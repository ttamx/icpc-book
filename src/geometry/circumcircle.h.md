---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/Point.h
    title: src/geometry/Point.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/MinimumEnclosingCircle.h
    title: src/geometry/MinimumEnclosingCircle.h
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://en.wikipedia.org/wiki/Circumcircle
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/circumcircle.h: line 16: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Ulf Lundstrom\n * Date: 2009-04-11\n * License: CC0\n * Source:\
    \ http://en.wikipedia.org/wiki/Circumcircle\n * Description:\\\\\n\\begin{minipage}{75mm}\n\
    The circumcirle of a triangle is the circle intersecting all three vertices. ccRadius\
    \ returns the radius of the circle going through points A, B and C and ccCenter\
    \ returns the center of the same circle.\n\\end{minipage}\n\\begin{minipage}{15mm}\n\
    \\vspace{-2mm}\n\\includegraphics[width=\\textwidth]{src/geometry/circumcircle}\n\
    \\end{minipage}\n * Status: tested\n */\n#pragma once\n\n#include \"src/geometry/Point.h\"\
    \n\ntypedef Point<double> P;\ndouble ccRadius(const P& A, const P& B, const P&\
    \ C) {\n\treturn (B-A).dist()*(C-B).dist()*(A-C).dist()/\n\t\t\tabs((B-A).cross(C-A))/2;\n\
    }\nP ccCenter(const P& A, const P& B, const P& C) {\n\tP b = C-A, c = B-A;\n\t\
    return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/circumcircle.h
  requiredBy:
  - src/geometry/MinimumEnclosingCircle.h
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/circumcircle.h
layout: document
redirect_from:
- /library/src/geometry/circumcircle.h
- /library/src/geometry/circumcircle.h.html
title: src/geometry/circumcircle.h
---
