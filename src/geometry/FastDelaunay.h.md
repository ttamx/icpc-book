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
    - https://github.com/Bathlamos/delaunay-triangulation/
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/FastDelaunay.h: line 15: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Philippe Legault\n * Date: 2016\n * License: MIT\n * Source:\
    \ https://github.com/Bathlamos/delaunay-triangulation/\n * Description: Fast Delaunay\
    \ triangulation.\n * Each circumcircle contains none of the input points.\n *\
    \ There must be no duplicate points.\n * If all points are on a line, no triangles\
    \ will be returned.\n * Should work for doubles as well, though there may be precision\
    \ issues in 'circ'.\n * Returns triangles in order \\{t[0][0], t[0][1], t[0][2],\
    \ t[1][0], \\dots\\}, all counter-clockwise.\n * Time: O(n \\log n)\n * Status:\
    \ stress-tested\n */\n#pragma once\n\n#include \"src/geometry/Point.h\"\n\ntypedef\
    \ Point<ll> P;\ntypedef struct Quad* Q;\ntypedef __int128_t lll; // (can be ll\
    \ if coords are < 2e4)\nP arb(LLONG_MAX,LLONG_MAX); // not equal to any other\
    \ point\n\nstruct Quad {\n\tQ rot, o; P p = arb; bool mark;\n\tP& F() { return\
    \ r()->p; }\n\tQ& r() { return rot->rot; }\n\tQ prev() { return rot->o->rot; }\n\
    \tQ next() { return r()->prev(); }\n} *H;\n\nbool circ(P p, P a, P b, P c) { //\
    \ is p in the circumcircle?\n\tlll p2 = p.dist2(), A = a.dist2()-p2,\n\t    B\
    \ = b.dist2()-p2, C = c.dist2()-p2;\n\treturn p.cross(a,b)*C + p.cross(b,c)*A\
    \ + p.cross(c,a)*B > 0;\n}\nQ makeEdge(P orig, P dest) {\n\tQ r = H ? H : new\
    \ Quad{new Quad{new Quad{new Quad{0}}}};\n\tH = r->o; r->r()->r() = r;\n\trep(i,0,4)\
    \ r = r->rot, r->p = arb, r->o = i & 1 ? r : r->r();\n\tr->p = orig; r->F() =\
    \ dest;\n\treturn r;\n}\nvoid splice(Q a, Q b) {\n\tswap(a->o->rot->o, b->o->rot->o);\
    \ swap(a->o, b->o);\n}\nQ connect(Q a, Q b) {\n\tQ q = makeEdge(a->F(), b->p);\n\
    \tsplice(q, a->next());\n\tsplice(q->r(), b);\n\treturn q;\n}\n\npair<Q,Q> rec(const\
    \ vector<P>& s) {\n\tif (sz(s) <= 3) {\n\t\tQ a = makeEdge(s[0], s[1]), b = makeEdge(s[1],\
    \ s.back());\n\t\tif (sz(s) == 2) return { a, a->r() };\n\t\tsplice(a->r(), b);\n\
    \t\tauto side = s[0].cross(s[1], s[2]);\n\t\tQ c = side ? connect(b, a) : 0;\n\
    \t\treturn {side < 0 ? c->r() : a, side < 0 ? c : b->r() };\n\t}\n\n#define H(e)\
    \ e->F(), e->p\n#define valid(e) (e->F().cross(H(base)) > 0)\n\tQ A, B, ra, rb;\n\
    \tint half = sz(s) / 2;\n\ttie(ra, A) = rec({all(s) - half});\n\ttie(B, rb) =\
    \ rec({sz(s) - half + all(s)});\n\twhile ((B->p.cross(H(A)) < 0 && (A = A->next()))\
    \ ||\n\t       (A->p.cross(H(B)) > 0 && (B = B->r()->o)));\n\tQ base = connect(B->r(),\
    \ A);\n\tif (A->p == ra->p) ra = base->r();\n\tif (B->p == rb->p) rb = base;\n\
    \n#define DEL(e, init, dir) Q e = init->dir; if (valid(e)) \\\n\t\twhile (circ(e->dir->F(),\
    \ H(base), e->F())) { \\\n\t\t\tQ t = e->dir; \\\n\t\t\tsplice(e, e->prev());\
    \ \\\n\t\t\tsplice(e->r(), e->r()->prev()); \\\n\t\t\te->o = H; H = e; e = t;\
    \ \\\n\t\t}\n\tfor (;;) {\n\t\tDEL(LC, base->r(), o);  DEL(RC, base, prev());\n\
    \t\tif (!valid(LC) && !valid(RC)) break;\n\t\tif (!valid(LC) || (valid(RC) &&\
    \ circ(H(RC), H(LC))))\n\t\t\tbase = connect(RC, base->r());\n\t\telse\n\t\t\t\
    base = connect(base->r(), LC->r());\n\t}\n\treturn { ra, rb };\n}\n\nvector<P>\
    \ triangulate(vector<P> pts) {\n\tsort(all(pts));  assert(unique(all(pts)) ==\
    \ pts.end());\n\tif (sz(pts) < 2) return {};\n\tQ e = rec(pts).first;\n\tvector<Q>\
    \ q = {e};\n\tint qi = 0;\n\twhile (e->o->F().cross(e->F(), e->p) < 0) e = e->o;\n\
    #define ADD { Q c = e; do { c->mark = 1; pts.push_back(c->p); \\\n\tq.push_back(c->r());\
    \ c = c->next(); } while (c != e); }\n\tADD; pts.clear();\n\twhile (qi < sz(q))\
    \ if (!(e = q[qi++])->mark) ADD;\n\treturn pts;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/FastDelaunay.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/FastDelaunay.h
layout: document
redirect_from:
- /library/src/geometry/FastDelaunay.h
- /library/src/geometry/FastDelaunay.h.html
title: src/geometry/FastDelaunay.h
---
