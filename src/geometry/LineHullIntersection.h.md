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
    - https://github.com/AlCash07/ACTL/blob/master/include/actl/geometry/algorithm/intersect/line_convex_polygon.hpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/LineHullIntersection.h: line 20: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * Author: Oleksandr Bacherikov, chilli\n * Date: 2019-05-07\n * License:\
    \ Boost Software License\n * Source: https://github.com/AlCash07/ACTL/blob/master/include/actl/geometry/algorithm/intersect/line_convex_polygon.hpp\n\
    \ * Description: Line-convex polygon intersection. The polygon must be ccw and\
    \ have no collinear points.\n * lineHull(line, poly) returns a pair describing\
    \ the intersection of a line with the polygon:\n *  \\begin{itemize*}\n *    \\\
    item $(-1, -1)$ if no collision,\n *    \\item $(i, -1)$ if touching the corner\
    \ $i$,\n *    \\item $(i, i)$ if along side $(i, i+1)$,\n *    \\item $(i, j)$\
    \ if crossing sides $(i, i+1)$ and $(j, j+1)$.\n *  \\end{itemize*}\n *  In the\
    \ last case, if a corner $i$ is crossed, this is treated as happening on side\
    \ $(i, i+1)$.\n *  The points are returned in the same order as the line hits\
    \ the polygon.\n * \\texttt{extrVertex} returns the point of a hull with the max\
    \ projection onto a line.\n * Time: O(\\log n)\n * Status: stress-tested\n */\n\
    #pragma once\n\n#include \"Point.h\"\n\n#define cmp(i,j) sgn(dir.perp().cross(poly[(i)%n]-poly[(j)%n]))\n\
    #define extr(i) cmp(i + 1, i) >= 0 && cmp(i, i - 1 + n) < 0\ntemplate <class P>\
    \ int extrVertex(vector<P>& poly, P dir) {\n\tint n = sz(poly), lo = 0, hi = n;\n\
    \tif (extr(0)) return 0;\n\twhile (lo + 1 < hi) {\n\t\tint m = (lo + hi) / 2;\n\
    \t\tif (extr(m)) return m;\n\t\tint ls = cmp(lo + 1, lo), ms = cmp(m + 1, m);\n\
    \t\t(ls < ms || (ls == ms && ls == cmp(lo, m)) ? hi : lo) = m;\n\t}\n\treturn\
    \ lo;\n}\n\n#define cmpL(i) sgn(a.cross(poly[i], b))\ntemplate <class P>\narray<int,\
    \ 2> lineHull(P a, P b, vector<P>& poly) {\n\tint endA = extrVertex(poly, (a -\
    \ b).perp());\n\tint endB = extrVertex(poly, (b - a).perp());\n\tif (cmpL(endA)\
    \ < 0 || cmpL(endB) > 0)\n\t\treturn {-1, -1};\n\tarray<int, 2> res;\n\trep(i,0,2)\
    \ {\n\t\tint lo = endB, hi = endA, n = sz(poly);\n\t\twhile ((lo + 1) % n != hi)\
    \ {\n\t\t\tint m = ((lo + hi + (lo < hi ? 0 : n)) / 2) % n;\n\t\t\t(cmpL(m) ==\
    \ cmpL(endB) ? lo : hi) = m;\n\t\t}\n\t\tres[i] = (lo + !cmpL(hi)) % n;\n\t\t\
    swap(endA, endB);\n\t}\n\tif (res[0] == res[1]) return {res[0], -1};\n\tif (!cmpL(res[0])\
    \ && !cmpL(res[1]))\n\t\tswitch ((res[0] - res[1] + sz(poly) + 1) % sz(poly))\
    \ {\n\t\t\tcase 0: return {res[0], res[0]};\n\t\t\tcase 2: return {res[1], res[1]};\n\
    \t\t}\n\treturn res;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/LineHullIntersection.h
  requiredBy: []
  timestamp: '2025-07-19 20:25:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/LineHullIntersection.h
layout: document
redirect_from:
- /library/src/geometry/LineHullIntersection.h
- /library/src/geometry/LineHullIntersection.h.html
title: src/geometry/LineHullIntersection.h
---
