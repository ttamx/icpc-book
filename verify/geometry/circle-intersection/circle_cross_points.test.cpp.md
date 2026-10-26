---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/CircleIntersection.h
    title: src/geometry/CircleIntersection.h
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.h
    title: src/geometry/Point.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-6
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/CircleIntersection.h: line 9: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E\"\
    \n#define ERROR 1e-6\n#include \"src/contest/template.hpp\"\n#include \"src/geometry/CircleIntersection.h\"\
    \n\nP rd(){\n    double x,y;\n    cin >> x >> y;\n    return P(x,y);\n}\nvoid\
    \ out(vector<P> v){\n    sort(ALL(v),[](P a,P b){\n        return abs(a.x-b.x)>1e-9?a.x<b.x:a.y<b.y;});\n\
    \    for(int i=0;i<SZ(v);i++)\n        cout << v[i].x << \" \" << v[i].y << (i+1<SZ(v)?\"\
    \ \":\"\\n\");\n}\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(10);\n    P a=rd();\n    double r1;\n    cin\
    \ >> r1;\n    P b=rd();\n    double r2;\n    cin >> r2;\n    pair<P,P> res;\n\
    \    circleInter(a,b,r1,r2,&res);\n    out({res.first,res.second});\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/geometry/CircleIntersection.h
  - src/geometry/Point.h
  isVerificationFile: true
  path: verify/geometry/circle-intersection/circle_cross_points.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 21:00:18+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/geometry/circle-intersection/circle_cross_points.test.cpp
layout: document
redirect_from:
- /verify/verify/geometry/circle-intersection/circle_cross_points.test.cpp
- /verify/verify/geometry/circle-intersection/circle_cross_points.test.cpp.html
title: verify/geometry/circle-intersection/circle_cross_points.test.cpp
---
