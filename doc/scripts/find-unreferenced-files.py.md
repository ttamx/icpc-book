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
  code: "import os\n\nfor (dirpath, dirnames, filenames) in os.walk('src'):\n    try:\n\
    \        with open(os.path.join(dirpath, 'chapter.tex')) as f:\n            chapter_tex\
    \ = f.read()\n    except:\n        continue\n\n    for fname in filenames:\n \
    \       if not fname.endswith('.h') or '-codeforces' in fname:\n            continue\n\
    \        if f'{{{fname}}}' in chapter_tex:\n            continue\n        print(os.path.join(dirpath,\
    \ fname))\n"
  dependsOn: []
  isVerificationFile: false
  path: doc/scripts/find-unreferenced-files.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: doc/scripts/find-unreferenced-files.py
layout: document
redirect_from:
- /library/doc/scripts/find-unreferenced-files.py
- /library/doc/scripts/find-unreferenced-files.py.html
title: doc/scripts/find-unreferenced-files.py
---
