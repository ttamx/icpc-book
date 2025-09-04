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
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/kdTree.h: line 8: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Stanford\n * Date: Unknown\n * Source: Stanford Notebook\n\
    \ * Description: KD-tree (2d, can be extended to 3d)\n * Status: Tested on excellentengineers\n\
    \ */\n#pragma once\n\n#include \"src/geometry/Point.h\"\n\ntypedef long long T;\n\
    typedef Point<T> P;\nconst T INF = numeric_limits<T>::max();\n\nbool on_x(const\
    \ P& a, const P& b) { return a.x < b.x; }\nbool on_y(const P& a, const P& b) {\
    \ return a.y < b.y; }\n\nstruct Node {\n\tP pt; // if this is a leaf, the single\
    \ point in it\n\tT x0 = INF, x1 = -INF, y0 = INF, y1 = -INF; // bounds\n\tNode\
    \ *first = 0, *second = 0;\n\n\tT distance(const P& p) { // min squared distance\
    \ to a point\n\t\tT x = (p.x < x0 ? x0 : p.x > x1 ? x1 : p.x);\n\t\tT y = (p.y\
    \ < y0 ? y0 : p.y > y1 ? y1 : p.y);\n\t\treturn (P(x,y) - p).dist2();\n\t}\n\n\
    \tNode(vector<P>&& vp) : pt(vp[0]) {\n\t\tfor (P p : vp) {\n\t\t\tx0 = min(x0,\
    \ p.x); x1 = max(x1, p.x);\n\t\t\ty0 = min(y0, p.y); y1 = max(y1, p.y);\n\t\t\
    }\n\t\tif (vp.size() > 1) {\n\t\t\t// split on x if width >= height (not ideal...)\n\
    \t\t\tsort(all(vp), x1 - x0 >= y1 - y0 ? on_x : on_y);\n\t\t\t// divide by taking\
    \ half the array for each child (not\n\t\t\t// best performance with many duplicates\
    \ in the middle)\n\t\t\tint half = sz(vp)/2;\n\t\t\tfirst = new Node({vp.begin(),\
    \ vp.begin() + half});\n\t\t\tsecond = new Node({vp.begin() + half, vp.end()});\n\
    \t\t}\n\t}\n};\n\nstruct KDTree {\n\tNode* root;\n\tKDTree(const vector<P>& vp)\
    \ : root(new Node({all(vp)})) {}\n\n\tpair<T, P> search(Node *node, const P& p)\
    \ {\n\t\tif (!node->first) {\n\t\t\t// uncomment if we should not find the point\
    \ itself:\n\t\t\t// if (p == node->pt) return {INF, P()};\n\t\t\treturn make_pair((p\
    \ - node->pt).dist2(), node->pt);\n\t\t}\n\n\t\tNode *f = node->first, *s = node->second;\n\
    \t\tT bfirst = f->distance(p), bsec = s->distance(p);\n\t\tif (bfirst > bsec)\
    \ swap(bsec, bfirst), swap(f, s);\n\n\t\t// search closest side first, other side\
    \ if needed\n\t\tauto best = search(f, p);\n\t\tif (bsec < best.first)\n\t\t\t\
    best = min(best, search(s, p));\n\t\treturn best;\n\t}\n\n\t// find nearest point\
    \ to a point, and its squared distance\n\t// (requires an arbitrary operator<\
    \ for Point)\n\tpair<T, P> nearest(const P& p) {\n\t\treturn search(root, p);\n\
    \t}\n};\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/kdTree.h
  requiredBy: []
  timestamp: '2025-07-19 20:33:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/kdTree.h
layout: document
redirect_from:
- /library/src/geometry/kdTree.h
- /library/src/geometry/kdTree.h.html
title: src/geometry/kdTree.h
---
