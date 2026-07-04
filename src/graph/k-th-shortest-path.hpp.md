---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/k-th-shortest-path/k_shortest_walk.test.cpp
    title: verify/graph/k-th-shortest-path/k_shortest_walk.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/k-th-shortest-path.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Description: K-th shortest path\n */\n\nvector<ll> kth_shortest_path(vector<vector<pair<int,ll>>>\
    \ &adj,int s,int t,int k){\n    int n=adj.size();\n    vector<vector<pair<int,ll>>>\
    \ radj(n);\n    for(int u=0;u<n;u++)for(auto [v,w]:adj[u])radj[v].emplace_back(u,w);\n\
    \    using P = pair<ll,int>;\n    priority_queue<P,vector<P>,greater<P>> pq;\n\
    \    vector<ll> dist(n,LINF);\n    vector<int> par(n,-1);\n    pq.emplace(dist[t]=0,t);\n\
    \    while(!pq.empty()){\n        auto [d,u]=pq.top();pq.pop();\n        if(d>dist[u])continue;\n\
    \        for(auto [v,w]:radj[u])if(d+w<dist[v])pq.emplace(dist[v]=d+w,v),par[v]=u;\n\
    \    }\n    if(dist[s]==LINF)return {};\n    struct Node{\n        ll val;\n \
    \       int id,rank,l,r;\n    };\n    vector<Node> nodes;\n    auto new_node=[&](ll\
    \ val,int id,int rank,int l,int r){\n        nodes.emplace_back(Node{val,id,rank,l,r});\n\
    \        return (int)nodes.size()-1;\n    };\n    function<int(int,ll,int)> insert=[&](int\
    \ t,ll val,int id){\n        if(t==-1||val<nodes[t].val)return new_node(val,id,0,t,-1);\n\
    \        int l=nodes[t].l,r=insert(nodes[t].r,val,id);\n        if(l==-1||nodes[r].rank>nodes[l].rank)swap(l,r);\n\
    \        return new_node(nodes[t].val,nodes[t].id,r!=-1?nodes[r].rank+1:0,l,r);\n\
    \    };\n    vector<int> ptr(n,-1);\n    vector<vector<int>> ch(n);\n    for(int\
    \ i=0;i<n;i++)if(par[i]!=-1)ch[par[i]].emplace_back(i);\n    queue<int> q;\n \
    \   q.emplace(t);\n    while(!q.empty()){\n        int u=q.front();q.pop();\n\
    \        bool f=false;\n        for(auto [v,w]:adj[u])if(dist[v]<LINF){\n    \
    \        ll c=w+dist[v]-dist[u];\n            if(!f&&!c&&v==par[u]){\n       \
    \         f=true;\n                continue;\n            }\n            ptr[u]=insert(ptr[u],c,v);\n\
    \        }\n        for(auto v:ch[u]){\n            ptr[v]=ptr[u];\n         \
    \   q.emplace(v);\n        }\n    }\n    vector<ll> ans{dist[s]};\n    if(ptr[s]==-1)return\
    \ ans;\n    pq.emplace(dist[s]+nodes[ptr[s]].val,ptr[s]);\n    while(!pq.empty()&&ans.size()<k){\n\
    \        auto [d,u]=pq.top();pq.pop();\n        ans.emplace_back(d);\n       \
    \ ll val=nodes[u].val;\n        int v=nodes[u].id,l=nodes[u].l,r=nodes[u].r;\n\
    \        if(ptr[v]!=-1)pq.emplace(d+nodes[ptr[v]].val,ptr[v]);\n        if(l!=-1)pq.emplace(d+nodes[l].val-val,l);\n\
    \        if(r!=-1)pq.emplace(d+nodes[r].val-val,r);\n    }\n    return ans;\n\
    }\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: K-th shortest\
    \ path\n */\n\nvector<ll> kth_shortest_path(vector<vector<pair<int,ll>>> &adj,int\
    \ s,int t,int k){\n    int n=adj.size();\n    vector<vector<pair<int,ll>>> radj(n);\n\
    \    for(int u=0;u<n;u++)for(auto [v,w]:adj[u])radj[v].emplace_back(u,w);\n  \
    \  using P = pair<ll,int>;\n    priority_queue<P,vector<P>,greater<P>> pq;\n \
    \   vector<ll> dist(n,LINF);\n    vector<int> par(n,-1);\n    pq.emplace(dist[t]=0,t);\n\
    \    while(!pq.empty()){\n        auto [d,u]=pq.top();pq.pop();\n        if(d>dist[u])continue;\n\
    \        for(auto [v,w]:radj[u])if(d+w<dist[v])pq.emplace(dist[v]=d+w,v),par[v]=u;\n\
    \    }\n    if(dist[s]==LINF)return {};\n    struct Node{\n        ll val;\n \
    \       int id,rank,l,r;\n    };\n    vector<Node> nodes;\n    auto new_node=[&](ll\
    \ val,int id,int rank,int l,int r){\n        nodes.emplace_back(Node{val,id,rank,l,r});\n\
    \        return (int)nodes.size()-1;\n    };\n    function<int(int,ll,int)> insert=[&](int\
    \ t,ll val,int id){\n        if(t==-1||val<nodes[t].val)return new_node(val,id,0,t,-1);\n\
    \        int l=nodes[t].l,r=insert(nodes[t].r,val,id);\n        if(l==-1||nodes[r].rank>nodes[l].rank)swap(l,r);\n\
    \        return new_node(nodes[t].val,nodes[t].id,r!=-1?nodes[r].rank+1:0,l,r);\n\
    \    };\n    vector<int> ptr(n,-1);\n    vector<vector<int>> ch(n);\n    for(int\
    \ i=0;i<n;i++)if(par[i]!=-1)ch[par[i]].emplace_back(i);\n    queue<int> q;\n \
    \   q.emplace(t);\n    while(!q.empty()){\n        int u=q.front();q.pop();\n\
    \        bool f=false;\n        for(auto [v,w]:adj[u])if(dist[v]<LINF){\n    \
    \        ll c=w+dist[v]-dist[u];\n            if(!f&&!c&&v==par[u]){\n       \
    \         f=true;\n                continue;\n            }\n            ptr[u]=insert(ptr[u],c,v);\n\
    \        }\n        for(auto v:ch[u]){\n            ptr[v]=ptr[u];\n         \
    \   q.emplace(v);\n        }\n    }\n    vector<ll> ans{dist[s]};\n    if(ptr[s]==-1)return\
    \ ans;\n    pq.emplace(dist[s]+nodes[ptr[s]].val,ptr[s]);\n    while(!pq.empty()&&ans.size()<k){\n\
    \        auto [d,u]=pq.top();pq.pop();\n        ans.emplace_back(d);\n       \
    \ ll val=nodes[u].val;\n        int v=nodes[u].id,l=nodes[u].l,r=nodes[u].r;\n\
    \        if(ptr[v]!=-1)pq.emplace(d+nodes[ptr[v]].val,ptr[v]);\n        if(l!=-1)pq.emplace(d+nodes[l].val-val,l);\n\
    \        if(r!=-1)pq.emplace(d+nodes[r].val-val,r);\n    }\n    return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/k-th-shortest-path.hpp
  requiredBy: []
  timestamp: '2026-07-05 00:41:55+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/k-th-shortest-path/k_shortest_walk.test.cpp
documentation_of: src/graph/k-th-shortest-path.hpp
layout: document
redirect_from:
- /library/src/graph/k-th-shortest-path.hpp
- /library/src/graph/k-th-shortest-path.hpp.html
title: src/graph/k-th-shortest-path.hpp
---
