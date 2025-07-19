---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/flows/hopcroft-karp.hpp
    title: src/flows/hopcroft-karp.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"verify/flows/hopcroft-karp/bipartitematching.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#line 2\
    \ \"src/contest/template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n \nusing namespace std;\nusing namespace\
    \ __gnu_pbds;\n \nusing ll = long long;\nusing db = long double;\nusing vi = vector<int>;\n\
    using vl = vector<ll>;\nusing vd = vector<db>;\nusing pii = pair<int,int>;\nusing\
    \ pll = pair<ll,ll>;\nusing pdd = pair<db,db>;\nconst int INF=0x3fffffff;\nconst\
    \ ll LINF=0x1fffffffffffffff;\nconst db DINF=numeric_limits<db>::infinity();\n\
    const db EPS=1e-9;\nconst db PI=acos(db(-1));\n \ntemplate<class T>\nusing ordered_set\
    \ = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \ \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/flows/hopcroft-karp.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-03-31\n * Description: Fast bipartite\
    \ matching algorithm.\n * Time: $O(E\\sqrt{V})$\n */\n\nstruct HopcroftKarp{\n\
    \    int n,m;\n    vector<int> match,lv,ptr;\n    vector<vector<int>> adj;\n \
    \   HopcroftKarp(){}\n    HopcroftKarp(int _n,int _m){init(_n,_m);}\n    void\
    \ init(int _n,int _m){\n        n=_n,m=_m;\n        adj.assign(n+m,vector<int>{});\n\
    \    }\n    void add_edge(int u,int v){\n        adj[u].emplace_back(v+n);\n \
    \   }\n    void bfs(){\n        lv.assign(n,-1);\n        queue<int> q;\n    \
    \    for(int i=0;i<n;i++)if(match[i]==-1){\n            lv[i]=0;\n           \
    \ q.emplace(i);\n        }\n        while(!q.empty()){\n            int u=q.front();\n\
    \            q.pop();\n            for(int v:adj[u])if(match[v]!=-1&&lv[match[v]]==-1){\n\
    \                lv[match[v]]=lv[u]+1;\n                q.emplace(match[v]);\n\
    \            }\n        }\n    }\n    bool dfs(int u){\n        for(int &i=ptr[u];i<adj[u].size();i++){\n\
    \            int v=adj[u][i];\n            if(match[v]==-1||(lv[match[v]]==lv[u]+1&&dfs(match[v]))){\n\
    \                match[u]=v,match[v]=u;\n                return true;\n      \
    \      }\n        }\n        return false;\n    }\n    int max_matching(){\n \
    \       int ans=0,cnt=0;\n        match.assign(n+m,-1);\n        do{\n       \
    \     ptr.assign(n,0);\n            bfs();\n            cnt=0;\n            for(int\
    \ i=0;i<n;i++)if(match[i]==-1&&dfs(i))cnt++;\n            ans+=cnt;\n        }while(cnt);\n\
    \        return ans;\n    }\n};\n#line 4 \"verify/flows/hopcroft-karp/bipartitematching.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,m,e;\n\
    \    cin >> n >> m >> e;\n    HopcroftKarp bm(n,m);\n    for(int i=0;i<e;i++){\n\
    \        int u,v;\n        cin >> u >> v;\n        bm.add_edge(u,v);\n    }\n\
    \    cout << bm.max_matching() << \"\\n\";\n    for(int i=0;i<n;i++){\n      \
    \  if(bm.match[i]!=-1){\n            cout << i << \" \" << bm.match[i]-n << \"\
    \\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ \"src/contest/template.hpp\"\n#include \"src/flows/hopcroft-karp.hpp\"\n\nint\
    \ main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,m,e;\n   \
    \ cin >> n >> m >> e;\n    HopcroftKarp bm(n,m);\n    for(int i=0;i<e;i++){\n\
    \        int u,v;\n        cin >> u >> v;\n        bm.add_edge(u,v);\n    }\n\
    \    cout << bm.max_matching() << \"\\n\";\n    for(int i=0;i<n;i++){\n      \
    \  if(bm.match[i]!=-1){\n            cout << i << \" \" << bm.match[i]-n << \"\
    \\n\";\n        }\n    }\n}"
  dependsOn:
  - src/contest/template.hpp
  - src/flows/hopcroft-karp.hpp
  isVerificationFile: true
  path: verify/flows/hopcroft-karp/bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2025-07-19 14:29:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/flows/hopcroft-karp/bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/verify/flows/hopcroft-karp/bipartitematching.test.cpp
- /verify/verify/flows/hopcroft-karp/bipartitematching.test.cpp.html
title: verify/flows/hopcroft-karp/bipartitematching.test.cpp
---
