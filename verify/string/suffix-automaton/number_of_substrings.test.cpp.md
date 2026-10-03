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
    \ __gnu_pbds;\n\n#define pb push_back\n#define eb emplace_back\n\n#define ALL(a)\
    \ a.begin(),a.end()\n#define RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n\
    #define RSORT(a) sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n#define UNI(a)\
    \ a.erase(unique(ALL(a)),a.end())\n#define SZ(a) (int)(a.size())\n#define LB(a,x)\
    \ (int)(lower_bound(ALL(a),x)-a.begin())\n#define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n\
    #define MIN(a) *min_element(ALL(a))\n#define MAX(a) *max_element(ALL(a))\n\nusing\
    \ ll = long long;\nusing db = long double;\nusing i128 = __int128_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\n\nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst int MOD=998244353;\nconst\
    \ int MOD2=1000000007;\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\ntemplate<class\
    \ T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\ntemplate<class T,class\
    \ U>\nbool chmin(T &a,U b){return b<a?a=b,1:0;}\ntemplate<class T,class U>\nbool\
    \ chmax(T &a,U b){return a<b?a=b,1:0;}\ntemplate<class T,class U>\nT SUM(const\
    \ U &a){return accumulate(ALL(a),T{});}\n\ntemplate<class T>\nusing ordered_set\
    \ = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/string/suffix-automaton.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-06-14\n * Description: Suffix Automaton\
    \ on a node pool (root = 1, 0 = null).\n * Call extend(c) with c in [0,A) for\
    \ each character. Instance must be\n * global; N > 2|s|. For a large alphabet\
    \ use map<int,int> nxt[N].\n * Time: $O(|s| \\cdot A)$\n */\n\ntemplate<int N,int\
    \ A=26>\nstruct SuffixAutomaton{\n    int nxt[N][A],link[N],len[N],occ[N],cnt=1,last=1;\n\
    \    void extend(int c){\n        int cur=++cnt,p=last;\n        len[cur]=len[last]+1,occ[cur]=1;\n\
    \        for(;p&&!nxt[p][c];p=link[p])nxt[p][c]=cur;\n        if(!p)link[cur]=1;\n\
    \        else if(int q=nxt[p][c];len[p]+1==len[q])link[cur]=q;\n        else{\n\
    \            int r=++cnt;\n            len[r]=len[p]+1,link[r]=link[q];\n    \
    \        copy(nxt[q],nxt[q]+A,nxt[r]);\n            for(;p&&nxt[p][c]==q;p=link[p])nxt[p][c]=r;\n\
    \            link[q]=link[cur]=r;\n        }\n        last=cur;\n    }\n    //\
    \ ---- usages ----\n    // # distinct non-empty substrings\n    ll distinct_substrings(){\n\
    \        ll res=0;\n        for(int i=2;i<=cnt;i++)res+=len[i]-len[link[i]];\n\
    \        return res;\n    }\n    // states sorted by len (shortest first), counting\
    \ sort;\n    // link[u] is shorter than u, nxt[u][c] is longer\n    vector<int>\
    \ order(){\n        vector<int> c(len[last]+1),o(cnt);\n        for(int i=1;i<=cnt;i++)c[len[i]]++;\n\
    \        for(int i=1;i<SZ(c);i++)c[i]+=c[i-1];\n        for(int i=cnt;i>=1;i--)o[--c[len[i]]]=i;\n\
    \        return o;\n    }\n    // occ[u] = # occurrences (endpos size) of u's\
    \ strings,\n    // call once after building\n    void calc_occ(){\n        auto\
    \ o=order();\n        for(int i=cnt-1;i>0;i--)occ[link[o[i]]]+=occ[o[i]];\n  \
    \  }\n    // # occurrences of non-empty t in s (needs calc_occ)\n    int count(const\
    \ string &t){\n        int u=1;\n        for(char x:t)if(!(u=nxt[u][x-'a']))return\
    \ 0;\n        return occ[u];\n    }\n    // longest common substring of s and\
    \ t\n    int lcs(const string &t){\n        int u=1,l=0,res=0;\n        for(char\
    \ x:t){\n            int c=x-'a';\n            while(u>1&&!nxt[u][c])u=link[u],l=len[u];\n\
    \            if(nxt[u][c])u=nxt[u][c],l++;\n            res=max(res,l);\n    \
    \    }\n        return res;\n    }\n    // k-th (1-indexed) lexicographically\
    \ smallest distinct\n    // substring, needs 1 <= k <= distinct_substrings()\n\
    \    string kth(ll k){\n        auto o=order();\n        vector<ll> dp(cnt+1,1);\
    \ // # paths from u (incl. empty)\n        for(int i=cnt-1;i>=0;i--)for(int c=0;c<A;c++)\n\
    \            if(int v=nxt[o[i]][c])dp[o[i]]+=dp[v];\n        string res;\n   \
    \     for(int u=1;k>0;){\n            for(int c=0;c<A;c++)if(int v=nxt[u][c]){\n\
    \                if(dp[v]>=k){res+=char('a'+c),u=v,k--;break;}\n             \
    \   k-=dp[v];\n            }\n        }\n        return res;\n    }\n};\n#line\
    \ 4 \"verify/string/suffix-automaton/number_of_substrings.test.cpp\"\n\nSuffixAutomaton<1000005>\
    \ sa;\n\nint main(){\n    string s;\n    cin >> s;\n    for(char c:s)sa.extend(c-'a');\n\
    \    cout << sa.distinct_substrings();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    #include \"src/contest/template.hpp\"\n#include \"src/string/suffix-automaton.hpp\"\
    \n\nSuffixAutomaton<1000005> sa;\n\nint main(){\n    string s;\n    cin >> s;\n\
    \    for(char c:s)sa.extend(c-'a');\n    cout << sa.distinct_substrings();\n}"
  dependsOn:
  - src/contest/template.hpp
  - src/string/suffix-automaton.hpp
  isVerificationFile: true
  path: verify/string/suffix-automaton/number_of_substrings.test.cpp
  requiredBy: []
  timestamp: '2026-10-03 23:41:23+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/string/suffix-automaton/number_of_substrings.test.cpp
layout: document
redirect_from:
- /verify/verify/string/suffix-automaton/number_of_substrings.test.cpp
- /verify/verify/string/suffix-automaton/number_of_substrings.test.cpp.html
title: verify/string/suffix-automaton/number_of_substrings.test.cpp
---
