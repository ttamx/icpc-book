---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/string/manacher/enumerate_palindromes.test.cpp
    title: verify/string/manacher/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/manacher.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Date: 2024-06-14\n * Description: Manacher's Algorithm. pal[i] := the length\
    \ of the longest palindrome centered at i/2.\n */\n\ntemplate<class STR>\nvector<int>\
    \ manacher(const STR &s){\n    int n=(int)s.size();\n    if(n==0)return {};\n\
    \    vector<int> pal(2*n-1);\n    for(int p=0,l=-1,r=-1;p<2*n-1;p++){\n      \
    \  int i=(p+1)>>1,j=p>>1;\n        int k=(i>=r?0:min(r-i,pal[2*(l+r)-p]));\n \
    \       while(j+k+1<n&&i-k-1>=0&&s[j+k+1]==s[i-k-1])k++;\n        pal[p]=k;\n\
    \        if(j+k>r)l=i-k,r=j+k;\n    }\n    for(int i=0;i<2*n-1;i++)pal[i]=pal[i]<<1|(i&1^1);\n\
    \    return pal;\n}\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-14\n * Description:\
    \ Manacher's Algorithm. pal[i] := the length of the longest palindrome centered\
    \ at i/2.\n */\n\ntemplate<class STR>\nvector<int> manacher(const STR &s){\n \
    \   int n=(int)s.size();\n    if(n==0)return {};\n    vector<int> pal(2*n-1);\n\
    \    for(int p=0,l=-1,r=-1;p<2*n-1;p++){\n        int i=(p+1)>>1,j=p>>1;\n   \
    \     int k=(i>=r?0:min(r-i,pal[2*(l+r)-p]));\n        while(j+k+1<n&&i-k-1>=0&&s[j+k+1]==s[i-k-1])k++;\n\
    \        pal[p]=k;\n        if(j+k>r)l=i-k,r=j+k;\n    }\n    for(int i=0;i<2*n-1;i++)pal[i]=pal[i]<<1|(i&1^1);\n\
    \    return pal;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/manacher.hpp
  requiredBy: []
  timestamp: '2025-07-19 13:39:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/string/manacher/enumerate_palindromes.test.cpp
documentation_of: src/string/manacher.hpp
layout: document
redirect_from:
- /library/src/string/manacher.hpp
- /library/src/string/manacher.hpp.html
title: src/string/manacher.hpp
---
