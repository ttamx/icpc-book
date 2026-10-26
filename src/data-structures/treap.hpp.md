---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/tree/euler-tour-tree.hpp
    title: src/tree/euler-tour-tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/tree/euler-tour-tree/dynamic_tree_subtree_add_subtree_sum.test.cpp
    title: verify/tree/euler-tour-tree/dynamic_tree_subtree_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structures/treap.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Description: Treap (1-indexed, 0 = null) with lazy reverse and\n * lazy\
    \ add (T needs +, T*int, ==). Weight-0 nodes take a position but\n * no value.\
    \ root/pos use parent pointers (not with P or pending rev).\n * N about $2\\ln\
    \ n$ per op if P.\n */\n\ntemplate<int N,class T,bool P=false>\nstruct Treap{\n\
    \    struct Node{int l,r,p,sz,w,c;bool rev;T val,sum,lz;} t[N];\n    int cnt=0;\n\
    \    int make(T v,int w=1){\n        t[++cnt]={0,0,0,1,w,w,0,v,w?v:T(),T()};return\
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
    \        return k;\n    } // (0-indexed)\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Treap (1-indexed,\
    \ 0 = null) with lazy reverse and\n * lazy add (T needs +, T*int, ==). Weight-0\
    \ nodes take a position but\n * no value. root/pos use parent pointers (not with\
    \ P or pending rev).\n * N about $2\\ln n$ per op if P.\n */\n\ntemplate<int N,class\
    \ T,bool P=false>\nstruct Treap{\n    struct Node{int l,r,p,sz,w,c;bool rev;T\
    \ val,sum,lz;} t[N];\n    int cnt=0;\n    int make(T v,int w=1){\n        t[++cnt]={0,0,0,1,w,w,0,v,w?v:T(),T()};return\
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
    \        return k;\n    } // (0-indexed)\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structures/treap.hpp
  requiredBy:
  - src/tree/euler-tour-tree.hpp
  timestamp: '2026-10-26 16:18:54+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/tree/euler-tour-tree/dynamic_tree_subtree_add_subtree_sum.test.cpp
documentation_of: src/data-structures/treap.hpp
layout: document
redirect_from:
- /library/src/data-structures/treap.hpp
- /library/src/data-structures/treap.hpp.html
title: src/data-structures/treap.hpp
---
