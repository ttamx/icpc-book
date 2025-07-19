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
  bundledCode: "#line 2 \"src/string/suffix-array.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-06-14\n * Description: Suffix Array.\n */\n\ntemplate<class\
    \ STR>\nstruct SuffixArray{\n    int n;\n    vector<int> sa,isa,lcp;\n    // SparseTable<MinMonoid<int>>\
    \ st;\n    SuffixArray(){}\n    SuffixArray(const STR &s){init(s);}\n    void\
    \ init(const STR &s){\n        n=(int)s.size();\n        sa=isa=lcp=vector<int>(n+1);\n\
    \        sa[0]=n;\n        iota(sa.begin()+1,sa.end(),0);\n        sort(sa.begin()+1,sa.end(),[&](int\
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
    \    // }\n};\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-14\n * Description:\
    \ Suffix Array.\n */\n\ntemplate<class STR>\nstruct SuffixArray{\n    int n;\n\
    \    vector<int> sa,isa,lcp;\n    // SparseTable<MinMonoid<int>> st;\n    SuffixArray(){}\n\
    \    SuffixArray(const STR &s){init(s);}\n    void init(const STR &s){\n     \
    \   n=(int)s.size();\n        sa=isa=lcp=vector<int>(n+1);\n        sa[0]=n;\n\
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
    \    // }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/suffix-array.hpp
  requiredBy: []
  timestamp: '2025-07-19 13:39:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/suffix-array.hpp
layout: document
redirect_from:
- /library/src/string/suffix-array.hpp
- /library/src/string/suffix-array.hpp.html
title: src/string/suffix-array.hpp
---
