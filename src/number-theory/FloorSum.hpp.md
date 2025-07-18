---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
    title: verify/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 3 \"src/number-theory/FloorSum.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-09-21\n * Description: Floor sum\
    \ function.\n *  $f(a, b, c, n) = \\sum_{x=0}^n \\lfloor \\frac{ax+b}{c} \\rfloor$\n\
    \ *  becareful when a,b,c are negetive (use custom floor division and mod instead)\n\
    \ * Time: $O(\\log a)$\n */\n\nll floor_sum(ll a,ll b,ll c,ll n){\n    ll res=n*(n+1)/2*(a/c)+(n+1)*(b/c);\n\
    \    a%=c,b%=c;\n    if(a==0)return res;\n    ll m=(a*n+b)/c;\n    return res+n*m-floor_sum(c,c-b-1,a,m-1);\n\
    }\n"
  code: "#pragma once\n#include \"src/contest/template.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-09-21\n * Description: Floor sum function.\n *  $f(a, b, c,\
    \ n) = \\sum_{x=0}^n \\lfloor \\frac{ax+b}{c} \\rfloor$\n *  becareful when a,b,c\
    \ are negetive (use custom floor division and mod instead)\n * Time: $O(\\log\
    \ a)$\n */\n\nll floor_sum(ll a,ll b,ll c,ll n){\n    ll res=n*(n+1)/2*(a/c)+(n+1)*(b/c);\n\
    \    a%=c,b%=c;\n    if(a==0)return res;\n    ll m=(a*n+b)/c;\n    return res+n*m-floor_sum(c,c-b-1,a,m-1);\n\
    }"
  dependsOn:
  - src/contest/template.hpp
  isVerificationFile: false
  path: src/number-theory/FloorSum.hpp
  requiredBy: []
  timestamp: '2025-07-19 03:24:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/number-theory/floor-sum/sum_of_floor_of_linear.test.cpp
documentation_of: src/number-theory/FloorSum.hpp
layout: document
redirect_from:
- /library/src/number-theory/FloorSum.hpp
- /library/src/number-theory/FloorSum.hpp.html
title: src/number-theory/FloorSum.hpp
---
