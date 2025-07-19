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
    links:
    - https://github.com/stjepang/snippets/blob/master/convex_hull.cpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/ConvexHull.h: line 19: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Stjepan Glavina, chilli\n * Date: 2019-05-05\n * License:\
    \ Unlicense\n * Source: https://github.com/stjepang/snippets/blob/master/convex_hull.cpp\n\
    \ * Description:\n\\\\\\begin{minipage}{75mm}\nReturns a vector of the points\
    \ of the convex hull in counter-clockwise order.\nPoints on the edge of the hull\
    \ between two other points are not considered part of the hull.\n\\end{minipage}\n\
    \\begin{minipage}{15mm}\n\\vspace{-6mm}\n\\includegraphics[width=\\textwidth]{content/geometry/ConvexHull}\n\
    \\vspace{-6mm}\n\\end{minipage}\n * Time: O(n \\log n)\n * Status: stress-tested,\
    \ tested with kattis:convexhull\n*/\n#pragma once\n\n#include \"Point.h\"\n\n\
    typedef Point<ll> P;\nvector<P> convexHull(vector<P> pts) {\n\tif (sz(pts) <=\
    \ 1) return pts;\n\tsort(all(pts));\n\tvector<P> h(sz(pts)+1);\n\tint s = 0, t\
    \ = 0;\n\tfor (int it = 2; it--; s = --t, reverse(all(pts)))\n\t\tfor (P p : pts)\
    \ {\n\t\t\twhile (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;\n\t\t\th[t++]\
    \ = p;\n\t\t}\n\treturn {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};\n\
    }\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/ConvexHull.h
  requiredBy: []
  timestamp: '2025-07-19 20:25:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/ConvexHull.h
layout: document
redirect_from:
- /library/src/geometry/ConvexHull.h
- /library/src/geometry/ConvexHull.h.html
title: src/geometry/ConvexHull.h
---
