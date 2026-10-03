#pragma once
#include "src/polynomials/formal-power-series.hpp"

/**
 * Author: Teetat T.
 * Description: Subproduct tree of points $x_0, \dots, x_{m-1}$.
 * Node $i$ covers $[l, r)$ and stores $\prod_{l \le j < r} (x - x_j)$, root is node $1$.
 * Time: $O(M \log^2 M)$
 */

template<class mint>
struct SubproductTree{
    int m;
    vector<mint> xs;
    vector<FormalPowerSeries<mint>> t;
    SubproductTree(const vector<mint> &xs)
        :m(xs.size()),xs(xs),t(4*m){if(m)build(1,0,m);}
    void build(int i,int l,int r){
        if(r-l==1)return void(t[i]={-xs[l],1});
        int mid=(l+r)/2;
        build(2*i,l,mid),build(2*i+1,mid,r);
        t[i]=t[2*i]*t[2*i+1];
    }
};
