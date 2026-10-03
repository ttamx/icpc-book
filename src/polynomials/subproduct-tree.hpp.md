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
    path: src/polynomials/formal-power-series.hpp
    title: src/polynomials/formal-power-series.hpp
  - icon: ':heavy_check_mark:'
    path: src/polynomials/ntt.hpp
    title: src/polynomials/ntt.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/polynomials/multipoint-evaluation.hpp
    title: src/polynomials/multipoint-evaluation.hpp
  - icon: ':heavy_check_mark:'
    path: src/polynomials/polynomial-interpolation.hpp
    title: src/polynomials/polynomial-interpolation.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/polynomials/multipoint-evaluation/multipoint_evaluation.test.cpp
    title: verify/polynomials/multipoint-evaluation/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
    title: verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
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
    \ vm &b){\n\t\treturn conv(a,b);\n\t}\n};\n\n#line 3 \"src/polynomials/formal-power-series.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-03-17\n * Description: basic operations\
    \ of formal power series\n */\n\ntemplate<class mint>\nstruct FormalPowerSeries:vector<mint>{\n\
    \    using vector<mint>::vector;\n    using FPS = FormalPowerSeries;\n\n    FPS\
    \ &operator+=(const FPS &r){\n        if(r.size()>this->size())this->resize(r.size());\n\
    \        for(int i=0;i<r.size();i++)(*this)[i]+=r[i];\n        return *this;\n\
    \    }\n    FPS &operator+=(const mint &r){\n        if(this->empty())this->resize(1);\n\
    \        (*this)[0]+=r;\n        return *this;\n    }\n    FPS &operator-=(const\
    \ FPS &r){\n        if(r.size()>this->size())this->resize(r.size());\n       \
    \ for(int i=0;i<r.size();i++)(*this)[i]-=r[i];\n        return *this;\n    }\n\
    \    FPS &operator-=(const mint &r){\n        if(this->empty())this->resize(1);\n\
    \        (*this)[0]-=r;\n        return *this;\n    }\n    FPS &operator*=(const\
    \ FPS &r){\n        auto res=NTT<mint>()(*this,r);\n        return *this=FPS(res.begin(),res.end());\n\
    \    }\n    FPS &operator*=(const mint &r){\n        for(auto &a:*this)a*=r;\n\
    \        return *this;\n    }\n    FPS &operator/=(const FPS &r){ // r.back()!=0\n\
    \        if(this->size()<r.size())return *this=FPS();\n        int n=this->size()-r.size()+1;\n\
    \        return *this=(rev().pre(n)*r.rev().inv(n)).pre(n).rev();\n    }\n   \
    \ FPS &operator%=(const FPS &r){\n        *this-=*this/r*r;\n        return *this=pre(r.size()-1).shrink();\n\
    \    }\n\n    friend FPS operator+(FPS l,const FPS &r){return l+=r;}\n    friend\
    \ FPS operator+(FPS l,const mint &r){return l+=r;}\n    friend FPS operator+(const\
    \ mint &l,FPS r){return r+=l;}\n    friend FPS operator-(FPS l,const FPS &r){return\
    \ l-=r;}\n    friend FPS operator-(FPS l,const mint &r){return l-=r;}\n    friend\
    \ FPS operator-(const mint &l,FPS r){return -(r-l);}\n    friend FPS operator*(FPS\
    \ l,const FPS &r){return l*=r;}\n    friend FPS operator*(FPS l,const mint &r){return\
    \ l*=r;}\n    friend FPS operator*(const mint &l,FPS r){return r*=l;}\n    friend\
    \ FPS operator/(FPS l,const FPS &r){return l/=r;}\n    friend FPS operator%(FPS\
    \ l,const FPS &r){return l%=r;}\n\n    FPS operator-()const{return (*this)*-1;}\n\
    \n    FPS rev()const{\n        FPS res(*this);\n        reverse(res.begin(),res.end());\n\
    \        return res;\n    }\n    FPS pre(int sz)const{\n        FPS res(this->begin(),this->begin()+min((int)this->size(),sz));\n\
    \        if(res.size()<sz)res.resize(sz);\n        return res;\n    }\n    FPS\
    \ shrink()const{\n        FPS res(*this);\n        while(!res.empty()&&res.back()==mint{})res.pop_back();\n\
    \        return res;\n    }\n    FPS operator>>(int sz)const{\n        if(this->size()<=sz)return\
    \ {};\n        FPS res(*this);\n        res.erase(res.begin(),res.begin()+sz);\n\
    \        return res;\n    }\n    FPS operator<<(int sz)const{\n        FPS res(*this);\n\
    \        res.insert(res.begin(),sz,mint{});\n        return res;\n    }\n    FPS\
    \ diff()const{\n        const int n=this->size();\n        FPS res(max(0,n-1));\n\
    \        for(int i=1;i<n;i++)res[i-1]=(*this)[i]*mint(i);\n        return res;\n\
    \    }\n    FPS integral()const{\n        const int n=this->size();\n        FPS\
    \ res(n+1);\n        res[0]=0;\n        if(n>0)res[1]=1;\n        ll mod=mint::get_mod();\n\
    \        for(int i=2;i<=n;i++)res[i]=(-res[mod%i])*(mod/i);\n        for(int i=0;i<n;i++)res[i+1]*=(*this)[i];\n\
    \        return res;\n    }\n    mint eval(const mint &x)const{\n        mint\
    \ res=0,w=1;\n        for(auto &a:*this)res+=a*w,w*=x;\n        return res;\n\
    \    }\n\n    FPS inv(int deg=-1)const{\n        assert(!this->empty()&&(*this)[0]!=mint(0));\n\
    \        if(deg==-1)deg=this->size();\n        FPS res{mint(1)/(*this)[0]};\n\
    \        for(int i=2;i>>1<deg;i<<=1){\n            res=(res*(mint(2)-res*pre(i))).pre(i);\n\
    \        }\n        return res.pre(deg);\n    }\n    FPS log(int deg=-1)const{\n\
    \        assert(!this->empty()&&(*this)[0]==mint(1));\n        if(deg==-1)deg=this->size();\n\
    \        return (pre(deg).diff()*inv(deg)).pre(deg-1).integral();\n    }\n   \
    \ FPS exp(int deg=-1)const{\n        assert(this->empty()||(*this)[0]==mint(0));\n\
    \        if(deg==-1)deg=this->size();\n        FPS res{mint(1)};\n        for(int\
    \ i=2;i>>1<deg;i<<=1){\n            res=(res*(pre(i)-res.log(i)+mint(1))).pre(i);\n\
    \        }\n        return res.pre(deg);\n    }\n    FPS pow(ll k,int deg=-1)const{\n\
    \        const int n=this->size();\n        if(deg==-1)deg=n;\n        if(k==0){\n\
    \            FPS res(deg);\n            if(deg)res[0]=mint(1);\n            return\
    \ res;\n        }\n        for(int i=0;i<n;i++){\n            if(__int128_t(i)*k>=deg)return\
    \ FPS(deg,mint(0));\n            if((*this)[i]==mint(0))continue;\n          \
    \  mint rev=mint(1)/(*this)[i];\n            FPS res=(((*this*rev)>>i).log(deg)*k).exp(deg);\n\
    \            res=((res*binpow((*this)[i],k))<<(i*k)).pre(deg);\n            return\
    \ res;\n        }\n        return FPS(deg,mint(0));\n    }\n};\n#line 3 \"src/polynomials/subproduct-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Description: Subproduct tree of points $x_0,\
    \ \\dots, x_{m-1}$.\n * Node $i$ covers $[l, r)$ and stores $\\prod_{l \\le j\
    \ < r} (x - x_j)$, root is node $1$.\n * Time: $O(M \\log^2 M)$\n */\n\ntemplate<class\
    \ mint>\nstruct SubproductTree{\n    int m;\n    vector<mint> xs;\n    vector<FormalPowerSeries<mint>>\
    \ t;\n    SubproductTree(const vector<mint> &xs)\n        :m(xs.size()),xs(xs),t(4*m){if(m)build(1,0,m);}\n\
    \    void build(int i,int l,int r){\n        if(r-l==1)return void(t[i]={-xs[l],1});\n\
    \        int mid=(l+r)/2;\n        build(2*i,l,mid),build(2*i+1,mid,r);\n    \
    \    t[i]=t[2*i]*t[2*i+1];\n    }\n};\n"
  code: "#pragma once\n#include \"src/polynomials/formal-power-series.hpp\"\n\n/**\n\
    \ * Author: Teetat T.\n * Description: Subproduct tree of points $x_0, \\dots,\
    \ x_{m-1}$.\n * Node $i$ covers $[l, r)$ and stores $\\prod_{l \\le j < r} (x\
    \ - x_j)$, root is node $1$.\n * Time: $O(M \\log^2 M)$\n */\n\ntemplate<class\
    \ mint>\nstruct SubproductTree{\n    int m;\n    vector<mint> xs;\n    vector<FormalPowerSeries<mint>>\
    \ t;\n    SubproductTree(const vector<mint> &xs)\n        :m(xs.size()),xs(xs),t(4*m){if(m)build(1,0,m);}\n\
    \    void build(int i,int l,int r){\n        if(r-l==1)return void(t[i]={-xs[l],1});\n\
    \        int mid=(l+r)/2;\n        build(2*i,l,mid),build(2*i+1,mid,r);\n    \
    \    t[i]=t[2*i]*t[2*i+1];\n    }\n};\n"
  dependsOn:
  - src/polynomials/formal-power-series.hpp
  - src/polynomials/ntt.hpp
  - src/number-theory/binpow.hpp
  - src/number-theory/montgomery-modint.hpp
  isVerificationFile: false
  path: src/polynomials/subproduct-tree.hpp
  requiredBy:
  - src/polynomials/polynomial-interpolation.hpp
  - src/polynomials/multipoint-evaluation.hpp
  timestamp: '2026-10-04 01:15:02+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/polynomials/polynomial-interpolation/polynomial_interpolation.test.cpp
  - verify/polynomials/multipoint-evaluation/multipoint_evaluation.test.cpp
documentation_of: src/polynomials/subproduct-tree.hpp
layout: document
redirect_from:
- /library/src/polynomials/subproduct-tree.hpp
- /library/src/polynomials/subproduct-tree.hpp.html
title: src/polynomials/subproduct-tree.hpp
---
