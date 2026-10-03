---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/counting_primes
    links:
    - https://judge.yosupo.jp/problem/counting_primes
  bundledCode: "#line 1 \"verify/number-theory/prime-counting/counting_primes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n#line 2\
    \ \"src/contest/template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/number-theory/prime-counting.hpp\"\
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
    \    }\n    }\n    T operator()(ll v){return v<=s?lo[v]:hi[n/v];}\n};\n#line 4\
    \ \"verify/number-theory/prime-counting/counting_primes.test.cpp\"\n\nint main(){\n\
    \    cin.tie(nullptr)->sync_with_stdio(false);\n    ll n;\n    cin >> n;\n   \
    \ Lucy<ll> pi(n,[](ll v){return v-1;});\n    cout << pi(n) << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n#include\
    \ \"src/contest/template.hpp\"\n#include \"src/number-theory/prime-counting.hpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    ll n;\n  \
    \  cin >> n;\n    Lucy<ll> pi(n,[](ll v){return v-1;});\n    cout << pi(n) <<\
    \ \"\\n\";\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/number-theory/prime-counting.hpp
  isVerificationFile: true
  path: verify/number-theory/prime-counting/counting_primes.test.cpp
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/number-theory/prime-counting/counting_primes.test.cpp
layout: document
redirect_from:
- /verify/verify/number-theory/prime-counting/counting_primes.test.cpp
- /verify/verify/number-theory/prime-counting/counting_primes.test.cpp.html
title: verify/number-theory/prime-counting/counting_primes.test.cpp
---
