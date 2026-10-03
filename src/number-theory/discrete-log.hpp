#pragma once

/**
 * Author: Teetat T.
 * Description: Baby-step giant-step. Returns the smallest
 *  $x \ge 0$ such that $a^x \equiv b \pmod m$, or $-1$ if none.
 *  Works for any $m \ge 1$ (non-coprime $a,m$ allowed).
 *  Assumes $m^2$ fits in \texttt{ll}.
 * Usage: discrete_log(2,3,5); // 3
 * Time: $O(\sqrt m)$
 */

ll discrete_log(ll a,ll b,ll m){
    a%=m,b%=m;
    ll k=1,add=0,g;
    while((g=gcd(a,m))>1){
        if(b==k)return add;
        if(b%g)return -1;
        b/=g,m/=g,add++,k=k*a/g%m;
    }
    ll n=sqrtl(m)+1,an=1;
    for(int i=0;i<n;i++)an=an*a%m;
    unordered_map<ll,ll> vals;
    for(ll q=0,cur=b;q<=n;q++)vals[cur]=q,cur=cur*a%m;
    for(ll p=1,cur=k;p<=n;p++){
        cur=cur*an%m;
        if(vals.count(cur))return n*p-vals[cur]+add;
    }
    return -1;
}
