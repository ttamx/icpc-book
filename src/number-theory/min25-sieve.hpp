#pragma once
#include "src/number-theory/prime-counting.hpp"

/**
 * Author: Teetat T.
 * Date: 2026-10-03
 * Description: min\_25 sieve: $\sum_{x=1}^{n} f(x)$ for multiplicative $f$.
 *  Supply \texttt{g(v)}$=\sum_{p\le v} f(p)$ for every $v=\lfloor n/i\rfloor$
 *  (combine \texttt{Lucy} sums of $p^k$ when $f(p)$ is a polynomial)
 *  and \texttt{fpe(p,e)}$=f(p^e)$ as \texttt{T}. Assumes $f(1)=1$.
 *  \texttt{T}: \texttt{ll}/\texttt{i128}/modint (watch overflow).
 * Usage: Lucy<mint> c(n,[](ll v){return mint(v-1);});
 *  Lucy<mint> s(n,[](ll v){return mint(v)*(v+1)/2-1;});
 *  auto g=[\&](ll v){return s(v)-c(v);}; // phi(p)=p-1
 *  auto fpe=[](ll p,int e){mint r=p-1;while(--e)r*=p;return r;};
 *  mint ans=min25<mint>(n,g,fpe);
 * Time: $O(n^{3/4}/\log n)$, $n=10^{10}$ in $\approx 0.3$s.
 */

template<class T,class G,class F>
T min25(ll n,G g,F fpe){
    int s=sqrtl(n);vector<int> pr;vector<bool> c(s+1);
    for(int i=2;i<=s;i++)if(!c[i]){
        pr.pb(i);
        for(ll j=(ll)i*i;j<=s;j+=i)c[j]=1;
    }
    // S(m,j) = sum of f(x), 2<=x<=m, lpf(x)>=pr[j]
    function<T(ll,int)> S=[&](ll m,int j){
        T r=g(m)-(j?g(pr[j-1]):T(0));
        for(int i=j;i<SZ(pr)&&(ll)pr[i]*pr[i]<=m;i++){
            ll p=pr[i],q=p;
            for(int e=1;q*p<=m;e++,q*=p)
                r+=fpe(p,e)*S(m/q,i+1)+fpe(p,e+1);
        }
        return r;
    };
    return S(n,0)+T(1);
}
