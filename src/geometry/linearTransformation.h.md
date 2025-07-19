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
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/linearTransformation.h: line 17: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * Author: Per Austrin, Ulf Lundstrom\n * Date: 2009-04-09\n * License:\
    \ CC0\n * Source:\n * Description:\\\\\n\\begin{minipage}{75mm}\n Apply the linear\
    \ transformation (translation, rotation and scaling) which takes line p0-p1 to\
    \ line q0-q1 to point r.\n\\end{minipage}\n\\begin{minipage}{15mm}\n\\vspace{-8mm}\n\
    \\includegraphics[width=\\textwidth]{content/geometry/linearTransformation}\n\\\
    vspace{-2mm}\n\\end{minipage}\n * Status: not tested\n */\n#pragma once\n\n#include\
    \ \"Point.h\"\n\ntypedef Point<double> P;\nP linearTransformation(const P& p0,\
    \ const P& p1,\n\t\tconst P& q0, const P& q1, const P& r) {\n\tP dp = p1-p0, dq\
    \ = q1-q0, num(dp.cross(dq), dp.dot(dq));\n\treturn q0 + P((r-p0).cross(num),\
    \ (r-p0).dot(num))/dp.dist2();\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/linearTransformation.h
  requiredBy: []
  timestamp: '2025-07-19 20:25:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/linearTransformation.h
layout: document
redirect_from:
- /library/src/geometry/linearTransformation.h
- /library/src/geometry/linearTransformation.h.html
title: src/geometry/linearTransformation.h
---
