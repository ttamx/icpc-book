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
    \ src/geometry/PolygonCut.h: line 20: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Ulf Lundstrom\n * Date: 2009-03-21\n * License: CC0\n * Source:\n\
    \ * Description:\\\\\n\\begin{minipage}{75mm}\n Returns a vector with the vertices\
    \ of a polygon with everything to the left of the line going from s to e cut away.\n\
    \\end{minipage}\n\\begin{minipage}{15mm}\n\\vspace{-6mm}\n\\includegraphics[width=\\\
    textwidth]{src/geometry/PolygonCut}\n\\vspace{-6mm}\n\\end{minipage}\n * Usage:\n\
    \ * \tvector<P> p = ...;\n * \tp = polygonCut(p, P(0,0), P(1,0));\n * Status:\
    \ tested but not extensively\n */\n#pragma once\n\n#include \"src/geometry/Point.h\"\
    \n\ntypedef Point<double> P;\nvector<P> polygonCut(const vector<P>& poly, P s,\
    \ P e) {\n\tvector<P> res;\n\trep(i,0,sz(poly)) {\n\t\tP cur = poly[i], prev =\
    \ i ? poly[i-1] : poly.back();\n\t\tauto a = s.cross(e, cur), b = s.cross(e, prev);\n\
    \t\tif ((a < 0) != (b < 0))\n\t\t\tres.push_back(cur + (prev - cur) * (a / (a\
    \ - b)));\n\t\tif (a < 0)\n\t\t\tres.push_back(cur);\n\t}\n\treturn res;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/PolygonCut.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/PolygonCut.h
layout: document
redirect_from:
- /library/src/geometry/PolygonCut.h
- /library/src/geometry/PolygonCut.h.html
title: src/geometry/PolygonCut.h
---
