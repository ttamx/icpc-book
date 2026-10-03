#pragma once

/**
 * Author: Teetat T.
 * Description: Given $f(0), \dots, f(n-1)$ of a polynomial $f$ of degree $< n$, return $f(c)$. Requires $n \le$ mod.
 * Time: $O(N)$
 */

template<class mint>
mint lagrange_interpolate(const vector<mint> &f,mint c){
    int n=f.size();
    if(n==0)return 0;
    if(c.val()<n)return f[c.val()];
    vector<mint> l(n+1),r(n+1),ifac(n);
    l[0]=r[n]=ifac[0]=1;
    for(int i=0;i<n;i++)l[i+1]=l[i]*(c-i);
    for(int i=n-1;i>=0;i--)r[i]=r[i+1]*(c-i);
    for(int i=1;i<n;i++)ifac[i]=ifac[i-1]*i;
    ifac[n-1]=ifac[n-1].inv();
    for(int i=n-1;i>1;i--)ifac[i-1]=ifac[i]*i;
    mint ans=0;
    for(int i=0;i<n;i++){
        mint cur=f[i]*ifac[i]*ifac[n-i-1];
        if((n-i-1)&1)cur*=-1;
        ans+=cur*l[i]*r[i+1];
    }
    return ans;
}
