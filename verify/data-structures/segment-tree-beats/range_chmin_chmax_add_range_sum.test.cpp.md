---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structures/segment-tree-beats.hpp
    title: src/data-structures/segment-tree-beats.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#line 2 \"src/contest/template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n \nusing namespace std;\nusing namespace\
    \ __gnu_pbds;\n \nusing ll = long long;\nusing db = long double;\nusing vi = vector<int>;\n\
    using vl = vector<ll>;\nusing vd = vector<db>;\nusing pii = pair<int,int>;\nusing\
    \ pll = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst int INF=0x3fffffff;\nconst\
    \ ll LINF=0x1fffffffffffffff;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const db EPS=1e-9;\nconst db PI=acos(db(-1));\n \ntemplate<class T>\nusing ordered_set\
    \ = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \ \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/data-structures/segment-tree-beats.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2025-07-18\n * Description: Segment Tree\
    \ Beats\n */\n\nstruct SegmentTreeBeats{\n    struct Node{\n        ll sum,add;\n\
    \        ll mn,mn2,fn;\n        ll mx,mx2,fx;\n        Node(){\n            sum=add=fn=fx=0,mn=mn2=LINF,mx=mx2=-LINF;\n\
    \        }\n        Node(ll v){\n            sum=mn=mx=v,add=0,mn2=LINF,mx2=-LINF,fn=fx=1;\n\
    \        }\n        friend Node operator+(const Node &l,const Node &r){\n    \
    \        Node res;\n            res.sum=l.sum+r.sum;\n            res.add=0;\n\
    \            if(l.mx>r.mx){\n                res.mx=l.mx,res.fx=l.fx;\n      \
    \          res.mx2=max(l.mx2,r.mx);\n            }else if(r.mx>l.mx){\n      \
    \          res.mx=r.mx,res.fx=r.fx;\n                res.mx2=max(r.mx2,l.mx);\n\
    \            }else{\n                res.mx=l.mx,res.fx=l.fx+r.fx;\n         \
    \       res.mx2=max(l.mx2,r.mx2);\n            }\n            if(l.mn<r.mn){\n\
    \                res.mn=l.mn,res.fn=l.fn;\n                res.mn2=min(l.mn2,r.mn);\n\
    \            }else if(r.mn<l.mn){\n                res.mn=r.mn,res.fn=r.fn;\n\
    \                res.mn2=min(r.mn2,l.mn);\n            }else{\n              \
    \  res.mn=l.mn,res.fn=l.fn+r.fn;\n                res.mn2=min(l.mn2,r.mn2);\n\
    \            }\n            return res;\n        }\n        void apply(int l,int\
    \ r,ll v){\n            sum+=(r-l+1)*v;\n            mx+=v,mx2+=v;\n         \
    \   mn+=v,mn2+=v;\n            add+=v;\n        }\n        void chmin(ll v){\n\
    \            if(v>=mx)return;\n            sum+=(v-mx)*fx;\n            if(mn==mx)mn=v;\n\
    \            if(mn2==mx)mn2=v;\n            mx=v;\n        }\n        void chmax(ll\
    \ v){\n            if(v<=mn)return;\n            sum+=(v-mn)*fn;\n           \
    \ if(mx==mn)mx=v;\n            if(mx2==mn)mx2=v;\n            mn=v;\n        }\n\
    \    };\n    int n;\n    vector<Node> t;\n    SegmentTreeBeats(){}\n    SegmentTreeBeats(int\
    \ n){init(n,[&](int){return 0;});}\n    template<class F>\n    SegmentTreeBeats(int\
    \ n,const F &f){init(n,f);}\n    template<class F>\n    void init(int _n,const\
    \ F &f){\n        n=_n;\n        int s=1;\n        while(s<n*2)s<<=1;\n      \
    \  t.assign(s,Node());\n        build(f);\n    }\n    template<class F>\n    void\
    \ build(int l,int r,int i,const F &f){\n        if(l==r)return void(t[i]=f(l));\n\
    \        int m=(l+r)/2;\n        build(l,m,i*2,f);\n        build(m+1,r,i*2+1,f);\n\
    \        pull(i);\n    }\n    void pull(int i){\n        t[i]=t[i*2]+t[i*2+1];\n\
    \    }\n    void push(int l,int r,int i){\n        int m=(l+r)/2;\n        t[i*2].apply(l,m,t[i].add);\n\
    \        t[i*2+1].apply(m+1,r,t[i].add);\n        t[i*2].chmin(t[i].mx);\n   \
    \     t[i*2+1].chmin(t[i].mx);\n        t[i*2].chmax(t[i].mn);\n        t[i*2+1].chmax(t[i].mn);\n\
    \        t[i].add=0;\n    }\n    void range_add(int l,int r,int i,int x,int y,ll\
    \ v){\n        if(y<l||r<x)return;\n        if(x<=l&&r<=y)return t[i].apply(l,r,v);\n\
    \        int m=(l+r)/2;\n        push(l,r,i);\n        range_add(l,m,i*2,x,y,v);\n\
    \        range_add(m+1,r,i*2+1,x,y,v);\n        pull(i);\n    }\n    void range_chmin(int\
    \ l,int r,int i,int x,int y,ll v){\n        if(y<l||r<x||t[i].mx<=v)return;\n\
    \        if(x<=l&&r<=y&&t[i].mx2<v)return t[i].chmin(v);\n        int m=(l+r)/2;\n\
    \        push(l,r,i);\n        range_chmin(l,m,i*2,x,y,v);\n        range_chmin(m+1,r,i*2+1,x,y,v);\n\
    \        pull(i);\n    }\n    void range_chmax(int l,int r,int i,int x,int y,ll\
    \ v){\n        if(y<l||r<x||t[i].mn>=v)return;\n        if(x<=l&&r<=y&&t[i].mn2>v)return\
    \ t[i].chmax(v);\n        int m=(l+r)/2;\n        push(l,r,i);\n        range_chmax(l,m,i*2,x,y,v);\n\
    \        range_chmax(m+1,r,i*2+1,x,y,v);\n        pull(i);\n    }\n    ll query(int\
    \ l,int r,int i,int x,int y){\n        if(y<l||r<x)return 0;\n        if(x<=l&&r<=y)return\
    \ t[i].sum;\n        int m=(l+r)/2;\n        push(l,r,i);\n        return query(l,m,i*2,x,y)+query(m+1,r,i*2+1,x,y);\n\
    \    }\n    template<class F>\n    void build(const F &f){build(0,n-1,1,f);}\n\
    \    void range_add(int x,int y,ll v){range_add(0,n-1,1,x,y,v);}\n    void range_chmin(int\
    \ x,int y,ll v){range_chmin(0,n-1,1,x,y,v);}\n    void range_chmax(int x,int y,ll\
    \ v){range_chmax(0,n-1,1,x,y,v);}\n    ll query(int x,int y){return query(0,n-1,1,x,y);}\n\
    };\n#line 4 \"verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    vector<ll> a(n);\n    for(auto &x:a)cin >> x;\n    SegmentTreeBeats\
    \ seg(n,[&](int i){return a[i];});\n    while(q--){\n        int op,l,r;\n   \
    \     cin >> op >> l >> r;\n        r--;\n        if(op==3){\n            cout\
    \ << seg.query(l,r) << \"\\n\";\n        }else{\n            ll v;\n         \
    \   cin >> v;\n            if(op==0){\n                seg.range_chmin(l,r,v);\n\
    \            }else if(op==1){\n                seg.range_chmax(l,r,v);\n     \
    \       }else{\n                seg.range_add(l,r,v);\n            }\n       \
    \ }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include \"src/contest/template.hpp\"\n#include \"src/data-structures/segment-tree-beats.hpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n\
    \    cin >> n >> q;\n    vector<ll> a(n);\n    for(auto &x:a)cin >> x;\n    SegmentTreeBeats\
    \ seg(n,[&](int i){return a[i];});\n    while(q--){\n        int op,l,r;\n   \
    \     cin >> op >> l >> r;\n        r--;\n        if(op==3){\n            cout\
    \ << seg.query(l,r) << \"\\n\";\n        }else{\n            ll v;\n         \
    \   cin >> v;\n            if(op==0){\n                seg.range_chmin(l,r,v);\n\
    \            }else if(op==1){\n                seg.range_chmax(l,r,v);\n     \
    \       }else{\n                seg.range_add(l,r,v);\n            }\n       \
    \ }\n    }\n}"
  dependsOn:
  - src/contest/template.hpp
  - src/data-structures/segment-tree-beats.hpp
  isVerificationFile: true
  path: verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-07-19 14:29:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp
- /verify/verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp.html
title: verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp
---
