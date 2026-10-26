#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H"
#define ERROR 1e-5
#include "src/contest/template.hpp"
#include "src/geometry/CirclePolyInter.h"

P rd(){
    double x,y;
    cin >> x >> y;
    return P(x,y);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int n;
    double r;
    cin >> n >> r;
    vector<P> v(n);
    for(auto &p:v)p=rd();
    cout << circlePoly(P(0,0),r,v) << "\n";
}
