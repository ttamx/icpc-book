---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
    title: verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/tree/link-cut-tree/dynamic_tree_vertex_set_path_composite.test.cpp
    title: verify/tree/link-cut-tree/dynamic_tree_vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/link-cut-tree.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Description: Link Cut Tree (1-indexed)\n */\n\ntemplate<int N,class T>\nstruct\
    \ LinkCutTree{\n    int ch[N][2],par[N],rev[N];\n    T val[N],sum[N],rsum[N],lz[N];\n\
    \    void toggle(int v){\n        if(!v)return;\n        swap(ch[v][0],ch[v][1]),swap(sum[v],rsum[v]),rev[v]^=1;\n\
    \    }\n    void apply(int v,T x){\n        if(!v)return;\n        val[v]=val[v]+x,lz[v]=lz[v]+x;\n\
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
    \    void set(int u,T v){reroot(u),val[u]=v,pull(u);}\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Link Cut Tree\
    \ (1-indexed)\n */\n\ntemplate<int N,class T>\nstruct LinkCutTree{\n    int ch[N][2],par[N],rev[N];\n\
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
    \    void set(int u,T v){reroot(u),val[u]=v,pull(u);}\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/link-cut-tree.hpp
  requiredBy: []
  timestamp: '2026-10-26 16:18:54+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
  - verify/tree/link-cut-tree/dynamic_tree_vertex_set_path_composite.test.cpp
documentation_of: src/tree/link-cut-tree.hpp
layout: document
redirect_from:
- /library/src/tree/link-cut-tree.hpp
- /library/src/tree/link-cut-tree.hpp.html
title: src/tree/link-cut-tree.hpp
---
