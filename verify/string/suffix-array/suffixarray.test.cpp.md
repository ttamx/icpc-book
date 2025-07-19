---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/string/suffix-array.hpp
    title: src/string/suffix-array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"verify/string/suffix-array/suffixarray.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n#line 2 \"src/contest/template.hpp\"\
    \n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n#include<ext/pb_ds/tree_policy.hpp>\n\
    \ \nusing namespace std;\nusing namespace __gnu_pbds;\n \nusing ll = long long;\n\
    using db = long double;\nusing vi = vector<int>;\nusing vl = vector<ll>;\nusing\
    \ vd = vector<db>;\nusing pii = pair<int,int>;\nusing pll = pair<ll,ll>;\nusing\
    \ pdd = pair<db,db>;\nconst int INF=0x3fffffff;\nconst ll LINF=0x1fffffffffffffff;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\
    \ \ntemplate<class T>\nusing ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \ \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/string/suffix-array.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-06-14\n * Description: Suffix Array.\n\
    \ */\n\ntemplate<class STR>\nstruct SuffixArray{\n    int n;\n    vector<int>\
    \ sa,isa,lcp;\n    // SparseTable<MinMonoid<int>> st;\n    SuffixArray(){}\n \
    \   SuffixArray(const STR &s){init(s);}\n    void init(const STR &s){\n      \
    \  n=(int)s.size();\n        sa=isa=lcp=vector<int>(n+1);\n        sa[0]=n;\n\
    \        iota(sa.begin()+1,sa.end(),0);\n        sort(sa.begin()+1,sa.end(),[&](int\
    \ i,int j){return s[i]<s[j];});\n        for(int i=1;i<=n;i++){\n            int\
    \ x=sa[i-1],y=sa[i];\n            isa[y]=i>1&&s[x]==s[y]?isa[x]:i;\n        }\n\
    \        for(int len=1;len<=n;len<<=1){\n            vector<int> ps(sa),pi(isa),pos(n+1);\n\
    \            iota(pos.begin(),pos.end(),0);\n            for(auto i:ps)if((i-=len)>=0)sa[pos[isa[i]]++]=i;\n\
    \            for(int i=1;i<=n;i++){\n                int x=sa[i-1],y=sa[i];\n\
    \                isa[y]=pi[x]==pi[y]&&pi[x+len]==pi[y+len]?isa[x]:i;\n       \
    \     }\n        }\n        for(int i=0,k=0;i<n;i++){\n            for(int j=sa[isa[i]-1];j+k<n&&s[j+k]==s[i+k];k++);\n\
    \            lcp[isa[i]]=k;\n            if(k)k--;\n        }\n        // st.init(lcp);\n\
    \    }\n    // int get_lcp(int i,int j){\n    //     if(i==j)return n-i;\n   \
    \ //     auto [l,r]=minmax(isa[i],isa[j]);\n    //     return st.query(l+1,r);\n\
    \    // }\n};\n\n#line 4 \"verify/string/suffix-array/suffixarray.test.cpp\"\n\
    \nint main(){\n    string s;\n    cin >> s;\n    SuffixArray sa(s);\n    for(int\
    \ i=1;i<=s.size();++i)cout << sa.sa[i] << \" \";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n#include\
    \ \"src/contest/template.hpp\"\n#include \"src/string/suffix-array.hpp\"\n\nint\
    \ main(){\n    string s;\n    cin >> s;\n    SuffixArray sa(s);\n    for(int i=1;i<=s.size();++i)cout\
    \ << sa.sa[i] << \" \";\n}"
  dependsOn:
  - src/contest/template.hpp
  - src/string/suffix-array.hpp
  isVerificationFile: true
  path: verify/string/suffix-array/suffixarray.test.cpp
  requiredBy: []
  timestamp: '2025-07-19 14:00:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/string/suffix-array/suffixarray.test.cpp
layout: document
redirect_from:
- /verify/verify/string/suffix-array/suffixarray.test.cpp
- /verify/verify/string/suffix-array/suffixarray.test.cpp.html
title: verify/string/suffix-array/suffixarray.test.cpp
---
