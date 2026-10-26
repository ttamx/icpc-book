---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/CirclePolyInter.h
    title: src/geometry/CirclePolyInter.h
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
    ERROR: 1e-5
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H
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
    \ src/geometry/CirclePolyInter.h: line 11: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H\"\
    \n#define ERROR 1e-5\n#include \"src/contest/template.hpp\"\n#include \"src/geometry/CirclePolyInter.h\"\
    \n\nP rd(){\n    double x,y;\n    cin >> x >> y;\n    return P(x,y);\n}\n\nint\
    \ main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    cout << fixed <<\
    \ setprecision(10);\n    int n;\n    double r;\n    cin >> n >> r;\n    vector<P>\
    \ v(n);\n    for(auto &p:v)p=rd();\n    cout << circlePoly(P(0,0),r,v) << \"\\\
    n\";\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/geometry/CirclePolyInter.h
  - src/geometry/Point.h
  isVerificationFile: true
  path: verify/geometry/circle-poly-inter/circle_polygon_area.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 21:00:18+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/geometry/circle-poly-inter/circle_polygon_area.test.cpp
layout: document
redirect_from:
- /verify/verify/geometry/circle-poly-inter/circle_polygon_area.test.cpp
- /verify/verify/geometry/circle-poly-inter/circle_polygon_area.test.cpp.html
title: verify/geometry/circle-poly-inter/circle_polygon_area.test.cpp
---
