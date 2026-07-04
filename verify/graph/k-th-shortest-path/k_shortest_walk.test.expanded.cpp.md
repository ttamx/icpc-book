---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/k_shortest_walk
    links:
    - https://judge.yosupo.jp/problem/k_shortest_walk
  bundledCode: "#line 1 \"verify/graph/k-th-shortest-path/k_shortest_walk.test.expanded.cpp\"\
    \n#line 1 \"verify\\\\graph\\\\k-th-shortest-path\\\\k_shortest_walk.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/k_shortest_walk\"\n#line 2\
    \ \"src\\\\contest\\\\template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n \nusing namespace std;\nusing namespace\
    \ __gnu_pbds;\n\n#define pb push_back\n#define eb emplace_back\n#define mp make_pair\n\
    #define mt make_tuple\n#define fi first\n#define se second\n\n#define ALL(a) a.begin(),a.end()\n\
    #define RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n#define RSORT(a)\
    \ sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n#define UNI(a) a.erase(unique(ALL(a)),a.end())\n\
    #define SZ(a) (int)(a.size())\n#define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n\
    #define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n#define MIN(a) *min_element(ALL(a))\n\
    #define MAX(a) *max_element(ALL(a))\n\nusing ll = long long;\nusing db = long\
    \ double;\nusing i128 = __int128_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    \nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const int MOD=998244353;\nconst int MOD2=1000000007;\nconst db EPS=1e-9;\nconst\
    \ db PI=acos(db(-1));\n\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
    \n#define vv(T,a,n,...) vector<vector<T>> a(n,vector<T>(__VA_ARGS__))\n#define\
    \ vvv(T,a,n,m,...) vector<vector<vector<T>>> a(n,vector<vector<T>>(m,vector<T>(__VA_ARGS__)))\n\
    #define vvvv(T,a,n,m,k,...) vector<vector<vector<vector<T>>>> a(n,vector<vector<vector<T>>>(m,vector<vector<T>>(k,vector<T>(__VA_ARGS__))))\n\
    \ntemplate<class T,class U>\nbool chmin(T &a,U b){return b<a?a=b,1:0;}\ntemplate<class\
    \ T,class U>\nbool chmax(T &a,U b){return a<b?a=b,1:0;}\ntemplate<class T,class\
    \ U>\nT SUM(const U &a){return accumulate(ALL(a),T{});}\n\ntemplate<class T>\n\
    using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src\\\
    \\graph\\\\k-th-shortest-path.hpp\"\n\n/**\n * Author: Teetat T.\n * Description:\
    \ K-th shortest path\n */\n\nvector<ll> kth_shortest_path(vector<vector<pair<int,ll>>>\
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
    }\n#line 4 \"verify\\\\graph\\\\k-th-shortest-path\\\\k_shortest_walk.test.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,m,s,t,k;\n    cin >> n >> m >> s >> t >> k;\n    vector<vector<pair<int,ll>>>\
    \ adj(n);\n    for(int i=0;i<m;i++){\n        int u,v,w;\n        cin >> u >>\
    \ v >> w;\n        adj[u].emplace_back(v,w);\n    }\n    auto ans=kth_shortest_path(adj,s,t,k);\n\
    \    ans.resize(k,-1);\n    for(auto x:ans)cout << x << \"\\n\";\n}\n"
  code: "#line 1 \"verify\\\\graph\\\\k-th-shortest-path\\\\k_shortest_walk.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/k_shortest_walk\"\n#line 2\
    \ \"src\\\\contest\\\\template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n \nusing namespace std;\nusing namespace\
    \ __gnu_pbds;\n\n#define pb push_back\n#define eb emplace_back\n#define mp make_pair\n\
    #define mt make_tuple\n#define fi first\n#define se second\n\n#define ALL(a) a.begin(),a.end()\n\
    #define RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n#define RSORT(a)\
    \ sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n#define UNI(a) a.erase(unique(ALL(a)),a.end())\n\
    #define SZ(a) (int)(a.size())\n#define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n\
    #define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n#define MIN(a) *min_element(ALL(a))\n\
    #define MAX(a) *max_element(ALL(a))\n\nusing ll = long long;\nusing db = long\
    \ double;\nusing i128 = __int128_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    \nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const int MOD=998244353;\nconst int MOD2=1000000007;\nconst db EPS=1e-9;\nconst\
    \ db PI=acos(db(-1));\n\ntemplate<class T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\
    \n#define vv(T,a,n,...) vector<vector<T>> a(n,vector<T>(__VA_ARGS__))\n#define\
    \ vvv(T,a,n,m,...) vector<vector<vector<T>>> a(n,vector<vector<T>>(m,vector<T>(__VA_ARGS__)))\n\
    #define vvvv(T,a,n,m,k,...) vector<vector<vector<vector<T>>>> a(n,vector<vector<vector<T>>>(m,vector<vector<T>>(k,vector<T>(__VA_ARGS__))))\n\
    \ntemplate<class T,class U>\nbool chmin(T &a,U b){return b<a?a=b,1:0;}\ntemplate<class\
    \ T,class U>\nbool chmax(T &a,U b){return a<b?a=b,1:0;}\ntemplate<class T,class\
    \ U>\nT SUM(const U &a){return accumulate(ALL(a),T{});}\n\ntemplate<class T>\n\
    using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src\\\
    \\graph\\\\k-th-shortest-path.hpp\"\n\n/**\n * Author: Teetat T.\n * Description:\
    \ K-th shortest path\n */\n\nvector<ll> kth_shortest_path(vector<vector<pair<int,ll>>>\
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
    }\n#line 4 \"verify\\\\graph\\\\k-th-shortest-path\\\\k_shortest_walk.test.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,m,s,t,k;\n    cin >> n >> m >> s >> t >> k;\n    vector<vector<pair<int,ll>>>\
    \ adj(n);\n    for(int i=0;i<m;i++){\n        int u,v,w;\n        cin >> u >>\
    \ v >> w;\n        adj[u].emplace_back(v,w);\n    }\n    auto ans=kth_shortest_path(adj,s,t,k);\n\
    \    ans.resize(k,-1);\n    for(auto x:ans)cout << x << \"\\n\";\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/graph/k-th-shortest-path/k_shortest_walk.test.expanded.cpp
  requiredBy: []
  timestamp: '2026-07-05 00:41:55+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/k-th-shortest-path/k_shortest_walk.test.expanded.cpp
layout: document
redirect_from:
- /verify/verify/graph/k-th-shortest-path/k_shortest_walk.test.expanded.cpp
- /verify/verify/graph/k-th-shortest-path/k_shortest_walk.test.expanded.cpp.html
title: verify/graph/k-th-shortest-path/k_shortest_walk.test.expanded.cpp
---
