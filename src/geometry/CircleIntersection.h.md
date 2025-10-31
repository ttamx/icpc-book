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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/CircleIntersection.h: line 9: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * Author: Simon Lindholm\n * Date: 2015-09-01\n * License: CC0\n *\
    \ Description: Computes the pair of points at which two circles intersect.\n *\
    \ Returns false in case of no intersection.\n * Status: stress-tested\n */\n#pragma\
    \ once\n\n#include \"src/geometry/Point.h\"\n\ntypedef Point<double> P;\nbool\
    \ circleInter(P a,P b,double r1,double r2,pair<P, P>* out) {\n\tif (a == b) {\
    \ assert(r1 != r2); return false; }\n\tP vec = b - a;\n\tdouble d2 = vec.dist2(),\
    \ sum = r1+r2, dif = r1-r2,\n\t       p = (d2 + r1*r1 - r2*r2)/(d2*2), h2 = r1*r1\
    \ - p*p*d2;\n\tif (sum*sum < d2 || dif*dif > d2) return false;\n\tP mid = a +\
    \ vec*p, per = vec.perp() * sqrt(fmax(0, h2) / d2);\n\t*out = {mid + per, mid\
    \ - per};\n\treturn true;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/CircleIntersection.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/CircleIntersection.h
layout: document
redirect_from:
- /library/src/geometry/CircleIntersection.h
- /library/src/geometry/CircleIntersection.h.html
title: src/geometry/CircleIntersection.h
---
