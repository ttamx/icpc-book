#pragma once

/**
 * Author: Teetat T.
 * Description: Deterministic Miller-Rabin primality test for
 *  all 64-bit $n$ and Pollard rho factorization.
 *  \texttt{factor(n)} returns the prime factors of $n$ sorted,
 *  with multiplicity (empty for $n=1$).
 * Usage: factor(360); // {2,2,2,3,3,5}
 * Time: $O(n^{1/4})$ gcd/mulmod for factor, $O(7\log n)$ for is\_prime.
 */

u64 mulmod(u64 a,u64 b,u64 m){return (unsigned __int128)a*b%m;}
u64 powmod(u64 b,u64 e,u64 m){
    u64 r=1;
    for(;e;b=mulmod(b,b,m),e>>=1)if(e&1)r=mulmod(r,b,m);
    return r;
}
bool is_prime(u64 n){
    if(n<2||n%6%4!=1)return (n|1)==3;
    u64 s=__builtin_ctzll(n-1),d=n>>s;
    for(u64 a:{2,325,9375,28178,450775,9780504,1795265022}){
        u64 p=powmod(a%n,d,n),i=s;
        while(p!=1&&p!=n-1&&a%n&&i--)p=mulmod(p,p,n);
        if(p!=n-1&&i!=s)return 0;
    }
    return 1;
}
u64 pollard(u64 n){
    u64 x=0,y=0,t=30,prd=2,i=1,q;
    auto f=[&](u64 x){return mulmod(x,x,n)+i;};
    while(t++%40||__gcd(prd,n)==1){
        if(x==y)x=++i,y=f(x);
        if((q=mulmod(prd,max(x,y)-min(x,y),n)))prd=q;
        x=f(x),y=f(f(y));
    }
    return __gcd(prd,n);
}
vector<u64> factor(u64 n){
    if(n==1)return {};
    if(is_prime(n))return {n};
    u64 x=n%2?pollard(n):2;
    auto l=factor(x),r=factor(n/x);
    l.insert(l.end(),ALL(r));
    sort(ALL(l));
    return l;
}
