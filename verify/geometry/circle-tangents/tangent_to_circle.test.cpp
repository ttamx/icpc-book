#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F"
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
    P p=rd(),c=rd();
    double r;
    cin >> r;
    vector<P> v;
    for(auto [a,b]:tangents(c,r,p,0.0))v.pb(a);
    sort(ALL(v),[](P x,P y){
        return abs(x.x-y.x)>1e-9?x.x<y.x:x.y<y.y;});
    for(P q:v)cout << q.x << " " << q.y << "\n";
}
