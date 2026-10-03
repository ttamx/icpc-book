---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/number-theory/binpow.hpp
    title: src/number-theory/binpow.hpp
  - icon: ':heavy_check_mark:'
    path: src/number-theory/montgomery-modint.hpp
    title: src/number-theory/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/polynomials/ntt.hpp
    title: src/polynomials/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/polynomials/linear-recurrence/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: verify/polynomials/linear-recurrence/kth_term_of_linearly_recurrent_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/number-theory/binpow.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-01-15\n * Description: n-th power using divide and conquer\n\
    \ * Time: $O(\\log b)$\n */\n\ntemplate<class T>\nconstexpr T binpow(T a,ll b){\n\
    \    T res=1;\n    for(;b>0;b>>=1,a*=a)if(b&1)res*=a;\n    return res;\n}\n\n\
    #line 2 \"src/number-theory/montgomery-modint.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Date: 2024-03-17\n * Description: modular arithmetic operators using\
    \ Montgomery space\n */\n\ntemplate<uint32_t mod,uint32_t root=0>\nstruct MontgomeryModInt{\n\
    \    using mint = MontgomeryModInt;\n    using i32 = int32_t;\n    using u32 =\
    \ uint32_t;\n    using u64 = uint64_t;\n\n    static constexpr u32 get_r(){\n\
    \        u32 res=1;\n        for(i32 i=0;i<5;i++)res*=2-mod*res;\n        return\
    \ res;\n    }\n\n    static const u32 r=get_r();\n    static const u32 n2=-u64(mod)%mod;\n\
    \    static_assert(mod<(1<<30));\n    static_assert((mod&1)==1);\n    static_assert(r*mod==1);\n\
    \n    u32 x;\n\n    constexpr MontgomeryModInt():x(0){}\n    constexpr MontgomeryModInt(const\
    \ int64_t &v):x(reduce(u64(v%mod+mod)*n2)){}\n\n    static constexpr u32 get_mod(){return\
    \ mod;}\n    static constexpr mint get_root(){return mint(root);}\n    explicit\
    \ constexpr operator int64_t()const{return val();}\n\n    static constexpr u32\
    \ reduce(const u64 &v){\n        return (v+u64(u32(v)*u32(-r))*mod)>>32;\n   \
    \ }\n\n    constexpr u32 val()const{\n        u32 res=reduce(x);\n        return\
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
    \n#line 4 \"src/polynomials/ntt.hpp\"\n\n/**\n * Author: Teetat T.\n * Description:\
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
    \ vm &b){\n\t\treturn conv(a,b);\n\t}\n};\n\n#line 3 \"src/polynomials/linear-recurrence.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Description: $k$-th term of $a_i = \\sum_{j=1}^{L}\
    \ c_{j-1} a_{i-j}$\n * given $a_0, \\dots, a_{L-1}$ (Bostan-Mori, $a_k = [x^k]\
    \ P/Q$).\n * Given only the first $2L$ terms $s$, combine with Berlekamp-Massey.\n\
    \ * Usage: linear_recurrence<mint>({0,1},{1,1},10) // 55\n * linear_recurrence(s,berlekamp_massey(s),k)\n\
    \ * Time: $O(L \\log L \\log k)$\n */\n\ntemplate<class mint>\nmint linear_recurrence(const\
    \ vector<mint> &a,\n    const vector<mint> &c,ll k){\n    if(k<SZ(a))return a[k];\n\
    \    int L=SZ(c),n=2,h;\n    if(!L)return 0;\n    while(n<=2*L)n*=2;\n    h=n/2;\n\
    \    vector<mint> P(n),Q(n),A(n),B(n);\n    Q[0]=1;\n    for(int i=0;i<L;i++)Q[i+1]=-c[i];\n\
    \    auto t=NTT<mint>::conv(vector<mint>(a.begin(),\n        a.begin()+L),vector<mint>(Q.begin(),Q.begin()+L+1));\n\
    \    copy(t.begin(),t.begin()+L,P.begin());\n    mint iv=mint(n).inv();\n    for(;k;k>>=1){\n\
    \        NTT<mint>::ntt(P),NTT<mint>::ntt(Q);\n        for(int i=0;i<n;i++){ //\
    \ Q(-x) <-> index i^h\n            A[-i&(n-1)]=P[i]*Q[i^h]*iv;\n            B[-i&(n-1)]=Q[i]*Q[i^h]*iv;\n\
    \        }\n        NTT<mint>::ntt(A),NTT<mint>::ntt(B);\n        fill(ALL(P),0),fill(ALL(Q),0);\n\
    \        for(int i=0;i<L;i++)P[i]=A[2*i+(k&1)];\n        for(int i=0;i<=L;i++)Q[i]=B[2*i];\n\
    \    }\n    return P[0];\n}\n"
  code: "#pragma once\n#include \"src/polynomials/ntt.hpp\"\n\n/**\n * Author: Teetat\
    \ T.\n * Description: $k$-th term of $a_i = \\sum_{j=1}^{L} c_{j-1} a_{i-j}$\n\
    \ * given $a_0, \\dots, a_{L-1}$ (Bostan-Mori, $a_k = [x^k] P/Q$).\n * Given only\
    \ the first $2L$ terms $s$, combine with Berlekamp-Massey.\n * Usage: linear_recurrence<mint>({0,1},{1,1},10)\
    \ // 55\n * linear_recurrence(s,berlekamp_massey(s),k)\n * Time: $O(L \\log L\
    \ \\log k)$\n */\n\ntemplate<class mint>\nmint linear_recurrence(const vector<mint>\
    \ &a,\n    const vector<mint> &c,ll k){\n    if(k<SZ(a))return a[k];\n    int\
    \ L=SZ(c),n=2,h;\n    if(!L)return 0;\n    while(n<=2*L)n*=2;\n    h=n/2;\n  \
    \  vector<mint> P(n),Q(n),A(n),B(n);\n    Q[0]=1;\n    for(int i=0;i<L;i++)Q[i+1]=-c[i];\n\
    \    auto t=NTT<mint>::conv(vector<mint>(a.begin(),\n        a.begin()+L),vector<mint>(Q.begin(),Q.begin()+L+1));\n\
    \    copy(t.begin(),t.begin()+L,P.begin());\n    mint iv=mint(n).inv();\n    for(;k;k>>=1){\n\
    \        NTT<mint>::ntt(P),NTT<mint>::ntt(Q);\n        for(int i=0;i<n;i++){ //\
    \ Q(-x) <-> index i^h\n            A[-i&(n-1)]=P[i]*Q[i^h]*iv;\n            B[-i&(n-1)]=Q[i]*Q[i^h]*iv;\n\
    \        }\n        NTT<mint>::ntt(A),NTT<mint>::ntt(B);\n        fill(ALL(P),0),fill(ALL(Q),0);\n\
    \        for(int i=0;i<L;i++)P[i]=A[2*i+(k&1)];\n        for(int i=0;i<=L;i++)Q[i]=B[2*i];\n\
    \    }\n    return P[0];\n}\n"
  dependsOn:
  - src/polynomials/ntt.hpp
  - src/number-theory/binpow.hpp
  - src/number-theory/montgomery-modint.hpp
  isVerificationFile: false
  path: src/polynomials/linear-recurrence.hpp
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/polynomials/linear-recurrence/kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: src/polynomials/linear-recurrence.hpp
layout: document
redirect_from:
- /library/src/polynomials/linear-recurrence.hpp
- /library/src/polynomials/linear-recurrence.hpp.html
title: src/polynomials/linear-recurrence.hpp
---
