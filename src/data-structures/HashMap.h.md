---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://codeforces.com/blog/entry/60737
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/data-structures/HashMap.h: line 10: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Simon Lindholm, chilli\n * Date: 2018-07-23\n * License:\
    \ CC0\n * Source: http://codeforces.com/blog/entry/60737\n * Description: Hash\
    \ map with mostly the same API as unordered\\_map, but \\tilde\n * 3x faster.\
    \ Uses 1.5x memory.\n * Initial capacity must be a power of 2 (if provided).\n\
    \ */\n#pragma once\n\n#include <bits/extc++.h> /** keep-include */\n// To use\
    \ most bits rather than just the lowest ones:\nstruct chash { // large odd number\
    \ for C\n\tconst uint64_t C = ll(4e18 * acos(0)) | 71;\n\tll operator()(ll x)\
    \ const { return __builtin_bswap64(x*C); }\n};\n__gnu_pbds::gp_hash_table<ll,int,chash>\
    \ h({},{},{},{},{1<<16});\n\n/** For CodeForces, or other places where hacking\
    \ might be a problem:\n\nconst int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash { // To use most bits rather than just the lowest ones:\n\tconst\
    \ uint64_t C = ll(4e18 * acos(0)) | 71; // large odd number\n\tll operator()(ll\
    \ x) const { return __builtin_bswap64((x^RANDOM)*C); }\n};\n__gnu_pbds::gp_hash_table<ll,\
    \ int, chash> h({},{},{},{}, {1 << 16});\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structures/HashMap.h
  requiredBy: []
  timestamp: '2025-07-17 00:10:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structures/HashMap.h
layout: document
redirect_from:
- /library/src/data-structures/HashMap.h
- /library/src/data-structures/HashMap.h.html
title: src/data-structures/HashMap.h
---
