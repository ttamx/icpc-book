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
  bundledCode: "#line 2 \"src/string/prefix-function.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-06-14\n * Description: Prefix function. pi[i] := the length\
    \ of the longest proper prefix of s[0:i] which is also a suffix of s[0:i].\n */\n\
    \ntemplate<class STR>\nvector<int> prefix_function(const STR &s){\n    int n=(int)s.size();\n\
    \    vector<int> pi(n);\n    for(int i=1,j=0;i<n;i++){\n        while(j>0&&s[i]!=s[j])j=pi[j-1];\n\
    \        if(s[i]==s[j])j++;\n        pi[i]=j;\n    }\n    return pi;\n}\n\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-06-14\n * Description:\
    \ Prefix function. pi[i] := the length of the longest proper prefix of s[0:i]\
    \ which is also a suffix of s[0:i].\n */\n\ntemplate<class STR>\nvector<int> prefix_function(const\
    \ STR &s){\n    int n=(int)s.size();\n    vector<int> pi(n);\n    for(int i=1,j=0;i<n;i++){\n\
    \        while(j>0&&s[i]!=s[j])j=pi[j-1];\n        if(s[i]==s[j])j++;\n      \
    \  pi[i]=j;\n    }\n    return pi;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/prefix-function.hpp
  requiredBy: []
  timestamp: '2025-07-19 13:39:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/prefix-function.hpp
layout: document
redirect_from:
- /library/src/string/prefix-function.hpp
- /library/src/string/prefix-function.hpp.html
title: src/string/prefix-function.hpp
---
