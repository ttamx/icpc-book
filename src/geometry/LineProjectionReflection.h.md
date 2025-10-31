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
    - https://vlecomte.github.io/cp-geo.pdf
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/LineProjectionReflection.h: line 13: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * Author: Victor Lecomte, chilli\n * Date: 2019-10-29\n * License:\
    \ CC0\n * Source: https://vlecomte.github.io/cp-geo.pdf\n * Description: Projects\
    \ point p onto line ab. Set refl=true to get reflection\n * of point p across\
    \ line ab instead. The wrong point will be returned if P is\n * an integer point\
    \ and the desired point doesn't have integer coordinates.\n * Products of three\
    \ coordinates are used in intermediate steps so watch out\n * for overflow.\n\
    \ * Status: stress-tested\n */\n#pragma once\n\n#include \"src/geometry/Point.h\"\
    \n\ntemplate<class P>\nP lineProj(P a, P b, P p, bool refl=false) {\n\tP v = b\
    \ - a;\n\treturn p - v.perp()*(1+refl)*v.cross(p-a)/v.dist2();\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/LineProjectionReflection.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/LineProjectionReflection.h
layout: document
redirect_from:
- /library/src/geometry/LineProjectionReflection.h
- /library/src/geometry/LineProjectionReflection.h.html
title: src/geometry/LineProjectionReflection.h
---
