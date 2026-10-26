#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C"
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
    int q;
    cin >> q;
    while(q--){
        P a=rd(),b=rd(),c=rd(),d=rd();
        P r=lineInter(a,b,c,d).second;
        cout << r.x << " " << r.y << "\n";
    }
}
