---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structures/LineContainer.hpp
    title: src/data-structures/LineContainer.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"verify/data-structures/line-container/line_add_get_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#line\
    \ 2 \"src/contest/template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n \nusing namespace std;\nusing namespace\
    \ __gnu_pbds;\n \nusing ll = long long;\nusing db = long double;\nusing vi = vector<int>;\n\
    using vl = vector<ll>;\nusing vd = vector<db>;\nusing pii = pair<int,int>;\nusing\
    \ pll = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst int INF=0x3fffffff;\nconst\
    \ ll LINF=0x1fffffffffffffff;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const db EPS=1e-9;\nconst db PI=acos(db(-1));\n \ntemplate<class T>\nusing ordered_set\
    \ = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \ \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 3 \"src/data-structures/LineContainer.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Description: Line Container (Minimize).\n *\
    \ Time: O(\\log N)\n */\n\nstruct Line{\n\tstatic bool querymode;\n    ll m,c;\n\
    \    mutable ll p;\n    Line(ll m,ll c):m(m),c(c),p(0){}\n    Line(ll p):m(0),c(0),p(p){}\n\
    \    bool operator<(const Line &o)const{\n        return querymode?p<o.p:m>o.m;\n\
    \    }\n};\n\nbool Line::querymode=false;\n\nstruct LineContainer:multiset<Line>{\n\
    \    ll div(ll a,ll b){\n        return a/b-((a^b)<0&&a%b);\n    }\n    bool isect(iterator\
    \ x,iterator y){\n        if(y==end())return x->p=LINF,false;\n        if(x->m==y->m)x->p=x->c<=y->c?LINF:-LINF;\n\
    \        else x->p=div(x->c-y->c,y->m-x->m);\n        return x->p>=y->p;\n   \
    \ }\n    void add(ll m,ll c){\n        auto x=insert(Line(m,c)),y=next(x);\n \
    \       while(isect(x,y))y=erase(y);\n        if((y=x)!=begin()&&isect(--x,y))isect(x,erase(y));\n\
    \        while((y=x)!=begin()&&(--x)->p>=y->p)isect(x,erase(y));\n    }\n    ll\
    \ get(ll x){\n        if(empty())return LINF;\n        Line::querymode=true;\n\
    \        auto l=lower_bound(Line(x));\n        Line::querymode=false;\n      \
    \  return l->m*x+l->c;\n    }\n};\n#line 4 \"verify/data-structures/line-container/line_add_get_min.test.cpp\"\
    \n\nint n,q;\nLineContainer cht;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    cin >> n >> q;\n    for(int i=0;i<n;i++){\n        ll a,b;\n        cin >>\
    \ a >> b;\n        cht.add(a,b);\n    }\n    while(q--){\n        int op;\n  \
    \      cin >> op;\n        if(op==0){\n            ll a,b;\n            cin >>\
    \ a >> b;\n            cht.add(a,b);\n        }else{\n            ll p;\n    \
    \        cin >> p;\n            cout << cht.get(p) << \"\\n\";\n        }\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ \"src/contest/template.hpp\"\n#include \"src/data-structures/LineContainer.hpp\"\
    \n\nint n,q;\nLineContainer cht;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    cin >> n >> q;\n    for(int i=0;i<n;i++){\n        ll a,b;\n        cin >>\
    \ a >> b;\n        cht.add(a,b);\n    }\n    while(q--){\n        int op;\n  \
    \      cin >> op;\n        if(op==0){\n            ll a,b;\n            cin >>\
    \ a >> b;\n            cht.add(a,b);\n        }else{\n            ll p;\n    \
    \        cin >> p;\n            cout << cht.get(p) << \"\\n\";\n        }\n  \
    \  }\n}"
  dependsOn:
  - src/contest/template.hpp
  - src/data-structures/LineContainer.hpp
  isVerificationFile: true
  path: verify/data-structures/line-container/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2025-07-17 17:33:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structures/line-container/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structures/line-container/line_add_get_min.test.cpp
- /verify/verify/data-structures/line-container/line_add_get_min.test.cpp.html
title: verify/data-structures/line-container/line_add_get_min.test.cpp
---
