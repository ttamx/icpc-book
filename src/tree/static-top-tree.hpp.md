---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/tree/static-top-tree/point_set_tree_path_composite_sum.test.cpp
    title: verify/tree/static-top-tree/point_set_tree_path_composite_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/tree/static-top-tree/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: verify/tree/static-top-tree/point_set_tree_path_composite_sum_fixed_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/contest/template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 3 \"src/tree/static-top-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-11-14\n * Description: Static top\
    \ tree of a tree with vertices $1..n$ (adj has size $n+1$, root $1$).\n * Node\
    \ pool is 1-indexed, 0 = null, at most $2n-1$ nodes; vertex $v$ is its own Vertex/AddVertex\
    \ node.\n * Balanced by subtree size, height $O(\\log n)$.\n * StaticTopTreeRerootingDP\
    \ takes a DP struct D (interface in the code).\n * After changing the data of\
    \ $v$, call update($v$).\n * Time: build $O(n \\log n)$, update / query\\_subtree\
    \ / query\\_reroot $O(\\log n)$, query\\_all $O(1)$\n */\n\nstruct StaticTopTree{\n\
    \    using P = pair<int,int>;\n    using G = vector<vector<int>>;\n    enum Type{Compress,Rake,AddVertex,Vertex};\n\
    \    int n,cnt,root;\n    G &adj;\n    vector<int> hv,fa,l,r,par,t;\n    StaticTopTree(G\
    \ &g):adj(g){ // 1-indexed\n        n=cnt=SZ(g)-1;\n        hv=fa=l=r=par=t=vector<int>(2*n+1);\n\
    \        vector<int> o{1},s(n+1,1);s[0]=0; // BFS order, sizes\n        for(int\
    \ i=0;i<SZ(o);i++){\n            int u=o[i];\n            for(int v:adj[u])if(v!=fa[u])fa[v]=u,o.pb(v);\n\
    \        }\n        for(int i=n-1;i>0;i--){\n            int u=o[i],p=fa[u];s[p]+=s[u];\n\
    \            if(s[u]>s[hv[p]])hv[p]=u;\n        }\n        root=compress(1).first;\n\
    \    }\n    int add(int i,int a,int b,Type ty){\n        if(!i)i=++cnt;\n    \
    \    l[i]=a,r[i]=b,t[i]=ty,par[a]=par[b]=i;\n        return i;\n    }\n    P merge(const\
    \ vector<P> &a,int x,int y,Type ty){\n        if(y-x==1)return a[x];\n       \
    \ int tot=0,m=x;\n        for(int k=x;k<y;k++)tot+=a[k].second;\n        while(tot>a[m].second)tot-=2*a[m++].second;\n\
    \        auto [i,si]=merge(a,x,m,ty);\n        auto [j,sj]=merge(a,m,y,ty);\n\
    \        return {add(0,i,j,ty),si+sj};\n    }\n    P compress(int i){\n      \
    \  vector<P> a{add_vertex(i)};\n        while(hv[i])a.eb(add_vertex(i=hv[i]));\n\
    \        return merge(a,0,SZ(a),Compress);\n    }\n    P rake(int i){\n      \
    \  vector<P> a;\n        for(int j:adj[i])\n            if(j!=fa[i]&&j!=hv[i])a.eb(compress(j));\n\
    \        return a.empty()?P(0,0):merge(a,0,SZ(a),Rake);\n    }\n    P add_vertex(int\
    \ i){\n        auto [j,s]=rake(i);\n        return {add(i,j,0,j?AddVertex:Vertex),s+1};\n\
    \    }\n};\n/* struct D{\n    struct Path{static Path unit();};\n    struct Point{static\
    \ Point unit();};\n    static Path vertex(int v),add_vertex(Point p,int v),\n\
    \        compress(Path up,Path down);\n    static Point add_edge(Path p),rake(Point\
    \ a,Point b);\n}; */\ntemplate<class D>\nstruct StaticTopTreeRerootingDP:StaticTopTree{\n\
    \    using Path = typename D::Path;\n    using Point = typename D::Point;\n  \
    \  vector<Path> path,rvpath;\n    vector<Point> point;\n    StaticTopTreeRerootingDP(G\
    \ &g):StaticTopTree(g){\n        path=rvpath=vector<Path>(cnt+1),point.resize(cnt+1);\n\
    \        calc(root);\n    }\n    void pull(int u){\n        int lc=l[u],rc=r[u];\n\
    \        if(t[u]==Vertex)path[u]=rvpath[u]=D::vertex(u);\n        else if(t[u]==Compress){\n\
    \            path[u]=D::compress(path[lc],path[rc]);\n            rvpath[u]=D::compress(rvpath[rc],rvpath[lc]);\n\
    \        }\n        else if(t[u]==Rake)point[u]=D::rake(pt(lc),pt(rc));\n    \
    \    else path[u]=rvpath[u]=D::add_vertex(pt(lc),u);\n    }\n    Point pt(int\
    \ c){\n        return t[c]==Rake?point[c]:D::add_edge(path[c]);}\n    void calc(int\
    \ u){if(u)calc(l[u]),calc(r[u]),pull(u);}\n    void update(int u){for(;u;u=par[u])pull(u);}\n\
    \    Path query_all(){return path[root];}\n    Path query_subtree(int u){\n  \
    \      Path res=path[u];\n        for(int p;(p=par[u])&&t[p]==Compress;u=p)\n\
    \            if(l[p]==u)res=D::compress(res,path[r[p]]);\n        return res;\n\
    \    }\n    pair<Path,Path> around(int u){ // {below u, rest of tree}\n      \
    \  Path dn=Path::unit(),up=dn;\n        int p=par[u];\n        for(;p&&t[p]==Compress;p=par[u=p])\n\
    \            if(l[p]==u)dn=D::compress(dn,path[r[p]]);\n            else up=D::compress(up,rvpath[l[p]]);\n\
    \        if(p){\n            Point s=Point::unit();\n            for(;t[p]==Rake;p=par[u=p])\n\
    \                s=D::rake(s,pt(l[p]^r[p]^u));\n            s=D::rake(s,out(p));\n\
    \            up=D::compress(up,D::add_vertex(s,p));\n        }\n        return\
    \ {dn,up};\n    }\n    Point out(int u){\n        auto [dn,up]=around(u);\n  \
    \      return D::rake(D::add_edge(dn),D::add_edge(up));\n    }\n    Path query_reroot(int\
    \ u){\n        Point s=out(u);\n        if(t[u]==AddVertex)s=D::rake(s,pt(l[u]));\n\
    \        return D::add_vertex(s,u);\n    }\n    Path query_side(int v,int w){//\
    \ remove (v,w) then query(v)\n        return fa[v]==w?query_subtree(v):around(w).second;\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"src/contest/template.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-11-14\n * Description: Static top tree of a tree with vertices\
    \ $1..n$ (adj has size $n+1$, root $1$).\n * Node pool is 1-indexed, 0 = null,\
    \ at most $2n-1$ nodes; vertex $v$ is its own Vertex/AddVertex node.\n * Balanced\
    \ by subtree size, height $O(\\log n)$.\n * StaticTopTreeRerootingDP takes a DP\
    \ struct D (interface in the code).\n * After changing the data of $v$, call update($v$).\n\
    \ * Time: build $O(n \\log n)$, update / query\\_subtree / query\\_reroot $O(\\\
    log n)$, query\\_all $O(1)$\n */\n\nstruct StaticTopTree{\n    using P = pair<int,int>;\n\
    \    using G = vector<vector<int>>;\n    enum Type{Compress,Rake,AddVertex,Vertex};\n\
    \    int n,cnt,root;\n    G &adj;\n    vector<int> hv,fa,l,r,par,t;\n    StaticTopTree(G\
    \ &g):adj(g){ // 1-indexed\n        n=cnt=SZ(g)-1;\n        hv=fa=l=r=par=t=vector<int>(2*n+1);\n\
    \        vector<int> o{1},s(n+1,1);s[0]=0; // BFS order, sizes\n        for(int\
    \ i=0;i<SZ(o);i++){\n            int u=o[i];\n            for(int v:adj[u])if(v!=fa[u])fa[v]=u,o.pb(v);\n\
    \        }\n        for(int i=n-1;i>0;i--){\n            int u=o[i],p=fa[u];s[p]+=s[u];\n\
    \            if(s[u]>s[hv[p]])hv[p]=u;\n        }\n        root=compress(1).first;\n\
    \    }\n    int add(int i,int a,int b,Type ty){\n        if(!i)i=++cnt;\n    \
    \    l[i]=a,r[i]=b,t[i]=ty,par[a]=par[b]=i;\n        return i;\n    }\n    P merge(const\
    \ vector<P> &a,int x,int y,Type ty){\n        if(y-x==1)return a[x];\n       \
    \ int tot=0,m=x;\n        for(int k=x;k<y;k++)tot+=a[k].second;\n        while(tot>a[m].second)tot-=2*a[m++].second;\n\
    \        auto [i,si]=merge(a,x,m,ty);\n        auto [j,sj]=merge(a,m,y,ty);\n\
    \        return {add(0,i,j,ty),si+sj};\n    }\n    P compress(int i){\n      \
    \  vector<P> a{add_vertex(i)};\n        while(hv[i])a.eb(add_vertex(i=hv[i]));\n\
    \        return merge(a,0,SZ(a),Compress);\n    }\n    P rake(int i){\n      \
    \  vector<P> a;\n        for(int j:adj[i])\n            if(j!=fa[i]&&j!=hv[i])a.eb(compress(j));\n\
    \        return a.empty()?P(0,0):merge(a,0,SZ(a),Rake);\n    }\n    P add_vertex(int\
    \ i){\n        auto [j,s]=rake(i);\n        return {add(i,j,0,j?AddVertex:Vertex),s+1};\n\
    \    }\n};\n/* struct D{\n    struct Path{static Path unit();};\n    struct Point{static\
    \ Point unit();};\n    static Path vertex(int v),add_vertex(Point p,int v),\n\
    \        compress(Path up,Path down);\n    static Point add_edge(Path p),rake(Point\
    \ a,Point b);\n}; */\ntemplate<class D>\nstruct StaticTopTreeRerootingDP:StaticTopTree{\n\
    \    using Path = typename D::Path;\n    using Point = typename D::Point;\n  \
    \  vector<Path> path,rvpath;\n    vector<Point> point;\n    StaticTopTreeRerootingDP(G\
    \ &g):StaticTopTree(g){\n        path=rvpath=vector<Path>(cnt+1),point.resize(cnt+1);\n\
    \        calc(root);\n    }\n    void pull(int u){\n        int lc=l[u],rc=r[u];\n\
    \        if(t[u]==Vertex)path[u]=rvpath[u]=D::vertex(u);\n        else if(t[u]==Compress){\n\
    \            path[u]=D::compress(path[lc],path[rc]);\n            rvpath[u]=D::compress(rvpath[rc],rvpath[lc]);\n\
    \        }\n        else if(t[u]==Rake)point[u]=D::rake(pt(lc),pt(rc));\n    \
    \    else path[u]=rvpath[u]=D::add_vertex(pt(lc),u);\n    }\n    Point pt(int\
    \ c){\n        return t[c]==Rake?point[c]:D::add_edge(path[c]);}\n    void calc(int\
    \ u){if(u)calc(l[u]),calc(r[u]),pull(u);}\n    void update(int u){for(;u;u=par[u])pull(u);}\n\
    \    Path query_all(){return path[root];}\n    Path query_subtree(int u){\n  \
    \      Path res=path[u];\n        for(int p;(p=par[u])&&t[p]==Compress;u=p)\n\
    \            if(l[p]==u)res=D::compress(res,path[r[p]]);\n        return res;\n\
    \    }\n    pair<Path,Path> around(int u){ // {below u, rest of tree}\n      \
    \  Path dn=Path::unit(),up=dn;\n        int p=par[u];\n        for(;p&&t[p]==Compress;p=par[u=p])\n\
    \            if(l[p]==u)dn=D::compress(dn,path[r[p]]);\n            else up=D::compress(up,rvpath[l[p]]);\n\
    \        if(p){\n            Point s=Point::unit();\n            for(;t[p]==Rake;p=par[u=p])\n\
    \                s=D::rake(s,pt(l[p]^r[p]^u));\n            s=D::rake(s,out(p));\n\
    \            up=D::compress(up,D::add_vertex(s,p));\n        }\n        return\
    \ {dn,up};\n    }\n    Point out(int u){\n        auto [dn,up]=around(u);\n  \
    \      return D::rake(D::add_edge(dn),D::add_edge(up));\n    }\n    Path query_reroot(int\
    \ u){\n        Point s=out(u);\n        if(t[u]==AddVertex)s=D::rake(s,pt(l[u]));\n\
    \        return D::add_vertex(s,u);\n    }\n    Path query_side(int v,int w){//\
    \ remove (v,w) then query(v)\n        return fa[v]==w?query_subtree(v):around(w).second;\n\
    \    }\n};\n"
  dependsOn:
  - src/contest/template.hpp
  isVerificationFile: false
  path: src/tree/static-top-tree.hpp
  requiredBy: []
  timestamp: '2026-10-26 18:23:08+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/tree/static-top-tree/point_set_tree_path_composite_sum.test.cpp
  - verify/tree/static-top-tree/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: src/tree/static-top-tree.hpp
layout: document
redirect_from:
- /library/src/tree/static-top-tree.hpp
- /library/src/tree/static-top-tree.hpp.html
title: src/tree/static-top-tree.hpp
---
