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
    \ src/geometry/PolygonCenter.h: line 10: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Ulf Lundstrom\n * Date: 2009-04-08\n * License: CC0\n * Source:\n\
    \ * Description: Returns the center of mass for a polygon.\n * Time: O(n)\n *\
    \ Status: Tested\n */\n#pragma once\n\n#include \"src/geometry/Point.h\"\n\ntypedef\
    \ Point<double> P;\nP polygonCenter(const vector<P>& v) {\n\tP res(0, 0); double\
    \ A = 0;\n\tfor (int i = 0, j = sz(v) - 1; i < sz(v); j = i++) {\n\t\tres = res\
    \ + (v[i] + v[j]) * v[j].cross(v[i]);\n\t\tA += v[j].cross(v[i]);\n\t}\n\treturn\
    \ res / A / 3;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/PolygonCenter.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/PolygonCenter.h
layout: document
redirect_from:
- /library/src/geometry/PolygonCenter.h
- /library/src/geometry/PolygonCenter.h.html
title: src/geometry/PolygonCenter.h
---
