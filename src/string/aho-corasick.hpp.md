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
  bundledCode: "#line 2 \"src/string/aho-corasick.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2025-07-19\n * Description: Aho-Corasick on a node pool (root =\
    \ 1, 0 = sentinel).\n * insert() returns the end node of a pattern. After build(),\
    \ ch is the\n * full automaton and val[u] = sum of val over all patterns that\
    \ are\n * suffixes of u. Instance must be global; N > total pattern length.\n\
    \ * Time: $O(A \\cdot N)$ build\n */\n\ntemplate<int N,class T,int A=26>\nstruct\
    \ AhoCorasick{\n    int ch[N][A],fail[N],cnt=1;\n    T val[N];\n    int insert(const\
    \ string &s,T v){\n        int u=1;\n        for(char x:s){\n            int &w=ch[u][x-'a'];\n\
    \            if(!w)w=++cnt;\n            u=w;\n        }\n        val[u]+=v;\n\
    \        return u;\n    }\n    void build(){\n        fill(ch[0],ch[0]+A,1); //\
    \ sentinel: every edge to root\n        vector<int> q{1};\n        for(int i=0;i<SZ(q);i++){\n\
    \            int u=q[i];\n            for(int c=0;c<A;c++){\n                int\
    \ &v=ch[u][c];\n                if(!v)v=ch[fail[u]][c];\n                else{\n\
    \                    fail[v]=ch[fail[u]][c];\n                    val[v]+=val[fail[v]],q.pb(v);\n\
    \                }\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2025-07-19\n * Description:\
    \ Aho-Corasick on a node pool (root = 1, 0 = sentinel).\n * insert() returns the\
    \ end node of a pattern. After build(), ch is the\n * full automaton and val[u]\
    \ = sum of val over all patterns that are\n * suffixes of u. Instance must be\
    \ global; N > total pattern length.\n * Time: $O(A \\cdot N)$ build\n */\n\ntemplate<int\
    \ N,class T,int A=26>\nstruct AhoCorasick{\n    int ch[N][A],fail[N],cnt=1;\n\
    \    T val[N];\n    int insert(const string &s,T v){\n        int u=1;\n     \
    \   for(char x:s){\n            int &w=ch[u][x-'a'];\n            if(!w)w=++cnt;\n\
    \            u=w;\n        }\n        val[u]+=v;\n        return u;\n    }\n \
    \   void build(){\n        fill(ch[0],ch[0]+A,1); // sentinel: every edge to root\n\
    \        vector<int> q{1};\n        for(int i=0;i<SZ(q);i++){\n            int\
    \ u=q[i];\n            for(int c=0;c<A;c++){\n                int &v=ch[u][c];\n\
    \                if(!v)v=ch[fail[u]][c];\n                else{\n            \
    \        fail[v]=ch[fail[u]][c];\n                    val[v]+=val[fail[v]],q.pb(v);\n\
    \                }\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/aho-corasick.hpp
  requiredBy: []
  timestamp: '2026-10-03 23:41:23+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/aho-corasick.hpp
layout: document
redirect_from:
- /library/src/string/aho-corasick.hpp
- /library/src/string/aho-corasick.hpp.html
title: src/string/aho-corasick.hpp
---
