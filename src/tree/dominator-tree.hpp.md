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
  bundledCode: "#line 2 \"src/tree/dominator-tree.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Description: Dominator tree of a directed graph from root $r$\n * (Lengauer-Tarjan).\
    \ Returns idom, with idom[r]=r and -1 for nodes\n * unreachable from $r$. Helpers\
    \ for common queries in namespace domtree.\n * Time: $O((N+M)\\log N)$\n */\n\n\
    // u dominates v: every path r->v passes through u.\n// idom(v): the strict dominator\
    \ of v closest to v.\n// e(u) = DFS preorder index; the code works in this numbering.\n\
    // g: 0-indexed, g[u] = out-neighbours of u\nvector<int> dominator_tree(const\
    \ vector<vector<int>> &g,int r){\n    int n=g.size(),t=0;\n    vector<int> id(n,-1),ord,p(n),it(n),st{r};\n\
    \    id[r]=t++,ord.push_back(r);\n    while(!st.empty()){ // iterative DFS, p\
    \ = DFS parent\n        int u=st.back();\n        if(it[u]==SZ(g[u]))st.pop_back();\n\
    \        else if(int v=g[u][it[u]++];id[v]<0)\n            p[id[v]=t++]=id[u],ord.pb(v),st.pb(v);\n\
    \    }\n    vector<vector<int>> rg(t),bk(t);\n    for(int u=0;u<n;u++)if(id[u]>=0)\n\
    \        for(int v:g[u])if(id[v]>=0)rg[id[v]].push_back(id[u]);\n    vector<int>\
    \ sd(t),lb(t),f(t),dom(t),path;\n    iota(ALL(sd),0),lb=f=sd;\n    auto eval=[&](int\
    \ v){ // min sdom label on DSU path\n        if(f[v]==v)return v;\n        for(int\
    \ x=v;f[f[x]]!=f[x];x=f[x])path.push_back(x);\n        for(;!path.empty();path.pop_back()){\n\
    \            int y=path.back();\n            if(sd[lb[f[y]]]<sd[lb[y]])lb[y]=lb[f[y]];\n\
    \            f[y]=f[f[y]];\n        }\n        return lb[v];\n    };\n    // sdom(u)\
    \ = v with min e(v) having a path v=w0..wk=u with\n    // e(wi)>e(u) for 0<i<k;\
    \ it is a proper DFS-tree ancestor.\n    // x(u) = node on tree path (sdom(u),u]\
    \ with min sdom(x).\n    // x(u)==u -> idom(u)=sdom(u), else idom(u)=idom(x(u)).\n\
    \    for(int w=t-1;w>0;w--){\n        for(int v:rg[w])sd[w]=min(sd[w],sd[eval(v)]);\n\
    \        bk[sd[w]].push_back(w),f[w]=p[w];\n        for(int v:bk[p[w]]){ // eval(v)\
    \ = x(v)\n            int u=eval(v);\n            dom[v]=sd[u]<sd[v]?u:p[w];\n\
    \        }\n        bk[p[w]].clear();\n    }\n    vector<int> res(n,-1);\n   \
    \ res[r]=r;\n    for(int w=1;w<t;w++){ // dom[w]=x(w) -> idom(x(w))\n        if(dom[w]!=sd[w])dom[w]=dom[dom[w]];\n\
    \        res[ord[w]]=ord[dom[w]];\n    }\n    return res;\n}\n\n// usage helpers,\
    \ idom = dominator_tree(g,r)\nnamespace domtree{\n    // children lists of the\
    \ dominator tree (edge idom[v]->v)\n    vector<vector<int>> children(const vector<int>\
    \ &idom){\n        int n=idom.size();\n        vector<vector<int>> ch(n);\n  \
    \      for(int v=0;v<n;v++)\n            if(idom[v]>=0&&idom[v]!=v)ch[idom[v]].pb(v);\n\
    \        return ch;\n    }\n    // O(1) \"u dominates v\" via tin/tout on the\
    \ dominator tree\n    // (u is an ancestor of v), false if v is unreachable\n\
    \    struct Dominates{\n        vector<int> tin,tout;\n        Dominates(const\
    \ vector<int> &idom,int r){\n            auto ch=children(idom);\n           \
    \ int n=idom.size(),T=0;\n            tin.assign(n,-1),tout.assign(n,-1);\n  \
    \          vector<int> st{r},it(n);\n            tin[r]=T++;\n            while(!st.empty()){\
    \ // iterative DFS\n                int u=st.back();\n                if(it[u]==SZ(ch[u]))tout[u]=T++,st.pop_back();\n\
    \                else{\n                    int v=ch[u][it[u]++];\n          \
    \          tin[v]=T++,st.pb(v);\n                }\n            }\n        }\n\
    \        bool operator()(int u,int v){\n            if(tin[v]<0)return false;\n\
    \            return tin[u]<=tin[v]&&tout[v]<=tout[u];\n        }\n    };\n   \
    \ // nodes on every r->t path (critical nodes), t up to r;\n    // size = number\
    \ of dominators of t, empty if unreachable\n    vector<int> critical(const vector<int>\
    \ &idom,int t){\n        vector<int> res;\n        if(idom[t]<0)return res;\n\
    \        for(;;t=idom[t]){\n            res.pb(t);\n            if(idom[t]==t)break;\n\
    \        }\n        return res;\n    }\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Dominator tree\
    \ of a directed graph from root $r$\n * (Lengauer-Tarjan). Returns idom, with\
    \ idom[r]=r and -1 for nodes\n * unreachable from $r$. Helpers for common queries\
    \ in namespace domtree.\n * Time: $O((N+M)\\log N)$\n */\n\n// u dominates v:\
    \ every path r->v passes through u.\n// idom(v): the strict dominator of v closest\
    \ to v.\n// e(u) = DFS preorder index; the code works in this numbering.\n// g:\
    \ 0-indexed, g[u] = out-neighbours of u\nvector<int> dominator_tree(const vector<vector<int>>\
    \ &g,int r){\n    int n=g.size(),t=0;\n    vector<int> id(n,-1),ord,p(n),it(n),st{r};\n\
    \    id[r]=t++,ord.push_back(r);\n    while(!st.empty()){ // iterative DFS, p\
    \ = DFS parent\n        int u=st.back();\n        if(it[u]==SZ(g[u]))st.pop_back();\n\
    \        else if(int v=g[u][it[u]++];id[v]<0)\n            p[id[v]=t++]=id[u],ord.pb(v),st.pb(v);\n\
    \    }\n    vector<vector<int>> rg(t),bk(t);\n    for(int u=0;u<n;u++)if(id[u]>=0)\n\
    \        for(int v:g[u])if(id[v]>=0)rg[id[v]].push_back(id[u]);\n    vector<int>\
    \ sd(t),lb(t),f(t),dom(t),path;\n    iota(ALL(sd),0),lb=f=sd;\n    auto eval=[&](int\
    \ v){ // min sdom label on DSU path\n        if(f[v]==v)return v;\n        for(int\
    \ x=v;f[f[x]]!=f[x];x=f[x])path.push_back(x);\n        for(;!path.empty();path.pop_back()){\n\
    \            int y=path.back();\n            if(sd[lb[f[y]]]<sd[lb[y]])lb[y]=lb[f[y]];\n\
    \            f[y]=f[f[y]];\n        }\n        return lb[v];\n    };\n    // sdom(u)\
    \ = v with min e(v) having a path v=w0..wk=u with\n    // e(wi)>e(u) for 0<i<k;\
    \ it is a proper DFS-tree ancestor.\n    // x(u) = node on tree path (sdom(u),u]\
    \ with min sdom(x).\n    // x(u)==u -> idom(u)=sdom(u), else idom(u)=idom(x(u)).\n\
    \    for(int w=t-1;w>0;w--){\n        for(int v:rg[w])sd[w]=min(sd[w],sd[eval(v)]);\n\
    \        bk[sd[w]].push_back(w),f[w]=p[w];\n        for(int v:bk[p[w]]){ // eval(v)\
    \ = x(v)\n            int u=eval(v);\n            dom[v]=sd[u]<sd[v]?u:p[w];\n\
    \        }\n        bk[p[w]].clear();\n    }\n    vector<int> res(n,-1);\n   \
    \ res[r]=r;\n    for(int w=1;w<t;w++){ // dom[w]=x(w) -> idom(x(w))\n        if(dom[w]!=sd[w])dom[w]=dom[dom[w]];\n\
    \        res[ord[w]]=ord[dom[w]];\n    }\n    return res;\n}\n\n// usage helpers,\
    \ idom = dominator_tree(g,r)\nnamespace domtree{\n    // children lists of the\
    \ dominator tree (edge idom[v]->v)\n    vector<vector<int>> children(const vector<int>\
    \ &idom){\n        int n=idom.size();\n        vector<vector<int>> ch(n);\n  \
    \      for(int v=0;v<n;v++)\n            if(idom[v]>=0&&idom[v]!=v)ch[idom[v]].pb(v);\n\
    \        return ch;\n    }\n    // O(1) \"u dominates v\" via tin/tout on the\
    \ dominator tree\n    // (u is an ancestor of v), false if v is unreachable\n\
    \    struct Dominates{\n        vector<int> tin,tout;\n        Dominates(const\
    \ vector<int> &idom,int r){\n            auto ch=children(idom);\n           \
    \ int n=idom.size(),T=0;\n            tin.assign(n,-1),tout.assign(n,-1);\n  \
    \          vector<int> st{r},it(n);\n            tin[r]=T++;\n            while(!st.empty()){\
    \ // iterative DFS\n                int u=st.back();\n                if(it[u]==SZ(ch[u]))tout[u]=T++,st.pop_back();\n\
    \                else{\n                    int v=ch[u][it[u]++];\n          \
    \          tin[v]=T++,st.pb(v);\n                }\n            }\n        }\n\
    \        bool operator()(int u,int v){\n            if(tin[v]<0)return false;\n\
    \            return tin[u]<=tin[v]&&tout[v]<=tout[u];\n        }\n    };\n   \
    \ // nodes on every r->t path (critical nodes), t up to r;\n    // size = number\
    \ of dominators of t, empty if unreachable\n    vector<int> critical(const vector<int>\
    \ &idom,int t){\n        vector<int> res;\n        if(idom[t]<0)return res;\n\
    \        for(;;t=idom[t]){\n            res.pb(t);\n            if(idom[t]==t)break;\n\
    \        }\n        return res;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/dominator-tree.hpp
  requiredBy: []
  timestamp: '2026-10-03 23:15:31+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/tree/dominator-tree.hpp
layout: document
redirect_from:
- /library/src/tree/dominator-tree.hpp
- /library/src/tree/dominator-tree.hpp.html
title: src/tree/dominator-tree.hpp
---
