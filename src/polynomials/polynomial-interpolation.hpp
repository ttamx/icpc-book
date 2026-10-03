#pragma once
#include "src/polynomials/multipoint-evaluation.hpp"

/**
 * Author: Teetat T.
 * Description: Polynomial $f$ of degree $< m$ with $f(x_i) = y_i$, $x_i$ must be distinct.
 * Time: $O(M \log^2 M)$
 */

template<class mint>
FormalPowerSeries<mint> polynomial_interpolation(
    const vector<mint> &xs,const vector<mint> &ys){
    using FPS = FormalPowerSeries<mint>;
    if(xs.empty())return {};
    SubproductTree<mint> T(xs);
    auto w=multipoint_evaluation(T.t[1].diff(),T);
    auto rec=[&](auto &&self,int i,int l,int r)->FPS {
        if(r-l==1)return {ys[l]/w[l]};
        int mid=(l+r)/2;
        auto L=self(self,2*i,l,mid),R=self(self,2*i+1,mid,r);
        return L*T.t[2*i+1]+R*T.t[2*i];
    };
    return rec(rec,1,0,T.m);
}
