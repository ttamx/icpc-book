---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/number-theory/discrete-log.hpp
    title: src/number-theory/discrete-log.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"verify/number-theory/discrete-log/discrete_logarithm_mod.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\
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
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/number-theory/discrete-log.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Description: Baby-step giant-step. Returns the\
    \ smallest\n *  $x \\ge 0$ such that $a^x \\equiv b \\pmod m$, or $-1$ if none.\n\
    \ *  Works for any $m \\ge 1$ (non-coprime $a,m$ allowed).\n *  Assumes $m^2$\
    \ fits in \\texttt{ll}.\n * Usage: discrete_log(2,3,5); // 3\n * Time: $O(\\sqrt\
    \ m)$\n */\n\nll discrete_log(ll a,ll b,ll m){\n    a%=m,b%=m;\n    ll k=1,add=0,g;\n\
    \    while((g=gcd(a,m))>1){\n        if(b==k)return add;\n        if(b%g)return\
    \ -1;\n        b/=g,m/=g,add++,k=k*a/g%m;\n    }\n    ll n=sqrtl(m)+1,an=1;\n\
    \    for(int i=0;i<n;i++)an=an*a%m;\n    unordered_map<ll,ll> vals;\n    for(ll\
    \ q=0,cur=b;q<=n;q++)vals[cur]=q,cur=cur*a%m;\n    for(ll p=1,cur=k;p<=n;p++){\n\
    \        cur=cur*an%m;\n        if(vals.count(cur))return n*p-vals[cur]+add;\n\
    \    }\n    return -1;\n}\n#line 4 \"verify/number-theory/discrete-log/discrete_logarithm_mod.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int t;\n \
    \   cin >> t;\n    while(t--){\n        ll x,y,m;\n        cin >> x >> y >> m;\n\
    \        cout << discrete_log(x,y,m) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n#include \"src/contest/template.hpp\"\n#include \"src/number-theory/discrete-log.hpp\"\
    \n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int t;\n \
    \   cin >> t;\n    while(t--){\n        ll x,y,m;\n        cin >> x >> y >> m;\n\
    \        cout << discrete_log(x,y,m) << \"\\n\";\n    }\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/number-theory/discrete-log.hpp
  isVerificationFile: true
  path: verify/number-theory/discrete-log/discrete_logarithm_mod.test.cpp
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/number-theory/discrete-log/discrete_logarithm_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/number-theory/discrete-log/discrete_logarithm_mod.test.cpp
- /verify/verify/number-theory/discrete-log/discrete_logarithm_mod.test.cpp.html
title: verify/number-theory/discrete-log/discrete_logarithm_mod.test.cpp
---
