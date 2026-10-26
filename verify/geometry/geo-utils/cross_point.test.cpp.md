---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/GeoUtils.h
    title: src/geometry/GeoUtils.h
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
    ERROR: 1e-8
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
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
    \ src/geometry/GeoUtils.h: line 13: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C\"\
    \n#define ERROR 1e-8\n#include \"src/contest/template.hpp\"\n#include \"src/geometry/GeoUtils.h\"\
    \n\nusing P = Point<double>;\nP rd(){\n    double x,y;\n    cin >> x >> y;\n \
    \   return P(x,y);\n}\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(10);\n    int q;\n    cin >> q;\n    while(q--){\n\
    \        P a=rd(),b=rd(),c=rd(),d=rd();\n        P r=lineInter(a,b,c,d).second;\n\
    \        cout << r.x << \" \" << r.y << \"\\n\";\n    }\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/geometry/GeoUtils.h
  - src/geometry/Point.h
  isVerificationFile: true
  path: verify/geometry/geo-utils/cross_point.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 21:00:18+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/geometry/geo-utils/cross_point.test.cpp
layout: document
redirect_from:
- /verify/verify/geometry/geo-utils/cross_point.test.cpp
- /verify/verify/geometry/geo-utils/cross_point.test.cpp.html
title: verify/geometry/geo-utils/cross_point.test.cpp
---
