---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data-structures/LineContainer.hpp
    title: src/data-structures/LineContainer.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structures/LinkCutTree.hpp
    title: src/data-structures/LinkCutTree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structures/line-container/line_add_get_min.test.cpp
    title: verify/data-structures/line-container/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data-structures/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
    title: verify/data-structures/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
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
  - src/data-structures/LinkCutTree.hpp
  - src/data-structures/LineContainer.hpp
  timestamp: '2025-07-17 16:04:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structures/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
  - verify/data-structures/line-container/line_add_get_min.test.cpp
documentation_of: src/contest/template.hpp
layout: document
redirect_from:
- /library/src/contest/template.hpp
- /library/src/contest/template.hpp.html
title: src/contest/template.hpp
---
