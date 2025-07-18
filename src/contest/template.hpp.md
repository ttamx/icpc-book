---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data-structures/LineContainer.hpp
    title: src/data-structures/LineContainer.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structures/SegmentTreeBeats.hpp
    title: src/data-structures/SegmentTreeBeats.hpp
  - icon: ':warning:'
    path: src/flows/BinaryOptimization.hpp
    title: src/flows/BinaryOptimization.hpp
  - icon: ':warning:'
    path: src/flows/Dinic.hpp
    title: src/flows/Dinic.hpp
  - icon: ':heavy_check_mark:'
    path: src/flows/HopcroftKarp.hpp
    title: src/flows/HopcroftKarp.hpp
  - icon: ':warning:'
    path: src/flows/KaryOptimization.hpp
    title: src/flows/KaryOptimization.hpp
  - icon: ':warning:'
    path: src/flows/MinCostFlow.hpp
    title: src/flows/MinCostFlow.hpp
  - icon: ':warning:'
    path: src/number-theory/CRT.hpp
    title: src/number-theory/CRT.hpp
  - icon: ':warning:'
    path: src/number-theory/Euclid.hpp
    title: src/number-theory/Euclid.hpp
  - icon: ':heavy_check_mark:'
    path: src/number-theory/FloorSum.hpp
    title: src/number-theory/FloorSum.hpp
  - icon: ':heavy_check_mark:'
    path: src/tree/LinkCutTree.hpp
    title: src/tree/LinkCutTree.hpp
  - icon: ':warning:'
    path: src/tree/StaticTopTree.hpp
    title: src/tree/StaticTopTree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structures/line-container/line_add_get_min.test.cpp
    title: verify/data-structures/line-container/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp
    title: verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/flows/hopcroft-karp/bipartitematching.test.cpp
    title: verify/flows/hopcroft-karp/bipartitematching.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
    title: verify/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
    title: verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/contest/template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n \nusing namespace std;\nusing namespace\
    \ __gnu_pbds;\n \nusing ll = long long;\nusing db = long double;\nusing vi = vector<int>;\n\
    using vl = vector<ll>;\nusing vd = vector<db>;\nusing pii = pair<int,int>;\nusing\
    \ pll = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst int INF=0x3fffffff;\nconst\
    \ ll LINF=0x1fffffffffffffff;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const db EPS=1e-9;\nconst db PI=acos(db(-1));\n \ntemplate<class T>\nusing ordered_set\
    \ = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \ \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n"
  code: "#pragma once\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n \nusing namespace std;\nusing namespace\
    \ __gnu_pbds;\n \nusing ll = long long;\nusing db = long double;\nusing vi = vector<int>;\n\
    using vl = vector<ll>;\nusing vd = vector<db>;\nusing pii = pair<int,int>;\nusing\
    \ pll = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst int INF=0x3fffffff;\nconst\
    \ ll LINF=0x1fffffffffffffff;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const db EPS=1e-9;\nconst db PI=acos(db(-1));\n \ntemplate<class T>\nusing ordered_set\
    \ = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \ \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());"
  dependsOn: []
  isVerificationFile: false
  path: src/contest/template.hpp
  requiredBy:
  - src/data-structures/SegmentTreeBeats.hpp
  - src/data-structures/LineContainer.hpp
  - src/tree/StaticTopTree.hpp
  - src/tree/LinkCutTree.hpp
  - src/flows/Dinic.hpp
  - src/flows/HopcroftKarp.hpp
  - src/flows/KaryOptimization.hpp
  - src/flows/MinCostFlow.hpp
  - src/flows/BinaryOptimization.hpp
  - src/number-theory/CRT.hpp
  - src/number-theory/Euclid.hpp
  - src/number-theory/FloorSum.hpp
  timestamp: '2025-07-17 16:04:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp
  - verify/data-structures/line-container/line_add_get_min.test.cpp
  - verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
  - verify/flows/hopcroft-karp/bipartitematching.test.cpp
  - verify/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
documentation_of: src/contest/template.hpp
layout: document
redirect_from:
- /library/src/contest/template.hpp
- /library/src/contest/template.hpp.html
title: src/contest/template.hpp
---
