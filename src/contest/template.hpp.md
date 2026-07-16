---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/tree/static-top-tree.hpp
    title: src/tree/static-top-tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structures/line-container/line_add_get_min.test.cpp
    title: verify/data-structures/line-container/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp
    title: verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/flows/general-matching/general_matching.test.cpp
    title: verify/flows/general-matching/general_matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/flows/hopcroft-karp/bipartitematching.test.cpp
    title: verify/flows/hopcroft-karp/bipartitematching.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/k-th-shortest-path/k_shortest_walk.test.cpp
    title: verify/graph/k-th-shortest-path/k_shortest_walk.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/miscellaneous/integral.test.cpp
    title: verify/miscellaneous/integral.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
    title: verify/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/string/manacher/enumerate_palindromes.test.cpp
    title: verify/string/manacher/enumerate_palindromes.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/string/suffix-array/number_of_substrings.test.cpp
    title: verify/string/suffix-array/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/string/suffix-array/suffixarray.test.cpp
    title: verify/string/suffix-array/suffixarray.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/string/suffix-automaton/number_of_substrings.test.cpp
    title: verify/string/suffix-automaton/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/string/z-algorithm/zalgorithm.test.cpp
    title: verify/string/z-algorithm/zalgorithm.test.cpp
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
    \ __gnu_pbds;\n\n#define pb push_back\n#define eb emplace_back\n#define mp make_pair\n\
    #define mt make_tuple\n#define fi first\n#define se second\n\n#define ALL(a) a.begin(),a.end()\n\
    #define RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n#define RSORT(a)\
    \ sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n#define UNI(a) a.erase(unique(ALL(a)),a.end())\n\
    #define SZ(a) (int)(a.size())\n#define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n\
    #define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n#define MIN(a) *min_element(ALL(a))\n\
    #define MAX(a) *max_element(ALL(a))\n\nusing ll = long long;\nusing db = long\
    \ double;\nusing i128 = __int128_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    \nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const int MOD=998244353;\nconst int MOD2=1000000007;\nconst db EPS=1e-9;\nconst\
    \ db PI=acos(db(-1));\n\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
    \n#define vv(T,a,n,...) vector<vector<T>> a(n,vector<T>(__VA_ARGS__))\n#define\
    \ vvv(T,a,n,m,...) vector<vector<vector<T>>> a(n,vector<vector<T>>(m,vector<T>(__VA_ARGS__)))\n\
    #define vvvv(T,a,n,m,k,...) vector<vector<vector<vector<T>>>> a(n,vector<vector<vector<T>>>(m,vector<vector<T>>(k,vector<T>(__VA_ARGS__))))\n\
    \ntemplate<class T,class U>\nbool chmin(T &a,U b){return b<a?a=b,1:0;}\ntemplate<class\
    \ T,class U>\nbool chmax(T &a,U b){return a<b?a=b,1:0;}\ntemplate<class T,class\
    \ U>\nT SUM(const U &a){return accumulate(ALL(a),T{});}\n\ntemplate<class T>\n\
    using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n"
  code: "#pragma once\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n \nusing namespace std;\nusing namespace\
    \ __gnu_pbds;\n\n#define pb push_back\n#define eb emplace_back\n#define mp make_pair\n\
    #define mt make_tuple\n#define fi first\n#define se second\n\n#define ALL(a) a.begin(),a.end()\n\
    #define RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n#define RSORT(a)\
    \ sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n#define UNI(a) a.erase(unique(ALL(a)),a.end())\n\
    #define SZ(a) (int)(a.size())\n#define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n\
    #define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n#define MIN(a) *min_element(ALL(a))\n\
    #define MAX(a) *max_element(ALL(a))\n\nusing ll = long long;\nusing db = long\
    \ double;\nusing i128 = __int128_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    \nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const int MOD=998244353;\nconst int MOD2=1000000007;\nconst db EPS=1e-9;\nconst\
    \ db PI=acos(db(-1));\n\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
    \n#define vv(T,a,n,...) vector<vector<T>> a(n,vector<T>(__VA_ARGS__))\n#define\
    \ vvv(T,a,n,m,...) vector<vector<vector<T>>> a(n,vector<vector<T>>(m,vector<T>(__VA_ARGS__)))\n\
    #define vvvv(T,a,n,m,k,...) vector<vector<vector<vector<T>>>> a(n,vector<vector<vector<T>>>(m,vector<vector<T>>(k,vector<T>(__VA_ARGS__))))\n\
    \ntemplate<class T,class U>\nbool chmin(T &a,U b){return b<a?a=b,1:0;}\ntemplate<class\
    \ T,class U>\nbool chmax(T &a,U b){return a<b?a=b,1:0;}\ntemplate<class T,class\
    \ U>\nT SUM(const U &a){return accumulate(ALL(a),T{});}\n\ntemplate<class T>\n\
    using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());"
  dependsOn: []
  isVerificationFile: false
  path: src/contest/template.hpp
  requiredBy:
  - src/tree/static-top-tree.hpp
  timestamp: '2026-07-05 00:41:55+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/flows/general-matching/general_matching.test.cpp
  - verify/flows/hopcroft-karp/bipartitematching.test.cpp
  - verify/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
  - verify/data-structures/line-container/line_add_get_min.test.cpp
  - verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp
  - verify/miscellaneous/integral.test.cpp
  - verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
  - verify/graph/k-th-shortest-path/k_shortest_walk.test.cpp
  - verify/string/suffix-array/number_of_substrings.test.cpp
  - verify/string/suffix-array/suffixarray.test.cpp
  - verify/string/suffix-automaton/number_of_substrings.test.cpp
  - verify/string/manacher/enumerate_palindromes.test.cpp
  - verify/string/z-algorithm/zalgorithm.test.cpp
documentation_of: src/contest/template.hpp
layout: document
redirect_from:
- /library/src/contest/template.hpp
- /library/src/contest/template.hpp.html
title: src/contest/template.hpp
---
