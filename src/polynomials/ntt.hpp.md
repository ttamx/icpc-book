---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/number-theory/binpow.hpp
    title: src/number-theory/binpow.hpp
  - icon: ':question:'
    path: src/number-theory/modint.hpp
    title: src/number-theory/modint.hpp
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/number-theory/binpow.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-01-15\n * Description: n-th power using divide and conquer\n\
    \ * Time: $O(\\log b)$\n */\n\ntemplate<class T>\nconstexpr T binpow(T a,ll b){\n\
    \    T res=1;\n    for(;b>0;b>>=1,a*=a)if(b&1)res*=a;\n    return res;\n}\n\n\
    #line 2 \"src/number-theory/modint.hpp\"\n\n/**\n * Author: Teetat T.\n * Date:\
    \ 2026-04-15\n * Description: modular arithmetic operations\n */\n\ntemplate<int\
    \ mod,int root=0>\nstruct ModInt{\n    using mint = ModInt;\n    \n\tstatic_assert(mod>0,\"\
    mod must be positive\");\n\n    int x;\n\n    constexpr ModInt():x(0){}\n    constexpr\
    \ ModInt(ll x):x((x%=mod)<0?x+mod:x){}\n    constexpr explicit operator int()const{return\
    \ x;}\n    constexpr int val()const{return x;}\n    constexpr static int get_mod(){return\
    \ mod;}\n    constexpr static mint get_root(){return mint(root);}\n    \n    constexpr\
    \ mint operator-()const{\n        mint res;\n        res.x=x?mod-x:0;\n      \
    \  return res;\n    }\n    constexpr mint operator+()const{return *this;}\n\n\
    \    constexpr mint inv()const{\n        int a=x,b=mod,u=1,v=0,q=0;\n        while(b>0){\n\
    \            q=a/b;\n            swap(a-=q*b,b);\n            swap(u-=q*v,v);\n\
    \        }\n        return mint(u);\n    }\n    constexpr mint pow(ll n)const{\n\
    \        mint res=1,a=*this;\n        for(;n>0;a*=a,n>>=1)if(n&1)res*=a;\n   \
    \     return res;\n    }\n    constexpr mint &operator+=(const mint &o){\n   \
    \     if((x+=o.x)>=mod)x-=mod;\n        return *this;\n    }\n    constexpr mint\
    \ &operator-=(const mint &o){\n        if((x-=o.x)<0)x+=mod;\n        return *this;\n\
    \    }\n    constexpr mint &operator*=(const mint &o){\n        x=(ll(x)*o.x)%mod;\n\
    \        return *this;\n    }\n    constexpr mint &operator/=(const mint &o){\n\
    \        return *this*=o.inv();\n    }\n\n    constexpr mint operator+(const mint\
    \ &o)const{return mint(*this)+=o;}\n    constexpr mint operator-(const mint &o)const{return\
    \ mint(*this)-=o;}\n    constexpr mint operator*(const mint &o)const{return mint(*this)*=o;}\n\
    \    constexpr mint operator/(const mint &o)const{return mint(*this)/=o;}\n\n\
    \    constexpr mint &operator++(){return *this+=mint(1);}\n    constexpr mint\
    \ &operator--(){return *this-=mint(1);}\n    constexpr mint operator++(int){mint\
    \ res=*this;*this+=mint(1);return res;}\n    constexpr mint operator--(int){mint\
    \ res=*this;*this-=mint(1);return res;}\n    \n    constexpr bool operator==(const\
    \ mint &o)const{return x==o.x;}\n    constexpr bool operator!=(const mint &o)const{return\
    \ x!=o.x;}\n    constexpr bool operator<(const mint &o)const{return x<o.x;}\n\
    \    \n    friend istream &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return\
    \ is;}\n    friend ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n\
    };\nusing mint998 = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;\n\
    #line 4 \"src/polynomials/ntt.hpp\"\n\n/**\n * Author: Teetat T.\n * Description:\
    \ Number Theoretic Transform\n * Time: $O(N \\log N)$\n */\n\n// For p < 2^30\
    \ there is also e.g. 5 << 25, 7 << 26, 479 << 21\n// and 483 << 21 (same root\
    \ = 62). The last two are > 10^9.\n\ntemplate<class mint>\nstruct NTT{\n\tusing\
    \ vm = vector<mint>;\n\t\n\tstatic constexpr mint root=mint::get_root();\n   \
    \ static_assert(root!=0);\n\n\tstatic void ntt(vm &a){\n\t\tint n=a.size(),L=31-__builtin_clz(n);\n\
    \t\tvm rt(n);\n\t\trt[1]=1;\n\t\tfor(int k=2,s=2;k<n;k*=2,s++){\n\t\t\tmint z[]={1,binpow(root,mint::get_mod()>>s)};\n\
    \t\t\tfor(int i=k;i<2*k;i++)rt[i]=rt[i/2]*z[i&1];\n\t\t}\n\t\tvector<int> rev(n);\n\
    \t\tfor(int i=1;i<n;i++)rev[i]=(rev[i/2]|(i&1)<<L)/2;\n\t\tfor(int i=1;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);\n\
    \t\tfor(int k=1;k<n;k*=2)for(int i=0;i<n;i+=2*k)for(int j=0;j<k;j++){\n\t\t\t\
    mint z=rt[j+k]*a[i+j+k];\n\t\t\ta[i+j+k]=a[i+j]-z;\n\t\t\ta[i+j]+=z;\n\t\t}\n\t\
    }\n\tstatic vm conv(const vm &a,const vm &b){\n\t\tif(a.empty()||b.empty())return\
    \ {};\n\t\tint s=a.size()+b.size()-1,n=2;\n\t\twhile(n<s)n<<=1;\n\t\tmint inv=mint(n).inv();\n\
    \t\tvm in1(a),in2(b),out(n);\n\t\tin1.resize(n),in2.resize(n);\n\t\tntt(in1),ntt(in2);\n\
    \t\tfor(int i=0;i<n;i++)out[-i&(n-1)]=in1[i]*in2[i]*inv;\n\t\tntt(out);\n\t\t\
    return vm(out.begin(),out.begin()+s);\n\t}\n\tvm operator()(const vm &a,const\
    \ vm &b){\n\t\treturn conv(a,b);\n\t}\n};\n\n"
  code: "#pragma once\n#include \"src/number-theory/binpow.hpp\"\n#include \"src/number-theory/modint.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Description: Number Theoretic Transform\n *\
    \ Time: $O(N \\log N)$\n */\n\n// For p < 2^30 there is also e.g. 5 << 25, 7 <<\
    \ 26, 479 << 21\n// and 483 << 21 (same root = 62). The last two are > 10^9.\n\
    \ntemplate<class mint>\nstruct NTT{\n\tusing vm = vector<mint>;\n\t\n\tstatic\
    \ constexpr mint root=mint::get_root();\n    static_assert(root!=0);\n\n\tstatic\
    \ void ntt(vm &a){\n\t\tint n=a.size(),L=31-__builtin_clz(n);\n\t\tvm rt(n);\n\
    \t\trt[1]=1;\n\t\tfor(int k=2,s=2;k<n;k*=2,s++){\n\t\t\tmint z[]={1,binpow(root,mint::get_mod()>>s)};\n\
    \t\t\tfor(int i=k;i<2*k;i++)rt[i]=rt[i/2]*z[i&1];\n\t\t}\n\t\tvector<int> rev(n);\n\
    \t\tfor(int i=1;i<n;i++)rev[i]=(rev[i/2]|(i&1)<<L)/2;\n\t\tfor(int i=1;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);\n\
    \t\tfor(int k=1;k<n;k*=2)for(int i=0;i<n;i+=2*k)for(int j=0;j<k;j++){\n\t\t\t\
    mint z=rt[j+k]*a[i+j+k];\n\t\t\ta[i+j+k]=a[i+j]-z;\n\t\t\ta[i+j]+=z;\n\t\t}\n\t\
    }\n\tstatic vm conv(const vm &a,const vm &b){\n\t\tif(a.empty()||b.empty())return\
    \ {};\n\t\tint s=a.size()+b.size()-1,n=2;\n\t\twhile(n<s)n<<=1;\n\t\tmint inv=mint(n).inv();\n\
    \t\tvm in1(a),in2(b),out(n);\n\t\tin1.resize(n),in2.resize(n);\n\t\tntt(in1),ntt(in2);\n\
    \t\tfor(int i=0;i<n;i++)out[-i&(n-1)]=in1[i]*in2[i]*inv;\n\t\tntt(out);\n\t\t\
    return vm(out.begin(),out.begin()+s);\n\t}\n\tvm operator()(const vm &a,const\
    \ vm &b){\n\t\treturn conv(a,b);\n\t}\n};\n\n"
  dependsOn:
  - src/number-theory/binpow.hpp
  - src/number-theory/modint.hpp
  isVerificationFile: false
  path: src/polynomials/ntt.hpp
  requiredBy:
  - src/polynomials/linear-recurrence.hpp
  - src/polynomials/multipoint-evaluation.hpp
  - src/polynomials/polynomial-interpolation.hpp
  - src/polynomials/taylor-shift.hpp
  - src/polynomials/formal-power-series.hpp
  - src/polynomials/subproduct-tree.hpp
  timestamp: '2026-10-26 18:51:44+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
  - verify/polynomials/taylor-shift/polynomial_taylor_shift.test.cpp
  - verify/polynomials/linear-recurrence/kth_term_of_linearly_recurrent_sequence.test.cpp
  - verify/polynomials/multipoint-evaluation/multipoint_evaluation.test.cpp
documentation_of: src/polynomials/ntt.hpp
layout: document
redirect_from:
- /library/src/polynomials/ntt.hpp
- /library/src/polynomials/ntt.hpp.html
title: src/polynomials/ntt.hpp
---
