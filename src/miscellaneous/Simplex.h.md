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
    \ src/miscellaneous/Simplex.h: line 16: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Stanford\n * Source: Stanford Notebook\n * License: MIT\n\
    \ * Description: Solves a general linear maximization problem: maximize $c^T x$\
    \ subject to $Ax \\le b$, $x \\ge 0$.\n * Returns -inf if there is no solution,\
    \ inf if there are arbitrarily good solutions, or the maximum value of $c^T x$\
    \ otherwise.\n * The input vector is set to an optimal $x$ (or in the unbounded\
    \ case, an arbitrary solution fulfilling the constraints).\n * Numerical stability\
    \ is not guaranteed. For better performance, define variables such that $x = 0$\
    \ is viable.\n * Usage:\n * vvd A = {{1,-1}, {-1,1}, {-1,-2}};\n * vd b = {1,1,-4},\
    \ c = {-1,-1}, x;\n * T val = LPSolver(A, b, c).solve(x);\n * Time: O(NM * \\\
    #pivots), where a pivot may be e.g. an edge relaxation. O(2^n) in the general\
    \ case.\n * Status: seems to work?\n */\n#pragma once\n\ntypedef double T; //\
    \ long double, Rational, double + mod<P>...\ntypedef vector<T> vd;\ntypedef vector<vd>\
    \ vvd;\n\nconst T eps = 1e-8, inf = 1/.0;\n#define MP make_pair\n#define ltj(X)\
    \ if(s == -1 || MP(X[j],N[j]) < MP(X[s],N[s])) s=j\n\nstruct LPSolver {\n\tint\
    \ m, n;\n\tvi N, B;\n\tvvd D;\n\n\tLPSolver(const vvd& A, const vd& b, const vd&\
    \ c) :\n\t\tm(sz(b)), n(sz(c)), N(n+1), B(m), D(m+2, vd(n+2)) {\n\t\t\trep(i,0,m)\
    \ rep(j,0,n) D[i][j] = A[i][j];\n\t\t\trep(i,0,m) { B[i] = n+i; D[i][n] = -1;\
    \ D[i][n+1] = b[i];}\n\t\t\trep(j,0,n) { N[j] = j; D[m][j] = -c[j]; }\n\t\t\t\
    N[n] = -1; D[m+1][n] = 1;\n\t\t}\n\n\tvoid pivot(int r, int s) {\n\t\tT *a = D[r].data(),\
    \ inv = 1 / a[s];\n\t\trep(i,0,m+2) if (i != r && abs(D[i][s]) > eps) {\n\t\t\t\
    T *b = D[i].data(), inv2 = b[s] * inv;\n\t\t\trep(j,0,n+2) b[j] -= a[j] * inv2;\n\
    \t\t\tb[s] = a[s] * inv2;\n\t\t}\n\t\trep(j,0,n+2) if (j != s) D[r][j] *= inv;\n\
    \t\trep(i,0,m+2) if (i != r) D[i][s] *= -inv;\n\t\tD[r][s] = inv;\n\t\tswap(B[r],\
    \ N[s]);\n\t}\n\n\tbool simplex(int phase) {\n\t\tint x = m + phase - 1;\n\t\t\
    for (;;) {\n\t\t\tint s = -1;\n\t\t\trep(j,0,n+1) if (N[j] != -phase) ltj(D[x]);\n\
    \t\t\tif (D[x][s] >= -eps) return true;\n\t\t\tint r = -1;\n\t\t\trep(i,0,m) {\n\
    \t\t\t\tif (D[i][s] <= eps) continue;\n\t\t\t\tif (r == -1 || MP(D[i][n+1] / D[i][s],\
    \ B[i])\n\t\t\t\t             < MP(D[r][n+1] / D[r][s], B[r])) r = i;\n\t\t\t\
    }\n\t\t\tif (r == -1) return false;\n\t\t\tpivot(r, s);\n\t\t}\n\t}\n\n\tT solve(vd\
    \ &x) {\n\t\tint r = 0;\n\t\trep(i,1,m) if (D[i][n+1] < D[r][n+1]) r = i;\n\t\t\
    if (D[r][n+1] < -eps) {\n\t\t\tpivot(r, n);\n\t\t\tif (!simplex(2) || D[m+1][n+1]\
    \ < -eps) return -inf;\n\t\t\trep(i,0,m) if (B[i] == -1) {\n\t\t\t\tint s = 0;\n\
    \t\t\t\trep(j,1,n+1) ltj(D[i]);\n\t\t\t\tpivot(i, s);\n\t\t\t}\n\t\t}\n\t\tbool\
    \ ok = simplex(1); x = vd(n);\n\t\trep(i,0,m) if (B[i] < n) x[B[i]] = D[i][n+1];\n\
    \t\treturn ok ? D[m][n+1] : inf;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/miscellaneous/Simplex.h
  requiredBy: []
  timestamp: '2025-07-19 21:34:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/miscellaneous/Simplex.h
layout: document
redirect_from:
- /library/src/miscellaneous/Simplex.h
- /library/src/miscellaneous/Simplex.h.html
title: src/miscellaneous/Simplex.h
---
