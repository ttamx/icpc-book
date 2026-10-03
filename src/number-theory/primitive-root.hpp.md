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
  bundledCode: "#line 2 \"src/number-theory/primitive-root.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Description: Primitive root finder.\n * Time: $O(Ans \\log \\\
    phi(n) \\log n)$\n */\n\nint modpow(int a,int b,int mod){\n    int res=1;\n  \
    \  while(b>0){\n        if(b&1)res=1LL*res*a%mod;\n        a=1LL*a*a%mod;\n  \
    \      b>>=1;\n    }\n    return res;\n}\n\nint primitive_root(int p){\n    vector<int>\
    \ fact;\n    int phi=p-1,n=phi;\n    for(int i=2; i*i<=n;i++){\n        if(n%i==0){\n\
    \            fact.emplace_back(i);\n            while(n%i==0)n/=i;\n        }\n\
    \    }\n    if(n>1)fact.emplace_back(n);\n    for(int res=2;res<=p;res++){\n \
    \       bool ok=true;\n        for(int i=0;i<fact.size()&&ok;i++){\n         \
    \   ok&=(modpow(res,phi/fact[i],p)!=1);\n        }\n        if(ok)return res;\n\
    \    }\n    return -1;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Description: Primitive root\
    \ finder.\n * Time: $O(Ans \\log \\phi(n) \\log n)$\n */\n\nint modpow(int a,int\
    \ b,int mod){\n    int res=1;\n    while(b>0){\n        if(b&1)res=1LL*res*a%mod;\n\
    \        a=1LL*a*a%mod;\n        b>>=1;\n    }\n    return res;\n}\n\nint primitive_root(int\
    \ p){\n    vector<int> fact;\n    int phi=p-1,n=phi;\n    for(int i=2; i*i<=n;i++){\n\
    \        if(n%i==0){\n            fact.emplace_back(i);\n            while(n%i==0)n/=i;\n\
    \        }\n    }\n    if(n>1)fact.emplace_back(n);\n    for(int res=2;res<=p;res++){\n\
    \        bool ok=true;\n        for(int i=0;i<fact.size()&&ok;i++){\n        \
    \    ok&=(modpow(res,phi/fact[i],p)!=1);\n        }\n        if(ok)return res;\n\
    \    }\n    return -1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/number-theory/primitive-root.hpp
  requiredBy: []
  timestamp: '2026-10-03 21:00:46+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/number-theory/primitive-root.hpp
layout: document
redirect_from:
- /library/src/number-theory/primitive-root.hpp
- /library/src/number-theory/primitive-root.hpp.html
title: src/number-theory/primitive-root.hpp
---
