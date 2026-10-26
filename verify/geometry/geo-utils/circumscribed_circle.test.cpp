#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C"
#define ERROR 1e-6
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
    P a=rd(),b=rd(),c=rd();
    P o=ccCenter(a,b,c);
    cout << o.x << " " << o.y << " " << ccRadius(a,b,c) << "\n";
}
