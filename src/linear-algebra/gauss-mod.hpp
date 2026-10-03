#pragma once

/**
 * Author: Teetat T.
 * Description: Gauss-Jordan elimination over a field $\mathbb{Z}_p$.
 * \texttt{gauss(a,c,d)} reduces $a$ to RREF on its first $c$ columns
 * (later columns are carried along), returns pivot columns and sets
 * $d=\det$ of the left $c\times c$ block (for square use).
 * \texttt{solve} returns rank or $-1$ if inconsistent, a solution $x$
 * (free vars $=0$) and a basis $K$ of $\{x : Ax=0\}$ ($|K|=m-$rank).
 * \texttt{mat\_inv} returns false if singular (then $a$ is garbage).
 * Usage: Mat<mint> A(n,vector<mint>(m)); int r=solve(A,b,m,x,K);
 * Time: $O(nm\cdot\min(n,m))$; $500\times 500$ det takes 60ms.
 */

template<class T>
using Mat=vector<vector<T>>;

template<class T>
vector<int> gauss(Mat<T> &a,int c,T &d){
    int n=SZ(a),r=0;
    vector<int> piv;d=1;
    for(int j=0;j<c&&r<n;j++){
        int p=r;
        while(p<n&&a[p][j]==0)p++;
        if(p==n)continue;
        if(p!=r)swap(a[p],a[r]),d=-d;
        auto &ar=a[r];
        d*=ar[j];T iv=ar[j].inv();
        for(int k=j;k<SZ(ar);k++)ar[k]*=iv;
        for(int i=0;i<n;i++)if(i!=r&&!(a[i][j]==0)){
            T f=a[i][j];
            for(int k=j;k<SZ(ar);k++)a[i][k]-=f*ar[k];
        }
        piv.pb(j),r++;
    }
    if(r<c)d=0;
    return piv;
}
template<class T>
T mat_det(Mat<T> a){T d;gauss(a,SZ(a),d);return d;}
template<class T>
int mat_rank(Mat<T> a,int m){T d;return SZ(gauss(a,m,d));}
template<class T>
bool mat_inv(Mat<T> &a){
    int n=SZ(a);T d;
    for(int i=0;i<n;i++)a[i].resize(2*n),a[i][n+i]=1;
    if(SZ(gauss(a,n,d))<n)return 0;
    for(auto &r:a)r.erase(r.begin(),r.begin()+n);
    return 1;
}
template<class T>
int solve(Mat<T> a,const vector<T> &b,int m,
          vector<T> &x,Mat<T> &K){
    int n=SZ(a);T d;
    for(int i=0;i<n;i++)a[i].pb(b[i]);
    auto piv=gauss(a,m,d);
    int r=SZ(piv);
    for(int i=r;i<n;i++)if(!(a[i][m]==0))return -1;
    x=vector<T>(m),K.clear();
    vector<int> fr(m,1);
    for(int i=0;i<r;i++)x[piv[i]]=a[i][m],fr[piv[i]]=0;
    for(int j=0;j<m;j++)if(fr[j]){
        vector<T> v(m);v[j]=1;
        for(int i=0;i<r;i++)v[piv[i]]=-a[i][j];
        K.pb(v);
    }
    return r;
}
