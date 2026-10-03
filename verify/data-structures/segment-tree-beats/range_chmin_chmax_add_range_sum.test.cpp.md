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
    \ __gnu_pbds;\n\n#define pb push_back\n#define eb emplace_back\n\n#define ALL(a)\
    \ a.begin(),a.end()\n#define RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n\
    #define RSORT(a) sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n#define UNI(a)\
    \ a.erase(unique(ALL(a)),a.end())\n#define SZ(a) (int)(a.size())\n#define LB(a,x)\
    \ (int)(lower_bound(ALL(a),x)-a.begin())\n#define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n\
    #define MIN(a) *min_element(ALL(a))\n#define MAX(a) *max_element(ALL(a))\n\nusing\
    \ ll = long long;\nusing db = long double;\nusing i128 = __int128_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\n\nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst int MOD=998244353;\nconst\
    \ int MOD2=1000000007;\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\ntemplate<class\
    \ T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\ntemplate<class T,class\
    \ U>\nbool chmin(T &a,U b){return b<a?a=b,1:0;}\ntemplate<class T,class U>\nbool\
    \ chmax(T &a,U b){return a<b?a=b,1:0;}\ntemplate<class T,class U>\nT SUM(const\
    \ U &a){return accumulate(ALL(a),T{});}\n\ntemplate<class T>\nusing ordered_set\
    \ = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/data-structures/segment-tree-beats.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2025-07-18\n * Description: Segment Tree\
    \ Beats. Supports range chmin, range\n * chmax, range add and range sum on 0-indexed\
    \ inclusive $[l,r]$.\n * Construct with SegmentTreeBeats(n,f) where f(i) gives\
    \ a[i].\n * Time: amortized $O(\\log^2 N)$ per operation (with range add).\n */\n\
    \nstruct SegmentTreeBeats{\n    struct Node{\n        ll sum=0,add=0,mn=LINF,mn2=LINF,fn=0;\n\
    \        ll mx=-LINF,mx2=-LINF,fx=0;\n        Node(){}\n        Node(ll v):sum(v),mn(v),fn(1),mx(v),fx(1){}\n\
    \        friend Node operator+(const Node &l,const Node &r){\n            Node\
    \ s;s.sum=l.sum+r.sum;\n            auto &a=l.mx<r.mx?r:l,&b=l.mx<r.mx?l:r;\n\
    \            s.mx=a.mx,s.fx=a.fx+(a.mx==b.mx?b.fx:0);\n            s.mx2=max(a.mx2,a.mx==b.mx?b.mx2:b.mx);\n\
    \            auto &c=r.mn<l.mn?r:l,&d=r.mn<l.mn?l:r;\n            s.mn=c.mn,s.fn=c.fn+(c.mn==d.mn?d.fn:0);\n\
    \            s.mn2=min(c.mn2,c.mn==d.mn?d.mn2:d.mn);\n            return s;\n\
    \        }\n        void apply(ll k,ll v){\n            sum+=k*v,mx+=v,mx2+=v,mn+=v,mn2+=v,add+=v;\n\
    \        }\n        void chmin(ll v){\n            if(v<mx)sum+=(v-mx)*fx,mn=mn==mx?v:mn,\n\
    \                mn2=mn2==mx?v:mn2,mx=v;\n        }\n        void chmax(ll v){\n\
    \            if(v>mn)sum+=(v-mn)*fn,mx=mx==mn?v:mx,\n                mx2=mx2==mn?v:mx2,mn=v;\n\
    \        }\n    };\n    int n;vector<Node> t;\n    SegmentTreeBeats(){}\n    SegmentTreeBeats(int\
    \ n){init(n,[&](int){return 0;});}\n    template<class F>\n    SegmentTreeBeats(int\
    \ n,const F &f){init(n,f);}\n    template<class F>\n    void init(int _n,const\
    \ F &f){\n        n=_n;int s=1;while(s<n*2)s<<=1;\n        t.assign(s,Node());build(f);\n\
    \    }\n    template<class F>\n    void build(int l,int r,int i,const F &f){\n\
    \        if(l==r)return void(t[i]=f(l));\n        int m=(l+r)/2;\n        build(l,m,i*2,f),build(m+1,r,i*2+1,f),pull(i);\n\
    \    }\n    void pull(int i){t[i]=t[i*2]+t[i*2+1];}\n    void push(int l,int r,int\
    \ i){\n        int m=(l+r)/2;Node &p=t[i],&a=t[i*2],&b=t[i*2+1];\n        a.apply(m-l+1,p.add),a.chmin(p.mx),a.chmax(p.mn);\n\
    \        b.apply(r-m,p.add),b.chmin(p.mx),b.chmax(p.mn);\n        p.add=0;\n \
    \   }\n    void range_add(int l,int r,int i,int x,int y,ll v){\n        if(y<l||r<x)return;\n\
    \        if(x<=l&&r<=y)return t[i].apply(r-l+1,v);\n        int m=(l+r)/2;push(l,r,i),range_add(l,m,i*2,x,y,v);\n\
    \        range_add(m+1,r,i*2+1,x,y,v),pull(i);\n    }\n    void range_chmin(int\
    \ l,int r,int i,int x,int y,ll v){\n        if(y<l||r<x||t[i].mx<=v)return;\n\
    \        if(x<=l&&r<=y&&t[i].mx2<v)return t[i].chmin(v);\n        int m=(l+r)/2;push(l,r,i),range_chmin(l,m,i*2,x,y,v);\n\
    \        range_chmin(m+1,r,i*2+1,x,y,v),pull(i);\n    }\n    void range_chmax(int\
    \ l,int r,int i,int x,int y,ll v){\n        if(y<l||r<x||t[i].mn>=v)return;\n\
    \        if(x<=l&&r<=y&&t[i].mn2>v)return t[i].chmax(v);\n        int m=(l+r)/2;push(l,r,i),range_chmax(l,m,i*2,x,y,v);\n\
    \        range_chmax(m+1,r,i*2+1,x,y,v),pull(i);\n    }\n    ll query(int l,int\
    \ r,int i,int x,int y){\n        if(y<l||r<x)return 0;\n        if(x<=l&&r<=y)return\
    \ t[i].sum;\n        int m=(l+r)/2;push(l,r,i);\n        return query(l,m,i*2,x,y)+query(m+1,r,i*2+1,x,y);\n\
    \    }\n    template<class F>\n    void build(const F &f){if(n)build(0,n-1,1,f);}\n\
    \    void range_add(int x,int y,ll v){range_add(0,n-1,1,x,y,v);}\n    void range_chmin(int\
    \ x,int y,ll v){\n        range_chmin(0,n-1,1,x,y,v);}\n    void range_chmax(int\
    \ x,int y,ll v){\n        range_chmax(0,n-1,1,x,y,v);}\n    ll query(int x,int\
    \ y){return query(0,n-1,1,x,y);}\n};\n#line 4 \"verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp\"\
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
  timestamp: '2026-10-04 01:45:10+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp
- /verify/verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp.html
title: verify/data-structures/segment-tree-beats/range_chmin_chmax_add_range_sum.test.cpp
---
