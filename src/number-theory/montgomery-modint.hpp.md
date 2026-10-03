---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/polynomials/formal-power-series.hpp
    title: src/polynomials/formal-power-series.hpp
  - icon: ':heavy_check_mark:'
    path: src/polynomials/linear-recurrence.hpp
    title: src/polynomials/linear-recurrence.hpp
  - icon: ':heavy_check_mark:'
    path: src/polynomials/multipoint-evaluation.hpp
    title: src/polynomials/multipoint-evaluation.hpp
  - icon: ':heavy_check_mark:'
    path: src/polynomials/ntt.hpp
    title: src/polynomials/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: src/polynomials/polynomial-interpolation.hpp
    title: src/polynomials/polynomial-interpolation.hpp
  - icon: ':heavy_check_mark:'
    path: src/polynomials/subproduct-tree.hpp
    title: src/polynomials/subproduct-tree.hpp
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
    path: verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
    title: verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomials/taylor-shift/polynomial_taylor_shift.test.cpp
    title: verify/polynomials/taylor-shift/polynomial_taylor_shift.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/number-theory/montgomery-modint.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2024-03-17\n * Description: modular arithmetic operators\
    \ using Montgomery space\n */\n\ntemplate<uint32_t mod,uint32_t root=0>\nstruct\
    \ MontgomeryModInt{\n    using mint = MontgomeryModInt;\n    using i32 = int32_t;\n\
    \    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static constexpr\
    \ u32 get_r(){\n        u32 res=1;\n        for(i32 i=0;i<5;i++)res*=2-mod*res;\n\
    \        return res;\n    }\n\n    static const u32 r=get_r();\n    static const\
    \ u32 n2=-u64(mod)%mod;\n    static_assert(mod<(1<<30));\n    static_assert((mod&1)==1);\n\
    \    static_assert(r*mod==1);\n\n    u32 x;\n\n    constexpr MontgomeryModInt():x(0){}\n\
    \    constexpr MontgomeryModInt(const int64_t &v):x(reduce(u64(v%mod+mod)*n2)){}\n\
    \n    static constexpr u32 get_mod(){return mod;}\n    static constexpr mint get_root(){return\
    \ mint(root);}\n    explicit constexpr operator int64_t()const{return val();}\n\
    \n    static constexpr u32 reduce(const u64 &v){\n        return (v+u64(u32(v)*u32(-r))*mod)>>32;\n\
    \    }\n\n    constexpr u32 val()const{\n        u32 res=reduce(x);\n        return\
    \ res>=mod?res-mod:res;\n    }\n\n    constexpr mint inv()const{\n        int\
    \ a=val(),b=mod,u=1,v=0,q=0;\n        while(b>0){\n            q=a/b;\n      \
    \      a-=q*b;\n            u-=q*v;\n            swap(a,b);\n            swap(u,v);\n\
    \        }\n        return mint(u);\n    }\n\n    constexpr mint &operator+=(const\
    \ mint &rhs){\n        if(i32(x+=rhs.x-2*mod)<0)x+=2*mod;\n        return *this;\n\
    \    }\n    constexpr mint &operator-=(const mint &rhs){\n        if(i32(x-=rhs.x)<0)x+=2*mod;\n\
    \        return *this;\n    }\n    constexpr mint &operator*=(const mint &rhs){\n\
    \        x=reduce(u64(x)*rhs.x);\n        return *this;\n    }\n    constexpr\
    \ mint &operator/=(const mint &rhs){\n        return *this*=rhs.inv();\n    }\n\
    \n    constexpr mint &operator++(){return *this+=mint(1);}\n    constexpr mint\
    \ &operator--(){return *this-=mint(1);}\n    constexpr mint operator++(int){\n\
    \        mint res=*this;\n        return *this+=mint(1),res;\n    }\n    constexpr\
    \ mint operator--(int){\n        mint res=*this;\n        return *this-=mint(1),res;\n\
    \    }\n\n    constexpr mint operator-()const{return mint()-mint(*this);};\n \
    \   constexpr mint operator+()const{return mint(*this);};\n\n    friend constexpr\
    \ mint operator+(const mint &lhs,const mint &rhs){return mint(lhs)+=rhs;}\n  \
    \  friend constexpr mint operator-(const mint &lhs,const mint &rhs){return mint(lhs)-=rhs;}\n\
    \    friend constexpr mint operator*(const mint &lhs,const mint &rhs){return mint(lhs)*=rhs;}\n\
    \    friend constexpr mint operator/(const mint &lhs,const mint &rhs){return mint(lhs)/=rhs;}\n\
    \    friend constexpr bool operator==(const mint &lhs,const mint &rhs){\n    \
    \    return (lhs.x>=mod?lhs.x-mod:lhs.x)==(rhs.x>=mod?rhs.x-mod:rhs.x);\n    }\n\
    \    friend constexpr bool operator!=(const mint &lhs,const mint &rhs){\n    \
    \    return (lhs.x>=mod?lhs.x-mod:lhs.x)!=(rhs.x>=mod?rhs.x-mod:rhs.x);\n    }\n\
    \    friend constexpr bool operator<(const mint &lhs,const mint &rhs){\n     \
    \   return (lhs.x>=mod?lhs.x-mod:lhs.x)<(rhs.x>=mod?rhs.x-mod:rhs.x); // for std::map\n\
    \    }\n\n    friend istream &operator>>(istream &is,mint &o){\n        int64_t\
    \ v;\n        is >> v;\n        o=mint(v);\n        return is;\n    }\n    friend\
    \ ostream &operator<<(ostream &os,const mint &o){\n        return os << o.val();\n\
    \    }\n};\nusing mint998 = MontgomeryModInt<998244353,3>;\nusing mint107 = MontgomeryModInt<1000000007>;\n\
    \n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2024-03-17\n * Description:\
    \ modular arithmetic operators using Montgomery space\n */\n\ntemplate<uint32_t\
    \ mod,uint32_t root=0>\nstruct MontgomeryModInt{\n    using mint = MontgomeryModInt;\n\
    \    using i32 = int32_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \n    static constexpr u32 get_r(){\n        u32 res=1;\n        for(i32 i=0;i<5;i++)res*=2-mod*res;\n\
    \        return res;\n    }\n\n    static const u32 r=get_r();\n    static const\
    \ u32 n2=-u64(mod)%mod;\n    static_assert(mod<(1<<30));\n    static_assert((mod&1)==1);\n\
    \    static_assert(r*mod==1);\n\n    u32 x;\n\n    constexpr MontgomeryModInt():x(0){}\n\
    \    constexpr MontgomeryModInt(const int64_t &v):x(reduce(u64(v%mod+mod)*n2)){}\n\
    \n    static constexpr u32 get_mod(){return mod;}\n    static constexpr mint get_root(){return\
    \ mint(root);}\n    explicit constexpr operator int64_t()const{return val();}\n\
    \n    static constexpr u32 reduce(const u64 &v){\n        return (v+u64(u32(v)*u32(-r))*mod)>>32;\n\
    \    }\n\n    constexpr u32 val()const{\n        u32 res=reduce(x);\n        return\
    \ res>=mod?res-mod:res;\n    }\n\n    constexpr mint inv()const{\n        int\
    \ a=val(),b=mod,u=1,v=0,q=0;\n        while(b>0){\n            q=a/b;\n      \
    \      a-=q*b;\n            u-=q*v;\n            swap(a,b);\n            swap(u,v);\n\
    \        }\n        return mint(u);\n    }\n\n    constexpr mint &operator+=(const\
    \ mint &rhs){\n        if(i32(x+=rhs.x-2*mod)<0)x+=2*mod;\n        return *this;\n\
    \    }\n    constexpr mint &operator-=(const mint &rhs){\n        if(i32(x-=rhs.x)<0)x+=2*mod;\n\
    \        return *this;\n    }\n    constexpr mint &operator*=(const mint &rhs){\n\
    \        x=reduce(u64(x)*rhs.x);\n        return *this;\n    }\n    constexpr\
    \ mint &operator/=(const mint &rhs){\n        return *this*=rhs.inv();\n    }\n\
    \n    constexpr mint &operator++(){return *this+=mint(1);}\n    constexpr mint\
    \ &operator--(){return *this-=mint(1);}\n    constexpr mint operator++(int){\n\
    \        mint res=*this;\n        return *this+=mint(1),res;\n    }\n    constexpr\
    \ mint operator--(int){\n        mint res=*this;\n        return *this-=mint(1),res;\n\
    \    }\n\n    constexpr mint operator-()const{return mint()-mint(*this);};\n \
    \   constexpr mint operator+()const{return mint(*this);};\n\n    friend constexpr\
    \ mint operator+(const mint &lhs,const mint &rhs){return mint(lhs)+=rhs;}\n  \
    \  friend constexpr mint operator-(const mint &lhs,const mint &rhs){return mint(lhs)-=rhs;}\n\
    \    friend constexpr mint operator*(const mint &lhs,const mint &rhs){return mint(lhs)*=rhs;}\n\
    \    friend constexpr mint operator/(const mint &lhs,const mint &rhs){return mint(lhs)/=rhs;}\n\
    \    friend constexpr bool operator==(const mint &lhs,const mint &rhs){\n    \
    \    return (lhs.x>=mod?lhs.x-mod:lhs.x)==(rhs.x>=mod?rhs.x-mod:rhs.x);\n    }\n\
    \    friend constexpr bool operator!=(const mint &lhs,const mint &rhs){\n    \
    \    return (lhs.x>=mod?lhs.x-mod:lhs.x)!=(rhs.x>=mod?rhs.x-mod:rhs.x);\n    }\n\
    \    friend constexpr bool operator<(const mint &lhs,const mint &rhs){\n     \
    \   return (lhs.x>=mod?lhs.x-mod:lhs.x)<(rhs.x>=mod?rhs.x-mod:rhs.x); // for std::map\n\
    \    }\n\n    friend istream &operator>>(istream &is,mint &o){\n        int64_t\
    \ v;\n        is >> v;\n        o=mint(v);\n        return is;\n    }\n    friend\
    \ ostream &operator<<(ostream &os,const mint &o){\n        return os << o.val();\n\
    \    }\n};\nusing mint998 = MontgomeryModInt<998244353,3>;\nusing mint107 = MontgomeryModInt<1000000007>;\n\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: src/number-theory/montgomery-modint.hpp
  requiredBy:
  - src/polynomials/taylor-shift.hpp
  - src/polynomials/polynomial-interpolation.hpp
  - src/polynomials/subproduct-tree.hpp
  - src/polynomials/ntt.hpp
  - src/polynomials/formal-power-series.hpp
  - src/polynomials/linear-recurrence.hpp
  - src/polynomials/multipoint-evaluation.hpp
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/linear-algebra/gauss-mod/system_of_linear_equations.test.cpp
  - verify/linear-algebra/gauss-mod/inverse_matrix.test.cpp
  - verify/linear-algebra/gauss-mod/matrix_rank.test.cpp
  - verify/linear-algebra/gauss-mod/matrix_det.test.cpp
  - verify/polynomials/taylor-shift/polynomial_taylor_shift.test.cpp
  - verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp
  - verify/polynomials/linear-recurrence/kth_term_of_linearly_recurrent_sequence.test.cpp
  - verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
  - verify/polynomials/multipoint-evaluation/multipoint_evaluation.test.cpp
  - verify/number-theory/min25-sieve/sum_of_totient_function.test.cpp
documentation_of: src/number-theory/montgomery-modint.hpp
layout: document
redirect_from:
- /library/src/number-theory/montgomery-modint.hpp
- /library/src/number-theory/montgomery-modint.hpp.html
title: src/number-theory/montgomery-modint.hpp
---
