#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G"
#define ERROR 1e-5
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
    cout << fixed << setprecision(10);
    P a=rd();
    double r1;
    cin >> r1;
    P b=rd();
    double r2;
    cin >> r2;
    vector<P> v;
    for(double s:{1,-1})
        for(auto [p,q]:tangents(a,r1,b,r2*s))v.pb(p);
    sort(ALL(v),[](P x,P y){
        return abs(x.x-y.x)>1e-9?x.x<y.x:x.y<y.y;});
    for(P p:v)cout << p.x << " " << p.y << "\n";
}
