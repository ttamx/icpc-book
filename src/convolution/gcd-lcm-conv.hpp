#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-07-29
 * Description: GCD/LCM convolution on indices $1..n-1$ (index 0
 * is ignored).
 * Multiple zeta: $A^\prime[n]=\sum_{n|m}A[m]$ (GCD).
 * Divisor zeta: $A^\prime[n]=\sum_{d|n}A[d]$ (LCM).
 * Mobius transforms are their inverses.
 * Time: $O(N\log\log N)$.
 */

template<class T> void multiple_zeta(vector<T> &a){
    int n=SZ(a);vector<bool> pr(n,1);
    for(int p=2;p<n;p++)if(pr[p])
        for(int i=(n-1)/p;i>0;i--)pr[i*p]=0,a[i]+=a[i*p];
}
template<class T> void multiple_mobius(vector<T> &a){
    int n=SZ(a);vector<bool> pr(n,1);
    for(int p=2;p<n;p++)if(pr[p])
        for(int i=1;i*p<n;i++)pr[i*p]=0,a[i]-=a[i*p];
}
template<class T> void divisor_zeta(vector<T> &a){
    int n=SZ(a);vector<bool> pr(n,1);
    for(int p=2;p<n;p++)if(pr[p])
        for(int i=1;i*p<n;i++)pr[i*p]=0,a[i*p]+=a[i];
}
template<class T> void divisor_mobius(vector<T> &a){
    int n=SZ(a);vector<bool> pr(n,1);
    for(int p=2;p<n;p++)if(pr[p])
        for(int i=(n-1)/p;i>0;i--)pr[i*p]=0,a[i*p]-=a[i];
}
template<class T> vector<T> gcd_conv(vector<T> a,vector<T> b){
    multiple_zeta(a);multiple_zeta(b);
    for(int i=0;i<SZ(a);i++)a[i]*=b[i];
    multiple_mobius(a);return a;
}
template<class T> vector<T> lcm_conv(vector<T> a,vector<T> b){
    divisor_zeta(a);divisor_zeta(b);
    for(int i=0;i<SZ(a);i++)a[i]*=b[i];
    divisor_mobius(a);return a;
}
