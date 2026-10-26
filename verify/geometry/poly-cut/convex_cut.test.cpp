#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C"
#define ERROR 1e-5
#include "src/contest/template.hpp"
#include "src/geometry/PolyCut.h"
#include "src/geometry/GeoUtils.h"

P rd(){
    double x,y;
    cin >> x >> y;
    return P(x,y);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<P> v(n);
    for(auto &p:v)p=rd();
    int q;
    cin >> q;
    while(q--){
        P a=rd(),b=rd();
        // polygonCut keeps the right side of s->e; AOJ wants the left
        auto c=polygonCut(v,b,a);
        cout << (SZ(c)<3?0:abs(polygonArea2(c))/2) << "\n";
    }
}
