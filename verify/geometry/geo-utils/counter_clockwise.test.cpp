#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"
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
    P a=rd(),b=rd();
    int q;
    cin >> q;
    while(q--){
        P c=rd();
        int s=sideOf(a,b,c);
        if(s>0)cout << "COUNTER_CLOCKWISE\n";
        else if(s<0)cout << "CLOCKWISE\n";
        else if(onSegment(a,b,c))cout << "ON_SEGMENT\n";
        else if((b-a).dot(c-a)<0)cout << "ONLINE_BACK\n";
        else cout << "ONLINE_FRONT\n";
    }
}
