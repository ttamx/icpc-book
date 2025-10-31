---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/OnSegment.h
    title: src/geometry/OnSegment.h
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
    \ src/geometry/SegmentIntersection.h: line 23: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * Author: Victor Lecomte, chilli\n * Date: 2019-04-27\n * License:\
    \ CC0\n * Source: https://vlecomte.github.io/cp-geo.pdf\n * Description:\\\\\n\
    \\begin{minipage}{75mm}\nIf a unique intersection point between the line segments\
    \ going from s1 to e1 and from s2 to e2 exists then it is returned.\nIf no intersection\
    \ point exists an empty vector is returned.\nIf infinitely many exist a vector\
    \ with 2 elements is returned, containing the endpoints of the common line segment.\n\
    The wrong position will be returned if P is Point<ll> and the intersection point\
    \ does not have integer coordinates.\nProducts of three coordinates are used in\
    \ intermediate steps so watch out for overflow if using int or long long.\n\\\
    end{minipage}\n\\begin{minipage}{15mm}\n\\includegraphics[width=\\textwidth]{src/geometry/SegmentIntersection}\n\
    \\end{minipage}\n * Usage:\n * vector<P> inter = segInter(s1,e1,s2,e2);\n * if\
    \ (sz(inter)==1)\n *   cout << \"segments intersect at \" << inter[0] << endl;\n\
    \ * Status: stress-tested, tested on kattis:intersection\n */\n#pragma once\n\n\
    #include \"src/geometry/Point.h\"\n#include \"src/geometry/OnSegment.h\"\n\ntemplate<class\
    \ P> vector<P> segInter(P a, P b, P c, P d) {\n\tauto oa = c.cross(d, a), ob =\
    \ c.cross(d, b),\n\t     oc = a.cross(b, c), od = a.cross(b, d);\n\t// Checks\
    \ if intersection is single non-endpoint point.\n\tif (sgn(oa) * sgn(ob) < 0 &&\
    \ sgn(oc) * sgn(od) < 0)\n\t\treturn {(a * ob - b * oa) / (ob - oa)};\n\tset<P>\
    \ s;\n\tif (onSegment(c, d, a)) s.insert(a);\n\tif (onSegment(c, d, b)) s.insert(b);\n\
    \tif (onSegment(a, b, c)) s.insert(c);\n\tif (onSegment(a, b, d)) s.insert(d);\n\
    \treturn {all(s)};\n}\n"
  dependsOn:
  - src/geometry/Point.h
  - src/geometry/OnSegment.h
  isVerificationFile: false
  path: src/geometry/SegmentIntersection.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/SegmentIntersection.h
layout: document
redirect_from:
- /library/src/geometry/SegmentIntersection.h
- /library/src/geometry/SegmentIntersection.h.html
title: src/geometry/SegmentIntersection.h
---
