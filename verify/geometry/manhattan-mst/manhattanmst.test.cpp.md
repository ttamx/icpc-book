---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/ManhattanMST.h
    title: src/geometry/ManhattanMST.h
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
    PROBLEM: https://judge.yosupo.jp/problem/manhattanmst
    links:
    - https://judge.yosupo.jp/problem/manhattanmst
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
    \ src/geometry/ManhattanMST.h: line 13: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n#include\
    \ \"src/contest/template.hpp\"\n#include \"src/geometry/ManhattanMST.h\"\n\nint\
    \ f[200005];\nint fd(int x){return f[x]==x?x:f[x]=fd(f[x]);}\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int n;\n    cin >> n;\n  \
    \  vector<P> v(n);\n    for(auto &p:v)cin >> p.x >> p.y;\n    auto e=manhattanMST(v);\n\
    \    sort(ALL(e));\n    iota(f,f+n,0);\n    ll w=0;\n    vector<pair<int,int>>\
    \ res;\n    for(auto [d,a,b]:e)if(fd(a)!=fd(b)){\n        f[fd(a)]=fd(b);\n  \
    \      w+=d;\n        res.pb({a,b});\n    }\n    cout << w << \"\\n\";\n    for(auto\
    \ [a,b]:res)cout << a << \" \" << b << \"\\n\";\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/geometry/ManhattanMST.h
  - src/geometry/Point.h
  isVerificationFile: true
  path: verify/geometry/manhattan-mst/manhattanmst.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 21:00:18+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/geometry/manhattan-mst/manhattanmst.test.cpp
layout: document
redirect_from:
- /verify/verify/geometry/manhattan-mst/manhattanmst.test.cpp
- /verify/verify/geometry/manhattan-mst/manhattanmst.test.cpp.html
title: verify/geometry/manhattan-mst/manhattanmst.test.cpp
---
