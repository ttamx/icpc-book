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
  code: "import glob\n\nfor fname in glob.glob('src/*/*.h'):\n    fname = fname.strip()\n\
    \    with open(fname) as f:\n        cont = list(f)\n    prline = -1\n    for\
    \ i, line in enumerate(cont):\n        if line.startswith('#pragma once'):\n \
    \           prline = i\n    if prline == -1:\n        continue\n    print(fname)\n\
    \    while not cont[prline-1].strip():\n        del cont[prline-1]\n        prline\
    \ -= 1\n    while not cont[prline+1].strip():\n        del cont[prline+1]\n  \
    \  cont[prline+1:prline+1] = ['\\n']\n    cont = ''.join(cont)\n    # print(cont)\n\
    \    # print()\n    with open(fname, 'w') as f:\n        f.write(cont)\n"
  dependsOn: []
  isVerificationFile: false
  path: doc/scripts/fix-newlines.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: doc/scripts/fix-newlines.py
layout: document
redirect_from:
- /library/doc/scripts/fix-newlines.py
- /library/doc/scripts/fix-newlines.py.html
title: doc/scripts/fix-newlines.py
---
