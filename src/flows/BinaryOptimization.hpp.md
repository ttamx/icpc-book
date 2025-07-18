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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/graph/flows/Dinic.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"src/graph/flows/Dinic.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-07-16\n * Description: Binary Optimization.\n *  minimize\
    \ $\\kappa + \\sum_i \\theta_i(x_i) + \\sum_{i<j} \\phi_{ij}(x_i,x_j) + \\sum_{i<j<k}\
    \ \\psi_{ijk}(x_i,x_j,x_k)$\n *  where $x_i \\in \\{0,1\\}$ and $\\phi_{ij},\\\
    psi_{ijk}$ are submodular functions.\n *  a set function $f$ is submodular if\
    \ $f(S) + f(T) \\geq f(S \\cap T) + f(S \\cup T)$ for all $S,T$.\n *  $\\phi_{ij}(0,1)\
    \ + \\phi_{ij}(1,0) \\geq \\phi_{ij}(1,1) + \\phi_{ij}(0,0)$.\n */\n\ntemplate<class\
    \ T,bool minimize=true>\nstruct BinaryOptimization{\n    static constexpr T INF=numeric_limits<T>::max()/2;\n\
    \    int n,s,t,buf;\n    T base;\n    map<pair<int,int>,T> edges;\n    BinaryOptimization(int\
    \ _n):n(_n),s(n),t(n+1),buf(n+2),base(0){}\n    void add_edge(int u,int v,T w){\n\
    \        assert(w>=0);\n        if(u==v||w==0)return;\n        auto &e=edges[{u,v}];\n\
    \        e=min(e+w,INF);\n    }\n    void add0(T w){\n        base+=w;\n    }\n\
    \    void _add1(int i,T a,T b){\n        if(a<=b){\n            add0(a);\n   \
    \         add_edge(s,i,b-a);\n        }else{\n            add0(b);\n         \
    \   add_edge(i,t,a-b);\n        }\n    }\n    void add1(int i,T x0,T x1){\n  \
    \      assert(0<=i&&i<n);\n        if(!minimize)x0=-x0,x1=-x1;\n        _add1(i,x0,x1);\n\
    \    }\n    void _add2(int i,int j,T a,T b,T c,T d){\n        assert(b+c>=a+d);\n\
    \        add0(a);\n        _add1(i,0,c-a);\n        _add1(j,0,d-c);\n        add_edge(i,j,b+c-a-d);\n\
    \    }\n    void add2(int i,int j,T x00,T x01,T x10,T x11){\n        assert(i!=j&&0<=i&&i<n&&0<=j&&j<n);\n\
    \        if(!minimize)x00=-x00,x01=-x01,x10=-x10,x11=-x11;\n        _add2(i,j,x00,x01,x10,x11);\n\
    \    }\n    void _add3(int i,int j,int k,T a,T b,T c,T d,T e,T f,T g,T h){\n \
    \       T p=a+d+f+g-b-c-e-h;\n        if(p>=0){\n            add0(a);\n      \
    \      _add1(i,0,f-b);\n            _add1(j,0,g-e);\n            _add1(k,0,d-c);\n\
    \            _add2(i,j,0,c+e-a-g,0,0);\n            _add2(i,k,0,0,b+e-a-f,0);\n\
    \            _add2(j,k,0,b+c-a-d,0,0);\n            int u=buf++;\n           \
    \ add0(-p);\n            add_edge(i,u,p);\n            add_edge(j,u,p);\n    \
    \        add_edge(k,u,p);\n            add_edge(u,t,p);\n        }else{\n    \
    \        add0(h);\n            _add1(i,c-g,0);\n            _add1(j,b-d,0);\n\
    \            _add1(k,e-f,0);\n            _add2(i,j,0,0,d+f-b-h,0);\n        \
    \    _add2(i,k,0,d+g-c-h,0,0);\n            _add2(j,k,0,0,f+g-e-h,0);\n      \
    \      int u=buf++;\n            add0(p);\n            add_edge(s,u,-p);\n   \
    \         add_edge(u,i,-p);\n            add_edge(u,j,-p);\n            add_edge(u,k,-p);\n\
    \        }\n    }\n    void add3(int i,int j,int k,T x000,T x001,T x010,T x011,T\
    \ x100,T x101,T x110,T x111){\n        assert(i!=j&&j!=k&&k!=i&&0<=i&&i<n&&0<=j&&j<n&&0<=k&&k<n);\n\
    \        if(!minimize){\n            x000=-x000,x001=-x001,x010=-x010,x011=-x011;\n\
    \            x100=-x100,x101=-x101,x110=-x110,x111=-x111;\n        }\n       \
    \ _add3(i,j,k,x000,x001,x010,x011,x100,x101,x110,x111);\n    }\n    pair<T,vector<int>>\
    \ solve(){\n        Dinic<T> dinic(buf,s,t);\n        for(auto &[p,w]:edges){\n\
    \            auto [u,v]=p;\n            dinic.add_edge(u,v,w);\n        }\n  \
    \      auto [ans,cut]=dinic.cut();\n        ans+=base;\n        ans=min(ans,INF);\n\
    \        cut.resize(n);\n        return {minimize?ans:-ans,cut};\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/flows/BinaryOptimization.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flows/BinaryOptimization.hpp
layout: document
redirect_from:
- /library/src/flows/BinaryOptimization.hpp
- /library/src/flows/BinaryOptimization.hpp.html
title: src/flows/BinaryOptimization.hpp
---
