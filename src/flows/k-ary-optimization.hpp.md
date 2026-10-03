---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/flows/dinic.hpp
    title: src/flows/dinic.hpp
  _extendedRequiredBy: []
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
    \    }\n};\n#line 3 \"src/flows/k-ary-optimization.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-07-16\n * Description: k-ary Optimization.\n * minimize $\\\
    kappa + \\sum_i \\theta_i(x_i) + \\sum_{i<j} \\phi_{ij}(x_i,x_j)$\n * where $x_i\
    \ \\in \\{0,1,\\ldots,k-1\\}$ and $\\phi_{i,j}$ is monge.\n * A function $f$ is\
    \ monge if $f(a,c)+f(b,d) \\leq f(a,d)+f(b,c)$ for all $a < b$ and $c < d$.\n\
    \ * $\\phi_{ij}(x-1,y)+\\phi_{ij}(x,y+1) \\leq \\phi_{ij}(x-1,y+1)+\\phi_{ij}(x,y)$.\n\
    \ * $\\phi_{ij}(x,y)+\\phi_{ij}(x-1,y+1)-\\phi_{ij}(x-1,y)-\\phi_{ij}(x,y+1) \\\
    geq 0$.\n */\n\ntemplate<class T,bool minimize=true>\nstruct K_aryOptimization{\n\
    \    static constexpr T INF=numeric_limits<T>::max()/2;\n    int n,s,t,buf;\n\
    \    T base;\n    vector<int> ks;\n    vector<vector<int>> id;\n    map<pair<int,int>,T>\
    \ edges;\n    K_aryOptimization(int n,int k){init(vector<int>(n,k));}\n    K_aryOptimization(const\
    \ vector<int> &_ks){init(_ks);}\n    void init(const vector<int> &_ks){\n    \
    \    ks=_ks;\n        n=ks.size();\n        s=0,t=1,buf=2;\n        base=0;\n\
    \        id.clear();\n        edges.clear();\n        for(auto &k:ks){\n     \
    \       assert(k>=1);\n            vector<int> a(k+1);\n            a[0]=s,a[k]=t;\n\
    \            for(int i=1;i<k;i++)a[i]=buf++;\n            id.emplace_back(a);\n\
    \            for(int i=2;i<k;i++)add_edge(a[i],a[i-1],INF);\n        }\n    }\n\
    \    void add_edge(int u,int v,T w){\n        assert(w>=0);\n        if(u==v||w==0)return;\n\
    \        auto &e=edges[{u,v}];\n        e=min(e+w,INF);\n    }\n    void add0(T\
    \ w){\n        base+=w;\n    }\n    void _add1(int i,vector<T> cost){\n      \
    \  add0(cost[0]);\n        for(int j=1;j<ks[i];j++){\n            T x=cost[j]-cost[j-1];\n\
    \            if(x>0)add_edge(id[i][j],t,x);\n            if(x<0)add0(x),add_edge(s,id[i][j],-x);\n\
    \        }\n    }\n    void add1(int i,vector<T> cost){\n        assert(0<=i&&i<n&&(int)cost.size()==ks[i]);\n\
    \        if(!minimize)for(auto &x:cost)x=-x;\n        _add1(i,cost);\n    }\n\
    \    void _add2(int i,int j,vector<vector<T>> cost){\n        int h=ks[i],w=ks[j];\n\
    \        _add1(j,cost[0]);\n        for(int x=h-1;x>=0;x--)for(int y=0;y<w;y++)cost[x][y]-=cost[0][y];\n\
    \        vector<T> a(h);\n        for(int x=0;x<h;x++)a[x]=cost[x][w-1];\n   \
    \     _add1(i,a);\n        for(int x=0;x<h;x++)for(int y=0;y<w;y++)cost[x][y]-=a[x];\n\
    \        for(int x=1;x<h;x++){\n            for(int y=0;y<w-1;y++){\n        \
    \        T w=cost[x][y]+cost[x-1][y+1]-cost[x-1][y]-cost[x][y+1];\n          \
    \      assert(w>=0); // monge\n                add_edge(id[i][x],id[j][y+1],w);\n\
    \            }\n        }\n    }\n    void add2(int i,int j,vector<vector<T>>\
    \ cost){\n        assert(0<=i&&i<n&&0<=j&&j<n&&i!=j);\n        assert((int)cost.size()==ks[i]);\n\
    \        for(auto &v:cost)assert((int)v.size()==ks[j]);\n        if(!minimize)for(auto\
    \ &v:cost)for(auto &x:v)x=-x;\n        _add2(i,j,cost);\n    }\n    pair<T,vector<int>>\
    \ solve(){\n        Dinic<T> dinic(buf,s,t);\n        for(auto &[p,w]:edges){\n\
    \            auto [u,v]=p;\n            dinic.add_edge(u,v,w);\n        }\n  \
    \      auto [val,cut]=dinic.cut();\n        val+=base;\n        if(!minimize)val=-val;\n\
    \        vector<int> ans(n);\n        for(int i=0;i<n;i++){\n            ans[i]=ks[i]-1;\n\
    \            for(int j=1;j<ks[i];j++)ans[i]-=cut[id[i][j]];\n        }\n     \
    \   return {val,ans};\n    }\n};\n"
  code: "#pragma once\n#include \"src/flows/dinic.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-07-16\n * Description: k-ary Optimization.\n * minimize $\\\
    kappa + \\sum_i \\theta_i(x_i) + \\sum_{i<j} \\phi_{ij}(x_i,x_j)$\n * where $x_i\
    \ \\in \\{0,1,\\ldots,k-1\\}$ and $\\phi_{i,j}$ is monge.\n * A function $f$ is\
    \ monge if $f(a,c)+f(b,d) \\leq f(a,d)+f(b,c)$ for all $a < b$ and $c < d$.\n\
    \ * $\\phi_{ij}(x-1,y)+\\phi_{ij}(x,y+1) \\leq \\phi_{ij}(x-1,y+1)+\\phi_{ij}(x,y)$.\n\
    \ * $\\phi_{ij}(x,y)+\\phi_{ij}(x-1,y+1)-\\phi_{ij}(x-1,y)-\\phi_{ij}(x,y+1) \\\
    geq 0$.\n */\n\ntemplate<class T,bool minimize=true>\nstruct K_aryOptimization{\n\
    \    static constexpr T INF=numeric_limits<T>::max()/2;\n    int n,s,t,buf;\n\
    \    T base;\n    vector<int> ks;\n    vector<vector<int>> id;\n    map<pair<int,int>,T>\
    \ edges;\n    K_aryOptimization(int n,int k){init(vector<int>(n,k));}\n    K_aryOptimization(const\
    \ vector<int> &_ks){init(_ks);}\n    void init(const vector<int> &_ks){\n    \
    \    ks=_ks;\n        n=ks.size();\n        s=0,t=1,buf=2;\n        base=0;\n\
    \        id.clear();\n        edges.clear();\n        for(auto &k:ks){\n     \
    \       assert(k>=1);\n            vector<int> a(k+1);\n            a[0]=s,a[k]=t;\n\
    \            for(int i=1;i<k;i++)a[i]=buf++;\n            id.emplace_back(a);\n\
    \            for(int i=2;i<k;i++)add_edge(a[i],a[i-1],INF);\n        }\n    }\n\
    \    void add_edge(int u,int v,T w){\n        assert(w>=0);\n        if(u==v||w==0)return;\n\
    \        auto &e=edges[{u,v}];\n        e=min(e+w,INF);\n    }\n    void add0(T\
    \ w){\n        base+=w;\n    }\n    void _add1(int i,vector<T> cost){\n      \
    \  add0(cost[0]);\n        for(int j=1;j<ks[i];j++){\n            T x=cost[j]-cost[j-1];\n\
    \            if(x>0)add_edge(id[i][j],t,x);\n            if(x<0)add0(x),add_edge(s,id[i][j],-x);\n\
    \        }\n    }\n    void add1(int i,vector<T> cost){\n        assert(0<=i&&i<n&&(int)cost.size()==ks[i]);\n\
    \        if(!minimize)for(auto &x:cost)x=-x;\n        _add1(i,cost);\n    }\n\
    \    void _add2(int i,int j,vector<vector<T>> cost){\n        int h=ks[i],w=ks[j];\n\
    \        _add1(j,cost[0]);\n        for(int x=h-1;x>=0;x--)for(int y=0;y<w;y++)cost[x][y]-=cost[0][y];\n\
    \        vector<T> a(h);\n        for(int x=0;x<h;x++)a[x]=cost[x][w-1];\n   \
    \     _add1(i,a);\n        for(int x=0;x<h;x++)for(int y=0;y<w;y++)cost[x][y]-=a[x];\n\
    \        for(int x=1;x<h;x++){\n            for(int y=0;y<w-1;y++){\n        \
    \        T w=cost[x][y]+cost[x-1][y+1]-cost[x-1][y]-cost[x][y+1];\n          \
    \      assert(w>=0); // monge\n                add_edge(id[i][x],id[j][y+1],w);\n\
    \            }\n        }\n    }\n    void add2(int i,int j,vector<vector<T>>\
    \ cost){\n        assert(0<=i&&i<n&&0<=j&&j<n&&i!=j);\n        assert((int)cost.size()==ks[i]);\n\
    \        for(auto &v:cost)assert((int)v.size()==ks[j]);\n        if(!minimize)for(auto\
    \ &v:cost)for(auto &x:v)x=-x;\n        _add2(i,j,cost);\n    }\n    pair<T,vector<int>>\
    \ solve(){\n        Dinic<T> dinic(buf,s,t);\n        for(auto &[p,w]:edges){\n\
    \            auto [u,v]=p;\n            dinic.add_edge(u,v,w);\n        }\n  \
    \      auto [val,cut]=dinic.cut();\n        val+=base;\n        if(!minimize)val=-val;\n\
    \        vector<int> ans(n);\n        for(int i=0;i<n;i++){\n            ans[i]=ks[i]-1;\n\
    \            for(int j=1;j<ks[i];j++)ans[i]-=cut[id[i][j]];\n        }\n     \
    \   return {val,ans};\n    }\n};"
  dependsOn:
  - src/flows/dinic.hpp
  isVerificationFile: false
  path: src/flows/k-ary-optimization.hpp
  requiredBy: []
  timestamp: '2026-10-04 01:45:10+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flows/k-ary-optimization.hpp
layout: document
redirect_from:
- /library/src/flows/k-ary-optimization.hpp
- /library/src/flows/k-ary-optimization.hpp.html
title: src/flows/k-ary-optimization.hpp
---
