---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structures/line-container/line_add_get_min.test.cpp
    title: verify/data-structures/line-container/line_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structures/line-container.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Description: Line Container (Minimize).\n * Time: O(\\log N)\n\
    \ */\n\nstruct Line{\n\tstatic bool querymode;\n    ll m,c;\n    mutable ll p;\n\
    \    Line(ll m,ll c):m(m),c(c),p(0){}\n    Line(ll p):m(0),c(0),p(p){}\n    bool\
    \ operator<(const Line &o)const{\n        return querymode?p<o.p:m>o.m;\n    }\n\
    };\n\nbool Line::querymode=false;\n\nstruct LineContainer:multiset<Line>{\n  \
    \  ll div(ll a,ll b){\n        return a/b-((a^b)<0&&a%b);\n    }\n    bool isect(iterator\
    \ x,iterator y){\n        if(y==end())return x->p=LINF,false;\n        if(x->m==y->m)x->p=x->c<=y->c?LINF:-LINF;\n\
    \        else x->p=div(x->c-y->c,y->m-x->m);\n        return x->p>=y->p;\n   \
    \ }\n    void add(ll m,ll c){\n        auto x=insert(Line(m,c)),y=next(x);\n \
    \       while(isect(x,y))y=erase(y);\n        if((y=x)!=begin()&&isect(--x,y))isect(x,erase(y));\n\
    \        while((y=x)!=begin()&&(--x)->p>=y->p)isect(x,erase(y));\n    }\n    ll\
    \ get(ll x){\n        if(empty())return LINF;\n        Line::querymode=true;\n\
    \        auto l=lower_bound(Line(x));\n        Line::querymode=false;\n      \
    \  return l->m*x+l->c;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Line Container\
    \ (Minimize).\n * Time: O(\\log N)\n */\n\nstruct Line{\n\tstatic bool querymode;\n\
    \    ll m,c;\n    mutable ll p;\n    Line(ll m,ll c):m(m),c(c),p(0){}\n    Line(ll\
    \ p):m(0),c(0),p(p){}\n    bool operator<(const Line &o)const{\n        return\
    \ querymode?p<o.p:m>o.m;\n    }\n};\n\nbool Line::querymode=false;\n\nstruct LineContainer:multiset<Line>{\n\
    \    ll div(ll a,ll b){\n        return a/b-((a^b)<0&&a%b);\n    }\n    bool isect(iterator\
    \ x,iterator y){\n        if(y==end())return x->p=LINF,false;\n        if(x->m==y->m)x->p=x->c<=y->c?LINF:-LINF;\n\
    \        else x->p=div(x->c-y->c,y->m-x->m);\n        return x->p>=y->p;\n   \
    \ }\n    void add(ll m,ll c){\n        auto x=insert(Line(m,c)),y=next(x);\n \
    \       while(isect(x,y))y=erase(y);\n        if((y=x)!=begin()&&isect(--x,y))isect(x,erase(y));\n\
    \        while((y=x)!=begin()&&(--x)->p>=y->p)isect(x,erase(y));\n    }\n    ll\
    \ get(ll x){\n        if(empty())return LINF;\n        Line::querymode=true;\n\
    \        auto l=lower_bound(Line(x));\n        Line::querymode=false;\n      \
    \  return l->m*x+l->c;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structures/line-container.hpp
  requiredBy: []
  timestamp: '2025-07-19 14:29:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structures/line-container/line_add_get_min.test.cpp
documentation_of: src/data-structures/line-container.hpp
layout: document
redirect_from:
- /library/src/data-structures/line-container.hpp
- /library/src/data-structures/line-container.hpp.html
title: src/data-structures/line-container.hpp
---
