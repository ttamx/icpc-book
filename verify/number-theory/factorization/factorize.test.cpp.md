---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/number-theory/factorization.hpp
    title: src/number-theory/factorization.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"verify/number-theory/factorization/factorize.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#line 2 \"src/contest/template.hpp\"\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/number-theory/factorization.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Description: Deterministic Miller-Rabin primality\
    \ test for\n *  all 64-bit $n$ and Pollard rho factorization.\n *  \\texttt{factor(n)}\
    \ returns the prime factors of $n$ sorted,\n *  with multiplicity (empty for $n=1$).\n\
    \ * Usage: factor(360); // {2,2,2,3,3,5}\n * Time: $O(n^{1/4})$ gcd/mulmod for\
    \ factor, $O(7\\log n)$ for is\\_prime.\n */\n\nu64 mulmod(u64 a,u64 b,u64 m){return\
    \ (unsigned __int128)a*b%m;}\nu64 powmod(u64 b,u64 e,u64 m){\n    u64 r=1;\n \
    \   for(;e;b=mulmod(b,b,m),e>>=1)if(e&1)r=mulmod(r,b,m);\n    return r;\n}\nbool\
    \ is_prime(u64 n){\n    if(n<2||n%6%4!=1)return (n|1)==3;\n    u64 s=__builtin_ctzll(n-1),d=n>>s;\n\
    \    for(u64 a:{2,325,9375,28178,450775,9780504,1795265022}){\n        u64 p=powmod(a%n,d,n),i=s;\n\
    \        while(p!=1&&p!=n-1&&a%n&&i--)p=mulmod(p,p,n);\n        if(p!=n-1&&i!=s)return\
    \ 0;\n    }\n    return 1;\n}\nu64 pollard(u64 n){\n    u64 x=0,y=0,t=30,prd=2,i=1,q;\n\
    \    auto f=[&](u64 x){return mulmod(x,x,n)+i;};\n    while(t++%40||__gcd(prd,n)==1){\n\
    \        if(x==y)x=++i,y=f(x);\n        if((q=mulmod(prd,max(x,y)-min(x,y),n)))prd=q;\n\
    \        x=f(x),y=f(f(y));\n    }\n    return __gcd(prd,n);\n}\nvector<u64> factor(u64\
    \ n){\n    if(n==1)return {};\n    if(is_prime(n))return {n};\n    u64 x=n%2?pollard(n):2;\n\
    \    auto l=factor(x),r=factor(n/x);\n    l.insert(l.end(),ALL(r));\n    sort(ALL(l));\n\
    \    return l;\n}\n#line 4 \"verify/number-theory/factorization/factorize.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int q;\n \
    \   cin >> q;\n    while(q--){\n        u64 a;\n        cin >> a;\n        auto\
    \ f=factor(a);\n        cout << f.size();\n        for(auto x:f)cout << \" \"\
    \ << x;\n        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include \"\
    src/contest/template.hpp\"\n#include \"src/number-theory/factorization.hpp\"\n\
    \nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int q;\n   \
    \ cin >> q;\n    while(q--){\n        u64 a;\n        cin >> a;\n        auto\
    \ f=factor(a);\n        cout << f.size();\n        for(auto x:f)cout << \" \"\
    \ << x;\n        cout << \"\\n\";\n    }\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/number-theory/factorization.hpp
  isVerificationFile: true
  path: verify/number-theory/factorization/factorize.test.cpp
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/number-theory/factorization/factorize.test.cpp
layout: document
redirect_from:
- /verify/verify/number-theory/factorization/factorize.test.cpp
- /verify/verify/number-theory/factorization/factorize.test.cpp.html
title: verify/number-theory/factorization/factorize.test.cpp
---
