---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/geometry/PolyhedronVolume.h: line 7: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Mattias de Zalenski\n * Date: 2002-11-04\n * Description:\
    \ Magic formula for the volume of a polyhedron. Faces should point outwards.\n\
    \ * Status: tested\n */\n#pragma once\n\ntemplate<class V, class L>\ndouble signedPolyVolume(const\
    \ V& p, const L& trilist) {\n\tdouble v = 0;\n\tfor (auto i : trilist) v += p[i.a].cross(p[i.b]).dot(p[i.c]);\n\
    \treturn v / 6;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/PolyhedronVolume.h
  requiredBy: []
  timestamp: '2025-07-19 20:25:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/PolyhedronVolume.h
layout: document
redirect_from:
- /library/src/geometry/PolyhedronVolume.h
- /library/src/geometry/PolyhedronVolume.h.html
title: src/geometry/PolyhedronVolume.h
---
