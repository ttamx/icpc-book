---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/number-theory/min25-sieve.hpp
    title: src/number-theory/min25-sieve.hpp
  - icon: ':question:'
    path: src/number-theory/modint.hpp
    title: src/number-theory/modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/number-theory/prime-counting.hpp
    title: src/number-theory/prime-counting.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"verify/number-theory/min25-sieve/sum_of_totient_function.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/number-theory/modint.hpp\"\
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
    \ = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;\n#line 2 \"src/number-theory/prime-counting.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2026-10-03\n * Description: Lucy\\_Hedgehog\
    \ sieve. For a completely multiplicative\n *  $f$ and every $v=\\lfloor n/i \\\
    rfloor$ computes $G(v)=\\sum_{p\\le v,\\,p \\text{ prime}} f(p)$.\n *  \\texttt{pre(v)}\
    \ must return $\\sum_{x=2}^{v} f(x)$ as \\texttt{T}\n *  (e.g. $v-1$ for $\\pi$,\
    \ $v(v+1)/2-1$ for sum of primes).\n *  Read with \\texttt{g(v)} for $v=\\lfloor\
    \ n/i \\rfloor$ (any $v\\le\\sqrt n$ works).\n *  Use \\texttt{T=ll} for $\\pi$,\
    \ \\texttt{i128} for $\\sum p$ ($n\\le 10^{12}$) or a modint.\n *  For a polynomial\
    \ $f(p)=\\sum c_k p^k$ run once per $k$ and combine.\n * Usage: Lucy<ll> pi(n,[](ll\
    \ v){return v-1;}); pi(n/3);\n *  Lucy<i128> sp(n,[](ll v){return (i128)v*(v+1)/2-1;});\n\
    \ * Time: $O(n^{3/4}/\\log n)$, $\\pi(10^{11})$ in $\\approx 0.2$s.\n */\n\ntemplate<class\
    \ T>\nstruct Lucy{\n    ll n;int s;vector<T> lo,hi; // lo[v]=G(v), hi[i]=G(n/i)\n\
    \    template<class F>\n    Lucy(ll n,F pre):n(n),s(sqrtl(n)),lo(s+1),hi(s+1){\n\
    \        for(int i=1;i<=s;i++)lo[i]=pre(i),hi[i]=pre(n/i);\n        for(int p=2;p<=s;p++){\n\
    \            if(lo[p]==lo[p-1])continue;\n            T fp=lo[p]-lo[p-1],b=lo[p-1];\n\
    \            ll q=(ll)p*p;int e=min<ll>(s,n/q);\n            for(int i=1;i<=e;i++){\n\
    \                ll d=(ll)i*p;\n                hi[i]-=fp*((d<=s?hi[d]:lo[n/d])-b);\n\
    \            }\n            for(int v=s;v>=q;v--)lo[v]-=fp*(lo[v/p]-b);\n    \
    \    }\n    }\n    T operator()(ll v){return v<=s?lo[v]:hi[n/v];}\n};\n#line 3\
    \ \"src/number-theory/min25-sieve.hpp\"\n\n/**\n * Author: Teetat T.\n * Date:\
    \ 2026-10-03\n * Description: min\\_25 sieve: $\\sum_{x=1}^{n} f(x)$ for multiplicative\
    \ $f$.\n *  Supply \\texttt{g(v)}$=\\sum_{p\\le v} f(p)$ for every $v=\\lfloor\
    \ n/i\\rfloor$\n *  (combine \\texttt{Lucy} sums of $p^k$ when $f(p)$ is a polynomial)\n\
    \ *  and \\texttt{fpe(p,e)}$=f(p^e)$ as \\texttt{T}. Assumes $f(1)=1$.\n *  \\\
    texttt{T}: \\texttt{ll}/\\texttt{i128}/modint (watch overflow).\n * Usage: Lucy<mint>\
    \ c(n,[](ll v){return mint(v-1);});\n *  Lucy<mint> s(n,[](ll v){return mint(v)*(v+1)/2-1;});\n\
    \ *  auto g=[\\&](ll v){return s(v)-c(v);}; // phi(p)=p-1\n *  auto fpe=[](ll\
    \ p,int e){mint r=p-1;while(--e)r*=p;return r;};\n *  mint ans=min25<mint>(n,g,fpe);\n\
    \ * Time: $O(n^{3/4}/\\log n)$, $n=10^{10}$ in $\\approx 0.3$s.\n */\n\ntemplate<class\
    \ T,class G,class F>\nT min25(ll n,G g,F fpe){\n    int s=sqrtl(n);vector<int>\
    \ pr;vector<bool> c(s+1);\n    for(int i=2;i<=s;i++)if(!c[i]){\n        pr.pb(i);\n\
    \        for(ll j=(ll)i*i;j<=s;j+=i)c[j]=1;\n    }\n    // S(m,j) = sum of f(x),\
    \ 2<=x<=m, lpf(x)>=pr[j]\n    function<T(ll,int)> S=[&](ll m,int j){\n       \
    \ T r=g(m)-(j?g(pr[j-1]):T(0));\n        for(int i=j;i<SZ(pr)&&(ll)pr[i]*pr[i]<=m;i++){\n\
    \            ll p=pr[i],q=p;\n            for(int e=1;q*p<=m;e++,q*=p)\n     \
    \           r+=fpe(p,e)*S(m/q,i+1)+fpe(p,e+1);\n        }\n        return r;\n\
    \    };\n    return S(n,0)+T(1);\n}\n#line 5 \"verify/number-theory/min25-sieve/sum_of_totient_function.test.cpp\"\
    \n\nusing mint = mint998;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    ll n;\n    cin >> n;\n    Lucy<mint> c(n,[](ll v){return mint(v-1);});\n\
    \    Lucy<mint> s(n,[](ll v){return mint(v)*(v+1)/2-1;});\n    auto g=[&](ll v){return\
    \ s(v)-c(v);};\n    auto fpe=[](ll p,int e){mint r=p-1;while(--e)r*=p;return r;};\n\
    \    cout << min25<mint>(n,g,fpe) << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n#include \"src/contest/template.hpp\"\n#include \"src/number-theory/modint.hpp\"\
    \n#include \"src/number-theory/min25-sieve.hpp\"\n\nusing mint = mint998;\n\n\
    int main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    ll n;\n    cin\
    \ >> n;\n    Lucy<mint> c(n,[](ll v){return mint(v-1);});\n    Lucy<mint> s(n,[](ll\
    \ v){return mint(v)*(v+1)/2-1;});\n    auto g=[&](ll v){return s(v)-c(v);};\n\
    \    auto fpe=[](ll p,int e){mint r=p-1;while(--e)r*=p;return r;};\n    cout <<\
    \ min25<mint>(n,g,fpe) << \"\\n\";\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/number-theory/modint.hpp
  - src/number-theory/min25-sieve.hpp
  - src/number-theory/prime-counting.hpp
  isVerificationFile: true
  path: verify/number-theory/min25-sieve/sum_of_totient_function.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 18:51:44+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/number-theory/min25-sieve/sum_of_totient_function.test.cpp
layout: document
redirect_from:
- /verify/verify/number-theory/min25-sieve/sum_of_totient_function.test.cpp
- /verify/verify/number-theory/min25-sieve/sum_of_totient_function.test.cpp.html
title: verify/number-theory/min25-sieve/sum_of_totient_function.test.cpp
---
