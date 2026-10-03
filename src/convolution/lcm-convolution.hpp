#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-07-29
 * Description: LCM Convolution.
 * Divisor Zeta Transform: $A^\prime[n]=\sum_{d|n}A[d]$.
 * Divisor Mobius Transform: $A[n]=\sum_{d|n}\mu(n/d)A^\prime[d]$.
 * Time: $O(N\log\log N)$.
 */

template<class T>
void divisor_zeta(vector<T> &a){
    int n=SZ(a);vector<bool> pr(n,1);
    for(int p=2;p<n;p++)if(pr[p])
        for(int i=1;i*p<n;i++)pr[i*p]=0,a[i*p]+=a[i];
}
template<class T>
void divisor_mobius(vector<T> &a){
    int n=SZ(a);vector<bool> pr(n,1);
    for(int p=2;p<n;p++)if(pr[p])
        for(int i=(n-1)/p;i>0;i--)pr[i*p]=0,a[i*p]-=a[i];
}
template<class T>
vector<T> lcm_convolution(vector<T> a,vector<T> b){
    divisor_zeta(a);divisor_zeta(b);
    for(int i=0;i<SZ(a);i++)a[i]*=b[i];
    divisor_mobius(a);return a;
}
