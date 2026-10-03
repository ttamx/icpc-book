---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/flows/min-cost-flow.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-03-31\n * Description: Minimum-cost maximum flow (successive\
    \ shortest\n * paths, Dijkstra with potentials; Bellman-Ford initializes the\n\
    \ * potentials if there are negative costs). No negative cycles.\n * Time: $O(FE\\\
    log{V})$ where $F$ is max flow.\n */\n\ntemplate<class F,class C>\nstruct MinCostFlow{\n\
    \    struct Edge{\n        int to;F flow,cap;C cost;\n        F getcap(){return\
    \ cap-flow;}\n    };\n    int n;\n    vector<Edge> e;\n    vector<vector<int>>\
    \ adj;\n    vector<C> pot,dist;\n    vector<int> pre;\n    bool neg;\n    const\
    \ F FINF=numeric_limits<F>::max()/2;\n    const C CINF=numeric_limits<C>::max()/2;\n\
    \    MinCostFlow(){}\n    MinCostFlow(int _n){init(_n);}\n    void init(int _n){n=_n,neg=0,e.clear(),adj.assign(n,{});}\n\
    \    void addEdge(int u,int v,F cap,C cost){\n        adj[u].pb(SZ(e)),e.pb({v,0,cap,cost});\n\
    \        adj[v].pb(SZ(e)),e.pb({u,0,0,-cost});\n        if(cost<0)neg=true;\n\
    \    }\n    bool dijkstra(int s,int t){\n        using P=pair<C,int>;\n      \
    \  dist.assign(n,CINF),pre.assign(n,-1);\n        PQ<P> pq;\n        dist[s]=0,pq.emplace(0,s);\n\
    \        while(!pq.empty()){\n            auto [d,u]=pq.top();pq.pop();\n    \
    \        if(dist[u]<d)continue;\n            for(int i:adj[u]){\n            \
    \    C nd=d+pot[u]-pot[e[i].to]+e[i].cost;\n                if(e[i].getcap()>0&&chmin(dist[e[i].to],nd))\n\
    \                    pre[e[i].to]=i,pq.emplace(nd,e[i].to);\n            }\n \
    \       }\n        return dist[t]<CINF;\n    }\n    pair<F,C> flow(int s,int t){\n\
    \        F flow=0;C cost=0;\n        pot.assign(n,0);\n        if(neg)for(int\
    \ k=0;k<n;k++)for(int i=0;i<SZ(e);i++)\n            if(int u=e[i^1].to,v=e[i].to;e[i].getcap()>0)\n\
    \                pot[v]=min(pot[v],pot[u]+e[i].cost);\n        while(dijkstra(s,t)){\n\
    \            for(int i=0;i<n;i++)pot[i]+=dist[i]<CINF?dist[i]:0;\n           \
    \ F aug=FINF;\n            for(int u=t;u!=s;u=e[pre[u]^1].to)\n              \
    \  aug=min(aug,e[pre[u]].getcap());\n            for(int u=t;u!=s;u=e[pre[u]^1].to)\n\
    \                e[pre[u]].flow+=aug,e[pre[u]^1].flow-=aug;\n            flow+=aug,cost+=aug*(pot[t]-pot[s]);\n\
    \        }\n        return {flow,cost};\n    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-03-31\n * Description:\
    \ Minimum-cost maximum flow (successive shortest\n * paths, Dijkstra with potentials;\
    \ Bellman-Ford initializes the\n * potentials if there are negative costs). No\
    \ negative cycles.\n * Time: $O(FE\\log{V})$ where $F$ is max flow.\n */\n\ntemplate<class\
    \ F,class C>\nstruct MinCostFlow{\n    struct Edge{\n        int to;F flow,cap;C\
    \ cost;\n        F getcap(){return cap-flow;}\n    };\n    int n;\n    vector<Edge>\
    \ e;\n    vector<vector<int>> adj;\n    vector<C> pot,dist;\n    vector<int> pre;\n\
    \    bool neg;\n    const F FINF=numeric_limits<F>::max()/2;\n    const C CINF=numeric_limits<C>::max()/2;\n\
    \    MinCostFlow(){}\n    MinCostFlow(int _n){init(_n);}\n    void init(int _n){n=_n,neg=0,e.clear(),adj.assign(n,{});}\n\
    \    void addEdge(int u,int v,F cap,C cost){\n        adj[u].pb(SZ(e)),e.pb({v,0,cap,cost});\n\
    \        adj[v].pb(SZ(e)),e.pb({u,0,0,-cost});\n        if(cost<0)neg=true;\n\
    \    }\n    bool dijkstra(int s,int t){\n        using P=pair<C,int>;\n      \
    \  dist.assign(n,CINF),pre.assign(n,-1);\n        PQ<P> pq;\n        dist[s]=0,pq.emplace(0,s);\n\
    \        while(!pq.empty()){\n            auto [d,u]=pq.top();pq.pop();\n    \
    \        if(dist[u]<d)continue;\n            for(int i:adj[u]){\n            \
    \    C nd=d+pot[u]-pot[e[i].to]+e[i].cost;\n                if(e[i].getcap()>0&&chmin(dist[e[i].to],nd))\n\
    \                    pre[e[i].to]=i,pq.emplace(nd,e[i].to);\n            }\n \
    \       }\n        return dist[t]<CINF;\n    }\n    pair<F,C> flow(int s,int t){\n\
    \        F flow=0;C cost=0;\n        pot.assign(n,0);\n        if(neg)for(int\
    \ k=0;k<n;k++)for(int i=0;i<SZ(e);i++)\n            if(int u=e[i^1].to,v=e[i].to;e[i].getcap()>0)\n\
    \                pot[v]=min(pot[v],pot[u]+e[i].cost);\n        while(dijkstra(s,t)){\n\
    \            for(int i=0;i<n;i++)pot[i]+=dist[i]<CINF?dist[i]:0;\n           \
    \ F aug=FINF;\n            for(int u=t;u!=s;u=e[pre[u]^1].to)\n              \
    \  aug=min(aug,e[pre[u]].getcap());\n            for(int u=t;u!=s;u=e[pre[u]^1].to)\n\
    \                e[pre[u]].flow+=aug,e[pre[u]^1].flow-=aug;\n            flow+=aug,cost+=aug*(pot[t]-pot[s]);\n\
    \        }\n        return {flow,cost};\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/flows/min-cost-flow.hpp
  requiredBy: []
  timestamp: '2026-10-04 01:45:10+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flows/min-cost-flow.hpp
layout: document
redirect_from:
- /library/src/flows/min-cost-flow.hpp
- /library/src/flows/min-cost-flow.hpp.html
title: src/flows/min-cost-flow.hpp
---
