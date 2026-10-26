#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"
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
    ll a=abs(polygonArea2(v));
    cout << a/2 << "." << (a%2?5:0) << "\n";
}
