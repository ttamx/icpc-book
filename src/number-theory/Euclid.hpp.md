---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/number-theory/CRT.hpp
    title: src/number-theory/CRT.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 3 \"src/number-theory/Euclid.hpp\"\
    \n\n/**\n * Author: Unknown\n * Date: 2002-09-15\n * Source: predates tinyKACTL\n\
    \ * Description: Finds two integers $x$ and $y$,such that $ax+by=\\gcd(a,b)$.\
    \ If\n * you just need gcd, use the built in \\texttt{\\_\\_gcd} instead.\n *\
    \ If $a$ and $b$ are coprime, then $x$ is the inverse of $a \\pmod{b}$.\n * $x\
    \ = x_0 + k * (b / g)$\n * $y = y_0 - k * (a / g)$\n */\n\nll euclid(ll a,ll b,ll\
    \ &x,ll &y){\n\tif(!b)return x=1,y=0,a;\n\tll d=euclid(b,a%b,y,x);\n\treturn y-=a/b*x,d;\n\
    }\n"
  code: "#pragma once\n#include \"src/contest/template.hpp\"\n\n/**\n * Author: Unknown\n\
    \ * Date: 2002-09-15\n * Source: predates tinyKACTL\n * Description: Finds two\
    \ integers $x$ and $y$,such that $ax+by=\\gcd(a,b)$. If\n * you just need gcd,\
    \ use the built in \\texttt{\\_\\_gcd} instead.\n * If $a$ and $b$ are coprime,\
    \ then $x$ is the inverse of $a \\pmod{b}$.\n * $x = x_0 + k * (b / g)$\n * $y\
    \ = y_0 - k * (a / g)$\n */\n\nll euclid(ll a,ll b,ll &x,ll &y){\n\tif(!b)return\
    \ x=1,y=0,a;\n\tll d=euclid(b,a%b,y,x);\n\treturn y-=a/b*x,d;\n}"
  dependsOn:
  - src/contest/template.hpp
  isVerificationFile: false
  path: src/number-theory/Euclid.hpp
  requiredBy:
  - src/number-theory/CRT.hpp
  timestamp: '2025-07-19 03:24:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/number-theory/Euclid.hpp
layout: document
redirect_from:
- /library/src/number-theory/Euclid.hpp
- /library/src/number-theory/Euclid.hpp.html
title: src/number-theory/Euclid.hpp
---
