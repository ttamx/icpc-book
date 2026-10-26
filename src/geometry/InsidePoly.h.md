---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/GeoUtils.h
    title: src/geometry/GeoUtils.h
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.h
    title: src/geometry/Point.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/geometry/inside-poly/polygon_point_containment.test.cpp
    title: verify/geometry/inside-poly/polygon_point_containment.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://vlecomte.github.io/cp-geo.pdf
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/InsidePoly.h: line 15: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Victor Lecomte, chilli\n * Date: 2019-04-26\n * License:\
    \ CC0\n * Source: https://vlecomte.github.io/cp-geo.pdf\n * Description: Returns\
    \ true if p lies within the polygon. If strict is true,\n * it returns false for\
    \ points on the boundary. The algorithm uses\n * products in intermediate steps\
    \ so watch out for overflow.\n * Time: O(n)\n * Usage:\n * vector<P> v = {P{4,4},\
    \ P{1,2}, P{2,1}};\n * bool in = inPolygon(v, P{3, 3}, false);\n * Status: stress-tested\
    \ and tested on kattis:pointinpolygon\n */\n#pragma once\n\n#include \"src/geometry/Point.h\"\
    \n#include \"src/geometry/GeoUtils.h\"\n\ntemplate<class P>\nbool inPolygon(vector<P>&\
    \ p,P a,bool strict=true){\n\tint cnt=0,n=SZ(p);\n\tfor(int i=0;i<n;i++){\n\t\t\
    P q=p[(i+1)%n];\n\t\tif(onSegment(p[i],q,a))return !strict;\n\t\t//or: if(segDist(p[i],q,a)<=eps)return\
    \ !strict;\n\t\tcnt^=((a.y<p[i].y)-(a.y<q.y))*a.cross(p[i],q)>0;\n\t}\n\treturn\
    \ cnt;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  - src/geometry/GeoUtils.h
  isVerificationFile: false
  path: src/geometry/InsidePoly.h
  requiredBy: []
  timestamp: '2026-10-26 18:23:08+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/geometry/inside-poly/polygon_point_containment.test.cpp
documentation_of: src/geometry/InsidePoly.h
layout: document
redirect_from:
- /library/src/geometry/InsidePoly.h
- /library/src/geometry/InsidePoly.h.html
title: src/geometry/InsidePoly.h
---
