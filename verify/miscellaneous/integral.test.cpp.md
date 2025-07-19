---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/numerical/integrate.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"src/contest/template.hpp\"\
    \n#include \"src/numerical/integrate.hpp\"\n\nint main(){\n    for(int r=1;r<=20;r++){\n\
    \        double out=quad(-r,r,[&](db x){\n            return quad(-r,r,[&](db\
    \ y){\n                return quad(-r,r,[&](db z){\n                    return\
    \ x*x+y*y+z*z<r*r;\n                },100);\n            },100);\n        },100);\n\
    \        double ans=4*PI*r*r*r/3;\n        auto err=abs(out-ans)/max(ans,1.0);\n\
    \        assert(err<1e-4);\n    }\n    int a,b;\n    cin >> a >> b;\n    cout\
    \ << a+b << \"\\n\";\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/miscellaneous/integral.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/miscellaneous/integral.test.cpp
layout: document
redirect_from:
- /verify/verify/miscellaneous/integral.test.cpp
- /verify/verify/miscellaneous/integral.test.cpp.html
title: verify/miscellaneous/integral.test.cpp
---
