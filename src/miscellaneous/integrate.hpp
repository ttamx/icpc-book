#pragma once

/**
 * Author: Teetat T.
 * Date: 2025-07-19
 * Description: find definite integral with Simpson's method, error proportional to dx^4.
 */

template<class F>
db quad(db a,db b,const F &f,int n){
    db res=0;
    db dx=(b-a)/n;
    db fl=0,fr=f(a);
    for(int i=0;i<n;i++){
        db l=a+dx*i,r=l+dx;
        fl=fr;
        fr=f(r);
        db fm=f((l+r)/2);
        res+=fl+4*fm+fr;
    }
    return res*dx/6;
}