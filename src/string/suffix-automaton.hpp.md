---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/string/suffix-automaton/number_of_substrings.test.cpp
    title: verify/string/suffix-automaton/number_of_substrings.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/suffix-automaton.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-06-14\n * Description: Suffix Automaton on a node pool (root\
    \ = 1, 0 = null).\n * Call extend(c) with c in [0,A) for each character. Instance\
    \ must be\n * global; N > 2|s|. For a large alphabet use map<int,int> nxt[N].\n\
    \ * Time: $O(|s| \\cdot A)$\n */\n\ntemplate<int N,int A=26>\nstruct SuffixAutomaton{\n\
    \    int nxt[N][A],link[N],len[N],occ[N],cnt=1,last=1;\n    void extend(int c){\n\
    \        int cur=++cnt,p=last;\n        len[cur]=len[last]+1,occ[cur]=1;\n   \
    \     for(;p&&!nxt[p][c];p=link[p])nxt[p][c]=cur;\n        if(!p)link[cur]=1;\n\
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
    \   k-=dp[v];\n            }\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-14\n * Description:\
    \ Suffix Automaton on a node pool (root = 1, 0 = null).\n * Call extend(c) with\
    \ c in [0,A) for each character. Instance must be\n * global; N > 2|s|. For a\
    \ large alphabet use map<int,int> nxt[N].\n * Time: $O(|s| \\cdot A)$\n */\n\n\
    template<int N,int A=26>\nstruct SuffixAutomaton{\n    int nxt[N][A],link[N],len[N],occ[N],cnt=1,last=1;\n\
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
    \   k-=dp[v];\n            }\n        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/suffix-automaton.hpp
  requiredBy: []
  timestamp: '2026-10-03 23:41:23+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/string/suffix-automaton/number_of_substrings.test.cpp
documentation_of: src/string/suffix-automaton.hpp
layout: document
redirect_from:
- /library/src/string/suffix-automaton.hpp
- /library/src/string/suffix-automaton.hpp.html
title: src/string/suffix-automaton.hpp
---
