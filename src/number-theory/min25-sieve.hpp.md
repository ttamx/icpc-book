---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/number-theory/prime-counting.hpp
    title: src/number-theory/prime-counting.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/number-theory/min25-sieve/sum_of_totient_function.test.cpp
    title: verify/number-theory/min25-sieve/sum_of_totient_function.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/number-theory/prime-counting.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2026-10-03\n * Description: Lucy\\_Hedgehog sieve. For a\
    \ completely multiplicative\n *  $f$ and every $v=\\lfloor n/i \\rfloor$ computes\
    \ $G(v)=\\sum_{p\\le v,\\,p \\text{ prime}} f(p)$.\n *  \\texttt{pre(v)} must\
    \ return $\\sum_{x=2}^{v} f(x)$ as \\texttt{T}\n *  (e.g. $v-1$ for $\\pi$, $v(v+1)/2-1$\
    \ for sum of primes).\n *  Read with \\texttt{g(v)} for $v=\\lfloor n/i \\rfloor$\
    \ (any $v\\le\\sqrt n$ works).\n *  Use \\texttt{T=ll} for $\\pi$, \\texttt{i128}\
    \ for $\\sum p$ ($n\\le 10^{12}$) or a modint.\n *  For a polynomial $f(p)=\\\
    sum c_k p^k$ run once per $k$ and combine.\n * Usage: Lucy<ll> pi(n,[](ll v){return\
    \ v-1;}); pi(n/3);\n *  Lucy<i128> sp(n,[](ll v){return (i128)v*(v+1)/2-1;});\n\
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
    \    };\n    return S(n,0)+T(1);\n}\n"
  code: "#pragma once\n#include \"src/number-theory/prime-counting.hpp\"\n\n/**\n\
    \ * Author: Teetat T.\n * Date: 2026-10-03\n * Description: min\\_25 sieve: $\\\
    sum_{x=1}^{n} f(x)$ for multiplicative $f$.\n *  Supply \\texttt{g(v)}$=\\sum_{p\\\
    le v} f(p)$ for every $v=\\lfloor n/i\\rfloor$\n *  (combine \\texttt{Lucy} sums\
    \ of $p^k$ when $f(p)$ is a polynomial)\n *  and \\texttt{fpe(p,e)}$=f(p^e)$ as\
    \ \\texttt{T}. Assumes $f(1)=1$.\n *  \\texttt{T}: \\texttt{ll}/\\texttt{i128}/modint\
    \ (watch overflow).\n * Usage: Lucy<mint> c(n,[](ll v){return mint(v-1);});\n\
    \ *  Lucy<mint> s(n,[](ll v){return mint(v)*(v+1)/2-1;});\n *  auto g=[\\&](ll\
    \ v){return s(v)-c(v);}; // phi(p)=p-1\n *  auto fpe=[](ll p,int e){mint r=p-1;while(--e)r*=p;return\
    \ r;};\n *  mint ans=min25<mint>(n,g,fpe);\n * Time: $O(n^{3/4}/\\log n)$, $n=10^{10}$\
    \ in $\\approx 0.3$s.\n */\n\ntemplate<class T,class G,class F>\nT min25(ll n,G\
    \ g,F fpe){\n    int s=sqrtl(n);vector<int> pr;vector<bool> c(s+1);\n    for(int\
    \ i=2;i<=s;i++)if(!c[i]){\n        pr.pb(i);\n        for(ll j=(ll)i*i;j<=s;j+=i)c[j]=1;\n\
    \    }\n    // S(m,j) = sum of f(x), 2<=x<=m, lpf(x)>=pr[j]\n    function<T(ll,int)>\
    \ S=[&](ll m,int j){\n        T r=g(m)-(j?g(pr[j-1]):T(0));\n        for(int i=j;i<SZ(pr)&&(ll)pr[i]*pr[i]<=m;i++){\n\
    \            ll p=pr[i],q=p;\n            for(int e=1;q*p<=m;e++,q*=p)\n     \
    \           r+=fpe(p,e)*S(m/q,i+1)+fpe(p,e+1);\n        }\n        return r;\n\
    \    };\n    return S(n,0)+T(1);\n}\n"
  dependsOn:
  - src/number-theory/prime-counting.hpp
  isVerificationFile: false
  path: src/number-theory/min25-sieve.hpp
  requiredBy: []
  timestamp: '2026-10-04 00:49:42+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/number-theory/min25-sieve/sum_of_totient_function.test.cpp
documentation_of: src/number-theory/min25-sieve.hpp
layout: document
redirect_from:
- /library/src/number-theory/min25-sieve.hpp
- /library/src/number-theory/min25-sieve.hpp.html
title: src/number-theory/min25-sieve.hpp
---
