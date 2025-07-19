---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
    title: verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/link-cut-tree.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Description: Link Cut Tree (1-indexed)\n */\n\ntemplate<int N,class T>\nstruct\
    \ LinkCutTree{\n    int ch[N][2],par[N],lz[N],rev[N];\n    T val[N],sum[N],rsum[N];\n\
    \    void toggle(int v){\n        if(!v)return;\n        swap(ch[v][0],ch[v][1]);\n\
    \        swap(sum[v],rsum[v]);\n        rev[v]^=1;\n    }\n    void push(int v){\n\
    \        if(!v||!rev[v])return;\n        toggle(ch[v][0]);\n        toggle(ch[v][1]);\n\
    \        rev[v]=0;\n    }\n    void pull(int v){\n        if(!v)return;\n    \
    \    sum[v]=sum[ch[v][0]]+val[v]+sum[ch[v][1]];\n        rsum[v]=rsum[ch[v][0]]+val[v]+rsum[ch[v][1]];\n\
    \    }\n    bool is_root(int v){\n        return ch[par[v]][0]!=v&&ch[par[v]][1]!=v;\n\
    \    }\n    bool pos(int v){\n        return ch[par[v]][1]==v;\n    }\n    void\
    \ rotate(int v){\n        int u=par[v],g=par[u];\n        bool x=pos(v);\n   \
    \     if(!is_root(u))ch[g][pos(u)]=v;\n        ch[u][x]=ch[v][!x];\n        if(ch[u][x])par[ch[u][x]]=u;\n\
    \        ch[v][!x]=u,par[u]=v,par[v]=g;\n        pull(u),pull(v);\n    }\n   \
    \ void splay(int v){\n        if(!v)return;\n        for(push(v);!is_root(v);rotate(v)){\n\
    \            int u=par[v];\n            if(is_root(u))push(u),push(v);\n     \
    \       else push(par[u]),push(u),push(v),rotate(pos(u)==pos(v)?u:v);\n      \
    \  }\n    }\n    void access(int v){\n        for(int u=v,c=0;u;u=par[u]){\n \
    \           splay(u);\n            ch[u][1]=c;\n            pull(c=u);\n     \
    \   }\n        splay(v);\n    }\n    void evert(int v){\n        access(v),toggle(v);\n\
    \    }\n    void link(int u,int v){\n        evert(u);\n        access(v);\n \
    \       par[u]=v;\n    }\n    void cut(int u,int v){\n        evert(u);\n    \
    \    access(v);\n        assert(par[u]==v);\n        ch[v][0]=par[u]=0;\n    \
    \    pull(v);\n    }\n    T aggregate(int u,int v){\n        evert(u);\n     \
    \   access(v);\n        return sum[v];\n    }\n    void set(int u,T v){\n    \
    \    evert(u);\n        val[u]=v;\n        pull(u);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Link Cut Tree\
    \ (1-indexed)\n */\n\ntemplate<int N,class T>\nstruct LinkCutTree{\n    int ch[N][2],par[N],lz[N],rev[N];\n\
    \    T val[N],sum[N],rsum[N];\n    void toggle(int v){\n        if(!v)return;\n\
    \        swap(ch[v][0],ch[v][1]);\n        swap(sum[v],rsum[v]);\n        rev[v]^=1;\n\
    \    }\n    void push(int v){\n        if(!v||!rev[v])return;\n        toggle(ch[v][0]);\n\
    \        toggle(ch[v][1]);\n        rev[v]=0;\n    }\n    void pull(int v){\n\
    \        if(!v)return;\n        sum[v]=sum[ch[v][0]]+val[v]+sum[ch[v][1]];\n \
    \       rsum[v]=rsum[ch[v][0]]+val[v]+rsum[ch[v][1]];\n    }\n    bool is_root(int\
    \ v){\n        return ch[par[v]][0]!=v&&ch[par[v]][1]!=v;\n    }\n    bool pos(int\
    \ v){\n        return ch[par[v]][1]==v;\n    }\n    void rotate(int v){\n    \
    \    int u=par[v],g=par[u];\n        bool x=pos(v);\n        if(!is_root(u))ch[g][pos(u)]=v;\n\
    \        ch[u][x]=ch[v][!x];\n        if(ch[u][x])par[ch[u][x]]=u;\n        ch[v][!x]=u,par[u]=v,par[v]=g;\n\
    \        pull(u),pull(v);\n    }\n    void splay(int v){\n        if(!v)return;\n\
    \        for(push(v);!is_root(v);rotate(v)){\n            int u=par[v];\n    \
    \        if(is_root(u))push(u),push(v);\n            else push(par[u]),push(u),push(v),rotate(pos(u)==pos(v)?u:v);\n\
    \        }\n    }\n    void access(int v){\n        for(int u=v,c=0;u;u=par[u]){\n\
    \            splay(u);\n            ch[u][1]=c;\n            pull(c=u);\n    \
    \    }\n        splay(v);\n    }\n    void evert(int v){\n        access(v),toggle(v);\n\
    \    }\n    void link(int u,int v){\n        evert(u);\n        access(v);\n \
    \       par[u]=v;\n    }\n    void cut(int u,int v){\n        evert(u);\n    \
    \    access(v);\n        assert(par[u]==v);\n        ch[v][0]=par[u]=0;\n    \
    \    pull(v);\n    }\n    T aggregate(int u,int v){\n        evert(u);\n     \
    \   access(v);\n        return sum[v];\n    }\n    void set(int u,T v){\n    \
    \    evert(u);\n        val[u]=v;\n        pull(u);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/link-cut-tree.hpp
  requiredBy: []
  timestamp: '2025-07-19 14:29:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/tree/link-cut-tree/dynamic_tree_vertex_add_path_sum.test.cpp
documentation_of: src/tree/link-cut-tree.hpp
layout: document
redirect_from:
- /library/src/tree/link-cut-tree.hpp
- /library/src/tree/link-cut-tree.hpp.html
title: src/tree/link-cut-tree.hpp
---
