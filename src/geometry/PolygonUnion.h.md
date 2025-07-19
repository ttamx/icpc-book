---
data:
  _extendedDependsOn:
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
    - https://codeforces.com/gym/101673/submission/50481926
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/PolygonUnion.h: line 12: #pragma once found in a non-first line\n"
  code: "/**\n * Author: black_horse2014, chilli\n * Date: 2019-10-29\n * License:\
    \ Unknown\n * Source: https://codeforces.com/gym/101673/submission/50481926\n\
    \ * Description: Calculates the area of the union of $n$ polygons (not necessarily\n\
    \ * convex). The points within each polygon must be given in CCW order.\n * (Epsilon\
    \ checks may optionally be added to sideOf/sgn, but shouldn't be needed.)\n *\
    \ Time: $O(N^2)$, where $N$ is the total number of points\n * Status: stress-tested,\
    \ Submitted on ECNA 2017 Problem A\n */\n#pragma once\n\n#include \"src/geometry/Point.h\"\
    \n#include \"src/geometry/sideOf.h\"\n\ntypedef Point<double> P;\ndouble rat(P\
    \ a, P b) { return sgn(b.x) ? a.x/b.x : a.y/b.y; }\ndouble polyUnion(vector<vector<P>>&\
    \ poly) {\n\tdouble ret = 0;\n\trep(i,0,sz(poly)) rep(v,0,sz(poly[i])) {\n\t\t\
    P A = poly[i][v], B = poly[i][(v + 1) % sz(poly[i])];\n\t\tvector<pair<double,\
    \ int>> segs = {{0, 0}, {1, 0}};\n\t\trep(j,0,sz(poly)) if (i != j) {\n\t\t\t\
    rep(u,0,sz(poly[j])) {\n\t\t\t\tP C = poly[j][u], D = poly[j][(u + 1) % sz(poly[j])];\n\
    \t\t\t\tint sc = sideOf(A, B, C), sd = sideOf(A, B, D);\n\t\t\t\tif (sc != sd)\
    \ {\n\t\t\t\t\tdouble sa = C.cross(D, A), sb = C.cross(D, B);\n\t\t\t\t\tif (min(sc,\
    \ sd) < 0)\n\t\t\t\t\t\tsegs.emplace_back(sa / (sa - sb), sgn(sc - sd));\n\t\t\
    \t\t} else if (!sc && !sd && j<i && sgn((B-A).dot(D-C))>0){\n\t\t\t\t\tsegs.emplace_back(rat(C\
    \ - A, B - A), 1);\n\t\t\t\t\tsegs.emplace_back(rat(D - A, B - A), -1);\n\t\t\t\
    \t}\n\t\t\t}\n\t\t}\n\t\tsort(all(segs));\n\t\tfor (auto& s : segs) s.first =\
    \ min(max(s.first, 0.0), 1.0);\n\t\tdouble sum = 0;\n\t\tint cnt = segs[0].second;\n\
    \t\trep(j,1,sz(segs)) {\n\t\t\tif (!cnt) sum += segs[j].first - segs[j - 1].first;\n\
    \t\t\tcnt += segs[j].second;\n\t\t}\n\t\tret += A.cross(B) * sum;\n\t}\n\treturn\
    \ ret / 2;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  - src/geometry/sideOf.h
  isVerificationFile: false
  path: src/geometry/PolygonUnion.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/PolygonUnion.h
layout: document
redirect_from:
- /library/src/geometry/PolygonUnion.h
- /library/src/geometry/PolygonUnion.h.html
title: src/geometry/PolygonUnion.h
---
