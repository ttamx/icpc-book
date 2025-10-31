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
    - https://codeforces.com/blog/entry/58747
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/ClosestPair.h: line 10: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Simon Lindholm\n * Date: 2019-04-17\n * License: CC0\n *\
    \ Source: https://codeforces.com/blog/entry/58747\n * Description: Finds the closest\
    \ pair of points.\n * Time: O(n \\log n)\n * Status: stress-tested\n */\n#pragma\
    \ once\n\n#include \"src/geometry/Point.h\"\n\ntypedef Point<ll> P;\npair<P, P>\
    \ closest(vector<P> v) {\n\tassert(sz(v) > 1);\n\tset<P> S;\n\tsort(all(v), [](P\
    \ a, P b) { return a.y < b.y; });\n\tpair<ll, pair<P, P>> ret{LLONG_MAX, {P(),\
    \ P()}};\n\tint j = 0;\n\tfor (P p : v) {\n\t\tP d{1 + (ll)sqrt(ret.first), 0};\n\
    \t\twhile (v[j].y <= p.y - d.x) S.erase(v[j++]);\n\t\tauto lo = S.lower_bound(p\
    \ - d), hi = S.upper_bound(p + d);\n\t\tfor (; lo != hi; ++lo)\n\t\t\tret = min(ret,\
    \ {(*lo - p).dist2(), {*lo, p}});\n\t\tS.insert(p);\n\t}\n\treturn ret.second;\n\
    }\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/ClosestPair.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/ClosestPair.h
layout: document
redirect_from:
- /library/src/geometry/ClosestPair.h
- /library/src/geometry/ClosestPair.h.html
title: src/geometry/ClosestPair.h
---
