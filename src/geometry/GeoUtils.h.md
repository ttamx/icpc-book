---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/Point.h
    title: src/geometry/Point.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/InsidePoly.h
    title: src/geometry/InsidePoly.h
  - icon: ':warning:'
    path: src/geometry/MinEnclosingCircle.h
    title: src/geometry/MinEnclosingCircle.h
  - icon: ':warning:'
    path: src/geometry/PointInsideHull.h
    title: src/geometry/PointInsideHull.h
  - icon: ':warning:'
    path: src/geometry/PolyUnion.h
    title: src/geometry/PolyUnion.h
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://vlecomte.github.io/cp-geo.pdf,
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.8/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/GeoUtils.h: line 13: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Ulf Lundstrom, Victor Lecomte, chilli\n * License: CC0\n\
    \ * Source: https://vlecomte.github.io/cp-geo.pdf, tinyKACTL\n * Description:\
    \ Basic primitives: lineDist, sideOf, onSegment,\n * segDist, lineInter, segInter,\
    \ lineProj,\n * linearTransformation, ccRadius/ccCenter (circumcircle),\n * polygonArea2,\
    \ polygonCenter. Integer points: products of up\n * to three coordinates, watch\
    \ overflow.\n * Time: O(1), polygon ones O(n)\n * Status: tested\n */\n#pragma\
    \ once\n\n#include \"src/geometry/Point.h\"\n\n// signed dist from p to line ab\
    \ (>0 left); a==b gives nan\ntemplate<class P> double lineDist(P a,P b,P p){\n\
    \treturn (double)(b-a).cross(p-a)/(b-a).dist();\n}\n// p seen from s towards e:\
    \ 1 left, 0 on, -1 right\ntemplate<class P>\nint sideOf(P s,P e,P p){return sgn(s.cross(e,p));}\n\
    // eps version: 0 if p within distance eps of line\ntemplate<class P> int sideOf(P\
    \ s,P e,P p,double eps){\n\tauto a=(e-s).cross(p-s);\n\tdouble l=(e-s).dist()*eps;\n\
    \treturn (a>l)-(a<-l);\n}\n// p on segment se (exact; for doubles use segDist<=eps)\n\
    template<class P> bool onSegment(P s,P e,P p){\n\treturn p.cross(s,e)==0&&(s-p).dot(e-p)<=0;\n\
    }\n// dist from p to segment se (Point<double>)\ntemplate<class P> double segDist(P\
    \ s,P e,P p){\n\tif(s==e)return (p-s).dist();\n\tauto d=(e-s).dist2(),t=min(d,max(.0,(p-s).dot(e-s)));\n\
    \treturn ((p-s)*d-(e-s)*t).dist()/d;\n}\n// lines s1e1,s2e2: {1,p} unique, {0,(0,0)}\
    \ parallel,\n// {-1,(0,0)} same line. Wrong if Point<ll> and p not integer\ntemplate<class\
    \ P> pair<int,P> lineInter(P s1,P e1,P s2,P e2){\n\tauto d=(e1-s1).cross(e2-s2);\n\
    \tif(d==0)return {-(s1.cross(e1,s2)==0),P(0,0)}; // parallel\n\tauto p=s2.cross(e1,e2),q=s2.cross(e2,s1);\n\
    \treturn {1,(s1*p+e1*q)/d};\n}\n// segments ab,cd: {} none, {p} one point, {p,q}\
    \ overlap\ntemplate<class P> vector<P> segInter(P a,P b,P c,P d){\n\tauto oa=c.cross(d,a),ob=c.cross(d,b);\n\
    \tauto oc=a.cross(b,c),od=a.cross(b,d);\n\tif(sgn(oa)*sgn(ob)<0&&sgn(oc)*sgn(od)<0)\n\
    \t\treturn {(a*ob-b*oa)/(ob-oa)};\n\tset<P> s;\n\tif(onSegment(c,d,a))s.insert(a);\n\
    \tif(onSegment(c,d,b))s.insert(b);\n\tif(onSegment(a,b,c))s.insert(c);\n\tif(onSegment(a,b,d))s.insert(d);\n\
    \treturn {ALL(s)};\n}\n// projection of p onto line ab (refl: reflection instead)\n\
    template<class P> P lineProj(P a,P b,P p,bool refl=false){\n\tP v=b-a;\n\treturn\
    \ p-v.perp()*(1+refl)*v.cross(p-a)/v.dist2();\n}\n// move the plane (rotate+scale+translate,\
    \ never mirror) so\n// p0->q0 and p1->q1; returns where r lands. As complex\n\
    // numbers: q0+(r-p0)*(q1-q0)/(p1-p0). Use Point<double>\ntemplate<class P>\n\
    P linearTransformation(P p0,P p1,P q0,P q1,P r){\n\tP dp=p1-p0,dq=q1-q0,num(dp.cross(dq),dp.dot(dq));\n\
    \treturn q0+P((r-p0).cross(num),(r-p0).dot(num))/dp.dist2();\n}\n// circumcircle\
    \ of ABC: radius / center (Point<double>)\ntemplate<class P> double ccRadius(P\
    \ A,P B,P C){\n\treturn (B-A).dist()*(C-B).dist()*(A-C).dist()/\n\t\tabs((B-A).cross(C-A))/2;\n\
    }\ntemplate<class P> P ccCenter(const P& A,const P& B,const P& C){\n\tP b=C-A,c=B-A;\n\
    \treturn A+(b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;\n}\n// twice signed\
    \ area (CW negative)\ntemplate<class T> T polygonArea2(const vector<Point<T>>&\
    \ v){\n\tT a=v.back().cross(v[0]);\n\tfor(int i=0;i<SZ(v)-1;i++)a+=v[i].cross(v[i+1]);\n\
    \treturn a;\n}\n// center of mass of polygon (Point<double>)\ntemplate<class P>\
    \ P polygonCenter(const vector<P>& v){\n\tP res(0,0);double A=0;\n\tfor(int i=0,j=SZ(v)-1;i<SZ(v);j=i++){\n\
    \t\tres=res+(v[i]+v[j])*v[j].cross(v[i]);\n\t\tA+=v[j].cross(v[i]);\n\t}\n\treturn\
    \ res/A/3;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/GeoUtils.h
  requiredBy:
  - src/geometry/PolyUnion.h
  - src/geometry/InsidePoly.h
  - src/geometry/MinEnclosingCircle.h
  - src/geometry/PointInsideHull.h
  timestamp: '2026-10-26 18:23:08+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/GeoUtils.h
layout: document
redirect_from:
- /library/src/geometry/GeoUtils.h
- /library/src/geometry/GeoUtils.h.html
title: src/geometry/GeoUtils.h
---
