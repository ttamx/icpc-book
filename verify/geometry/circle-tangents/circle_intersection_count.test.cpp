#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A"
#include "src/contest/template.hpp"
#include "src/geometry/CircleTangents.h"

using P = Point<double>;
P rd(){
    double x,y;
    cin >> x >> y;
    return P(x,y);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    P a=rd();
    double r1;
    cin >> r1;
    P b=rd();
    double r2;
    cin >> r2;
    // common tangents = external + internal
    cout << SZ(tangents(a,r1,b,r2))+SZ(tangents(a,r1,b,-r2)) << "\n";
}
