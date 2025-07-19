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
    \ T.\n * Date: 2025-07-19\n * Description: Aho-Corasick.\n */\n\ntemplate<class\
    \ T>\nstruct AhoCorasick{\n    struct Node{\n        array<int,26> ch;\n     \
    \   int fail;\n        T val;\n        Node(){\n            fill(ch.begin(),ch.end(),-1);\n\
    \            fail=-1;\n            val=0;\n        }\n    };\n    vector<Node>\
    \ nodes;\n    AhoCorasick(){new_node();}\n    int new_node(){\n        nodes.emplace_back(Node());\n\
    \        return nodes.size()-1;\n    }\n    void insert(const string &s,const\
    \ T &val){\n        int u=0;\n        for(auto x:s){\n            int c=x-'a';\n\
    \            if(nodes[u].ch[c]==-1)nodes[u].ch[c]=new_node();\n            u=nodes[u].ch[c];\n\
    \        }\n        nodes[u].val+=val;\n    }\n    void build(){\n        vector<int>\
    \ q{0};\n        for(int i=0;i<q.size();i++){\n            int u=q[i];\n     \
    \       int v;\n            for(int c=0;c<26;c++){\n                if((v=nodes[u].ch[c])!=-1){\n\
    \                    int p=nodes[u].fail;\n                    while(p!=-1&&nodes[p].ch[c]==-1)p=nodes[p].fail;\n\
    \                    p=p!=-1?nodes[p].ch[c]:0;\n                    nodes[v].fail=p;\n\
    \                    nodes[v].val+=nodes[p].val;\n                    q.emplace_back(v);\n\
    \                }\n            }\n        }\n        for(auto u:q){\n       \
    \     for(int c=0;c<26;c++){\n                if(nodes[u].ch[c]==-1){\n      \
    \              int p=nodes[u].fail;\n                    while(p!=-1&&nodes[p].ch[c]==-1)p=nodes[p].fail;\n\
    \                    nodes[u].ch[c]=p!=-1?nodes[p].ch[c]:0;\n                }\n\
    \            }\n        }\n    }\n};\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2025-07-19\n * Description:\
    \ Aho-Corasick.\n */\n\ntemplate<class T>\nstruct AhoCorasick{\n    struct Node{\n\
    \        array<int,26> ch;\n        int fail;\n        T val;\n        Node(){\n\
    \            fill(ch.begin(),ch.end(),-1);\n            fail=-1;\n           \
    \ val=0;\n        }\n    };\n    vector<Node> nodes;\n    AhoCorasick(){new_node();}\n\
    \    int new_node(){\n        nodes.emplace_back(Node());\n        return nodes.size()-1;\n\
    \    }\n    void insert(const string &s,const T &val){\n        int u=0;\n   \
    \     for(auto x:s){\n            int c=x-'a';\n            if(nodes[u].ch[c]==-1)nodes[u].ch[c]=new_node();\n\
    \            u=nodes[u].ch[c];\n        }\n        nodes[u].val+=val;\n    }\n\
    \    void build(){\n        vector<int> q{0};\n        for(int i=0;i<q.size();i++){\n\
    \            int u=q[i];\n            int v;\n            for(int c=0;c<26;c++){\n\
    \                if((v=nodes[u].ch[c])!=-1){\n                    int p=nodes[u].fail;\n\
    \                    while(p!=-1&&nodes[p].ch[c]==-1)p=nodes[p].fail;\n      \
    \              p=p!=-1?nodes[p].ch[c]:0;\n                    nodes[v].fail=p;\n\
    \                    nodes[v].val+=nodes[p].val;\n                    q.emplace_back(v);\n\
    \                }\n            }\n        }\n        for(auto u:q){\n       \
    \     for(int c=0;c<26;c++){\n                if(nodes[u].ch[c]==-1){\n      \
    \              int p=nodes[u].fail;\n                    while(p!=-1&&nodes[p].ch[c]==-1)p=nodes[p].fail;\n\
    \                    nodes[u].ch[c]=p!=-1?nodes[p].ch[c]:0;\n                }\n\
    \            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/string/aho-corasick.hpp
  requiredBy: []
  timestamp: '2025-07-19 14:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/aho-corasick.hpp
layout: document
redirect_from:
- /library/src/string/aho-corasick.hpp
- /library/src/string/aho-corasick.hpp.html
title: src/string/aho-corasick.hpp
---
