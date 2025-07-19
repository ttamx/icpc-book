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
  bundledCode: "#line 2 \"src/miscellaneous/integrate.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2025-07-19\n * Description: find definite integral with Simpson's\
    \ method, error proportional to dx^4.\n */\n\ntemplate<class F>\ndb quad(db a,db\
    \ b,const F &f,int n){\n    db res=0;\n    db dx=(b-a)/n;\n    db fl=0,fr=f(a);\n\
    \    for(int i=0;i<n;i++){\n        db l=a+dx*i,r=l+dx;\n        fl=fr;\n    \
    \    fr=f(r);\n        db fm=f((l+r)/2);\n        res+=fl+4*fm+fr;\n    }\n  \
    \  return res*dx/6;\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2025-07-19\n * Description:\
    \ find definite integral with Simpson's method, error proportional to dx^4.\n\
    \ */\n\ntemplate<class F>\ndb quad(db a,db b,const F &f,int n){\n    db res=0;\n\
    \    db dx=(b-a)/n;\n    db fl=0,fr=f(a);\n    for(int i=0;i<n;i++){\n       \
    \ db l=a+dx*i,r=l+dx;\n        fl=fr;\n        fr=f(r);\n        db fm=f((l+r)/2);\n\
    \        res+=fl+4*fm+fr;\n    }\n    return res*dx/6;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/miscellaneous/integrate.hpp
  requiredBy: []
  timestamp: '2025-07-19 19:14:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/miscellaneous/integrate.hpp
layout: document
redirect_from:
- /library/src/miscellaneous/integrate.hpp
- /library/src/miscellaneous/integrate.hpp.html
title: src/miscellaneous/integrate.hpp
---
