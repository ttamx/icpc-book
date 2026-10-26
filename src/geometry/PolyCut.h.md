---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.h
    title: src/geometry/Point.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/geometry/poly-cut/convex_cut.test.cpp
    title: verify/geometry/poly-cut/convex_cut.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/PolyCut.h: line 20: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Ulf Lundstrom\n * Date: 2009-03-21\n * License: CC0\n * Source:\n\
    \ * Description:\\\\\n\\begin{minipage}{75mm}\n Returns a vector with the vertices\
    \ of a polygon with everything to the left of the line going from s to e cut away.\n\
    \\end{minipage}\n\\begin{minipage}{15mm}\n\\vspace{-6mm}\n\\includegraphics[width=\\\
    textwidth]{src/geometry/PolyCut}\n\\vspace{-6mm}\n\\end{minipage}\n * Usage:\n\
    \ * \tvector<P> p = ...;\n * \tp = polygonCut(p, P(0,0), P(1,0));\n * Status:\
    \ tested but not extensively\n */\n#pragma once\n\n#include \"src/geometry/Point.h\"\
    \n\nusing P = Point<double>;\nvector<P> polygonCut(const vector<P>& poly,P s,P\
    \ e){\n\tvector<P> res;\n\tfor(int i=0;i<SZ(poly);i++){\n\t\tP cur=poly[i],prev=i?poly[i-1]:poly.back();\n\
    \t\tauto a=s.cross(e,cur),b=s.cross(e,prev);\n\t\tif((a<0)!=(b<0))res.push_back(cur+(prev-cur)*(a/(a-b)));\n\
    \t\tif(a<0)res.push_back(cur);\n\t}\n\treturn res;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/PolyCut.h
  requiredBy: []
  timestamp: '2026-10-26 18:23:08+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/geometry/poly-cut/convex_cut.test.cpp
documentation_of: src/geometry/PolyCut.h
layout: document
redirect_from:
- /library/src/geometry/PolyCut.h
- /library/src/geometry/PolyCut.h.html
title: src/geometry/PolyCut.h
---
