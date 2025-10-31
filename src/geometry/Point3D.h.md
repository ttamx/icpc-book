---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/3dHull.h
    title: src/geometry/3dHull.h
  - icon: ':warning:'
    path: src/geometry/DelaunayTriangulation.h
    title: src/geometry/DelaunayTriangulation.h
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
    \ src/geometry/Point3D.h: line 11: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Ulf Lundstrom with inspiration from tinyKACTL\n * Date: 2009-04-14\n\
    \ * License: CC0\n * Source:\n * Description: Class to handle points in 3D space.\n\
    \ * \tT can be e.g. double or long long.\n * Usage:\n * Status: tested, except\
    \ for phi and theta\n */\n#pragma once\n\ntemplate<class T> struct Point3D {\n\
    \ttypedef Point3D P;\n\ttypedef const P& R;\n\tT x, y, z;\n\texplicit Point3D(T\
    \ x=0, T y=0, T z=0) : x(x), y(y), z(z) {}\n\tbool operator<(R p) const {\n\t\t\
    return tie(x, y, z) < tie(p.x, p.y, p.z); }\n\tbool operator==(R p) const {\n\t\
    \treturn tie(x, y, z) == tie(p.x, p.y, p.z); }\n\tP operator+(R p) const { return\
    \ P(x+p.x, y+p.y, z+p.z); }\n\tP operator-(R p) const { return P(x-p.x, y-p.y,\
    \ z-p.z); }\n\tP operator*(T d) const { return P(x*d, y*d, z*d); }\n\tP operator/(T\
    \ d) const { return P(x/d, y/d, z/d); }\n\tT dot(R p) const { return x*p.x + y*p.y\
    \ + z*p.z; }\n\tP cross(R p) const {\n\t\treturn P(y*p.z - z*p.y, z*p.x - x*p.z,\
    \ x*p.y - y*p.x);\n\t}\n\tT dist2() const { return x*x + y*y + z*z; }\n\tdouble\
    \ dist() const { return sqrt((double)dist2()); }\n\t//Azimuthal angle (longitude)\
    \ to x-axis in interval [-pi, pi]\n\tdouble phi() const { return atan2(y, x);\
    \ } \n\t//Zenith angle (latitude) to the z-axis in interval [0, pi]\n\tdouble\
    \ theta() const { return atan2(sqrt(x*x+y*y),z); }\n\tP unit() const { return\
    \ *this/(T)dist(); } //makes dist()=1\n\t//returns unit vector normal to *this\
    \ and p\n\tP normal(P p) const { return cross(p).unit(); }\n\t//returns point\
    \ rotated 'angle' radians ccw around axis\n\tP rotate(double angle, P axis) const\
    \ {\n\t\tdouble s = sin(angle), c = cos(angle); P u = axis.unit();\n\t\treturn\
    \ u*dot(u)*(1-c) + (*this)*c - cross(u)*s;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/Point3D.h
  requiredBy:
  - src/geometry/DelaunayTriangulation.h
  - src/geometry/3dHull.h
  timestamp: '2025-07-19 20:25:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/Point3D.h
layout: document
redirect_from:
- /library/src/geometry/Point3D.h
- /library/src/geometry/Point3D.h.html
title: src/geometry/Point3D.h
---
