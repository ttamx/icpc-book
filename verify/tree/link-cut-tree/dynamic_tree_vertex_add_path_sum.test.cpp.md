---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/tree/link-cut-tree.hpp
    title: src/tree/link-cut-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
  bundledCode: "#line 1 \"verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/tree/link-cut-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Description: Link Cut Tree (1-indexed)\n */\n\
    \ntemplate<int N,class T>\nstruct LinkCutTree{\n    int ch[N][2],par[N],rev[N];\n\
    \    T val[N],sum[N],rsum[N],lz[N];\n    void toggle(int v){\n        if(!v)return;\n\
    \        swap(ch[v][0],ch[v][1]),swap(sum[v],rsum[v]),rev[v]^=1;\n    }\n    void\
    \ apply(int v,T x){\n        if(!v)return;\n        val[v]=val[v]+x,lz[v]=lz[v]+x;\n\
    \        sum[v]=sum[v]+x,rsum[v]=rsum[v]+x;\n    }\n    void push(int v){\n  \
    \      if(rev[v])toggle(ch[v][0]),toggle(ch[v][1]),rev[v]=0;\n        apply(ch[v][0],lz[v]),apply(ch[v][1],lz[v]),lz[v]=T();\n\
    \    }\n    void pull(int v){\n        sum[v]=sum[ch[v][0]]+val[v]+sum[ch[v][1]];\n\
    \        rsum[v]=rsum[ch[v][1]]+val[v]+rsum[ch[v][0]];\n    }\n    bool pos(int\
    \ v){return ch[par[v]][1]==v;}\n    bool is_root(int v){return ch[par[v]][pos(v)]!=v;}\n\
    \    void rotate(int v){\n        int u=par[v],g=par[u],x=pos(v);\n        if(!is_root(u))ch[g][pos(u)]=v;\n\
    \        if((ch[u][x]=ch[v][!x]))par[ch[u][x]]=u;\n        ch[v][!x]=u,par[u]=v,par[v]=g,pull(u),pull(v);\n\
    \    }\n    void splay(int v){\n        for(push(v);!is_root(v);rotate(v)){\n\
    \            int u=par[v],r=is_root(u);\n            if(!r)push(par[u]);\n   \
    \         push(u),push(v);\n            if(!r)rotate(pos(u)==pos(v)?u:v);\n  \
    \      }\n    }\n    void access(int v){\n        for(int u=v,c=0;u;c=u,u=par[u])\n\
    \            splay(u),ch[u][1]=c,pull(u);\n        splay(v);\n    }\n    void\
    \ reroot(int v){access(v),toggle(v);}\n    bool connected(int u,int v){\n    \
    \    reroot(u),access(v);return u==v||par[u];}\n    void link(int u,int v){\n\
    \        reroot(u),access(v);\n        assert(u!=v&&!par[u]);par[u]=v;}\n    void\
    \ cut(int u,int v){\n        reroot(u),access(v);\n        assert(ch[v][0]==u&&!ch[u][0]&&!ch[u][1]);\n\
    \        ch[v][0]=par[u]=0,pull(v);\n    }\n    T aggregate(int u,int v){\n  \
    \      reroot(u),access(v);return sum[v];}\n    void add(int u,int v,T x){reroot(u),access(v),apply(v,x);}\n\
    \    void set(int u,T v){reroot(u),val[u]=v,pull(u);}\n};\n#line 4 \"verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp\"\
    \n\nconst int N=2e5+5;\n\nint n,q;\nll a[N];\nLinkCutTree<N,ll> lct;\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    cin >> n >> q;\n    for(int\
    \ i=1;i<=n;i++){\n        cin >> a[i];\n        lct.set(i,a[i]);\n    }\n    for(int\
    \ i=0;i<n-1;i++){\n        int u,v;\n        cin >> u >> v;\n        u++,v++;\n\
    \        lct.link(u,v);\n    }\n    while(q--){\n        int op;\n        cin\
    \ >> op;\n        if(op==0){\n            int u,v,x,y;\n            cin >> u >>\
    \ v >> x >> y;\n            u++,v++,x++,y++;\n            lct.cut(u,v);\n    \
    \        lct.link(x,y);\n        }else if(op==1){\n            int u,x;\n    \
    \        cin >> u >> x;\n            u++;\n            lct.set(u,a[u]+=x);\n \
    \       }else{\n            int u,v;\n            cin >> u >> v;\n           \
    \ u++,v++;\n            cout << lct.aggregate(u,v) << \"\\n\";\n        }\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n#include \"src/contest/template.hpp\"\n#include \"src/tree/link-cut-tree.hpp\"\
    \n\nconst int N=2e5+5;\n\nint n,q;\nll a[N];\nLinkCutTree<N,ll> lct;\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    cin >> n >> q;\n    for(int\
    \ i=1;i<=n;i++){\n        cin >> a[i];\n        lct.set(i,a[i]);\n    }\n    for(int\
    \ i=0;i<n-1;i++){\n        int u,v;\n        cin >> u >> v;\n        u++,v++;\n\
    \        lct.link(u,v);\n    }\n    while(q--){\n        int op;\n        cin\
    \ >> op;\n        if(op==0){\n            int u,v,x,y;\n            cin >> u >>\
    \ v >> x >> y;\n            u++,v++,x++,y++;\n            lct.cut(u,v);\n    \
    \        lct.link(x,y);\n        }else if(op==1){\n            int u,x;\n    \
    \        cin >> u >> x;\n            u++;\n            lct.set(u,a[u]+=x);\n \
    \       }else{\n            int u,v;\n            cin >> u >> v;\n           \
    \ u++,v++;\n            cout << lct.aggregate(u,v) << \"\\n\";\n        }\n  \
    \  }\n}"
  dependsOn:
  - src/contest/template.hpp
  - src/tree/link-cut-tree.hpp
  isVerificationFile: true
  path: verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 16:18:54+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
- /verify/verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp.html
title: verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
---
