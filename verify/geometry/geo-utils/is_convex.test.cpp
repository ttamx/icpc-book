#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"
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
    int n;
    cin >> n;
    vector<P> v(n);
    for(auto &p:v)p=rd();
    bool ok=true;
    for(int i=0;i<n;i++)
        if(sideOf(v[i],v[(i+1)%n],v[(i+2)%n])<0)ok=false;
    cout << ok << "\n";
}
