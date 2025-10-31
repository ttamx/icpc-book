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
    \ src/geometry/CircleTangents.h: line 13: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Victor Lecomte, chilli\n * Date: 2019-10-31\n * License:\
    \ CC0\n * Source: https://vlecomte.github.io/cp-geo.pdf\n * Description: Finds\
    \ the external tangents of two circles, or internal if r2 is negated.\n * Can\
    \ return 0, 1, or 2 tangents -- 0 if one circle contains the other (or overlaps\
    \ it, in the internal case, or if the circles are the same);\n * 1 if the circles\
    \ are tangent to each other (in which case .first = .second and the tangent line\
    \ is perpendicular to the line between the centers).\n * .first and .second give\
    \ the tangency points at circle 1 and 2 respectively.\n * To find the tangents\
    \ of a circle with a point set r2 to 0.\n * Status: tested\n */\n#pragma once\n\
    \n#include \"src/geometry/Point.h\"\n\ntemplate<class P>\nvector<pair<P, P>> tangents(P\
    \ c1, double r1, P c2, double r2) {\n\tP d = c2 - c1;\n\tdouble dr = r1 - r2,\
    \ d2 = d.dist2(), h2 = d2 - dr * dr;\n\tif (d2 == 0 || h2 < 0)  return {};\n\t\
    vector<pair<P, P>> out;\n\tfor (double sign : {-1, 1}) {\n\t\tP v = (d * dr +\
    \ d.perp() * sqrt(h2) * sign) / d2;\n\t\tout.push_back({c1 + v * r1, c2 + v *\
    \ r2});\n\t}\n\tif (h2 == 0) out.pop_back();\n\treturn out;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/CircleTangents.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/CircleTangents.h
layout: document
redirect_from:
- /library/src/geometry/CircleTangents.h
- /library/src/geometry/CircleTangents.h.html
title: src/geometry/CircleTangents.h
---
