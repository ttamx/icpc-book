#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"
#include "src/contest/template.hpp"
#include "src/geometry/GeoUtils.h"

using P = Point<ll>;
P rd(){
    ll x,y;
    cin >> x >> y;
    return P(x,y);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--){
        P a=rd(),b=rd(),c=rd(),d=rd();
        cout << !segInter(a,b,c,d).empty() << "\n";
    }
}
