---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/linear-algebra/gauss-mod.hpp
    title: src/linear-algebra/gauss-mod.hpp
  - icon: ':heavy_check_mark:'
    path: src/number-theory/montgomery-modint.hpp
    title: src/number-theory/montgomery-modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"verify/linear-algebra/gauss-mod/matrix_det.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n#line 2 \"src/contest/template.hpp\"\
    \n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n#include<ext/pb_ds/tree_policy.hpp>\n\
    \ \nusing namespace std;\nusing namespace __gnu_pbds;\n\n#define pb push_back\n\
    #define eb emplace_back\n\n#define ALL(a) a.begin(),a.end()\n#define RALL(a) a.rbegin(),a.rend()\n\
    #define SORT(a) sort(ALL(a))\n#define RSORT(a) sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n\
    #define UNI(a) a.erase(unique(ALL(a)),a.end())\n#define SZ(a) (int)(a.size())\n\
    #define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())\n#define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/number-theory/montgomery-modint.hpp\"\
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
    \n#line 2 \"src/linear-algebra/gauss-mod.hpp\"\n\n/**\n * Author: Teetat T.\n\
    \ * Description: Gauss-Jordan elimination over a field $\\mathbb{Z}_p$.\n * \\\
    texttt{gauss(a,c,d)} reduces $a$ to RREF on its first $c$ columns\n * (later columns\
    \ are carried along), returns pivot columns and sets\n * $d=\\det$ of the left\
    \ $c\\times c$ block (for square use).\n * \\texttt{solve} returns rank or $-1$\
    \ if inconsistent, a solution $x$\n * (free vars $=0$) and a basis $K$ of $\\\
    {x : Ax=0\\}$ ($|K|=m-$rank).\n * \\texttt{mat\\_inv} returns false if singular\
    \ (then $a$ is garbage).\n * Usage: Mat<mint> A(n,vector<mint>(m)); int r=solve(A,b,m,x,K);\n\
    \ * Time: $O(nm\\cdot\\min(n,m))$; $500\\times 500$ det takes 60ms.\n */\n\ntemplate<class\
    \ T>\nusing Mat=vector<vector<T>>;\n\ntemplate<class T>\nvector<int> gauss(Mat<T>\
    \ &a,int c,T &d){\n    int n=SZ(a),r=0;\n    vector<int> piv;d=1;\n    for(int\
    \ j=0;j<c&&r<n;j++){\n        int p=r;\n        while(p<n&&a[p][j]==0)p++;\n \
    \       if(p==n)continue;\n        if(p!=r)swap(a[p],a[r]),d=-d;\n        auto\
    \ &ar=a[r];\n        d*=ar[j];T iv=ar[j].inv();\n        for(int k=j;k<SZ(ar);k++)ar[k]*=iv;\n\
    \        for(int i=0;i<n;i++)if(i!=r&&!(a[i][j]==0)){\n            T f=a[i][j];\n\
    \            for(int k=j;k<SZ(ar);k++)a[i][k]-=f*ar[k];\n        }\n        piv.pb(j),r++;\n\
    \    }\n    if(r<c)d=0;\n    return piv;\n}\ntemplate<class T>\nT mat_det(Mat<T>\
    \ a){T d;gauss(a,SZ(a),d);return d;}\ntemplate<class T>\nint mat_rank(Mat<T> a,int\
    \ m){T d;return SZ(gauss(a,m,d));}\ntemplate<class T>\nbool mat_inv(Mat<T> &a){\n\
    \    int n=SZ(a);T d;\n    for(int i=0;i<n;i++)a[i].resize(2*n),a[i][n+i]=1;\n\
    \    if(SZ(gauss(a,n,d))<n)return 0;\n    for(auto &r:a)r.erase(r.begin(),r.begin()+n);\n\
    \    return 1;\n}\ntemplate<class T>\nint solve(Mat<T> a,const vector<T> &b,int\
    \ m,\n          vector<T> &x,Mat<T> &K){\n    int n=SZ(a);T d;\n    for(int i=0;i<n;i++)a[i].pb(b[i]);\n\
    \    auto piv=gauss(a,m,d);\n    int r=SZ(piv);\n    for(int i=r;i<n;i++)if(!(a[i][m]==0))return\
    \ -1;\n    x=vector<T>(m),K.clear();\n    vector<int> fr(m,1);\n    for(int i=0;i<r;i++)x[piv[i]]=a[i][m],fr[piv[i]]=0;\n\
    \    for(int j=0;j<m;j++)if(fr[j]){\n        vector<T> v(m);v[j]=1;\n        for(int\
    \ i=0;i<r;i++)v[piv[i]]=-a[i][j];\n        K.pb(v);\n    }\n    return r;\n}\n\
    #line 5 \"verify/linear-algebra/gauss-mod/matrix_det.test.cpp\"\n\nusing mint\
    \ = mint998;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n \
    \   int n;\n    cin >> n;\n    Mat<mint> a(n,vector<mint>(n));\n    for(auto &r:a)for(auto\
    \ &v:r)cin >> v;\n    cout << mat_det(a) << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n#include\
    \ \"src/contest/template.hpp\"\n#include \"src/number-theory/montgomery-modint.hpp\"\
    \n#include \"src/linear-algebra/gauss-mod.hpp\"\n\nusing mint = mint998;\n\nint\
    \ main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n;\n    cin\
    \ >> n;\n    Mat<mint> a(n,vector<mint>(n));\n    for(auto &r:a)for(auto &v:r)cin\
    \ >> v;\n    cout << mat_det(a) << \"\\n\";\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/number-theory/montgomery-modint.hpp
  - src/linear-algebra/gauss-mod.hpp
  isVerificationFile: true
  path: verify/linear-algebra/gauss-mod/matrix_det.test.cpp
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/linear-algebra/gauss-mod/matrix_det.test.cpp
layout: document
redirect_from:
- /verify/verify/linear-algebra/gauss-mod/matrix_det.test.cpp
- /verify/verify/linear-algebra/gauss-mod/matrix_det.test.cpp.html
title: verify/linear-algebra/gauss-mod/matrix_det.test.cpp
---
