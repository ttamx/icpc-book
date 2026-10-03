#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-07-29
 * Description: Bitwise OR Convolution. $|A|=|B|$ must be a power of 2.
 * Subset Zeta Transform: $A^\prime[S]=\sum_{T\subseteq S}A[T]$.
 * Subset Mobius Transform: $A[T]=\sum_{S\subseteq T}(-1)^{|T-S|}A^\prime[S]$.
 * Time: $O(N\log N)$.
 */

template<class T>
void subset_zeta(vector<T> &a){
    int n=SZ(a);assert(n==(n&-n));
    for(int i=1;i<n;i<<=1)for(int j=n;j--;)if(j&i)a[j]+=a[j^i];
}
template<class T>
void subset_mobius(vector<T> &a){
    int n=SZ(a);assert(n==(n&-n));
    for(int i=n;i>>=1;)for(int j=n;j--;)if(j&i)a[j]-=a[j^i];
}
template<class T>
vector<T> or_convolution(vector<T> a,vector<T> b){
    subset_zeta(a);subset_zeta(b);
    for(int i=0;i<SZ(a);i++)a[i]*=b[i];
    subset_mobius(a);return a;
}
