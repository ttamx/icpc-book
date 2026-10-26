#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-07-29
 * Description: Bitwise AND/OR/XOR convolution. $|A|=|B|$ must be
 * equal and a power of 2.
 * Superset zeta: $A^\prime[S]=\sum_{T\supseteq S}A[T]$ (AND).
 * Subset zeta: $A^\prime[S]=\sum_{T\subseteq S}A[T]$ (OR).
 * Mobius transforms are their inverses.
 * XOR FWHT: $A^\prime[S]=\sum_T(-1)^{|S\&T|}A[T]$.
 * Time: $O(N\log N)$.
 */

template<class T> void superset_zeta(vector<T> &a){
    int n=SZ(a);assert(n==(n&-n));
    for(int i=1;i<n;i<<=1)for(int j=n;j--;)if(j&i)a[j^i]+=a[j];
}
template<class T> void superset_mobius(vector<T> &a){
    int n=SZ(a);assert(n==(n&-n));
    for(int i=n;i>>=1;)for(int j=n;j--;)if(j&i)a[j^i]-=a[j];
}
template<class T> void subset_zeta(vector<T> &a){
    int n=SZ(a);assert(n==(n&-n));
    for(int i=1;i<n;i<<=1)for(int j=n;j--;)if(j&i)a[j]+=a[j^i];
}
template<class T> void subset_mobius(vector<T> &a){
    int n=SZ(a);assert(n==(n&-n));
    for(int i=n;i>>=1;)for(int j=n;j--;)if(j&i)a[j]-=a[j^i];
}
template<class T> void fwht(vector<T> &a){
    int n=SZ(a);assert(n==(n&-n));
    for(int i=1;i<n;i<<=1)for(int j=n;j--;)if(j&i){
        T &u=a[j^i],&v=a[j];tie(u,v)=make_pair(u+v,u-v);
    }
}
template<class T> vector<T> and_conv(vector<T> a,vector<T> b){
    superset_zeta(a);superset_zeta(b);
    for(int i=0;i<SZ(a);i++)a[i]*=b[i];
    superset_mobius(a);return a;
}
template<class T> vector<T> or_conv(vector<T> a,vector<T> b){
    subset_zeta(a);subset_zeta(b);
    for(int i=0;i<SZ(a);i++)a[i]*=b[i];
    subset_mobius(a);return a;
}
template<class T> vector<T> xor_conv(vector<T> a,vector<T> b){
    int n=SZ(a);fwht(a);fwht(b);
    for(int i=0;i<n;i++)a[i]*=b[i];
    fwht(a);T d=T(1)/T(n);
    if(d==T(0))for(auto &x:a)x/=n;else for(auto &x:a)x*=d;
    return a;
}
