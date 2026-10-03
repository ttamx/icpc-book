#pragma once

/**
 * Author: Teetat T.
 * Description: Linear basis over GF(2) of 64-bit integers.
 * \texttt{b[i]} has top bit $i$; \texttt{r} = rank. \texttt{ins}
 * returns false if $x$ was already representable (then some
 * nonempty subset xors to $0$). \texttt{mx(x)}: max of $x\oplus s$,
 * \texttt{red(x)}: min of $x\oplus s$ over the span $s$ (so $x$ is
 * representable iff \texttt{red(x)==0}). \texttt{mn()}: min nonzero
 * span value. \texttt{kth(k)}: $k$-th smallest ($0$-indexed, $k<2^r$,
 * $0$ counts) span value.
 * \texttt{gauss\_xor}: solves $Ax=b$ over GF(2), row $i$ = bits
 * $0..m-1$ of \texttt{a[i]}, $b_i$ = bit $m$. Returns rank or $-1$;
 * free variables $=0$.
 * Time: $O(64)$ per op, \texttt{kth} $O(64^2)$; \texttt{gauss\_xor}
 * $O(nm\cdot\min(n,m)/64)$.
 */

struct XorBasis{
    u64 b[64]={};int r=0;
    bool ins(u64 x){
        for(int i=63;i>=0;i--)if(x>>i&1){
            if(!b[i])return b[i]=x,++r;
            x^=b[i];
        }
        return 0;
    }
    u64 red(u64 x){
        for(int i=63;i>=0;i--)chmin(x,x^b[i]);
        return x;
    }
    u64 mx(u64 x=0){
        for(int i=63;i>=0;i--)chmax(x,x^b[i]);
        return x;
    }
    u64 mn(){
        for(int i=0;i<64;i++)if(b[i])return b[i];
        return 0;
    }
    u64 kth(u64 k){
        u64 res=0;int t=0;
        for(int i=0;i<64;i++)if(b[i]){
            for(int j=i-1;j>=0;j--)if(b[i]>>j&1)b[i]^=b[j];
            if(k>>t++&1)res^=b[i];
        }
        return res;
    }
};

template<size_t N>
int gauss_xor(vector<bitset<N>> a,int m,bitset<N> &x){
    int n=SZ(a),r=0;vector<int> piv;
    for(int j=0;j<m&&r<n;j++){
        int p=r;
        while(p<n&&!a[p][j])p++;
        if(p==n)continue;
        swap(a[p],a[r]);
        for(int i=0;i<n;i++)if(i!=r&&a[i][j])a[i]^=a[r];
        piv.pb(j),r++;
    }
    for(int i=r;i<n;i++)if(a[i][m])return -1;
    x.reset();
    for(int i=0;i<r;i++)x[piv[i]]=a[i][m];
    return r;
}
