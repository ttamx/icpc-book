#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-07-29
 * Description: Bitwise XOR Convolution. $|A|=|B|$ must be a power of 2.
 * Fast Walsh-Hadamard Transform: $A^\prime[S]=\sum_T(-1)^{|S\&T|}A[T]$.
 * Time: $O(N\log N)$.
 */

template<class T>
void fwht(vector<T> &a){
    int n=SZ(a);assert(n==(n&-n));
    for(int i=1;i<n;i<<=1)for(int j=n;j--;)if(j&i){
        T &u=a[j^i],&v=a[j];tie(u,v)=make_pair(u+v,u-v);
    }
}
template<class T>
vector<T> xor_convolution(vector<T> a,vector<T> b){
    int n=SZ(a);fwht(a);fwht(b);
    for(int i=0;i<n;i++)a[i]*=b[i];
    fwht(a);T d=T(1)/T(n);
    if(d==T(0))for(auto &x:a)x/=n;else for(auto &x:a)x*=d;
    return a;
}
