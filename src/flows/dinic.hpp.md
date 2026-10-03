---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/flows/binary-optimization.hpp
    title: src/flows/binary-optimization.hpp
  - icon: ':warning:'
    path: src/flows/k-ary-optimization.hpp
    title: src/flows/k-ary-optimization.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/flows/dinic.hpp\"\n\n/**\n * Author: Teetat T.\n * Date:\
    \ 2024-07-15\n * Description: Dinic's Algorithm for finding the maximum flow.\n\
    \ * cut() returns the flow and res[i]=1 iff i is on the sink side.\n * Time: $O(V^2E)$\
    \ in general, $O(VE\\log U)$ with scaling\n * where $U$ is the maximum capacity.\n\
    \ */\n\ntemplate<class T,bool directed=true,bool scaling=true>\nstruct Dinic{\n\
    \    static constexpr T INF=numeric_limits<T>::max()/2;\n    struct Edge{\n  \
    \      int to;T flow,cap;\n        T remain(){return cap-flow;}\n    };\n    int\
    \ n,s,t;T U;\n    vector<Edge> e;\n    vector<vector<int>> g;\n    vector<int>\
    \ ptr,lv;\n    bool calculated;T max_flow;\n    Dinic(){}\n    Dinic(int n,int\
    \ s,int t){init(n,s,t);}\n    void init(int _n,int _s,int _t){\n        n=_n,s=_s,t=_t,U=0,calculated=false;\n\
    \        e.clear(),g.assign(n,{});\n    }\n    void add_edge(int from,int to,T\
    \ cap){\n        assert(0<=from&&from<n&&0<=to&&to<n);\n        g[from].pb(SZ(e)),e.pb({to,0,cap});\n\
    \        g[to].pb(SZ(e)),e.pb({from,0,directed?0:cap});\n        U=max(U,cap);\n\
    \    }\n    bool bfs(T scale){\n        lv.assign(n,-1),lv[s]=0;\n        vector<int>\
    \ q{s};\n        for(int i=0;i<SZ(q);i++)for(int j:g[q[i]]){\n            int\
    \ v=e[j].to;\n            if(lv[v]==-1&&e[j].remain()>=scale)\n              \
    \  lv[v]=lv[q[i]]+1,q.pb(v);\n        }\n        return lv[t]!=-1;\n    }\n  \
    \  T dfs(int u,int t,T f){\n        if(u==t||f==0)return f;\n        for(int &i=ptr[u];i<SZ(g[u]);i++){\n\
    \            int j=g[u][i],v=e[j].to;\n            if(lv[v]!=lv[u]+1)continue;\n\
    \            T r=dfs(v,t,min(f,e[j].remain()));\n            if(r>0)return e[j].flow+=r,e[j^1].flow-=r,r;\n\
    \        }\n        return 0;\n    }\n    T flow(){\n        if(calculated)return\
    \ max_flow;\n        calculated=true,max_flow=0;\n        T scale=scaling&&U?1LL<<(63-__builtin_clzll(U)):1LL;\n\
    \        for(;scale>0;scale>>=1)while(bfs(scale)){\n            ptr.assign(n,0);\n\
    \            while(T f=dfs(s,t,INF))max_flow+=f;\n        }\n        return max_flow;\n\
    \    }\n    pair<T,vector<int>> cut(){\n        flow();\n        vector<int> res(n);\n\
    \        for(int i=0;i<n;i++)res[i]=lv[i]==-1;\n        return {max_flow,res};\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-07-15\n * Description:\
    \ Dinic's Algorithm for finding the maximum flow.\n * cut() returns the flow and\
    \ res[i]=1 iff i is on the sink side.\n * Time: $O(V^2E)$ in general, $O(VE\\\
    log U)$ with scaling\n * where $U$ is the maximum capacity.\n */\n\ntemplate<class\
    \ T,bool directed=true,bool scaling=true>\nstruct Dinic{\n    static constexpr\
    \ T INF=numeric_limits<T>::max()/2;\n    struct Edge{\n        int to;T flow,cap;\n\
    \        T remain(){return cap-flow;}\n    };\n    int n,s,t;T U;\n    vector<Edge>\
    \ e;\n    vector<vector<int>> g;\n    vector<int> ptr,lv;\n    bool calculated;T\
    \ max_flow;\n    Dinic(){}\n    Dinic(int n,int s,int t){init(n,s,t);}\n    void\
    \ init(int _n,int _s,int _t){\n        n=_n,s=_s,t=_t,U=0,calculated=false;\n\
    \        e.clear(),g.assign(n,{});\n    }\n    void add_edge(int from,int to,T\
    \ cap){\n        assert(0<=from&&from<n&&0<=to&&to<n);\n        g[from].pb(SZ(e)),e.pb({to,0,cap});\n\
    \        g[to].pb(SZ(e)),e.pb({from,0,directed?0:cap});\n        U=max(U,cap);\n\
    \    }\n    bool bfs(T scale){\n        lv.assign(n,-1),lv[s]=0;\n        vector<int>\
    \ q{s};\n        for(int i=0;i<SZ(q);i++)for(int j:g[q[i]]){\n            int\
    \ v=e[j].to;\n            if(lv[v]==-1&&e[j].remain()>=scale)\n              \
    \  lv[v]=lv[q[i]]+1,q.pb(v);\n        }\n        return lv[t]!=-1;\n    }\n  \
    \  T dfs(int u,int t,T f){\n        if(u==t||f==0)return f;\n        for(int &i=ptr[u];i<SZ(g[u]);i++){\n\
    \            int j=g[u][i],v=e[j].to;\n            if(lv[v]!=lv[u]+1)continue;\n\
    \            T r=dfs(v,t,min(f,e[j].remain()));\n            if(r>0)return e[j].flow+=r,e[j^1].flow-=r,r;\n\
    \        }\n        return 0;\n    }\n    T flow(){\n        if(calculated)return\
    \ max_flow;\n        calculated=true,max_flow=0;\n        T scale=scaling&&U?1LL<<(63-__builtin_clzll(U)):1LL;\n\
    \        for(;scale>0;scale>>=1)while(bfs(scale)){\n            ptr.assign(n,0);\n\
    \            while(T f=dfs(s,t,INF))max_flow+=f;\n        }\n        return max_flow;\n\
    \    }\n    pair<T,vector<int>> cut(){\n        flow();\n        vector<int> res(n);\n\
    \        for(int i=0;i<n;i++)res[i]=lv[i]==-1;\n        return {max_flow,res};\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/flows/dinic.hpp
  requiredBy:
  - src/flows/binary-optimization.hpp
  - src/flows/k-ary-optimization.hpp
  timestamp: '2026-10-04 01:45:10+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flows/dinic.hpp
layout: document
redirect_from:
- /library/src/flows/dinic.hpp
- /library/src/flows/dinic.hpp.html
title: src/flows/dinic.hpp
---
