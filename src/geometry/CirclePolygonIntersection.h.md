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
    - https://github.com/spaghetti-source/algorithm/blob/master/geometry/_geom.cc#L744
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/CirclePolygonIntersection.h: line 11: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * Author: chilli, Takanori MAEHARA\n * Date: 2019-10-31\n * License:\
    \ CC0\n * Source: https://github.com/spaghetti-source/algorithm/blob/master/geometry/_geom.cc#L744\n\
    \ * Description: Returns the area of the intersection of a circle with a\n * ccw\
    \ polygon.\n * Time: O(n)\n * Status: Tested on GNYR 2019 Gerrymandering, stress-tested\n\
    \ */\n#pragma once\n\n#include \"src/geometry/Point.h\"\n\ntypedef Point<double>\
    \ P;\n#define arg(p, q) atan2(p.cross(q), p.dot(q))\ndouble circlePoly(P c, double\
    \ r, vector<P> ps) {\n\tauto tri = [&](P p, P q) {\n\t\tauto r2 = r * r / 2;\n\
    \t\tP d = q - p;\n\t\tauto a = d.dot(p)/d.dist2(), b = (p.dist2()-r*r)/d.dist2();\n\
    \t\tauto det = a * a - b;\n\t\tif (det <= 0) return arg(p, q) * r2;\n\t\tauto\
    \ s = max(0., -a-sqrt(det)), t = min(1., -a+sqrt(det));\n\t\tif (t < 0 || 1 <=\
    \ s) return arg(p, q) * r2;\n\t\tP u = p + d * s, v = q + d * (t-1);\n\t\treturn\
    \ arg(p,u) * r2 + u.cross(v)/2 + arg(v,q) * r2;\n\t};\n\tauto sum = 0.0;\n\trep(i,0,sz(ps))\n\
    \t\tsum += tri(ps[i] - c, ps[(i + 1) % sz(ps)] - c);\n\treturn sum;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/CirclePolygonIntersection.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/CirclePolygonIntersection.h
layout: document
redirect_from:
- /library/src/geometry/CirclePolygonIntersection.h
- /library/src/geometry/CirclePolygonIntersection.h.html
title: src/geometry/CirclePolygonIntersection.h
---
