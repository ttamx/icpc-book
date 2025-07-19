---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/CircleIntersection.h
    title: src/geometry/CircleIntersection.h
  - icon: ':warning:'
    path: src/geometry/CircleLine.h
    title: src/geometry/CircleLine.h
  - icon: ':warning:'
    path: src/geometry/CirclePolygonIntersection.h
    title: src/geometry/CirclePolygonIntersection.h
  - icon: ':warning:'
    path: src/geometry/CircleTangents.h
    title: src/geometry/CircleTangents.h
  - icon: ':warning:'
    path: src/geometry/ClosestPair.h
    title: src/geometry/ClosestPair.h
  - icon: ':warning:'
    path: src/geometry/ConvexHull.h
    title: src/geometry/ConvexHull.h
  - icon: ':warning:'
    path: src/geometry/DelaunayTriangulation.h
    title: src/geometry/DelaunayTriangulation.h
  - icon: ':warning:'
    path: src/geometry/FastDelaunay.h
    title: src/geometry/FastDelaunay.h
  - icon: ':warning:'
    path: src/geometry/HullDiameter.h
    title: src/geometry/HullDiameter.h
  - icon: ':warning:'
    path: src/geometry/InsidePolygon.h
    title: src/geometry/InsidePolygon.h
  - icon: ':warning:'
    path: src/geometry/LineHullIntersection.h
    title: src/geometry/LineHullIntersection.h
  - icon: ':warning:'
    path: src/geometry/LineProjectionReflection.h
    title: src/geometry/LineProjectionReflection.h
  - icon: ':warning:'
    path: src/geometry/ManhattanMST.h
    title: src/geometry/ManhattanMST.h
  - icon: ':warning:'
    path: src/geometry/MinimumEnclosingCircle.h
    title: src/geometry/MinimumEnclosingCircle.h
  - icon: ':warning:'
    path: src/geometry/OnSegment.h
    title: src/geometry/OnSegment.h
  - icon: ':warning:'
    path: src/geometry/PointInsideHull.h
    title: src/geometry/PointInsideHull.h
  - icon: ':warning:'
    path: src/geometry/PolygonArea.h
    title: src/geometry/PolygonArea.h
  - icon: ':warning:'
    path: src/geometry/PolygonCenter.h
    title: src/geometry/PolygonCenter.h
  - icon: ':warning:'
    path: src/geometry/PolygonCut.h
    title: src/geometry/PolygonCut.h
  - icon: ':warning:'
    path: src/geometry/PolygonUnion.h
    title: src/geometry/PolygonUnion.h
  - icon: ':warning:'
    path: src/geometry/SegmentDistance.h
    title: src/geometry/SegmentDistance.h
  - icon: ':warning:'
    path: src/geometry/SegmentIntersection.h
    title: src/geometry/SegmentIntersection.h
  - icon: ':warning:'
    path: src/geometry/circumcircle.h
    title: src/geometry/circumcircle.h
  - icon: ':warning:'
    path: src/geometry/kdTree.h
    title: src/geometry/kdTree.h
  - icon: ':warning:'
    path: src/geometry/lineDistance.h
    title: src/geometry/lineDistance.h
  - icon: ':warning:'
    path: src/geometry/lineIntersection.h
    title: src/geometry/lineIntersection.h
  - icon: ':warning:'
    path: src/geometry/linearTransformation.h
    title: src/geometry/linearTransformation.h
  - icon: ':warning:'
    path: src/geometry/sideOf.h
    title: src/geometry/sideOf.h
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
    \ src/geometry/Point.h: line 10: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Ulf Lundstrom\n * Date: 2009-02-26\n * License: CC0\n * Source:\
    \ My head with inspiration from tinyKACTL\n * Description: Class to handle points\
    \ in the plane.\n * \tT can be e.g. double or long long. (Avoid int.)\n * Status:\
    \ Works fine, used a lot\n */\n#pragma once\n\ntemplate <class T> int sgn(T x)\
    \ { return (x > 0) - (x < 0); }\ntemplate<class T>\nstruct Point {\n\ttypedef\
    \ Point P;\n\tT x, y;\n\texplicit Point(T x=0, T y=0) : x(x), y(y) {}\n\tbool\
    \ operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }\n\tbool operator==(P\
    \ p) const { return tie(x,y)==tie(p.x,p.y); }\n\tP operator+(P p) const { return\
    \ P(x+p.x, y+p.y); }\n\tP operator-(P p) const { return P(x-p.x, y-p.y); }\n\t\
    P operator*(T d) const { return P(x*d, y*d); }\n\tP operator/(T d) const { return\
    \ P(x/d, y/d); }\n\tT dot(P p) const { return x*p.x + y*p.y; }\n\tT cross(P p)\
    \ const { return x*p.y - y*p.x; }\n\tT cross(P a, P b) const { return (a-*this).cross(b-*this);\
    \ }\n\tT dist2() const { return x*x + y*y; }\n\tdouble dist() const { return sqrt((double)dist2());\
    \ }\n\t// angle to x-axis in interval [-pi, pi]\n\tdouble angle() const { return\
    \ atan2(y, x); }\n\tP unit() const { return *this/dist(); } // makes dist()=1\n\
    \tP perp() const { return P(-y, x); } // rotates +90 degrees\n\tP normal() const\
    \ { return perp().unit(); }\n\t// returns point rotated 'a' radians ccw around\
    \ the origin\n\tP rotate(double a) const {\n\t\treturn P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));\
    \ }\n\tfriend ostream& operator<<(ostream& os, P p) {\n\t\treturn os << \"(\"\
    \ << p.x << \",\" << p.y << \")\"; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/Point.h
  requiredBy:
  - src/geometry/circumcircle.h
  - src/geometry/LineHullIntersection.h
  - src/geometry/kdTree.h
  - src/geometry/linearTransformation.h
  - src/geometry/CirclePolygonIntersection.h
  - src/geometry/PolygonCut.h
  - src/geometry/lineDistance.h
  - src/geometry/CircleLine.h
  - src/geometry/sideOf.h
  - src/geometry/InsidePolygon.h
  - src/geometry/ClosestPair.h
  - src/geometry/FastDelaunay.h
  - src/geometry/ConvexHull.h
  - src/geometry/PolygonUnion.h
  - src/geometry/CircleIntersection.h
  - src/geometry/PolygonCenter.h
  - src/geometry/SegmentDistance.h
  - src/geometry/lineIntersection.h
  - src/geometry/HullDiameter.h
  - src/geometry/SegmentIntersection.h
  - src/geometry/PolygonArea.h
  - src/geometry/PointInsideHull.h
  - src/geometry/MinimumEnclosingCircle.h
  - src/geometry/LineProjectionReflection.h
  - src/geometry/DelaunayTriangulation.h
  - src/geometry/OnSegment.h
  - src/geometry/ManhattanMST.h
  - src/geometry/CircleTangents.h
  timestamp: '2025-07-19 20:25:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/Point.h
layout: document
redirect_from:
- /library/src/geometry/Point.h
- /library/src/geometry/Point.h.html
title: src/geometry/Point.h
---
