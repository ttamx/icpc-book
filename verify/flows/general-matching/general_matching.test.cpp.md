---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/flows/general-matching.hpp
    title: src/flows/general-matching.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/general_matching
    links:
    - https://judge.yosupo.jp/problem/general_matching
  bundledCode: "#line 1 \"verify/flows/general-matching/general_matching.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\n#line\
    \ 2 \"src/contest/template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n \nusing namespace std;\nusing namespace\
    \ __gnu_pbds;\n \nusing ll = long long;\nusing db = long double;\nusing vi = vector<int>;\n\
    using vl = vector<ll>;\nusing vd = vector<db>;\nusing pii = pair<int,int>;\nusing\
    \ pll = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst int INF=0x3fffffff;\nconst\
    \ ll LINF=0x1fffffffffffffff;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const db EPS=1e-9;\nconst db PI=acos(db(-1));\n \ntemplate<class T>\nusing ordered_set\
    \ = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \ \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/flows/general-matching.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2025-09-03\n * Description: General matching\
    \ using blossom algorithm.\n * Time: O(E \\sqrt{V} log_{\\max(2,1+E/V)}).\n */\n\
    \nstruct GeneralMatching{\n    int n;\n    vector<vector<int>> adj;\n    vector<int>\
    \ match,vis,link,fa,dep;\n    queue<int> q;\n    GeneralMatching(int n):n(n),adj(n),match(n,-1),vis(n),link(n),fa(n),dep(n){}\n\
    \    void add_edge(int u,int v){\n        adj[u].emplace_back(v);\n        adj[v].emplace_back(u);\n\
    \    }\n    int fp(int u){\n        while(fa[u]!=u)u=fa[u]=fa[fa[u]];\n      \
    \  return u;\n    }\n    int lca(int u,int v){\n        u=fp(u),v=fp(v);\n   \
    \     while(u!=v){\n            if(dep[u]<dep[v])swap(u,v);\n            u=fp(link[match[u]]);\n\
    \        }\n        return u;\n    }\n    void blossom(int u,int v,int p){\n \
    \       while(fp(u)!=p){\n            link[u]=v;\n            v=match[u];\n  \
    \          if(vis[v]==0){\n                vis[v]=1;\n                q.emplace(v);\n\
    \            }\n            fa[u]=fa[v]=p;\n            u=link[v];\n        }\n\
    \    }\n    int augment(int u){\n        while(!q.empty())q.pop();\n        iota(fa.begin(),fa.end(),0);\n\
    \        fill(vis.begin(),vis.end(),-1);\n        q.emplace(u);\n        vis[u]=1;\n\
    \        dep[u]=0;\n        while(!q.empty()){\n            int u=q.front();\n\
    \            q.pop();\n            for(auto v:adj[u]){\n                if(vis[v]==-1){\n\
    \                    vis[v]=0;\n                    link[v]=u;\n             \
    \       dep[v]=dep[u]+1;\n                    if(match[v]==-1){\n            \
    \            for(int x=v,y=u,z;y!=-1;x=z,y=x==-1?-1:link[x]){\n              \
    \              z=match[y];\n                            match[x]=y;\n        \
    \                    match[y]=x;\n                        }\n                \
    \        return 1;\n                    }\n                    vis[match[v]]=1;\n\
    \                    dep[match[v]]=dep[u]+2;\n                    q.emplace(match[v]);\n\
    \                }else if(vis[v]==1&&fp(u)!=fp(v)){\n                    int p=lca(u,v);\n\
    \                    blossom(u,v,p);\n                    blossom(v,u,p);\n  \
    \              }\n            }\n        }\n        return 0;\n    }\n    int\
    \ max_matching(){\n        int res=0;\n        for(int u=0;u<n;u++){\n       \
    \     if(match[u]!=-1)continue;\n            for(auto v:adj[u]){\n           \
    \     if(match[v]==-1){\n                    match[u]=v;\n                   \
    \ match[v]=u;\n                    res++;\n                    break;\n      \
    \          }\n            }\n        }\n        for(int u=0;u<n;u++){\n      \
    \      if(match[u]==-1){\n                res+=augment(u);\n            }\n  \
    \      }\n        return res;\n    }\n};\n#line 4 \"verify/flows/general-matching/general_matching.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,m;\n\
    \    cin >> n >> m;\n    GeneralMatching gm(n);\n    for(int i=0;i<m;i++){\n \
    \       int u,v;\n        cin >> u >> v;\n        gm.add_edge(u,v);\n    }\n \
    \   cout << gm.max_matching() << \"\\n\";\n    for(int i=0;i<n;i++){\n       \
    \ if(gm.match[i]!=-1&&i<gm.match[i]){\n            cout << i << \" \" << gm.match[i]\
    \ << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\n#include\
    \ \"src/contest/template.hpp\"\n#include \"src/flows/general-matching.hpp\"\n\n\
    int main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,m;\n   \
    \ cin >> n >> m;\n    GeneralMatching gm(n);\n    for(int i=0;i<m;i++){\n    \
    \    int u,v;\n        cin >> u >> v;\n        gm.add_edge(u,v);\n    }\n    cout\
    \ << gm.max_matching() << \"\\n\";\n    for(int i=0;i<n;i++){\n        if(gm.match[i]!=-1&&i<gm.match[i]){\n\
    \            cout << i << \" \" << gm.match[i] << \"\\n\";\n        }\n    }\n\
    }"
  dependsOn:
  - src/contest/template.hpp
  - src/flows/general-matching.hpp
  isVerificationFile: true
  path: verify/flows/general-matching/general_matching.test.cpp
  requiredBy: []
  timestamp: '2025-09-04 09:17:36+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/flows/general-matching/general_matching.test.cpp
layout: document
redirect_from:
- /verify/verify/flows/general-matching/general_matching.test.cpp
- /verify/verify/flows/general-matching/general_matching.test.cpp.html
title: verify/flows/general-matching/general_matching.test.cpp
---
