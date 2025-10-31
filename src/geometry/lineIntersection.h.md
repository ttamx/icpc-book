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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/lineIntersection.h: line 22: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * Author: Victor Lecomte, chilli\n * Date: 2019-05-05\n * License:\
    \ CC0\n * Source: https://vlecomte.github.io/cp-geo.pdf\n * Description:\\\\\n\
    \\begin{minipage}{75mm}\nIf a unique intersection point of the lines going through\
    \ s1,e1 and s2,e2 exists \\{1, point\\} is returned.\nIf no intersection point\
    \ exists \\{0, (0,0)\\} is returned and if infinitely many exists \\{-1, (0,0)\\\
    } is returned.\nThe wrong position will be returned if P is Point<ll> and the\
    \ intersection point does not have integer coordinates.\nProducts of three coordinates\
    \ are used in intermediate steps so watch out for overflow if using int or ll.\n\
    \\end{minipage}\n\\begin{minipage}{15mm}\n\\includegraphics[width=\\textwidth]{src/geometry/lineIntersection}\n\
    \\end{minipage}\n * Usage:\n * \tauto res = lineInter(s1,e1,s2,e2);\n * \tif (res.first\
    \ == 1)\n * \t\tcout << \"intersection point at \" << res.second << endl;\n *\
    \ Status: stress-tested, and tested through half-plane tests\n */\n#pragma once\n\
    \n#include \"src/geometry/Point.h\"\n\ntemplate<class P>\npair<int, P> lineInter(P\
    \ s1, P e1, P s2, P e2) {\n\tauto d = (e1 - s1).cross(e2 - s2);\n\tif (d == 0)\
    \ // if parallel\n\t\treturn {-(s1.cross(e1, s2) == 0), P(0, 0)};\n\tauto p =\
    \ s2.cross(e1, e2), q = s2.cross(e2, s1);\n\treturn {1, (s1 * p + e1 * q) / d};\n\
    }\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/lineIntersection.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/lineIntersection.h
layout: document
redirect_from:
- /library/src/geometry/lineIntersection.h
- /library/src/geometry/lineIntersection.h.html
title: src/geometry/lineIntersection.h
---
