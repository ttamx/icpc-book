#pragma once

/**
 * Author: Teetat T.
 * Description: Tonelli-Shanks. Returns $x$ with
 *  $x^2 \equiv a \pmod p$ for prime $p$ (the other root is $p-x$),
 *  or $-1$ if $a$ is not a quadratic residue.
 * Usage: mod_sqrt(2,7); // 3 or 4
 * Time: $O(\log^2 p)$
 */

ll mod_sqrt(ll a,ll p){
    auto mul=[&](ll x,ll y){return ll(i128(x)*y%p);};
    auto pw=[&](ll b,ll e){
        ll r=1;
        for(;e;b=mul(b,b),e>>=1)if(e&1)r=mul(r,b);
        return r;
    };
    a%=p;
    if(a<0)a+=p;
    if(a==0||p==2)return a;
    if(pw(a,(p-1)/2)!=1)return -1;
    ll s=p-1,r=0,z=2;
    while(s%2==0)s/=2,r++;
    while(pw(z,(p-1)/2)!=p-1)z++;
    ll x=pw(a,(s+1)/2),b=pw(a,s),g=pw(z,s);
    while(b!=1){
        ll t=b,m=0;
        while(t!=1)t=mul(t,t),m++;
        ll gs=pw(g,1LL<<(r-m-1));
        g=mul(gs,gs),x=mul(x,gs),b=mul(b,g),r=m;
    }
    return x;
}
