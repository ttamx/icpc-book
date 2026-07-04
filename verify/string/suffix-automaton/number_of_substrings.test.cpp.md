---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/string/suffix-automaton.hpp
    title: src/string/suffix-automaton.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"verify/string/suffix-automaton/number_of_substrings.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n#line\
    \ 2 \"src/contest/template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/string/suffix-automaton.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-06-14\n * Description: Suffix Automaton.\n\
    \ */\n\ntemplate<class STR>\nstruct SuffixAutomaton{\n    using T = typename STR::value_type;\n\
    \    struct Node{\n        map<T,int> nxt;\n        int link,len;\n        Node(int\
    \ link,int len):link(link),len(len){}\n    };\n    vector<Node> nodes;\n    int\
    \ last;\n    SuffixAutomaton():nodes{Node(-1,0)},last(0){}\n    SuffixAutomaton(const\
    \ STR &s):SuffixAutomaton(){\n        for(auto c:s)extend(c);\n    }\n    int\
    \ new_node(int link,int len){\n        nodes.emplace_back(Node(link,len));\n \
    \       return (int)nodes.size()-1;\n    }\n    void extend(T c){\n        int\
    \ cur=new_node(0,nodes[last].len+1);\n        int p=last;\n        while(p!=-1&&!nodes[p].nxt.count(c)){\n\
    \            nodes[p].nxt[c]=cur;\n            p=nodes[p].link;\n        }\n \
    \       if(p!=-1){\n            int q=nodes[p].nxt[c];\n            if(nodes[p].len+1==nodes[q].len){\n\
    \                nodes[cur].link=q;\n            }else{\n                int r=new_node(nodes[q].link,nodes[p].len+1);\n\
    \                nodes[r].nxt=nodes[q].nxt;\n                while(p!=-1&&nodes[p].nxt[c]==q){\n\
    \                    nodes[p].nxt[c]=r;\n                    p=nodes[p].link;\n\
    \                }\n                nodes[q].link=nodes[cur].link=r;\n       \
    \     }\n        }\n        last=cur;\n    }\n    ll distinct_substrings(){\n\
    \        ll res=0;\n        for(int i=1;i<(int)nodes.size();i++)res+=nodes[i].len-nodes[nodes[i].link].len;\n\
    \        return res;\n    }\n};\n\n#line 4 \"verify/string/suffix-automaton/number_of_substrings.test.cpp\"\
    \n\nint main(){\n    string s;\n    cin >> s;\n    SuffixAutomaton sa(s);\n  \
    \  cout << sa.distinct_substrings();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    #include \"src/contest/template.hpp\"\n#include \"src/string/suffix-automaton.hpp\"\
    \n\nint main(){\n    string s;\n    cin >> s;\n    SuffixAutomaton sa(s);\n  \
    \  cout << sa.distinct_substrings();\n}"
  dependsOn:
  - src/contest/template.hpp
  - src/string/suffix-automaton.hpp
  isVerificationFile: true
  path: verify/string/suffix-automaton/number_of_substrings.test.cpp
  requiredBy: []
  timestamp: '2026-07-05 00:41:55+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/string/suffix-automaton/number_of_substrings.test.cpp
layout: document
redirect_from:
- /verify/verify/string/suffix-automaton/number_of_substrings.test.cpp
- /verify/verify/string/suffix-automaton/number_of_substrings.test.cpp.html
title: verify/string/suffix-automaton/number_of_substrings.test.cpp
---
