#pragma once
#include "src/polynomials/ntt.hpp"

/**
 * Author: Teetat T.
 * Description: $k$-th term of $a_i = \sum_{j=1}^{L} c_{j-1} a_{i-j}$
 * given $a_0, \dots, a_{L-1}$ (Bostan-Mori, $a_k = [x^k] P/Q$).
 * Given only the first $2L$ terms $s$, combine with Berlekamp-Massey.
 * Usage: linear_recurrence<mint>({0,1},{1,1},10) // 55
 * linear_recurrence(s,berlekamp_massey(s),k)
 * Time: $O(L \log L \log k)$
 */

template<class mint>
mint linear_recurrence(const vector<mint> &a,
    const vector<mint> &c,ll k){
    if(k<SZ(a))return a[k];
    int L=SZ(c),n=2,h;
    if(!L)return 0;
    while(n<=2*L)n*=2;
    h=n/2;
    vector<mint> P(n),Q(n),A(n),B(n);
    Q[0]=1;
    for(int i=0;i<L;i++)Q[i+1]=-c[i];
    auto t=NTT<mint>::conv(vector<mint>(a.begin(),
        a.begin()+L),vector<mint>(Q.begin(),Q.begin()+L+1));
    copy(t.begin(),t.begin()+L,P.begin());
    mint iv=mint(n).inv();
    for(;k;k>>=1){
        NTT<mint>::ntt(P),NTT<mint>::ntt(Q);
        for(int i=0;i<n;i++){ // Q(-x) <-> index i^h
            A[-i&(n-1)]=P[i]*Q[i^h]*iv;
            B[-i&(n-1)]=Q[i]*Q[i^h]*iv;
        }
        NTT<mint>::ntt(A),NTT<mint>::ntt(B);
        fill(ALL(P),0),fill(ALL(Q),0);
        for(int i=0;i<L;i++)P[i]=A[2*i+(k&1)];
        for(int i=0;i<=L;i++)Q[i]=B[2*i];
    }
    return P[0];
}
