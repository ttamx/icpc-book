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
    - https://cp-algorithms.com/geometry/halfplane-intersection.html
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/HalfPlane.h: line 21: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Teetat T.\n * Date: 2026-10-03\n * License: CC0\n * Source:\
    \ https://cp-algorithms.com/geometry/halfplane-intersection.html\n * Description:\
    \ Intersection of half-planes. Half-plane $(s,e)$ keeps\n *  the points LEFT of\
    \ the directed line $s\\to e$, i.e. $s.cross(e,p)\\ge0$\n *  (opposite of polygonCut,\
    \ which keeps the right side).\n *  Returns the vertices in ccw order, empty if\
    \ the intersection is empty\n *  or has zero area. The result must be bounded:\
    \ add a bounding box.\n *  EPS is absolute: with a huge box ($B>10^5$) zero-area\
    \ answers may\n *  survive as thin slivers.\n * Usage:\n * \tvector<L> h={...};\
    \ double B=1e5;\n * \tP c[4]={P(-B,-B),P(B,-B),P(B,B),P(-B,B)};\n * \tfor(int\
    \ i=0;i<4;i++)h.pb({c[i],c[(i+1)%4]});\n * \tvector<P> poly=halfPlane(h);\n *\
    \ Time: $O(n \\log n)$\n * Status: stress-tested against repeated polygonCut\n\
    \ */\n#pragma once\n\n#include \"src/geometry/Point.h\"\n\ntypedef Point<double>\
    \ P;\ntypedef array<P,2> L;\nP hpInter(L a,L b){\n\tP d=a[1]-a[0],e=b[1]-b[0];\n\
    \treturn a[0]+d*((b[0]-a[0]).cross(e)/d.cross(e));\n}\nvector<P> halfPlane(vector<L>\
    \ h){\n\tauto dir=[](L l){return l[1]-l[0];};\n\tauto out=[](L l,P p){return l[0].cross(l[1],p)<-EPS;};\n\
    \tauto hf=[&](L l){P d=dir(l);return d.y<0||(!d.y&&d.x<0);};\n\tauto cr=[&](L\
    \ a,L b){return dir(a).cross(dir(b));};\n\tsort(ALL(h),[&](L a,L b){\n\t\tif(hf(a)!=hf(b))return\
    \ hf(a)<hf(b);\n\t\treturn cr(a,b)?cr(a,b)>0:b[0].cross(b[1],a[0])>0;});\n\tdeque<L>\
    \ q;\n\tauto bk=[&]{return hpInter(q[SZ(q)-1],q[SZ(q)-2]);};\n\tauto fr=[&]{return\
    \ hpInter(q[0],q[1]);};\n\tfor(int i=0;i<SZ(h);i++){\n\t\tL l=h[i];\n\t\tif(i&&hf(l)==hf(h[i-1])&&!cr(l,h[i-1]))continue;\n\
    \t\twhile(SZ(q)>1&&out(l,bk()))q.pop_back();\n\t\twhile(SZ(q)>1&&out(l,fr()))q.pop_front();\n\
    \t\tif(SZ(q)&&abs(dir(l).cross(dir(q.back())))<EPS){\n\t\t\tif(dir(l).dot(dir(q.back()))<0)return\
    \ {};\n\t\t\tif(out(l,q.back()[0]))q.pop_back();\n\t\t\telse continue;\n\t\t}\n\
    \t\tq.pb(l);\n\t}\n\twhile(SZ(q)>2&&out(q[0],bk()))q.pop_back();\n\twhile(SZ(q)>2&&out(q.back(),fr()))q.pop_front();\n\
    \tif(SZ(q)<3)return {};\n\tvector<P> r;double a=0;\n\tfor(int i=0;i<SZ(q);i++)r.pb(hpInter(q[i],q[(i+1)%SZ(q)]));\n\
    \tfor(int i=0;i<SZ(r);i++)a+=r[i].cross(r[(i+1)%SZ(r)]);\n\treturn a>EPS?r:vector<P>();\n\
    }\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/HalfPlane.h
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/HalfPlane.h
layout: document
redirect_from:
- /library/src/geometry/HalfPlane.h
- /library/src/geometry/HalfPlane.h.html
title: src/geometry/HalfPlane.h
---
