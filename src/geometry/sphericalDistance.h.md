---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/sphericalDistance.h: line 14: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * Author: Ulf Lundstrom\n * Date: 2009-04-07\n * License: CC0\n * Source:\
    \ My geometric reasoning\n * Description: Returns the shortest distance on the\
    \ sphere with radius radius between the points\n * with azimuthal angles (longitude)\
    \ f1 ($\\phi_1$) and f2 ($\\phi_2$) from x axis and zenith angles\n * (latitude)\
    \ t1 ($\\theta_1$) and t2 ($\\theta_2$) from z axis (0 = north pole). All angles\
    \ measured\n * in radians. The algorithm starts by converting the spherical coordinates\
    \ to cartesian coordinates\n * so if that is what you have you can use only the\
    \ two last rows. dx*radius is then the difference\n * between the two points in\
    \ the x direction and d*radius is the total distance between the points.\n * Status:\
    \ tested on kattis:airlinehub\n */\n#pragma once\n\ndouble sphericalDistance(double\
    \ f1, double t1,\n\t\tdouble f2, double t2, double radius) {\n\tdouble dx = sin(t2)*cos(f2)\
    \ - sin(t1)*cos(f1);\n\tdouble dy = sin(t2)*sin(f2) - sin(t1)*sin(f1);\n\tdouble\
    \ dz = cos(t2) - cos(t1);\n\tdouble d = sqrt(dx*dx + dy*dy + dz*dz);\n\treturn\
    \ radius*2*asin(d/2);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/sphericalDistance.h
  requiredBy: []
  timestamp: '2025-07-19 20:25:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/sphericalDistance.h
layout: document
redirect_from:
- /library/src/geometry/sphericalDistance.h
- /library/src/geometry/sphericalDistance.h.html
title: src/geometry/sphericalDistance.h
---
