---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/miscellaneous/integrate.hpp
    title: src/miscellaneous/integrate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/miscellaneous/integral.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"src/contest/template.hpp\"\
    \n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n#include<ext/pb_ds/tree_policy.hpp>\n\
    \ \nusing namespace std;\nusing namespace __gnu_pbds;\n \nusing ll = long long;\n\
    using db = long double;\nusing vi = vector<int>;\nusing vl = vector<ll>;\nusing\
    \ vd = vector<db>;\nusing pii = pair<int,int>;\nusing pll = pair<ll,ll>;\nusing\
    \ pdd = pair<db,db>;\nconst int INF=0x3fffffff;\nconst ll LINF=0x1fffffffffffffff;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\
    \ \ntemplate<class T>\nusing ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \ \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/miscellaneous/integrate.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2025-07-19\n * Description: find definite\
    \ integral with Simpson's method, error proportional to dx^4.\n */\n\ntemplate<class\
    \ F>\ndb quad(db a,db b,const F &f,int n){\n    db res=0;\n    db dx=(b-a)/n;\n\
    \    db fl=0,fr=f(a);\n    for(int i=0;i<n;i++){\n        db l=a+dx*i,r=l+dx;\n\
    \        fl=fr;\n        fr=f(r);\n        db fm=f((l+r)/2);\n        res+=fl+4*fm+fr;\n\
    \    }\n    return res*dx/6;\n}\n#line 4 \"verify/miscellaneous/integral.test.cpp\"\
    \n\nint main(){\n    for(int r=1;r<=20;r++){\n        double out=quad(-r,r,[&](db\
    \ x){\n            return quad(-r,r,[&](db y){\n                return quad(-r,r,[&](db\
    \ z){\n                    return x*x+y*y+z*z<r*r;\n                },100);\n\
    \            },100);\n        },100);\n        double ans=4*PI*r*r*r/3;\n    \
    \    auto err=abs(out-ans)/max(ans,1.0);\n        assert(err<1e-4);\n    }\n \
    \   int a,b;\n    cin >> a >> b;\n    cout << a+b << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"src/contest/template.hpp\"\
    \n#include \"src/miscellaneous/integrate.hpp\"\n\nint main(){\n    for(int r=1;r<=20;r++){\n\
    \        double out=quad(-r,r,[&](db x){\n            return quad(-r,r,[&](db\
    \ y){\n                return quad(-r,r,[&](db z){\n                    return\
    \ x*x+y*y+z*z<r*r;\n                },100);\n            },100);\n        },100);\n\
    \        double ans=4*PI*r*r*r/3;\n        auto err=abs(out-ans)/max(ans,1.0);\n\
    \        assert(err<1e-4);\n    }\n    int a,b;\n    cin >> a >> b;\n    cout\
    \ << a+b << \"\\n\";\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/miscellaneous/integrate.hpp
  isVerificationFile: true
  path: verify/miscellaneous/integral.test.cpp
  requiredBy: []
  timestamp: '2025-07-19 19:17:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/miscellaneous/integral.test.cpp
layout: document
redirect_from:
- /verify/verify/miscellaneous/integral.test.cpp
- /verify/verify/miscellaneous/integral.test.cpp.html
title: verify/miscellaneous/integral.test.cpp
---
