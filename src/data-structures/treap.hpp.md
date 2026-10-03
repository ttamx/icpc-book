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
  bundledCode: "#line 2 \"src/data-structures/treap.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Description: Implicit treap on a node pool (1-indexed, 0 = null),\n *\
    \ with range sum and lazy range reverse. Merge picks the root with\n * probability\
    \ proportional to size, so no priorities are stored and\n * subtrees can be shared:\
    \ with P=true every write clones the node\n * first (persistent treap, old roots\
    \ stay valid). The instance must be\n * global; N must cover all clones (about\
    \ $2\\ln n$ per op if P).\n * Usage:\n *  Treap<N,ll> T; int root=0; // or Treap<N,ll,true>\
    \ (persistent)\n *  root=T.merge(root,T.make(x)); // push back x\n *  auto [a,b]=T.split(root,k);\
    \ // a = first k elements\n *  root=T.reverse(root,l,r); ll s=T.query(root,l,r);\
    \ // [l,r)\n * Time: $O(\\log N)$ expected per operation\n */\n\ntemplate<int\
    \ N,class T,bool P=false>\nstruct Treap{\n    struct Node{int l,r,sz;bool rev;T\
    \ val,sum;} t[N];\n    int cnt=0;\n    int make(T v){t[++cnt]={0,0,1,0,v,v};return\
    \ cnt;}\n    int cp(int u){ // clone before writing (persistent only)\n      \
    \  if(!P||!u)return u;\n        t[++cnt]=t[u];\n        return cnt;\n    }\n \
    \   void pull(int u){\n        auto &[l,r,sz,rev,val,sum]=t[u];\n        sz=t[l].sz+1+t[r].sz;\n\
    \        sum=t[l].sum+val+t[r].sum;\n    }\n    void flip(int &u){\n        if(!u)return;\n\
    \        u=cp(u),swap(t[u].l,t[u].r),t[u].rev^=1;\n    }\n    void push(int u){\n\
    \        if(t[u].rev)flip(t[u].l),flip(t[u].r),t[u].rev=0;\n    }\n    // first\
    \ k elements | rest\n    pair<int,int> split(int u,int k){\n        if(!u)return\
    \ {0,0};\n        u=cp(u),push(u);\n        if(t[t[u].l].sz>=k){\n           \
    \ auto [a,b]=split(t[u].l,k);\n            t[u].l=b,pull(u);\n            return\
    \ {a,u};\n        }\n        auto [a,b]=split(t[u].r,k-t[t[u].l].sz-1);\n    \
    \    t[u].r=a,pull(u);\n        return {u,b};\n    }\n    int merge(int a,int\
    \ b){\n        if(!a||!b)return a^b;\n        if(int(rng()%(t[a].sz+t[b].sz))<t[a].sz){\n\
    \            a=cp(a),push(a);\n            t[a].r=merge(t[a].r,b),pull(a);\n \
    \           return a;\n        }\n        b=cp(b),push(b);\n        t[b].l=merge(a,t[b].l),pull(b);\n\
    \        return b;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Implicit treap\
    \ on a node pool (1-indexed, 0 = null),\n * with range sum and lazy range reverse.\
    \ Merge picks the root with\n * probability proportional to size, so no priorities\
    \ are stored and\n * subtrees can be shared: with P=true every write clones the\
    \ node\n * first (persistent treap, old roots stay valid). The instance must be\n\
    \ * global; N must cover all clones (about $2\\ln n$ per op if P).\n * Usage:\n\
    \ *  Treap<N,ll> T; int root=0; // or Treap<N,ll,true> (persistent)\n *  root=T.merge(root,T.make(x));\
    \ // push back x\n *  auto [a,b]=T.split(root,k); // a = first k elements\n *\
    \  root=T.reverse(root,l,r); ll s=T.query(root,l,r); // [l,r)\n * Time: $O(\\\
    log N)$ expected per operation\n */\n\ntemplate<int N,class T,bool P=false>\n\
    struct Treap{\n    struct Node{int l,r,sz;bool rev;T val,sum;} t[N];\n    int\
    \ cnt=0;\n    int make(T v){t[++cnt]={0,0,1,0,v,v};return cnt;}\n    int cp(int\
    \ u){ // clone before writing (persistent only)\n        if(!P||!u)return u;\n\
    \        t[++cnt]=t[u];\n        return cnt;\n    }\n    void pull(int u){\n \
    \       auto &[l,r,sz,rev,val,sum]=t[u];\n        sz=t[l].sz+1+t[r].sz;\n    \
    \    sum=t[l].sum+val+t[r].sum;\n    }\n    void flip(int &u){\n        if(!u)return;\n\
    \        u=cp(u),swap(t[u].l,t[u].r),t[u].rev^=1;\n    }\n    void push(int u){\n\
    \        if(t[u].rev)flip(t[u].l),flip(t[u].r),t[u].rev=0;\n    }\n    // first\
    \ k elements | rest\n    pair<int,int> split(int u,int k){\n        if(!u)return\
    \ {0,0};\n        u=cp(u),push(u);\n        if(t[t[u].l].sz>=k){\n           \
    \ auto [a,b]=split(t[u].l,k);\n            t[u].l=b,pull(u);\n            return\
    \ {a,u};\n        }\n        auto [a,b]=split(t[u].r,k-t[t[u].l].sz-1);\n    \
    \    t[u].r=a,pull(u);\n        return {u,b};\n    }\n    int merge(int a,int\
    \ b){\n        if(!a||!b)return a^b;\n        if(int(rng()%(t[a].sz+t[b].sz))<t[a].sz){\n\
    \            a=cp(a),push(a);\n            t[a].r=merge(t[a].r,b),pull(a);\n \
    \           return a;\n        }\n        b=cp(b),push(b);\n        t[b].l=merge(a,t[b].l),pull(b);\n\
    \        return b;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structures/treap.hpp
  requiredBy: []
  timestamp: '2026-10-04 01:15:02+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structures/treap.hpp
layout: document
redirect_from:
- /library/src/data-structures/treap.hpp
- /library/src/data-structures/treap.hpp.html
title: src/data-structures/treap.hpp
---
