---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/CircleIntersection.h
    title: src/geometry/CircleIntersection.h
  - icon: ':heavy_check_mark:'
    path: src/geometry/CircleLine.h
    title: src/geometry/CircleLine.h
  - icon: ':heavy_check_mark:'
    path: src/geometry/CirclePolyInter.h
    title: src/geometry/CirclePolyInter.h
  - icon: ':heavy_check_mark:'
    path: src/geometry/CircleTangents.h
    title: src/geometry/CircleTangents.h
  - icon: ':warning:'
    path: src/geometry/ClosestPair.h
    title: src/geometry/ClosestPair.h
  - icon: ':heavy_check_mark:'
    path: src/geometry/ConvexHull.h
    title: src/geometry/ConvexHull.h
  - icon: ':warning:'
    path: src/geometry/DelaunayTriangulation.h
    title: src/geometry/DelaunayTriangulation.h
  - icon: ':warning:'
    path: src/geometry/FastDelaunay.h
    title: src/geometry/FastDelaunay.h
  - icon: ':heavy_check_mark:'
    path: src/geometry/GeoUtils.h
    title: src/geometry/GeoUtils.h
  - icon: ':warning:'
    path: src/geometry/HalfPlane.h
    title: src/geometry/HalfPlane.h
  - icon: ':heavy_check_mark:'
    path: src/geometry/HullDiameter.h
    title: src/geometry/HullDiameter.h
  - icon: ':heavy_check_mark:'
    path: src/geometry/InsidePoly.h
    title: src/geometry/InsidePoly.h
  - icon: ':warning:'
    path: src/geometry/LineHullIntersection.h
    title: src/geometry/LineHullIntersection.h
  - icon: ':heavy_check_mark:'
    path: src/geometry/ManhattanMST.h
    title: src/geometry/ManhattanMST.h
  - icon: ':warning:'
    path: src/geometry/MaxTriangle.h
    title: src/geometry/MaxTriangle.h
  - icon: ':warning:'
    path: src/geometry/MinEnclosingCircle.h
    title: src/geometry/MinEnclosingCircle.h
  - icon: ':warning:'
    path: src/geometry/PointInsideHull.h
    title: src/geometry/PointInsideHull.h
  - icon: ':heavy_check_mark:'
    path: src/geometry/PolyCut.h
    title: src/geometry/PolyCut.h
  - icon: ':warning:'
    path: src/geometry/PolyUnion.h
    title: src/geometry/PolyUnion.h
  - icon: ':warning:'
    path: src/geometry/kdTree.h
    title: src/geometry/kdTree.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/geometry/circle-intersection/circle_cross_points.test.cpp
    title: verify/geometry/circle-intersection/circle_cross_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/circle-line/circle_line_cross_points.test.cpp
    title: verify/geometry/circle-line/circle_line_cross_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/circle-poly-inter/circle_polygon_area.test.cpp
    title: verify/geometry/circle-poly-inter/circle_polygon_area.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/circle-tangents/circle_intersection_count.test.cpp
    title: verify/geometry/circle-tangents/circle_intersection_count.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/circle-tangents/common_tangent.test.cpp
    title: verify/geometry/circle-tangents/common_tangent.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/circle-tangents/tangent_to_circle.test.cpp
    title: verify/geometry/circle-tangents/tangent_to_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/convex-hull/static_convex_hull.test.cpp
    title: verify/geometry/convex-hull/static_convex_hull.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/geo-utils/circumscribed_circle.test.cpp
    title: verify/geometry/geo-utils/circumscribed_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/geo-utils/counter_clockwise.test.cpp
    title: verify/geometry/geo-utils/counter_clockwise.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/geo-utils/cross_point.test.cpp
    title: verify/geometry/geo-utils/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/geo-utils/is_convex.test.cpp
    title: verify/geometry/geo-utils/is_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/geo-utils/polygon_area.test.cpp
    title: verify/geometry/geo-utils/polygon_area.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/geo-utils/projection.test.cpp
    title: verify/geometry/geo-utils/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/geo-utils/reflection.test.cpp
    title: verify/geometry/geo-utils/reflection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/geo-utils/segment_distance.test.cpp
    title: verify/geometry/geo-utils/segment_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/geo-utils/segment_intersection.test.cpp
    title: verify/geometry/geo-utils/segment_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/hull-diameter/furthest_pair.test.cpp
    title: verify/geometry/hull-diameter/furthest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/inside-poly/polygon_point_containment.test.cpp
    title: verify/geometry/inside-poly/polygon_point_containment.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/manhattan-mst/manhattanmst.test.cpp
    title: verify/geometry/manhattan-mst/manhattanmst.test.cpp
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
    \ src/geometry/Point.h: line 10: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Ulf Lundstrom\n * Date: 2009-02-26\n * License: CC0\n * Source:\
    \ My head with inspiration from tinyKACTL\n * Description: Class to handle points\
    \ in the plane.\n * \tT can be e.g. double or long long. (Avoid int.)\n * Status:\
    \ Works fine, used a lot\n */\n#pragma once\n\ntemplate<class T> int sgn(T x){return\
    \ (x>0)-(x<0);}\ntemplate<class T>\nstruct Point{\n\tusing P = Point;\n\tT x,y;\n\
    \texplicit Point(T x=0,T y=0):x(x),y(y){}\n\tbool operator<(P p)const{return tie(x,y)<tie(p.x,p.y);}\n\
    \tbool operator==(P p)const{return tie(x,y)==tie(p.x,p.y);}\n\tP operator+(P p)const{return\
    \ P(x+p.x,y+p.y);}\n\tP operator-(P p)const{return P(x-p.x,y-p.y);}\n\tP operator*(T\
    \ d)const{return P(x*d,y*d);}\n\tP operator/(T d)const{return P(x/d,y/d);}\n\t\
    T dot(P p)const{return x*p.x+y*p.y;}\n\tT cross(P p)const{return x*p.y-y*p.x;}\n\
    \tT cross(P a,P b)const{return (a-*this).cross(b-*this);}\n\tT dist2()const{return\
    \ x*x+y*y;}\n\tdouble dist()const{return sqrt((double)dist2());}\n\t// angle to\
    \ x-axis in interval [-pi, pi]\n\tdouble angle()const{return atan2(y,x);}\n\t\
    P unit()const{return *this/dist();} // makes dist()=1\n\tP perp()const{return\
    \ P(-y,x);} // rotates +90 degrees\n\tP normal()const{return perp().unit();}\n\
    \t// returns point rotated 'a' radians ccw around the origin\n\tP rotate(double\
    \ a)const{\n\t\treturn P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));}\n\tfriend ostream&\
    \ operator<<(ostream& os,P p){\n\t\treturn os<<\"(\"<<p.x<<\",\"<<p.y<<\")\";}\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/Point.h
  requiredBy:
  - src/geometry/CircleTangents.h
  - src/geometry/PolyUnion.h
  - src/geometry/CirclePolyInter.h
  - src/geometry/DelaunayTriangulation.h
  - src/geometry/PolyCut.h
  - src/geometry/CircleIntersection.h
  - src/geometry/InsidePoly.h
  - src/geometry/ConvexHull.h
  - src/geometry/FastDelaunay.h
  - src/geometry/MinEnclosingCircle.h
  - src/geometry/ManhattanMST.h
  - src/geometry/HullDiameter.h
  - src/geometry/MaxTriangle.h
  - src/geometry/LineHullIntersection.h
  - src/geometry/HalfPlane.h
  - src/geometry/ClosestPair.h
  - src/geometry/PointInsideHull.h
  - src/geometry/GeoUtils.h
  - src/geometry/CircleLine.h
  - src/geometry/kdTree.h
  timestamp: '2026-10-26 18:23:08+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/geometry/circle-tangents/common_tangent.test.cpp
  - verify/geometry/circle-tangents/tangent_to_circle.test.cpp
  - verify/geometry/circle-tangents/circle_intersection_count.test.cpp
  - verify/geometry/circle-line/circle_line_cross_points.test.cpp
  - verify/geometry/poly-cut/convex_cut.test.cpp
  - verify/geometry/inside-poly/polygon_point_containment.test.cpp
  - verify/geometry/convex-hull/static_convex_hull.test.cpp
  - verify/geometry/circle-poly-inter/circle_polygon_area.test.cpp
  - verify/geometry/manhattan-mst/manhattanmst.test.cpp
  - verify/geometry/geo-utils/reflection.test.cpp
  - verify/geometry/geo-utils/projection.test.cpp
  - verify/geometry/geo-utils/cross_point.test.cpp
  - verify/geometry/geo-utils/is_convex.test.cpp
  - verify/geometry/geo-utils/segment_intersection.test.cpp
  - verify/geometry/geo-utils/circumscribed_circle.test.cpp
  - verify/geometry/geo-utils/polygon_area.test.cpp
  - verify/geometry/geo-utils/segment_distance.test.cpp
  - verify/geometry/geo-utils/counter_clockwise.test.cpp
  - verify/geometry/hull-diameter/furthest_pair.test.cpp
  - verify/geometry/circle-intersection/circle_cross_points.test.cpp
documentation_of: src/geometry/Point.h
layout: document
redirect_from:
- /library/src/geometry/Point.h
- /library/src/geometry/Point.h.html
title: src/geometry/Point.h
---
