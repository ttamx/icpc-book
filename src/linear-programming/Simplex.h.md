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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.7/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/linear-programming/Simplex.h: line 16: #pragma once found in a non-first\
    \ line\n"
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
    \ m, n;\n\tvector<int> N, B;\n\tvvd D;\n\n\tLPSolver(const vvd& A, const vd& b,\
    \ const vd& c) :\n\t\tm(SZ(b)), n(SZ(c)), N(n+1), B(m), D(m+2, vd(n+2)) {\n\t\t\
    \tfor(int i=0;i<m;i++) for(int j=0;j<n;j++) D[i][j] = A[i][j];\n\t\t\tfor(int\
    \ i=0;i<m;i++) { B[i] = n+i; D[i][n] = -1; D[i][n+1] = b[i];}\n\t\t\tfor(int j=0;j<n;j++)\
    \ { N[j] = j; D[m][j] = -c[j]; }\n\t\t\tN[n] = -1; D[m+1][n] = 1;\n\t\t}\n\n\t\
    void pivot(int r, int s) {\n\t\tT *a = D[r].data(), inv = 1 / a[s];\n\t\tfor(int\
    \ i=0;i<m+2;i++) if (i != r && abs(D[i][s]) > eps) {\n\t\t\tT *b = D[i].data(),\
    \ inv2 = b[s] * inv;\n\t\t\tfor(int j=0;j<n+2;j++) b[j] -= a[j] * inv2;\n\t\t\t\
    b[s] = a[s] * inv2;\n\t\t}\n\t\tfor(int j=0;j<n+2;j++) if (j != s) D[r][j] *=\
    \ inv;\n\t\tfor(int i=0;i<m+2;i++) if (i != r) D[i][s] *= -inv;\n\t\tD[r][s] =\
    \ inv;\n\t\tswap(B[r], N[s]);\n\t}\n\n\tbool simplex(int phase) {\n\t\tint x =\
    \ m + phase - 1;\n\t\tfor (;;) {\n\t\t\tint s = -1;\n\t\t\tfor(int j=0;j<n+1;j++)\
    \ if (N[j] != -phase) ltj(D[x]);\n\t\t\tif (D[x][s] >= -eps) return true;\n\t\t\
    \tint r = -1;\n\t\t\tfor(int i=0;i<m;i++) {\n\t\t\t\tif (D[i][s] <= eps) continue;\n\
    \t\t\t\tif (r == -1 || MP(D[i][n+1] / D[i][s], B[i])\n\t\t\t\t             < MP(D[r][n+1]\
    \ / D[r][s], B[r])) r = i;\n\t\t\t}\n\t\t\tif (r == -1) return false;\n\t\t\t\
    pivot(r, s);\n\t\t}\n\t}\n\n\tT solve(vd &x) {\n\t\tint r = 0;\n\t\tfor(int i=1;i<m;i++)\
    \ if (D[i][n+1] < D[r][n+1]) r = i;\n\t\tif (D[r][n+1] < -eps) {\n\t\t\tpivot(r,\
    \ n);\n\t\t\tif (!simplex(2) || D[m+1][n+1] < -eps) return -inf;\n\t\t\tfor(int\
    \ i=0;i<m;i++) if (B[i] == -1) {\n\t\t\t\tint s = 0;\n\t\t\t\tfor(int j=1;j<n+1;j++)\
    \ ltj(D[i]);\n\t\t\t\tpivot(i, s);\n\t\t\t}\n\t\t}\n\t\tbool ok = simplex(1);\
    \ x = vd(n);\n\t\tfor(int i=0;i<m;i++) if (B[i] < n) x[B[i]] = D[i][n+1];\n\t\t\
    return ok ? D[m][n+1] : inf;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/linear-programming/Simplex.h
  requiredBy: []
  timestamp: '2026-10-03 23:15:31+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/linear-programming/Simplex.h
layout: document
redirect_from:
- /library/src/linear-programming/Simplex.h
- /library/src/linear-programming/Simplex.h.html
title: src/linear-programming/Simplex.h
---
