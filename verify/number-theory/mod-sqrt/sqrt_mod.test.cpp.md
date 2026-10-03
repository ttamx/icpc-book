---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/number-theory/mod-sqrt.hpp
    title: src/number-theory/mod-sqrt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"verify/number-theory/mod-sqrt/sqrt_mod.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n#line 2 \"src/contest/template.hpp\"\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/number-theory/mod-sqrt.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Description: Tonelli-Shanks. Returns $x$ with\n\
    \ *  $x^2 \\equiv a \\pmod p$ for prime $p$ (the other root is $p-x$),\n *  or\
    \ $-1$ if $a$ is not a quadratic residue.\n * Usage: mod_sqrt(2,7); // 3 or 4\n\
    \ * Time: $O(\\log^2 p)$\n */\n\nll mod_sqrt(ll a,ll p){\n    auto mul=[&](ll\
    \ x,ll y){return ll(i128(x)*y%p);};\n    auto pw=[&](ll b,ll e){\n        ll r=1;\n\
    \        for(;e;b=mul(b,b),e>>=1)if(e&1)r=mul(r,b);\n        return r;\n    };\n\
    \    a%=p;\n    if(a<0)a+=p;\n    if(a==0||p==2)return a;\n    if(pw(a,(p-1)/2)!=1)return\
    \ -1;\n    ll s=p-1,r=0,z=2;\n    while(s%2==0)s/=2,r++;\n    while(pw(z,(p-1)/2)!=p-1)z++;\n\
    \    ll x=pw(a,(s+1)/2),b=pw(a,s),g=pw(z,s);\n    while(b!=1){\n        ll t=b,m=0;\n\
    \        while(t!=1)t=mul(t,t),m++;\n        ll gs=pw(g,1LL<<(r-m-1));\n     \
    \   g=mul(gs,gs),x=mul(x,gs),b=mul(b,g),r=m;\n    }\n    return x;\n}\n#line 4\
    \ \"verify/number-theory/mod-sqrt/sqrt_mod.test.cpp\"\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int t;\n    cin >> t;\n    while(t--){\n        ll y,p;\n        cin >> y\
    \ >> p;\n        cout << mod_sqrt(y,p) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n#include \"\
    src/contest/template.hpp\"\n#include \"src/number-theory/mod-sqrt.hpp\"\n\nint\
    \ main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int t;\n    cin\
    \ >> t;\n    while(t--){\n        ll y,p;\n        cin >> y >> p;\n        cout\
    \ << mod_sqrt(y,p) << \"\\n\";\n    }\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/number-theory/mod-sqrt.hpp
  isVerificationFile: true
  path: verify/number-theory/mod-sqrt/sqrt_mod.test.cpp
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/number-theory/mod-sqrt/sqrt_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/number-theory/mod-sqrt/sqrt_mod.test.cpp
- /verify/verify/number-theory/mod-sqrt/sqrt_mod.test.cpp.html
title: verify/number-theory/mod-sqrt/sqrt_mod.test.cpp
---
