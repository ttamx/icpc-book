---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/number-theory/montgomery-modint.hpp
    title: src/number-theory/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/polynomials/berlekamp-massey.hpp
    title: src/polynomials/berlekamp-massey.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
    links:
    - https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "#line 1 \"verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\n\
    #line 2 \"src/contest/template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n \nusing namespace std;\nusing namespace\
    \ __gnu_pbds;\n\n#define pb push_back\n#define eb emplace_back\n\n#define ALL(a)\
    \ a.begin(),a.end()\n#define RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n\
    #define RSORT(a) sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n#define UNI(a)\
    \ a.erase(unique(ALL(a)),a.end())\n#define SZ(a) (int)(a.size())\n#define LB(a,x)\
    \ (int)(lower_bound(ALL(a),x)-a.begin())\n#define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n\
    #define MIN(a) *min_element(ALL(a))\n#define MAX(a) *max_element(ALL(a))\n\nusing\
    \ ll = long long;\nusing db = long double;\nusing i128 = __int128_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\n\nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst int MOD=998244353;\nconst\
    \ int MOD2=1000000007;\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\ntemplate<class\
    \ T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\ntemplate<class T,class\
    \ U>\nbool chmin(T &a,U b){return b<a?a=b,1:0;}\ntemplate<class T,class U>\nbool\
    \ chmax(T &a,U b){return a<b?a=b,1:0;}\ntemplate<class T,class U>\nT SUM(const\
    \ U &a){return accumulate(ALL(a),T{});}\n\ntemplate<class T>\nusing ordered_set\
    \ = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/polynomials/berlekamp-massey.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Description: Finds the shortest recurrence $c$\
    \ of length $L$ with\n * $s_i = \\sum_{j=1}^{L} c_{j-1} s_{i-j}$ for all $L \\\
    le i < n$.\n * Needs $2L$ terms to recover a recurrence of order $L$.\n * Usage:\
    \ berlekamp_massey(vector<mint>{0,1,1,3,5,11}) // {1,2}\n * Time: $O(N^2)$\n */\n\
    \ntemplate<class mint>\nvector<mint> berlekamp_massey(const vector<mint> &s){\n\
    \    int n=SZ(s),L=0,m=0;\n    vector<mint> C(n+1),B(n+1),T;\n    C[0]=B[0]=1;\n\
    \    mint b=1;\n    for(int i=0;i<n;i++){\n        m++;\n        mint d=s[i];\n\
    \        for(int j=1;j<=L;j++)d+=C[j]*s[i-j];\n        if(d==mint(0))continue;\n\
    \        T=C;\n        mint coef=d/b;\n        for(int j=m;j<=n;j++)C[j]-=coef*B[j-m];\n\
    \        if(2*L>i)continue;\n        L=i+1-L,B=T,b=d,m=0;\n    }\n    vector<mint>\
    \ c(L);\n    for(int i=0;i<L;i++)c[i]=-C[i+1];\n    return c;\n}\n#line 2 \"src/number-theory/montgomery-modint.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-03-17\n * Description: modular arithmetic\
    \ operators using Montgomery space\n */\n\ntemplate<uint32_t mod,uint32_t root=0>\n\
    struct MontgomeryModInt{\n    using mint = MontgomeryModInt;\n    using i32 =\
    \ int32_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static\
    \ constexpr u32 get_r(){\n        u32 res=1;\n        for(i32 i=0;i<5;i++)res*=2-mod*res;\n\
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
    \n#line 5 \"verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp\"\
    \n\nusing mint = mint998;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n;\n    cin >> n;\n    vector<mint> a(n);\n    for(auto &x:a)cin >> x;\n\
    \    auto c=berlekamp_massey(a);\n    int d=c.size();\n    cout << d << \"\\n\"\
    ;\n    for(int i=0;i<d;i++)cout << c[i] << \" \\n\"[i==d-1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n#include \"src/contest/template.hpp\"\n#include \"src/polynomials/berlekamp-massey.hpp\"\
    \n#include \"src/number-theory/montgomery-modint.hpp\"\n\nusing mint = mint998;\n\
    \nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n;\n   \
    \ cin >> n;\n    vector<mint> a(n);\n    for(auto &x:a)cin >> x;\n    auto c=berlekamp_massey(a);\n\
    \    int d=c.size();\n    cout << d << \"\\n\";\n    for(int i=0;i<d;i++)cout\
    \ << c[i] << \" \\n\"[i==d-1];\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/polynomials/berlekamp-massey.hpp
  - src/number-theory/montgomery-modint.hpp
  isVerificationFile: true
  path: verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp
layout: document
redirect_from:
- /verify/verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp
- /verify/verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp.html
title: verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp
---
