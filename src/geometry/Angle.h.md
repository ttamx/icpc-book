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
    \ src/geometry/Angle.h: line 15: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Simon Lindholm\n * Date: 2015-01-31\n * License: CC0\n *\
    \ Source: me\n * Description: A class for ordering angles (as represented by int\
    \ points and\n *  a number of rotations around the origin). Useful for rotational\
    \ sweeping.\n *  Sometimes also represents points or vectors.\n * Usage:\n * \
    \ vector<Angle> v = {w[0], w[0].t360() ...}; // sorted\n *  int j = 0; rep(i,0,n)\
    \ { while (v[j] < v[i].t180()) ++j; }\n *  // sweeps j such that (j-i) represents\
    \ the number of positively oriented triangles with vertices at 0 and i\n * Status:\
    \ Used, works well\n */\n#pragma once\n\nstruct Angle {\n\tint x, y;\n\tint t;\n\
    \tAngle(int x, int y, int t=0) : x(x), y(y), t(t) {}\n\tAngle operator-(Angle\
    \ b) const { return {x-b.x, y-b.y, t}; }\n\tint half() const {\n\t\tassert(x ||\
    \ y);\n\t\treturn y < 0 || (y == 0 && x < 0);\n\t}\n\tAngle t90() const { return\
    \ {-y, x, t + (half() && x >= 0)}; }\n\tAngle t180() const { return {-x, -y, t\
    \ + half()}; }\n\tAngle t360() const { return {x, y, t + 1}; }\n};\nbool operator<(Angle\
    \ a, Angle b) {\n\t// add a.dist2() and b.dist2() to also compare distances\n\t\
    return make_tuple(a.t, a.half(), a.y * (ll)b.x) <\n\t       make_tuple(b.t, b.half(),\
    \ a.x * (ll)b.y);\n}\n\n// Given two points, this calculates the smallest angle\
    \ between\n// them, i.e., the angle that covers the defined line segment.\npair<Angle,\
    \ Angle> segmentAngles(Angle a, Angle b) {\n\tif (b < a) swap(a, b);\n\treturn\
    \ (b < a.t180() ?\n\t        make_pair(a, b) : make_pair(b, a.t360()));\n}\nAngle\
    \ operator+(Angle a, Angle b) { // point a + vector b\n\tAngle r(a.x + b.x, a.y\
    \ + b.y, a.t);\n\tif (a.t180() < r) r.t--;\n\treturn r.t180() < a ? r.t360() :\
    \ r;\n}\nAngle angleDiff(Angle a, Angle b) { // angle b - angle a\n\tint tu =\
    \ b.t - a.t; a.t = b.t;\n\treturn {a.x*b.x + a.y*b.y, a.x*b.y - a.y*b.x, tu -\
    \ (b < a)};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/Angle.h
  requiredBy: []
  timestamp: '2025-07-19 20:25:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/Angle.h
layout: document
redirect_from:
- /library/src/geometry/Angle.h
- /library/src/geometry/Angle.h.html
title: src/geometry/Angle.h
---
