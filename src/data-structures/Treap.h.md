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
    \ src/data-structures/Treap.h: line 11: #pragma once found in a non-first line\n"
  code: "/**\n * Author: someone on Codeforces\n * Date: 2017-03-14\n * Source: folklore\n\
    \ * Description: A short self-balancing tree. It acts as a\n *  sequential container\
    \ with log-time splits/joins, and\n *  is easy to augment with additional data.\n\
    \ * Time: $O(\\log N)$\n * Status: stress-tested\n */\n#pragma once\n\nstruct\
    \ Node {\n\tNode *l = 0, *r = 0;\n\tint val, y, c = 1;\n\tNode(int val) : val(val),\
    \ y(rand()) {}\n\tvoid recalc();\n};\n\nint cnt(Node* n) { return n ? n->c : 0;\
    \ }\nvoid Node::recalc() { c = cnt(l) + cnt(r) + 1; }\n\ntemplate<class F> void\
    \ each(Node* n, F f) {\n\tif (n) { each(n->l, f); f(n->val); each(n->r, f); }\n\
    }\n\npair<Node*, Node*> split(Node* n, int k) {\n\tif (!n) return {};\n\tif (cnt(n->l)\
    \ >= k) { // \"n->val >= k\" for lower_bound(k)\n\t\tauto [L,R] = split(n->l,\
    \ k);\n\t\tn->l = R;\n\t\tn->recalc();\n\t\treturn {L, n};\n\t} else {\n\t\tauto\
    \ [L,R] = split(n->r,k - cnt(n->l) - 1); // and just \"k\"\n\t\tn->r = L;\n\t\t\
    n->recalc();\n\t\treturn {n, R};\n\t}\n}\n\nNode* merge(Node* l, Node* r) {\n\t\
    if (!l) return r;\n\tif (!r) return l;\n\tif (l->y > r->y) {\n\t\tl->r = merge(l->r,\
    \ r);\n\t\treturn l->recalc(), l;\n\t} else {\n\t\tr->l = merge(l, r->l);\n\t\t\
    return r->recalc(), r;\n\t}\n}\n\nNode* ins(Node* t, Node* n, int pos) {\n\tauto\
    \ [l,r] = split(t, pos);\n\treturn merge(merge(l, n), r);\n}\n\n// Example application:\
    \ move the range [l, r) to index k\nvoid move(Node*& t, int l, int r, int k) {\n\
    \tNode *a, *b, *c;\n\ttie(a,b) = split(t, l); tie(b,c) = split(b, r - l);\n\t\
    if (k <= l) t = merge(ins(a, b, k), c);\n\telse t = merge(a, ins(c, b, k - r));\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structures/Treap.h
  requiredBy: []
  timestamp: '2025-07-17 00:10:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structures/Treap.h
layout: document
redirect_from:
- /library/src/data-structures/Treap.h
- /library/src/data-structures/Treap.h.html
title: src/data-structures/Treap.h
---
