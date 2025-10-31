---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/Point.h
    title: src/geometry/Point.h
  - icon: ':warning:'
    path: src/geometry/circumcircle.h
    title: src/geometry/circumcircle.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/MinimumEnclosingCircle.h: line 10: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * Author: Andrew He, chilli\n * Date: 2019-05-07\n * License: CC0\n\
    \ * Source: folklore\n * Description: Computes the minimum circle that encloses\
    \ a set of points.\n * Time: expected O(n)\n * Status: stress-tested\n */\n#pragma\
    \ once\n\n#include \"circumcircle.h\"\n\npair<P, double> mec(vector<P> ps) {\n\
    \tshuffle(all(ps), mt19937(time(0)));\n\tP o = ps[0];\n\tdouble r = 0, EPS = 1\
    \ + 1e-8;\n\trep(i,0,sz(ps)) if ((o - ps[i]).dist() > r * EPS) {\n\t\to = ps[i],\
    \ r = 0;\n\t\trep(j,0,i) if ((o - ps[j]).dist() > r * EPS) {\n\t\t\to = (ps[i]\
    \ + ps[j]) / 2;\n\t\t\tr = (o - ps[i]).dist();\n\t\t\trep(k,0,j) if ((o - ps[k]).dist()\
    \ > r * EPS) {\n\t\t\t\to = ccCenter(ps[i], ps[j], ps[k]);\n\t\t\t\tr = (o - ps[i]).dist();\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn {o, r};\n}\n"
  dependsOn:
  - src/geometry/circumcircle.h
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/MinimumEnclosingCircle.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/MinimumEnclosingCircle.h
layout: document
redirect_from:
- /library/src/geometry/MinimumEnclosingCircle.h
- /library/src/geometry/MinimumEnclosingCircle.h.html
title: src/geometry/MinimumEnclosingCircle.h
---
