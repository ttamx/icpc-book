---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/ConvexHull.h
    title: src/geometry/ConvexHull.h
  - icon: ':heavy_check_mark:'
    path: src/geometry/HullDiameter.h
    title: src/geometry/HullDiameter.h
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
    PROBLEM: https://judge.yosupo.jp/problem/furthest_pair
    links:
    - https://judge.yosupo.jp/problem/furthest_pair
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
    \ src/geometry/ConvexHull.h: line 19: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/furthest_pair\"\n#include\
    \ \"src/contest/template.hpp\"\n#include \"src/geometry/ConvexHull.h\"\n#include\
    \ \"src/geometry/HullDiameter.h\"\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int t;\n    cin >> t;\n    while(t--){\n        int n;\n        cin >> n;\n\
    \        vector<P> v(n);\n        map<P,vector<int>> id;\n        for(int i=0;i<n;i++)cin\
    \ >> v[i].x >> v[i].y,id[v[i]].pb(i);\n        auto [a,b]=hullDiameter(convexHull(v));\n\
    \        int i=id[a][0],j=id[b][a==b&&SZ(id[b])>1];\n        cout << i << \" \"\
    \ << j << \"\\n\";\n    }\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/geometry/ConvexHull.h
  - src/geometry/Point.h
  - src/geometry/HullDiameter.h
  isVerificationFile: true
  path: verify/geometry/hull-diameter/furthest_pair.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 21:00:18+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/geometry/hull-diameter/furthest_pair.test.cpp
layout: document
redirect_from:
- /verify/verify/geometry/hull-diameter/furthest_pair.test.cpp
- /verify/verify/geometry/hull-diameter/furthest_pair.test.cpp.html
title: verify/geometry/hull-diameter/furthest_pair.test.cpp
---
