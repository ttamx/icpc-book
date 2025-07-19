---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 3 \"src/tree/static-top-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-11-14\n * Description: Static Top\
    \ Tree.\n */\n\ntemplate<class G>\nstruct StaticTopTree{\n    using P = pair<int,int>;\n\
    \    enum Type{Compress,Rake,AddEdge,AddVertex,Vertex};\n    int n,root;\n   \
    \ G &adj;\n    vector<int> hv,fa,lch,rch,par;\n    vector<Type> type;\n    StaticTopTree(G\
    \ &adj):adj(adj){build();}\n    int dfs(int u){\n        int s=1,mx=0;\n     \
    \   for(auto v:adj[u]){\n            if(v==fa[u])continue;\n            fa[v]=u;\n\
    \            int t=dfs(v);\n            if(t>mx)mx=t,hv[u]=v;\n            s+=t;\n\
    \        }\n        return s;\n    }\n    void build(){\n        n=adj.size();\n\
    \        hv=fa=lch=rch=par=vector<int>(n,-1);\n        type.assign(n,Compress);\n\
    \        dfs(0,-1);\n        root=compress(0).second;\n    }\n    int add(int\
    \ i,int l,int r,Type t){\n        if(i==-1){\n            i=n++;\n           \
    \ lch.emplace_back(l);\n            rch.emplace_back(r);\n            par.emplace_back(-1);\n\
    \            type.emplace_back(t);\n        }else{\n            lch[i]=l,rch[i]=r,type[i]=t;\n\
    \        }\n        if(l!=-1)par[l]=i;\n        if(r!=-1)par[r]=i;\n        return\
    \ i;\n    }\n    /*\n    pair<int,int> merge(vector<pair<int,int>> a,Type t){\n\
    \        if(a.size()==1)return a[0];\n        int tot=0;\n        vector<pair<int,int>>\
    \ l,r;\n        for(auto [i,s]:a)tot+=s;\n        for(auto [i,s]:a){\n       \
    \     (tot>s?l:r).emplace_back(i,s);\n            tot-=s*2;\n        }\n     \
    \   auto [i,si]=merge(l,t);\n        auto [j,sj]=merge(r,t);\n        return {add(-1,i,j,t),si+sj};\n\
    \    }\n    */\n    P compress(int i){\n        vector<P> a{add_vertex(i)};\n\
    \        auto work=[&](){\n            auto [sj,j]=a.back();\n            a.pop_back();\n\
    \            auto [si,i]=a.back();\n            a.back()={max(si,sj)+1,add(-1,i,j,Compress)};\n\
    \        };\n        while(hv[i]!=-1){\n            a.emplace_back(add_vertex(i=hv[i]));\n\
    \            while(true){\n                if(a.size()>=3&&(a.end()[-3].first==a.end()[-2].first||a.end()[-3].first<=a.back().first)){\n\
    \                    P tmp=a.back();\n                    a.pop_back();\n    \
    \                work();\n                    a.emplace_back(tmp);\n         \
    \       }else if(a.size()>=2&&a.end()[-2].first<=a.back().first){\n          \
    \          work();\n                }else break;\n            }\n        }\n \
    \       while(a.size()>=2)work();\n        return a[0];\n    }\n    P rake(int\
    \ i){\n        priority_queue<P,vector<P>,greater<P>> pq;\n        for(int j:adj[i])if(j!=fa[i]&&j!=hv[i])pq.emplace(add_edge(j));\n\
    \        while(pq.size()>=2){\n            auto [si,i]=pq.top();pq.pop();\n  \
    \          auto [sj,j]=pq.top();pq.pop();\n            pq.emplace(max(si,sj)+1,add(-1,i,j,Rake));\n\
    \        }\n        return pq.empty()?make_pair(0,-1):pq.top();\n    }\n    P\
    \ add_edge(int i){\n        auto [sj,j]=compress(i);\n        return {sj+1,add(-1,j,-1,AddEdge)};\n\
    \    }\n    P add_vertex(int i){\n        auto [sj,j]=rake(i);\n        return\
    \ {sj+1,add(i,j,-1,j==-1?Vertex:AddVertex)};\n    }\n};\n\n/*\nstruct TreeDP{\n\
    \    struct Path{\n        static Path unit();\n    };\n    struct Point{\n  \
    \      static Point unit();\n    };\n    static Path compress(Path l,Path r);\n\
    \    static Point rake(Point l,Point r);\n    static Point add_edge(Path p);\n\
    \    static Path add_vertex(Point p,int u);\n    static Path vertex(int u);\n\
    };\n*/\n\ntemplate<class G,class TreeDP>\nstruct StaticTopTreeRerootingDP{\n \
    \   using Path = typename TreeDP::Path;\n    using Point = typename TreeDP::Point;\n\
    \    StaticTopTree<G> stt;\n    vector<Path> path,rpath;\n    vector<Point> point;\n\
    \    StaticTopTreeRerootingDP(G &adj):stt(adj){\n        int n=stt.n;\n      \
    \  path.resize(n);\n        point.resize(n);\n        rpath.resize(n);\n     \
    \   dfs(stt.root);\n    }\n    void _update(int u){\n        if(stt.type[u]==stt.Vertex){\n\
    \            path[u]=rpath[u]=TreeDP::vertex(u);\n        }else if(stt.type[u]==stt.Compress){\n\
    \            path[u]=TreeDP::compress(path[stt.lch[u]],path[stt.rch[u]]);\n  \
    \          rpath[u]=TreeDP::compress(rpath[stt.rch[u]],rpath[stt.lch[u]]);\n \
    \       }else if(stt.type[u]==stt.Rake){\n            point[u]=TreeDP::rake(point[stt.lch[u]],point[stt.rch[u]]);\n\
    \        }else if(stt.type[u]==stt.AddEdge){\n            point[u]=TreeDP::add_edge(path[stt.lch[u]]);\n\
    \        }else{\n            path[u]=rpath[u]=TreeDP::add_vertex(point[stt.lch[u]],u);\n\
    \        }\n    }\n    void dfs(int u){\n        if(u==-1)return;\n        dfs(stt.lch[u]);\n\
    \        dfs(stt.rch[u]);\n        _update(u);\n    }\n    void update(int u){\n\
    \        for(;u!=-1;u=stt.par[u])_update(u);\n    }\n    Path query_all(){\n \
    \       return path[stt.root];\n    }\n    Path query_subtree(int u){\n      \
    \  Path res=path[u];\n        while(true){\n            int p=stt.par[u];\n  \
    \          if(p==-1||stt.type[p]!=stt.Compress)break;\n            if(stt.lch[p]==u)res=TreeDP::compress(path[stt.rch[p]],res);\n\
    \        }\n        return res;\n    }\n    Path query_reroot(int u){\n      \
    \  auto rec=[&](auto &&rec,int u)->Point {\n            int p=stt.par[u];\n  \
    \          Path below=Path::unit(),above=Path::unit();\n            while(p!=-1&&stt.type[p]==stt.Compress){\n\
    \                int l=stt.lch[p],r=stt.rch[p];\n                if(l==u)below=TreeDP::compress(below,path[r]);\n\
    \                else above=TreeDP::compress(above,rpath[l]);\n              \
    \  u=p;\n                p=stt.par[u];\n            }\n            if(p!=-1){\n\
    \                u=p;\n                p=stt.par[u];\n                Point sum=Point::unit();\n\
    \                while(stt.type[p]==stt.Rake){\n                    int l=stt.lch[p],r=stt.rch[p];\n\
    \                    sum=TreeDP::rake(sum,u==r?point[l]:point[r]);\n         \
    \           u=p;\n                    p=stt.par[u];\n                }\n     \
    \           sum=TreeDP::rake(sum,rec(rec,p));\n                above=TreeDP::compress(above,TreeDP::add_vertex(sum,p));\n\
    \            }\n            return TreeDP::rake(TreeDP::add_edge(below),TreeDP::add_edge(above));\n\
    \        };\n        Point res=rec(rec,u);\n        if(stt.type[u]==stt.AddVertex){\n\
    \            res=TreeDP::rake(res,point[stt.lch[u]]);\n        }\n        return\
    \ TreeDP::add_vertex(res,u);\n    }\n};\n"
  code: "#pragma once\n#include \"src/contest/template.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-11-14\n * Description: Static Top Tree.\n */\n\ntemplate<class\
    \ G>\nstruct StaticTopTree{\n    using P = pair<int,int>;\n    enum Type{Compress,Rake,AddEdge,AddVertex,Vertex};\n\
    \    int n,root;\n    G &adj;\n    vector<int> hv,fa,lch,rch,par;\n    vector<Type>\
    \ type;\n    StaticTopTree(G &adj):adj(adj){build();}\n    int dfs(int u){\n \
    \       int s=1,mx=0;\n        for(auto v:adj[u]){\n            if(v==fa[u])continue;\n\
    \            fa[v]=u;\n            int t=dfs(v);\n            if(t>mx)mx=t,hv[u]=v;\n\
    \            s+=t;\n        }\n        return s;\n    }\n    void build(){\n \
    \       n=adj.size();\n        hv=fa=lch=rch=par=vector<int>(n,-1);\n        type.assign(n,Compress);\n\
    \        dfs(0,-1);\n        root=compress(0).second;\n    }\n    int add(int\
    \ i,int l,int r,Type t){\n        if(i==-1){\n            i=n++;\n           \
    \ lch.emplace_back(l);\n            rch.emplace_back(r);\n            par.emplace_back(-1);\n\
    \            type.emplace_back(t);\n        }else{\n            lch[i]=l,rch[i]=r,type[i]=t;\n\
    \        }\n        if(l!=-1)par[l]=i;\n        if(r!=-1)par[r]=i;\n        return\
    \ i;\n    }\n    /*\n    pair<int,int> merge(vector<pair<int,int>> a,Type t){\n\
    \        if(a.size()==1)return a[0];\n        int tot=0;\n        vector<pair<int,int>>\
    \ l,r;\n        for(auto [i,s]:a)tot+=s;\n        for(auto [i,s]:a){\n       \
    \     (tot>s?l:r).emplace_back(i,s);\n            tot-=s*2;\n        }\n     \
    \   auto [i,si]=merge(l,t);\n        auto [j,sj]=merge(r,t);\n        return {add(-1,i,j,t),si+sj};\n\
    \    }\n    */\n    P compress(int i){\n        vector<P> a{add_vertex(i)};\n\
    \        auto work=[&](){\n            auto [sj,j]=a.back();\n            a.pop_back();\n\
    \            auto [si,i]=a.back();\n            a.back()={max(si,sj)+1,add(-1,i,j,Compress)};\n\
    \        };\n        while(hv[i]!=-1){\n            a.emplace_back(add_vertex(i=hv[i]));\n\
    \            while(true){\n                if(a.size()>=3&&(a.end()[-3].first==a.end()[-2].first||a.end()[-3].first<=a.back().first)){\n\
    \                    P tmp=a.back();\n                    a.pop_back();\n    \
    \                work();\n                    a.emplace_back(tmp);\n         \
    \       }else if(a.size()>=2&&a.end()[-2].first<=a.back().first){\n          \
    \          work();\n                }else break;\n            }\n        }\n \
    \       while(a.size()>=2)work();\n        return a[0];\n    }\n    P rake(int\
    \ i){\n        priority_queue<P,vector<P>,greater<P>> pq;\n        for(int j:adj[i])if(j!=fa[i]&&j!=hv[i])pq.emplace(add_edge(j));\n\
    \        while(pq.size()>=2){\n            auto [si,i]=pq.top();pq.pop();\n  \
    \          auto [sj,j]=pq.top();pq.pop();\n            pq.emplace(max(si,sj)+1,add(-1,i,j,Rake));\n\
    \        }\n        return pq.empty()?make_pair(0,-1):pq.top();\n    }\n    P\
    \ add_edge(int i){\n        auto [sj,j]=compress(i);\n        return {sj+1,add(-1,j,-1,AddEdge)};\n\
    \    }\n    P add_vertex(int i){\n        auto [sj,j]=rake(i);\n        return\
    \ {sj+1,add(i,j,-1,j==-1?Vertex:AddVertex)};\n    }\n};\n\n/*\nstruct TreeDP{\n\
    \    struct Path{\n        static Path unit();\n    };\n    struct Point{\n  \
    \      static Point unit();\n    };\n    static Path compress(Path l,Path r);\n\
    \    static Point rake(Point l,Point r);\n    static Point add_edge(Path p);\n\
    \    static Path add_vertex(Point p,int u);\n    static Path vertex(int u);\n\
    };\n*/\n\ntemplate<class G,class TreeDP>\nstruct StaticTopTreeRerootingDP{\n \
    \   using Path = typename TreeDP::Path;\n    using Point = typename TreeDP::Point;\n\
    \    StaticTopTree<G> stt;\n    vector<Path> path,rpath;\n    vector<Point> point;\n\
    \    StaticTopTreeRerootingDP(G &adj):stt(adj){\n        int n=stt.n;\n      \
    \  path.resize(n);\n        point.resize(n);\n        rpath.resize(n);\n     \
    \   dfs(stt.root);\n    }\n    void _update(int u){\n        if(stt.type[u]==stt.Vertex){\n\
    \            path[u]=rpath[u]=TreeDP::vertex(u);\n        }else if(stt.type[u]==stt.Compress){\n\
    \            path[u]=TreeDP::compress(path[stt.lch[u]],path[stt.rch[u]]);\n  \
    \          rpath[u]=TreeDP::compress(rpath[stt.rch[u]],rpath[stt.lch[u]]);\n \
    \       }else if(stt.type[u]==stt.Rake){\n            point[u]=TreeDP::rake(point[stt.lch[u]],point[stt.rch[u]]);\n\
    \        }else if(stt.type[u]==stt.AddEdge){\n            point[u]=TreeDP::add_edge(path[stt.lch[u]]);\n\
    \        }else{\n            path[u]=rpath[u]=TreeDP::add_vertex(point[stt.lch[u]],u);\n\
    \        }\n    }\n    void dfs(int u){\n        if(u==-1)return;\n        dfs(stt.lch[u]);\n\
    \        dfs(stt.rch[u]);\n        _update(u);\n    }\n    void update(int u){\n\
    \        for(;u!=-1;u=stt.par[u])_update(u);\n    }\n    Path query_all(){\n \
    \       return path[stt.root];\n    }\n    Path query_subtree(int u){\n      \
    \  Path res=path[u];\n        while(true){\n            int p=stt.par[u];\n  \
    \          if(p==-1||stt.type[p]!=stt.Compress)break;\n            if(stt.lch[p]==u)res=TreeDP::compress(path[stt.rch[p]],res);\n\
    \        }\n        return res;\n    }\n    Path query_reroot(int u){\n      \
    \  auto rec=[&](auto &&rec,int u)->Point {\n            int p=stt.par[u];\n  \
    \          Path below=Path::unit(),above=Path::unit();\n            while(p!=-1&&stt.type[p]==stt.Compress){\n\
    \                int l=stt.lch[p],r=stt.rch[p];\n                if(l==u)below=TreeDP::compress(below,path[r]);\n\
    \                else above=TreeDP::compress(above,rpath[l]);\n              \
    \  u=p;\n                p=stt.par[u];\n            }\n            if(p!=-1){\n\
    \                u=p;\n                p=stt.par[u];\n                Point sum=Point::unit();\n\
    \                while(stt.type[p]==stt.Rake){\n                    int l=stt.lch[p],r=stt.rch[p];\n\
    \                    sum=TreeDP::rake(sum,u==r?point[l]:point[r]);\n         \
    \           u=p;\n                    p=stt.par[u];\n                }\n     \
    \           sum=TreeDP::rake(sum,rec(rec,p));\n                above=TreeDP::compress(above,TreeDP::add_vertex(sum,p));\n\
    \            }\n            return TreeDP::rake(TreeDP::add_edge(below),TreeDP::add_edge(above));\n\
    \        };\n        Point res=rec(rec,u);\n        if(stt.type[u]==stt.AddVertex){\n\
    \            res=TreeDP::rake(res,point[stt.lch[u]]);\n        }\n        return\
    \ TreeDP::add_vertex(res,u);\n    }\n};\n"
  dependsOn:
  - src/contest/template.hpp
  isVerificationFile: false
  path: src/tree/static-top-tree.hpp
  requiredBy: []
  timestamp: '2025-07-19 14:35:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/tree/static-top-tree.hpp
layout: document
redirect_from:
- /library/src/tree/static-top-tree.hpp
- /library/src/tree/static-top-tree.hpp.html
title: src/tree/static-top-tree.hpp
---
