#pragma once

/**
 * Author: Teetat T.
 * Description: Gauss-Jordan elimination over reals with partial
 * pivoting (max $|a_{ij}|$ in column). \texttt{solve\_db} solves
 * $Ax=b$ ($A$ is $n\times m$), returns rank or $-1$ if inconsistent;
 * free variables are set to $0$. \texttt{det\_db} returns $\det A$.
 * Beware, entries with $|a|<$ EPS are treated as $0$, so scale
 * the input to magnitude $\approx 1$ (EPS is absolute). Ill-conditioned
 * systems (e.g. Hilbert matrices) give garbage; for integer data use
 * the mod-$p$ version (\texttt{db} has a 64-bit mantissa, so exact
 * integers beyond $\approx 10^{18}$ are lost). Check residual $|Ax-b|$.
 * Time: $O(nm\cdot\min(n,m))$
 */

using vd=vector<db>;

int gauss_db(vector<vd> &a,int c,db &d,vector<int> &piv){
    int n=SZ(a),r=0;d=1,piv.clear();
    for(int j=0;j<c&&r<n;j++){
        int p=r;
        for(int i=r;i<n;i++)
            if(fabsl(a[i][j])>fabsl(a[p][j]))p=i;
        if(fabsl(a[p][j])<EPS)continue;
        if(p!=r)swap(a[p],a[r]),d=-d;
        auto &ar=a[r];db v=ar[j];d*=v;
        for(int k=j;k<SZ(ar);k++)ar[k]/=v;
        for(int i=0;i<n;i++)if(i!=r&&fabsl(a[i][j])>0){
            db f=a[i][j];
            for(int k=j;k<SZ(ar);k++)a[i][k]-=f*ar[k];
        }
        piv.pb(j),r++;
    }
    if(r<c)d=0;
    return r;
}
db det_db(vector<vd> a){
    db d;vector<int> p;gauss_db(a,SZ(a),d,p);return d;
}
int solve_db(vector<vd> a,const vd &b,int m,vd &x){
    int n=SZ(a);db d;vector<int> p;
    for(int i=0;i<n;i++)a[i].pb(b[i]);
    int r=gauss_db(a,m,d,p);
    for(int i=r;i<n;i++)if(fabsl(a[i][m])>EPS)return -1;
    x.assign(m,0);
    for(int i=0;i<r;i++)x[p[i]]=a[i][m];
    return r;
}
