#pragma once

/**
 * Author: Teetat T.
 * Date: 2026-10-03
 * Description: Lucy\_Hedgehog sieve. For a completely multiplicative
 *  $f$ and every $v=\lfloor n/i \rfloor$ computes $G(v)=\sum_{p\le v,\,p \text{ prime}} f(p)$.
 *  \texttt{pre(v)} must return $\sum_{x=2}^{v} f(x)$ as \texttt{T}
 *  (e.g. $v-1$ for $\pi$, $v(v+1)/2-1$ for sum of primes).
 *  Read with \texttt{g(v)} for $v=\lfloor n/i \rfloor$ (any $v\le\sqrt n$ works).
 *  Use \texttt{T=ll} for $\pi$, \texttt{i128} for $\sum p$ ($n\le 10^{12}$) or a modint.
 *  For a polynomial $f(p)=\sum c_k p^k$ run once per $k$ and combine.
 * Usage: Lucy<ll> pi(n,[](ll v){return v-1;}); pi(n/3);
 *  Lucy<i128> sp(n,[](ll v){return (i128)v*(v+1)/2-1;});
 * Time: $O(n^{3/4}/\log n)$, $\pi(10^{11})$ in $\approx 0.2$s.
 */

template<class T>
struct Lucy{
    ll n;int s;vector<T> lo,hi; // lo[v]=G(v), hi[i]=G(n/i)
    template<class F>
    Lucy(ll n,F pre):n(n),s(sqrtl(n)),lo(s+1),hi(s+1){
        for(int i=1;i<=s;i++)lo[i]=pre(i),hi[i]=pre(n/i);
        for(int p=2;p<=s;p++){
            if(lo[p]==lo[p-1])continue;
            T fp=lo[p]-lo[p-1],b=lo[p-1];
            ll q=(ll)p*p;int e=min<ll>(s,n/q);
            for(int i=1;i<=e;i++){
                ll d=(ll)i*p;
                hi[i]-=fp*((d<=s?hi[d]:lo[n/d])-b);
            }
            for(int v=s;v>=q;v--)lo[v]-=fp*(lo[v/p]-b);
        }
    }
    T operator()(ll v){return v<=s?lo[v]:hi[n/v];}
};
