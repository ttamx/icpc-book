---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/CircleTangents.h
    title: src/geometry/CircleTangents.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A
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
    \ src/geometry/CircleTangents.h: line 13: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\"\
    \n#include \"src/contest/template.hpp\"\n#include \"src/geometry/CircleTangents.h\"\
    \n\nusing P = Point<double>;\nP rd(){\n    double x,y;\n    cin >> x >> y;\n \
    \   return P(x,y);\n}\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    P a=rd();\n    double r1;\n    cin >> r1;\n    P b=rd();\n    double r2;\n\
    \    cin >> r2;\n    // common tangents = external + internal\n    cout << SZ(tangents(a,r1,b,r2))+SZ(tangents(a,r1,b,-r2))\
    \ << \"\\n\";\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/geometry/CircleTangents.h
  - src/geometry/Point.h
  isVerificationFile: true
  path: verify/geometry/circle-tangents/circle_intersection_count.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 21:00:18+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/geometry/circle-tangents/circle_intersection_count.test.cpp
layout: document
redirect_from:
- /verify/verify/geometry/circle-tangents/circle_intersection_count.test.cpp
- /verify/verify/geometry/circle-tangents/circle_intersection_count.test.cpp.html
title: verify/geometry/circle-tangents/circle_intersection_count.test.cpp
---
