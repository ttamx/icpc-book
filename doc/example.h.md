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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ doc/example.h: line 15: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Chen Xing\n * Date: 2009-03-13\n * License: CC0\n * Source:\
    \ Conversation with H\xE5kan and Ulf.\n * Description: Example structures and\
    \ functions that doesn't really do\n *  anything. Latex commands are supported\
    \ here, though! Like this: $2^2=3$\n * Usage:\n *  int res = exampleFunction1(mice,\
    \ cats, catsCount);\n *  int random = exampleFunction2();\n * Time: O(M * N^4)\
    \ where M = cats, N = mice\n * Memory: O(2^N) where N = cats\n * Status: Untested\n\
    \ */\n#pragma once\n\n/// Headers and macros from contest/template.h are automatically\
    \ included.\n\n#include \"Example.h\" /// Header name will be kept in final list.\n\
    \nstruct ExampleStructure {\n\tll alpha;\n\tpii nodes;\n\tvi edges;\n};\n\nint\
    \ exampleFunction1(vi mice, int* cats, int catsCount) {\n\t/// This is a stupid\
    \ comment that will be removed.\n\tint sum = 0;\n\n\trep(i, 1, catsCount) {\n\t\
    \t// This comment will be kept!\n\t\tfor (auto it : mice) {\n\t\t\t/// This will\
    \ be removed.\n\t\t\t// And this kept.\n\t\t\tsum += cats[i] * it;\n\t\t}\n\t\
    }\n\t// Use tab indent and keep a line width of at most 63 chars,\n\t// where\
    \ tabs count as 2 characters wide.\n\t//<---------------------Maximum width----------------------->\n\
    \treturn sum;\n}\n\nint exampleFunction2() {\n\treturn rand();\n}\n\nint exampleFunction3(int\
    \ a, int b, int c) {\n\treturn exampleFunction2() * a * b * c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: doc/example.h
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: doc/example.h
layout: document
redirect_from:
- /library/doc/example.h
- /library/doc/example.h.html
title: doc/example.h
---
