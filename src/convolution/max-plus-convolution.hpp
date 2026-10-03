#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-09-01
 * Description: Max Plus Convolution. Find $C[k]=\max_{i+j=k}\{A[i]+B[j]\}$
 * for arbitrary $A$ and concave $B$ ($B[i]-B[i-1]\ge B[i+1]-B[i]$).
 * smawck is the SMAWK algorithm for row-wise maxima of a totally
 * monotone matrix; f(i,j,k) is true if $M[i][j]\le M[i][k]$
 * (i.e. column k is at least as good as j, higher is better).
 * Time: $O(N+M)$.
 */

template<class F>
vector<int> smawck(const F &f,const vector<int> &rows,
                   const vector<int> &cols){
    int n=SZ(rows),m=SZ(cols);
    if(max(n,m)<=2){
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++)for(int j:cols)
            if(ans[i]==-1||f(rows[i],ans[i],j))ans[i]=j;
        return ans;
    }
    if(n<m){
        vector<int> st;
        for(int j:cols){
            while(SZ(st)&&f(rows[SZ(st)-1],st.back(),j))
                st.pop_back();
            if(SZ(st)<n)st.emplace_back(j);
        }
        return smawck(f,rows,st);
    }
    vector<int> ans(n,-1),nr;
    for(int i=1;i<n;i+=2)nr.emplace_back(rows[i]);
    auto res=smawck(f,nr,cols);
    for(int i=0;i<SZ(nr);i++)ans[2*i+1]=res[i];
    for(int i=0,l=0,r=0;i<n;i+=2){
        if(i+1==n)r=m;
        while(r<m&&cols[r]<=ans[i+1])r++;
        for(ans[i]=cols[l];l+1<r;)
            if(f(rows[i],ans[i],cols[++l]))ans[i]=cols[l];
    }
    return ans;
}
template<class F>
vector<int> smawck(const F &f,int n,int m){
    vector<int> r(n),c(m);iota(ALL(r),0);iota(ALL(c),0);
    return smawck(f,r,c);
}
template<class T>
vector<T> max_plus_convolution_arbitary_convex(vector<T> a,
        const vector<T> &b){
    int n=SZ(a),m=SZ(b);if(!n||!m)return {};
    if(m==1){for(auto &x:a)x+=b[0];return a;}
    auto f=[&](int i,int j){return a[j]+b[i-j];};
    auto cmp=[&](int i,int j,int k){
        return i>=k&&(i-j>=m||f(i,j)<=f(i,k));};
    auto best=smawck(cmp,n+m-1,n);vector<T> ans(n+m-1);
    for(int i=0;i<n+m-1;i++)ans[i]=f(i,best[i]);
    return ans;
}
