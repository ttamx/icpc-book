#pragma once
#include "src/polynomials/formal-power-series.hpp"

/**
 * Author: Teetat T.
 * Description: Given $f(x)$, returns $f(x+c)$. Needs $N < $ mod.
 * Time: $O(N \log N)$
 */

template<class mint>
FormalPowerSeries<mint> taylor_shift(
    FormalPowerSeries<mint> f,mint c){
    int n=SZ(f);
    if(!n)return f;
    vector<mint> fac(n,1),ifac(n),b(n);
    for(int i=1;i<n;i++)fac[i]=fac[i-1]*mint(i);
    ifac[n-1]=fac[n-1].inv();
    for(int i=n-1;i>0;i--)ifac[i-1]=ifac[i]*mint(i);
    mint p=1;
    for(int i=0;i<n;i++){
        f[i]*=fac[i],b[i]=p*ifac[i],p*=c;
    }
    reverse(ALL(f));
    auto g=NTT<mint>::conv(f,b);
    for(int i=0;i<n;i++)f[i]=g[n-1-i]*ifac[i];
    return f;
}
