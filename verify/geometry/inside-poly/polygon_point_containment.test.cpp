#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"
#include "src/contest/template.hpp"
#include "src/geometry/InsidePoly.h"

using P = Point<ll>;
P rd(){
    ll x,y;
    cin >> x >> y;
    return P(x,y);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<P> v(n);
    for(auto &p:v)p=rd();
    int q;
    cin >> q;
    while(q--){
        P a=rd();
        cout << (inPolygon(v,a,true)?2:inPolygon(v,a,false)?1:0) << "\n";
    }
}
