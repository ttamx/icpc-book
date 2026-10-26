---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/CircleLine.h
    title: src/geometry/CircleLine.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
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
    \ src/geometry/CircleLine.h: line 11: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D\"\
    \n#define ERROR 1e-6\n#include \"src/contest/template.hpp\"\n#include \"src/geometry/CircleLine.h\"\
    \n\nusing P = Point<double>;\nP rd(){\n    double x,y;\n    cin >> x >> y;\n \
    \   return P(x,y);\n}\nvoid out(vector<P> v){\n    sort(ALL(v),[](P a,P b){\n\
    \        return abs(a.x-b.x)>1e-9?a.x<b.x:a.y<b.y;});\n    for(int i=0;i<SZ(v);i++)\n\
    \        cout << v[i].x << \" \" << v[i].y << (i+1<SZ(v)?\" \":\"\\n\");\n}\n\n\
    int main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(10);\n    P c=rd();\n    double r;\n    cin >> r;\n    int q;\n\
    \    cin >> q;\n    while(q--){\n        P a=rd(),b=rd();\n        auto v=circleLine(c,r,a,b);\n\
    \        if(SZ(v)==1)v.pb(v[0]);\n        out(v);\n    }\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/geometry/CircleLine.h
  - src/geometry/Point.h
  isVerificationFile: true
  path: verify/geometry/circle-line/circle_line_cross_points.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 21:00:18+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/geometry/circle-line/circle_line_cross_points.test.cpp
layout: document
redirect_from:
- /verify/verify/geometry/circle-line/circle_line_cross_points.test.cpp
- /verify/verify/geometry/circle-line/circle_line_cross_points.test.cpp.html
title: verify/geometry/circle-line/circle_line_cross_points.test.cpp
---
