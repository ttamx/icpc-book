---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/polynomials/formal-power-series.hpp
    title: src/polynomials/formal-power-series.hpp
  - icon: ':heavy_check_mark:'
    path: src/polynomials/linear-recurrence.hpp
    title: src/polynomials/linear-recurrence.hpp
  - icon: ':question:'
    path: src/polynomials/multipoint-evaluation.hpp
    title: src/polynomials/multipoint-evaluation.hpp
  - icon: ':question:'
    path: src/polynomials/ntt.hpp
    title: src/polynomials/ntt.hpp
  - icon: ':x:'
    path: src/polynomials/polynomial-interpolation.hpp
    title: src/polynomials/polynomial-interpolation.hpp
  - icon: ':question:'
    path: src/polynomials/subproduct-tree.hpp
    title: src/polynomials/subproduct-tree.hpp
  - icon: ':x:'
    path: src/polynomials/taylor-shift.hpp
    title: src/polynomials/taylor-shift.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/linear-algebra/gauss-mod/inverse_matrix.test.cpp
    title: verify/linear-algebra/gauss-mod/inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/linear-algebra/gauss-mod/matrix_det.test.cpp
    title: verify/linear-algebra/gauss-mod/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/linear-algebra/gauss-mod/matrix_rank.test.cpp
    title: verify/linear-algebra/gauss-mod/matrix_rank.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/linear-algebra/gauss-mod/system_of_linear_equations.test.cpp
    title: verify/linear-algebra/gauss-mod/system_of_linear_equations.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/number-theory/min25-sieve/sum_of_totient_function.test.cpp
    title: verify/number-theory/min25-sieve/sum_of_totient_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp
    title: verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomials/linear-recurrence/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: verify/polynomials/linear-recurrence/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomials/multipoint-evaluation/multipoint_evaluation.test.cpp
    title: verify/polynomials/multipoint-evaluation/multipoint_evaluation.test.cpp
  - icon: ':x:'
    path: verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
    title: verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
  - icon: ':x:'
    path: verify/polynomials/taylor-shift/polynomial_taylor_shift.test.cpp
    title: verify/polynomials/taylor-shift/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/tree/link-cut-tree/dynamic_tree_vertex_set_path_composite.test.cpp
    title: verify/tree/link-cut-tree/dynamic_tree_vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/tree/static-top-tree/point_set_tree_path_composite_sum.test.cpp
    title: verify/tree/static-top-tree/point_set_tree_path_composite_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/tree/static-top-tree/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: verify/tree/static-top-tree/point_set_tree_path_composite_sum_fixed_root.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/number-theory/modint.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2026-04-15\n * Description: modular arithmetic operations\n */\n\
    \ntemplate<int mod,int root=0>\nstruct ModInt{\n    using mint = ModInt;\n   \
    \ \n\tstatic_assert(mod>0,\"mod must be positive\");\n\n    int x;\n\n    constexpr\
    \ ModInt():x(0){}\n    constexpr ModInt(ll x):x((x%=mod)<0?x+mod:x){}\n    constexpr\
    \ explicit operator int()const{return x;}\n    constexpr int val()const{return\
    \ x;}\n    constexpr static int get_mod(){return mod;}\n    constexpr static mint\
    \ get_root(){return mint(root);}\n    \n    constexpr mint operator-()const{\n\
    \        mint res;\n        res.x=x?mod-x:0;\n        return res;\n    }\n   \
    \ constexpr mint operator+()const{return *this;}\n\n    constexpr mint inv()const{\n\
    \        int a=x,b=mod,u=1,v=0,q=0;\n        while(b>0){\n            q=a/b;\n\
    \            swap(a-=q*b,b);\n            swap(u-=q*v,v);\n        }\n       \
    \ return mint(u);\n    }\n    constexpr mint pow(ll n)const{\n        mint res=1,a=*this;\n\
    \        for(;n>0;a*=a,n>>=1)if(n&1)res*=a;\n        return res;\n    }\n    constexpr\
    \ mint &operator+=(const mint &o){\n        if((x+=o.x)>=mod)x-=mod;\n       \
    \ return *this;\n    }\n    constexpr mint &operator-=(const mint &o){\n     \
    \   if((x-=o.x)<0)x+=mod;\n        return *this;\n    }\n    constexpr mint &operator*=(const\
    \ mint &o){\n        x=(ll(x)*o.x)%mod;\n        return *this;\n    }\n    constexpr\
    \ mint &operator/=(const mint &o){\n        return *this*=o.inv();\n    }\n\n\
    \    constexpr mint operator+(const mint &o)const{return mint(*this)+=o;}\n  \
    \  constexpr mint operator-(const mint &o)const{return mint(*this)-=o;}\n    constexpr\
    \ mint operator*(const mint &o)const{return mint(*this)*=o;}\n    constexpr mint\
    \ operator/(const mint &o)const{return mint(*this)/=o;}\n\n    constexpr mint\
    \ &operator++(){return *this+=mint(1);}\n    constexpr mint &operator--(){return\
    \ *this-=mint(1);}\n    constexpr mint operator++(int){mint res=*this;*this+=mint(1);return\
    \ res;}\n    constexpr mint operator--(int){mint res=*this;*this-=mint(1);return\
    \ res;}\n    \n    constexpr bool operator==(const mint &o)const{return x==o.x;}\n\
    \    constexpr bool operator!=(const mint &o)const{return x!=o.x;}\n    constexpr\
    \ bool operator<(const mint &o)const{return x<o.x;}\n    \n    friend istream\
    \ &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return is;}\n    friend\
    \ ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n};\nusing mint998\
    \ = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2026-04-15\n * Description:\
    \ modular arithmetic operations\n */\n\ntemplate<int mod,int root=0>\nstruct ModInt{\n\
    \    using mint = ModInt;\n    \n\tstatic_assert(mod>0,\"mod must be positive\"\
    );\n\n    int x;\n\n    constexpr ModInt():x(0){}\n    constexpr ModInt(ll x):x((x%=mod)<0?x+mod:x){}\n\
    \    constexpr explicit operator int()const{return x;}\n    constexpr int val()const{return\
    \ x;}\n    constexpr static int get_mod(){return mod;}\n    constexpr static mint\
    \ get_root(){return mint(root);}\n    \n    constexpr mint operator-()const{\n\
    \        mint res;\n        res.x=x?mod-x:0;\n        return res;\n    }\n   \
    \ constexpr mint operator+()const{return *this;}\n\n    constexpr mint inv()const{\n\
    \        int a=x,b=mod,u=1,v=0,q=0;\n        while(b>0){\n            q=a/b;\n\
    \            swap(a-=q*b,b);\n            swap(u-=q*v,v);\n        }\n       \
    \ return mint(u);\n    }\n    constexpr mint pow(ll n)const{\n        mint res=1,a=*this;\n\
    \        for(;n>0;a*=a,n>>=1)if(n&1)res*=a;\n        return res;\n    }\n    constexpr\
    \ mint &operator+=(const mint &o){\n        if((x+=o.x)>=mod)x-=mod;\n       \
    \ return *this;\n    }\n    constexpr mint &operator-=(const mint &o){\n     \
    \   if((x-=o.x)<0)x+=mod;\n        return *this;\n    }\n    constexpr mint &operator*=(const\
    \ mint &o){\n        x=(ll(x)*o.x)%mod;\n        return *this;\n    }\n    constexpr\
    \ mint &operator/=(const mint &o){\n        return *this*=o.inv();\n    }\n\n\
    \    constexpr mint operator+(const mint &o)const{return mint(*this)+=o;}\n  \
    \  constexpr mint operator-(const mint &o)const{return mint(*this)-=o;}\n    constexpr\
    \ mint operator*(const mint &o)const{return mint(*this)*=o;}\n    constexpr mint\
    \ operator/(const mint &o)const{return mint(*this)/=o;}\n\n    constexpr mint\
    \ &operator++(){return *this+=mint(1);}\n    constexpr mint &operator--(){return\
    \ *this-=mint(1);}\n    constexpr mint operator++(int){mint res=*this;*this+=mint(1);return\
    \ res;}\n    constexpr mint operator--(int){mint res=*this;*this-=mint(1);return\
    \ res;}\n    \n    constexpr bool operator==(const mint &o)const{return x==o.x;}\n\
    \    constexpr bool operator!=(const mint &o)const{return x!=o.x;}\n    constexpr\
    \ bool operator<(const mint &o)const{return x<o.x;}\n    \n    friend istream\
    \ &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return is;}\n    friend\
    \ ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n};\nusing mint998\
    \ = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;"
  dependsOn: []
  isVerificationFile: false
  path: src/number-theory/modint.hpp
  requiredBy:
  - src/polynomials/ntt.hpp
  - src/polynomials/linear-recurrence.hpp
  - src/polynomials/multipoint-evaluation.hpp
  - src/polynomials/polynomial-interpolation.hpp
  - src/polynomials/taylor-shift.hpp
  - src/polynomials/formal-power-series.hpp
  - src/polynomials/subproduct-tree.hpp
  timestamp: '2026-10-26 04:09:11+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/linear-algebra/gauss-mod/inverse_matrix.test.cpp
  - verify/linear-algebra/gauss-mod/matrix_det.test.cpp
  - verify/linear-algebra/gauss-mod/system_of_linear_equations.test.cpp
  - verify/linear-algebra/gauss-mod/matrix_rank.test.cpp
  - verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
  - verify/polynomials/taylor-shift/polynomial_taylor_shift.test.cpp
  - verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp
  - verify/polynomials/linear-recurrence/kth_term_of_linearly_recurrent_sequence.test.cpp
  - verify/polynomials/multipoint-evaluation/multipoint_evaluation.test.cpp
  - verify/number-theory/min25-sieve/sum_of_totient_function.test.cpp
  - verify/tree/link-cut-tree/dynamic_tree_vertex_set_path_composite.test.cpp
  - verify/tree/static-top-tree/point_set_tree_path_composite_sum.test.cpp
  - verify/tree/static-top-tree/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: src/number-theory/modint.hpp
layout: document
redirect_from:
- /library/src/number-theory/modint.hpp
- /library/src/number-theory/modint.hpp.html
title: src/number-theory/modint.hpp
---
