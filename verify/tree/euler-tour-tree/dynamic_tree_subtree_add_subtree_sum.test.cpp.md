---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structures/treap.hpp
    title: src/data-structures/treap.hpp
  - icon: ':heavy_check_mark:'
    path: src/tree/euler-tour-tree.hpp
    title: src/tree/euler-tour-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum
  bundledCode: "#line 1 \"verify/tree/euler-tour-tree/dynamic_tree_subtree_add_subtree_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum\"\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/data-structures/treap.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Description: Treap (1-indexed, 0 = null) with\
    \ lazy reverse and\n * lazy add (T needs +, T*int, ==). Weight-0 nodes take a\
    \ position but\n * no value. root/pos use parent pointers (not with P or pending\
    \ rev).\n * N about $2\\ln n$ per op if P.\n */\n\ntemplate<int N,class T,bool\
    \ P=false>\nstruct Treap{\n    struct Node{int l,r,p,sz,w,c;bool rev;T val,sum,lz;}\
    \ t[N];\n    int cnt=0;\n    int make(T v,int w=1){\n        t[++cnt]={0,0,0,1,w,w,0,v,w?v:T(),T()};return\
    \ cnt;}\n    int cp(int u){ // clone before writing (persistent only)\n      \
    \  if(!P||!u)return u;\n        t[++cnt]=t[u];\n        return cnt;\n    }\n \
    \   void pull(int u){\n        auto &[l,r,p,sz,w,c,rev,val,sum,lz]=t[u];\n   \
    \     sz=t[l].sz+1+t[r].sz,c=t[l].c+w+t[r].c;\n        sum=t[l].sum+t[r].sum;\n\
    \        if(w)sum=sum+val;\n        t[l].p=t[r].p=u;\n    }\n    void flip(int\
    \ &u){\n        if(!u)return;\n        u=cp(u),swap(t[u].l,t[u].r),t[u].rev^=1;\n\
    \    }\n    void apply(int &u,T x){ // add x to every value in u\n        if(!u)return;\n\
    \        u=cp(u);\n        auto &a=t[u];\n        a.val=a.val+x,a.sum=a.sum+x*a.c,a.lz=a.lz+x;\n\
    \    }\n    void push(int u){\n        if(t[u].rev)flip(t[u].l),flip(t[u].r),t[u].rev=0;\n\
    \        T &x=t[u].lz;\n        if(!(x==T()))apply(t[u].l,x),apply(t[u].r,x),x=T();\n\
    \    }\n    pair<int,int> split(int u,int k){ // first k elements, rest\n    \
    \    if(!u)return {0,0};\n        u=cp(u),push(u);\n        if(t[t[u].l].sz>=k){\n\
    \            auto [a,b]=split(t[u].l,k);\n            t[u].l=b,pull(u),t[u].p=0;\n\
    \            return {a,u};\n        }\n        auto [a,b]=split(t[u].r,k-t[t[u].l].sz-1);\n\
    \        t[u].r=a,pull(u),t[u].p=0;\n        return {u,b};\n    }\n    int merge(int\
    \ a,int b){\n        if(!a||!b)return t[a^b].p=0,a^b;\n        if(int(rng()%(t[a].sz+t[b].sz))<t[a].sz){\n\
    \            a=cp(a),push(a);\n            t[a].r=merge(t[a].r,b),pull(a),t[a].p=0;\n\
    \            return a;\n        }\n        b=cp(b),push(b);\n        t[b].l=merge(a,t[b].l),pull(b),t[b].p=0;\n\
    \        return b;\n    }\n    int root(int u){while(t[u].p)u=t[u].p;return u;}\n\
    \    int pos(int u){ // index of node u in its sequence\n        int k=t[t[u].l].sz;\n\
    \        for(;t[u].p;u=t[u].p)\n            if(t[t[u].p].r==u)k+=t[t[t[u].p].l].sz+1;\n\
    \        return k;\n    } // (0-indexed)\n};\n#line 3 \"src/tree/euler-tour-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Description: Euler tour tree: a dynamic forest\
    \ on vertices $1..n$\n * with subtree add / subtree sum. Each tree is its Euler\
    \ tour (vertex\n * nodes + a weight-0 node per directed edge) in a Treap. The\
    \ subtree\n * of $v$ whose parent is $p$ (adjacent) lies between the edge nodes\n\
    \ * $(p,v)$ and $(v,p)$. N > 3n (cut edge nodes are recycled).\n * Usage: EulerTourTree<N,ll>\
    \ ett; ett.init(n); ett.set(v,x);\n *  ett.link(u,v); ett.cut(u,v); ett.add(v,p,x);\
    \ ett.query(v,p);\n * Time: $O(\\log n)$ expected per operation\n */\n\ntemplate<int\
    \ N,class T>\nstruct EulerTourTree:Treap<N,T>{\n    using B = Treap<N,T>;using\
    \ B::t,B::make,B::split;\n    using B::merge,B::root,B::pos,B::apply;\n    map<pair<int,int>,int>\
    \ E; // directed edge -> node\n    vector<int> fr; // freed edge nodes\n    void\
    \ init(int n){for(int i=1;i<=n;i++)make(T());}\n    int edge(){ // recycled or\
    \ new weight-0 node\n        if(fr.empty())return make(T(),0);\n        int x=fr.back();fr.pop_back();\n\
    \        return t[x]={0,0,0,1},x;\n    }\n    void reroot(int v){\n        auto\
    \ [a,b]=split(root(v),pos(v));\n        merge(b,a);\n    }\n    void link(int\
    \ u,int v){\n        reroot(u),reroot(v);\n        assert(root(u)!=root(v));\n\
    \        int e=E[{u,v}]=edge(),f=E[{v,u}]=edge();\n        merge(merge(merge(root(u),e),root(v)),f);\n\
    \    }\n    void cut(int u,int v){ // sides: y, and x+z minus edges\n        auto\
    \ [x,y,z,in]=range(v,u);\n        fr.pb(E[{u,v}]),fr.pb(E[{v,u}]);\n        E.erase({u,v}),E.erase({v,u});\n\
    \        merge(split(x,t[x].sz-1).first,split(z,1).second);\n    }\n    // tour\
    \ = X|Y|Z cut at edge nodes (p,v),(v,p); subtree of v\n    // (parent p) is Y\
    \ if (p,v) is first, else X and Z (cyclic)\n    array<int,4> range(int v,int p){\n\
    \        int a=pos(E[{p,v}]),b=pos(E[{v,p}]);\n        auto [x,z]=split(root(v),max(a,b));\n\
    \        auto [x1,y]=split(x,min(a,b)+1);\n        return {x1,y,z,a<b};\n    }\n\
    \    void add(int v,int p,T w){\n        auto [x,y,z,in]=range(v,p);\n       \
    \ if(in)apply(y,w);\n        else apply(x,w),apply(z,w);\n        merge(merge(x,y),z);\n\
    \    }\n    T query(int v,int p){\n        auto [x,y,z,in]=range(v,p);\n     \
    \   T s=in?t[y].sum:t[x].sum+t[z].sum;\n        merge(merge(x,y),z);\n       \
    \ return s;\n    }\n    void set(int v,T x){ // point set\n        auto [a,b]=split(root(v),pos(v));\n\
    \        auto [c,d]=split(b,1); // c == v\n        t[c].val=t[c].sum=x;\n    \
    \    merge(a,merge(c,d));\n    }\n};\n#line 4 \"verify/tree/euler-tour-tree/dynamic_tree_subtree_add_subtree_sum.test.cpp\"\
    \n\nconst int N=2e5+5;\nEulerTourTree<3*N,ll> ett;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,q;\n    cin >> n >> q;\n    ett.init(n);\n    for(int i=1;i<=n;i++){\n\
    \        ll a;\n        cin >> a;\n        ett.set(i,a);\n    }\n    for(int i=0;i<n-1;i++){\n\
    \        int u,v;\n        cin >> u >> v;\n        ett.link(u+1,v+1);\n    }\n\
    \    while(q--){\n        int t;\n        cin >> t;\n        if(t==0){\n     \
    \       int u,v,w,x;\n            cin >> u >> v >> w >> x;\n            ett.cut(u+1,v+1),ett.link(w+1,x+1);\n\
    \        }else if(t==1){\n            int v,p;\n            ll x;\n          \
    \  cin >> v >> p >> x;\n            ett.add(v+1,p+1,x);\n        }else{\n    \
    \        int v,p;\n            cin >> v >> p;\n            cout << ett.query(v+1,p+1)\
    \ << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum\"\
    \n#include \"src/contest/template.hpp\"\n#include \"src/tree/euler-tour-tree.hpp\"\
    \n\nconst int N=2e5+5;\nEulerTourTree<3*N,ll> ett;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,q;\n    cin >> n >> q;\n    ett.init(n);\n    for(int i=1;i<=n;i++){\n\
    \        ll a;\n        cin >> a;\n        ett.set(i,a);\n    }\n    for(int i=0;i<n-1;i++){\n\
    \        int u,v;\n        cin >> u >> v;\n        ett.link(u+1,v+1);\n    }\n\
    \    while(q--){\n        int t;\n        cin >> t;\n        if(t==0){\n     \
    \       int u,v,w,x;\n            cin >> u >> v >> w >> x;\n            ett.cut(u+1,v+1),ett.link(w+1,x+1);\n\
    \        }else if(t==1){\n            int v,p;\n            ll x;\n          \
    \  cin >> v >> p >> x;\n            ett.add(v+1,p+1,x);\n        }else{\n    \
    \        int v,p;\n            cin >> v >> p;\n            cout << ett.query(v+1,p+1)\
    \ << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/tree/euler-tour-tree.hpp
  - src/data-structures/treap.hpp
  isVerificationFile: true
  path: verify/tree/euler-tour-tree/dynamic_tree_subtree_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 18:23:08+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/tree/euler-tour-tree/dynamic_tree_subtree_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/tree/euler-tour-tree/dynamic_tree_subtree_add_subtree_sum.test.cpp
- /verify/verify/tree/euler-tour-tree/dynamic_tree_subtree_add_subtree_sum.test.cpp.html
title: verify/tree/euler-tour-tree/dynamic_tree_subtree_add_subtree_sum.test.cpp
---
