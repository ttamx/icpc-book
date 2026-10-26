#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
#define ERROR 1e-8
#include "src/contest/template.hpp"
#include "src/geometry/GeoUtils.h"

using P = Point<double>;
P rd(){
    double x,y;
    cin >> x >> y;
    return P(x,y);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(10);
    P a=rd(),b=rd();
    int q;
    cin >> q;
    while(q--){
        P r=lineProj(a,b,rd(),true);
        cout << r.x << " " << r.y << "\n";
    }
}
