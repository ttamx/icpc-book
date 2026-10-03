---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/flows/hopcroft-karp/bipartitematching.test.cpp
    title: verify/flows/hopcroft-karp/bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/flows/hopcroft-karp.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-03-31\n * Description: Fast bipartite matching algorithm.\
    \ Left $[0,n)$,\n * right $[0,m)$; after max\\_matching(), match[i] ($i<n$) is\n\
    \ * $n+$(matched right vertex) or -1.\n * Time: $O(E\\sqrt{V})$\n */\n\nstruct\
    \ HopcroftKarp{\n    int n,m;\n    vector<int> match,lv,ptr;\n    vector<vector<int>>\
    \ adj;\n    HopcroftKarp(){}\n    HopcroftKarp(int _n,int _m){init(_n,_m);}\n\
    \    void init(int _n,int _m){n=_n,m=_m,adj.assign(n+m,{});}\n    void add_edge(int\
    \ u,int v){adj[u].pb(v+n);}\n    void bfs(){\n        lv.assign(n,-1);\n     \
    \   vector<int> q;\n        for(int i=0;i<n;i++)if(match[i]==-1)lv[i]=0,q.pb(i);\n\
    \        for(int i=0;i<SZ(q);i++)for(int v:adj[q[i]])\n            if(int w=match[v];w!=-1&&lv[w]==-1)\n\
    \                lv[w]=lv[q[i]]+1,q.pb(w);\n    }\n    bool dfs(int u){\n    \
    \    for(int &i=ptr[u];i<SZ(adj[u]);i++){\n            int v=adj[u][i],w=match[v];\n\
    \            if(w==-1||(lv[w]==lv[u]+1&&dfs(w)))\n                return match[u]=v,match[v]=u,true;\n\
    \        }\n        return false;\n    }\n    int max_matching(){\n        int\
    \ ans=0,c=1;\n        match.assign(n+m,-1);\n        while(c){\n            ptr.assign(n,0),bfs(),c=0;\n\
    \            for(int i=0;i<n;i++)c+=match[i]==-1&&dfs(i);\n            ans+=c;\n\
    \        }\n        return ans;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-03-31\n * Description:\
    \ Fast bipartite matching algorithm. Left $[0,n)$,\n * right $[0,m)$; after max\\\
    _matching(), match[i] ($i<n$) is\n * $n+$(matched right vertex) or -1.\n * Time:\
    \ $O(E\\sqrt{V})$\n */\n\nstruct HopcroftKarp{\n    int n,m;\n    vector<int>\
    \ match,lv,ptr;\n    vector<vector<int>> adj;\n    HopcroftKarp(){}\n    HopcroftKarp(int\
    \ _n,int _m){init(_n,_m);}\n    void init(int _n,int _m){n=_n,m=_m,adj.assign(n+m,{});}\n\
    \    void add_edge(int u,int v){adj[u].pb(v+n);}\n    void bfs(){\n        lv.assign(n,-1);\n\
    \        vector<int> q;\n        for(int i=0;i<n;i++)if(match[i]==-1)lv[i]=0,q.pb(i);\n\
    \        for(int i=0;i<SZ(q);i++)for(int v:adj[q[i]])\n            if(int w=match[v];w!=-1&&lv[w]==-1)\n\
    \                lv[w]=lv[q[i]]+1,q.pb(w);\n    }\n    bool dfs(int u){\n    \
    \    for(int &i=ptr[u];i<SZ(adj[u]);i++){\n            int v=adj[u][i],w=match[v];\n\
    \            if(w==-1||(lv[w]==lv[u]+1&&dfs(w)))\n                return match[u]=v,match[v]=u,true;\n\
    \        }\n        return false;\n    }\n    int max_matching(){\n        int\
    \ ans=0,c=1;\n        match.assign(n+m,-1);\n        while(c){\n            ptr.assign(n,0),bfs(),c=0;\n\
    \            for(int i=0;i<n;i++)c+=match[i]==-1&&dfs(i);\n            ans+=c;\n\
    \        }\n        return ans;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/flows/hopcroft-karp.hpp
  requiredBy: []
  timestamp: '2026-10-04 01:45:10+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/flows/hopcroft-karp/bipartitematching.test.cpp
documentation_of: src/flows/hopcroft-karp.hpp
layout: document
redirect_from:
- /library/src/flows/hopcroft-karp.hpp
- /library/src/flows/hopcroft-karp.hpp.html
title: src/flows/hopcroft-karp.hpp
---
