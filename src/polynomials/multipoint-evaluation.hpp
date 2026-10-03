#pragma once
#include "src/polynomials/subproduct-tree.hpp"

/**
 * Author: Teetat T.
 * Description: Evaluate polynomial $f$ at points $x_0, \dots, x_{m-1}$.
 * Time: $O(N \log^2 N)$ where $N = \max(|f|, M)$
 */

template<class mint>
vector<mint> multipoint_evaluation(
    const FormalPowerSeries<mint> &f,
    const SubproductTree<mint> &T){
    vector<mint> res(T.m);
    auto rec=[&](auto &&self,auto g,int i,int l,int r)->void {
        g%=T.t[i];
        if(r-l<=64){
            for(int j=l;j<r;j++)res[j]=g.eval(T.xs[j]);
            return;
        }
        int mid=(l+r)/2;
        self(self,g,2*i,l,mid),self(self,g,2*i+1,mid,r);
    };
    if(T.m)rec(rec,f,1,0,T.m);
    return res;
}
template<class mint>
vector<mint> multipoint_evaluation(
    const FormalPowerSeries<mint> &f,const vector<mint> &xs){
    return multipoint_evaluation(f,SubproductTree<mint>(xs));
}
