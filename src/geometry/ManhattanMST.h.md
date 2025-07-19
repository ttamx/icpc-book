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
    - https://github.com/spaghetti-source/algorithm/blob/master/geometry/rectilinear_mst.cc
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/ManhattanMST.h: line 13: #pragma once found in a non-first line\n"
  code: "/**\n * Author: chilli, Takanori MAEHARA\n * Date: 2019-11-02\n * License:\
    \ CC0\n * Source: https://github.com/spaghetti-source/algorithm/blob/master/geometry/rectilinear_mst.cc\n\
    \ * Description: Given N points, returns up to 4*N edges, which are guaranteed\n\
    \ * to contain a minimum spanning tree for the graph with edge weights w(p, q)\
    \ =\n * |p.x - q.x| + |p.y - q.y|. Edges are in the form (distance, src, dst).\
    \ Use a\n * standard MST algorithm on the result to find the final MST.\n * Time:\
    \ O(N \\log N)\n * Status: Stress-tested\n */\n#pragma once\n#include \"Point.h\"\
    \n\ntypedef Point<int> P;\nvector<array<int, 3>> manhattanMST(vector<P> ps) {\n\
    \tvi id(sz(ps));\n\tiota(all(id), 0);\n\tvector<array<int, 3>> edges;\n\trep(k,0,4)\
    \ {\n\t\tsort(all(id), [&](int i, int j) {\n\t\t     return (ps[i]-ps[j]).x <\
    \ (ps[j]-ps[i]).y;});\n\t\tmap<int, int> sweep;\n\t\tfor (int i : id) {\n\t\t\t\
    for (auto it = sweep.lower_bound(-ps[i].y);\n\t\t\t\t        it != sweep.end();\
    \ sweep.erase(it++)) {\n\t\t\t\tint j = it->second;\n\t\t\t\tP d = ps[i] - ps[j];\n\
    \t\t\t\tif (d.y > d.x) break;\n\t\t\t\tedges.push_back({d.y + d.x, i, j});\n\t\
    \t\t}\n\t\t\tsweep[-ps[i].y] = i;\n\t\t}\n\t\tfor (P& p : ps) if (k & 1) p.x =\
    \ -p.x; else swap(p.x, p.y);\n\t}\n\treturn edges;\n}\n"
  dependsOn:
  - src/geometry/Point.h
  isVerificationFile: false
  path: src/geometry/ManhattanMST.h
  requiredBy: []
  timestamp: '2025-07-19 20:25:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/ManhattanMST.h
layout: document
redirect_from:
- /library/src/geometry/ManhattanMST.h
- /library/src/geometry/ManhattanMST.h.html
title: src/geometry/ManhattanMST.h
---
