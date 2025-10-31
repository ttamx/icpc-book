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
    path: src/geometry/SegmentDistance.h
    title: src/geometry/SegmentDistance.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://vlecomte.github.io/cp-geo.pdf
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/InsidePolygon.h: line 15: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Victor Lecomte, chilli\n * Date: 2019-04-26\n * License:\
    \ CC0\n * Source: https://vlecomte.github.io/cp-geo.pdf\n * Description: Returns\
    \ true if p lies within the polygon. If strict is true,\n * it returns false for\
    \ points on the boundary. The algorithm uses\n * products in intermediate steps\
    \ so watch out for overflow.\n * Time: O(n)\n * Usage:\n * vector<P> v = {P{4,4},\
    \ P{1,2}, P{2,1}};\n * bool in = inPolygon(v, P{3, 3}, false);\n * Status: stress-tested\
    \ and tested on kattis:pointinpolygon\n */\n#pragma once\n\n#include \"src/geometry/Point.h\"\
    \n#include \"src/geometry/OnSegment.h\"\n#include \"src/geometry/SegmentDistance.h\"\
    \n\ntemplate<class P>\nbool inPolygon(vector<P> &p, P a, bool strict = true) {\n\
    \tint cnt = 0, n = sz(p);\n\trep(i,0,n) {\n\t\tP q = p[(i + 1) % n];\n\t\tif (onSegment(p[i],\
    \ q, a)) return !strict;\n\t\t//or: if (segDist(p[i], q, a) <= eps) return !strict;\n\
    \t\tcnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i], q) > 0;\n\t}\n\treturn cnt;\n\
    }\n"
  dependsOn:
  - src/geometry/Point.h
  - src/geometry/OnSegment.h
  - src/geometry/SegmentDistance.h
  isVerificationFile: false
  path: src/geometry/InsidePolygon.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/InsidePolygon.h
layout: document
redirect_from:
- /library/src/geometry/InsidePolygon.h
- /library/src/geometry/InsidePolygon.h.html
title: src/geometry/InsidePolygon.h
---
