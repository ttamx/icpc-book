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
  bundledCode: "#line 3 \"src/miscellaneous/range-xor.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-11-27\n * Description: find all range of x such that l <=\
    \ x xor p < r.\n */\n\ntemplate<class F>\nvoid range_xor(ll p,ll l,ll r,const\
    \ F &query){\n    for(int i=0;i<60;i++){\n        if(l==r)break;\n        ll b=1LL<<i;\n\
    \        if(l&b){\n            query(l^p,(l^p)+b);\n            l+=b;\n      \
    \  }\n        if(r&b){\n            r-=b;\n            query(r^p,(r^p)+b);\n \
    \       }\n        if(p&b){\n            p^=b;\n        }\n    }\n}\n"
  code: "#pragma once\n#include \"src/miscellaneous/range-xor.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-11-27\n * Description: find all range of x such that\
    \ l <= x xor p < r.\n */\n\ntemplate<class F>\nvoid range_xor(ll p,ll l,ll r,const\
    \ F &query){\n    for(int i=0;i<60;i++){\n        if(l==r)break;\n        ll b=1LL<<i;\n\
    \        if(l&b){\n            query(l^p,(l^p)+b);\n            l+=b;\n      \
    \  }\n        if(r&b){\n            r-=b;\n            query(r^p,(r^p)+b);\n \
    \       }\n        if(p&b){\n            p^=b;\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/miscellaneous/range-xor.hpp
  requiredBy: []
  timestamp: '2025-07-19 19:14:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/miscellaneous/range-xor.hpp
layout: document
redirect_from:
- /library/src/miscellaneous/range-xor.hpp
- /library/src/miscellaneous/range-xor.hpp.html
title: src/miscellaneous/range-xor.hpp
---
