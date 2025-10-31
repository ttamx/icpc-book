---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Matching/Hungarian.h
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/flows/hungarian-algorithm.hpp: line 15: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * Author: Benjamin Qi, chilli\n * Date: 2020-04-04\n * License: CC0\n\
    \ * Source: https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Matching/Hungarian.h\n\
    \ * Description: Given a weighted bipartite graph, matches every node on\n * the\
    \ left with a node on the right such that no\n * nodes are in two matchings and\
    \ the sum of the edge weights is minimal. Takes\n * cost[N][M], where cost[i][j]\
    \ = cost for L[i] to be matched with R[j] and\n * returns (min cost, match), where\
    \ L[i] is matched with\n * R[match[i]]. Negate costs for max cost. Requires $N\
    \ \\le M$.\n * Time: O(N^2M)\n * Status: Tested on kattis:cordonbleu, stress-tested\n\
    \ */\n#pragma once\n\npair<ll, vector<int>> hungarian(const vector<vector<ll>>\
    \ &a) {\n\tif (a.empty()) return {0, {}};\n\tint n = a.size() + 1, m = a[0].size()\
    \ + 1;\n\tvector<ll> u(n), v(m);\n    vector<int> p(m), ans(n - 1);\n\tfor(int\
    \ i=1;i<n;i++) {\n\t\tp[0] = i;\n\t\tint j0 = 0; // add \"dummy\" worker 0\n\t\
    \tvector<ll> dist(m, LLONG_MAX);\n        vector<int> pre(m, -1);\n\t\tvector<bool>\
    \ done(m + 1);\n\t\tdo { // dijkstra\n\t\t\tdone[j0] = true;\n\t\t\tint i0 = p[j0],\
    \ j1;\n            ll delta = LLONG_MAX;\n\t\t\tfor(int j=1;j<m;j++) if (!done[j])\
    \ {\n\t\t\t\tauto cur = a[i0 - 1][j - 1] - u[i0] - v[j];\n\t\t\t\tif (cur < dist[j])\
    \ dist[j] = cur, pre[j] = j0;\n\t\t\t\tif (dist[j] < delta) delta = dist[j], j1\
    \ = j;\n\t\t\t}\n\t\t\tfor(int j=0;j<m;j++) {\n\t\t\t\tif (done[j]) u[p[j]] +=\
    \ delta, v[j] -= delta;\n\t\t\t\telse dist[j] -= delta;\n\t\t\t}\n\t\t\tj0 = j1;\n\
    \t\t} while (p[j0]);\n\t\twhile (j0) { // update alternating path\n\t\t\tint j1\
    \ = pre[j0];\n\t\t\tp[j0] = p[j1], j0 = j1;\n\t\t}\n\t}\n\tfor(int j=1;j<m;j++)\
    \ if (p[j]) ans[p[j] - 1] = j - 1;\n\treturn {-v[0], ans}; // min cost\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: src/flows/hungarian-algorithm.hpp
  requiredBy: []
  timestamp: '2025-07-19 19:25:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flows/hungarian-algorithm.hpp
layout: document
redirect_from:
- /library/src/flows/hungarian-algorithm.hpp
- /library/src/flows/hungarian-algorithm.hpp.html
title: src/flows/hungarian-algorithm.hpp
---
