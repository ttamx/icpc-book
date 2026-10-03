#pragma once

/**
 * Author: Teetat T.
 * Description: Smallest primitive root of a prime $p$.
 * Time: $O(Ans \log \phi(n) \log n)$
 */

int modpow(int a,int b,int mod){
    int res=1;
    while(b>0){
        if(b&1)res=1LL*res*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return res;
}

int primitive_root(int p){
    vector<int> fact;
    int phi=p-1,n=phi;
    for(int i=2; i*i<=n;i++){
        if(n%i==0){
            fact.emplace_back(i);
            while(n%i==0)n/=i;
        }
    }
    if(n>1)fact.emplace_back(n);
    for(int res=1;res<p;res++){
        bool ok=true;
        for(int i=0;i<fact.size()&&ok;i++){
            ok&=(modpow(res,phi/fact[i],p)!=1);
        }
        if(ok)return res;
    }
    return -1;
}