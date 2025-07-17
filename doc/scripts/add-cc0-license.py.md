---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "\nfor fname in open('todo'):\n    fname = fname.strip()\n    print(fname)\n\
    \    with open(fname) as f:\n        cont = list(f)\n    beforeline = -1\n   \
    \ for i, line in enumerate(cont):\n        if line.startswith(' * Author:') or\
    \ line.startswith(' * Date:'):\n            beforeline = i+1\n    cont[beforeline:beforeline]\
    \ = [' * License: CC0\\n']\n    cont = ''.join(cont)\n    with open(fname, 'w')\
    \ as f:\n        f.write(cont)\n"
  dependsOn: []
  isVerificationFile: false
  path: doc/scripts/add-cc0-license.py
  requiredBy: []
  timestamp: '2019-12-25 17:45:28+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: doc/scripts/add-cc0-license.py
layout: document
redirect_from:
- /library/doc/scripts/add-cc0-license.py
- /library/doc/scripts/add-cc0-license.py.html
title: doc/scripts/add-cc0-license.py
---
