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
    - https://codeforces.com/blog/entry/48868
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/HullDiameter.h: line 11: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Oleksandr Bacherikov, chilli\n * Date: 2019-05-05\n * License:\
    \ Boost Software License\n * Source: https://codeforces.com/blog/entry/48868\n\
    \ * Description: Returns the two points with max distance on a convex hull (ccw,\n\
    \ * no duplicate/collinear points).\n * Status: stress-tested, tested on kattis:roberthood\n\
    \ * Time: O(n)\n */\n#pragma once\n#include \"src/geometry/Point.h\"\n\ntypedef\
    \ Point<ll> P;\narray<P, 2> hullDiameter(vector<P> S) {\n\tint n = sz(S), j =\
    \ n < 2 ? 0 : 1;\n\tpair<ll, array<P, 2>> res({0, {S[0], S[0]}});\n\trep(i,0,j)\n\
    \t\tfor (;; j = (j + 1) % n) {\n\t\t\tres = max(res, {(S[i] - S[j]).dist2(), {S[i],\
    \ S[j]}});\n\t\t\tif ((S[(j + 1) % n] - S[j]).cross(S[i + 1] - S[i]) >= 0)\n\t\
    \t\t\tbreak;\n\t\t}\n\treturn res.second;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/HullDiameter.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/HullDiameter.h
layout: document
redirect_from:
- /library/src/geometry/HullDiameter.h
- /library/src/geometry/HullDiameter.h.html
title: src/geometry/HullDiameter.h
---
