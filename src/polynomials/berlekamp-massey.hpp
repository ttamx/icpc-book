#pragma once

/**
 * Author: Teetat T.
 * Description: Finds the shortest recurrence $c$ of length $L$ with
 * $s_i = \sum_{j=1}^{L} c_{j-1} s_{i-j}$ for all $L \le i < n$.
 * Needs $2L$ terms to recover a recurrence of order $L$.
 * Usage: berlekamp_massey(vector<mint>{0,1,1,3,5,11}) // {1,2}
 * Time: $O(N^2)$
 */

template<class mint>
vector<mint> berlekamp_massey(const vector<mint> &s){
    int n=SZ(s),L=0,m=0;
    vector<mint> C(n+1),B(n+1),T;
    C[0]=B[0]=1;
    mint b=1;
    for(int i=0;i<n;i++){
        m++;
        mint d=s[i];
        for(int j=1;j<=L;j++)d+=C[j]*s[i-j];
        if(d==mint(0))continue;
        T=C;
        mint coef=d/b;
        for(int j=m;j<=n;j++)C[j]-=coef*B[j-m];
        if(2*L>i)continue;
        L=i+1-L,B=T,b=d,m=0;
    }
    vector<mint> c(L);
    for(int i=0;i<L;i++)c[i]=-C[i+1];
    return c;
}
