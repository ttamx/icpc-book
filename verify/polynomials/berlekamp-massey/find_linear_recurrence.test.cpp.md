---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':question:'
    path: src/number-theory/modint.hpp
    title: src/number-theory/modint.hpp
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
    \ c(L);\n    for(int i=0;i<L;i++)c[i]=-C[i+1];\n    return c;\n}\n#line 2 \"src/number-theory/modint.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2026-04-15\n * Description: modular arithmetic\
    \ operations\n */\n\ntemplate<int mod,int root=0>\nstruct ModInt{\n    using mint\
    \ = ModInt;\n    \n\tstatic_assert(mod>0,\"mod must be positive\");\n\n    int\
    \ x;\n\n    constexpr ModInt():x(0){}\n    constexpr ModInt(ll x):x((x%=mod)<0?x+mod:x){}\n\
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
    \ = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;\n#line 5 \"verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp\"\
    \n\nusing mint = mint998;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n;\n    cin >> n;\n    vector<mint> a(n);\n    for(auto &x:a)cin >> x;\n\
    \    auto c=berlekamp_massey(a);\n    int d=c.size();\n    cout << d << \"\\n\"\
    ;\n    for(int i=0;i<d;i++)cout << c[i] << \" \\n\"[i==d-1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n#include \"src/contest/template.hpp\"\n#include \"src/polynomials/berlekamp-massey.hpp\"\
    \n#include \"src/number-theory/modint.hpp\"\n\nusing mint = mint998;\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    int n;\n    cin >> n;\n  \
    \  vector<mint> a(n);\n    for(auto &x:a)cin >> x;\n    auto c=berlekamp_massey(a);\n\
    \    int d=c.size();\n    cout << d << \"\\n\";\n    for(int i=0;i<d;i++)cout\
    \ << c[i] << \" \\n\"[i==d-1];\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/polynomials/berlekamp-massey.hpp
  - src/number-theory/modint.hpp
  isVerificationFile: true
  path: verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 18:51:44+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp
layout: document
redirect_from:
- /verify/verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp
- /verify/verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp.html
title: verify/polynomials/berlekamp-massey/find_linear_recurrence.test.cpp
---
