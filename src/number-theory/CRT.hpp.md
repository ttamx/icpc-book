---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':warning:'
    path: src/number-theory/Euclid.hpp
    title: src/number-theory/Euclid.hpp
  _extendedRequiredBy: []
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
    }\n#line 4 \"src/number-theory/CRT.hpp\"\n\n/**\n * Author: Simon Lindholm\n *\
    \ Date: 2019-05-22\n * License: CC0\n * Description: Chinese Remainder Theorem.\n\
    \ *\n * \\texttt{crt(a, m, b, n)} computes $x$ such that $x\\equiv a \\pmod m$,\
    \ $x\\equiv b \\pmod n$.\n * If $|a| < m$ and $|b| < n$, $x$ will obey $0 \\le\
    \ x < \\text{lcm}(m, n)$.\n * Assumes $mn < 2^{62}$.\n * If x0 and y0 is one of\
    \ the solutions of ax + by = g, then the general solution is\n * x = x0 + k *\
    \ (b / g) and y = y0 - k * (a / g).\n * Time: $\\log(n)$\n * Status: Works\n */\n\
    \nll crt(ll a,ll m,ll b,ll n){\n\tif(n>m)swap(a,b),swap(m,n);\n\tll x,y,g=euclid(m,n,x,y);\n\
    \tif((a-b)%g!=0)return -1LL; // no solution\n\tx=(b-a)%n*x%n/g*m+a;\n\treturn\
    \ x<0?x+m*n/g:x;\n}\n"
  code: "#pragma once\n#include \"src/contest/template.hpp\"\n#include \"src/number-theory/Euclid.hpp\"\
    \ \n\n/**\n * Author: Simon Lindholm\n * Date: 2019-05-22\n * License: CC0\n *\
    \ Description: Chinese Remainder Theorem.\n *\n * \\texttt{crt(a, m, b, n)} computes\
    \ $x$ such that $x\\equiv a \\pmod m$, $x\\equiv b \\pmod n$.\n * If $|a| < m$\
    \ and $|b| < n$, $x$ will obey $0 \\le x < \\text{lcm}(m, n)$.\n * Assumes $mn\
    \ < 2^{62}$.\n * If x0 and y0 is one of the solutions of ax + by = g, then the\
    \ general solution is\n * x = x0 + k * (b / g) and y = y0 - k * (a / g).\n * Time:\
    \ $\\log(n)$\n * Status: Works\n */\n\nll crt(ll a,ll m,ll b,ll n){\n\tif(n>m)swap(a,b),swap(m,n);\n\
    \tll x,y,g=euclid(m,n,x,y);\n\tif((a-b)%g!=0)return -1LL; // no solution\n\tx=(b-a)%n*x%n/g*m+a;\n\
    \treturn x<0?x+m*n/g:x;\n}"
  dependsOn:
  - src/contest/template.hpp
  - src/number-theory/Euclid.hpp
  isVerificationFile: false
  path: src/number-theory/CRT.hpp
  requiredBy: []
  timestamp: '2025-07-19 03:24:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/number-theory/CRT.hpp
layout: document
redirect_from:
- /library/src/number-theory/CRT.hpp
- /library/src/number-theory/CRT.hpp.html
title: src/number-theory/CRT.hpp
---
