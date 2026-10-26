#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D"
#define ERROR 1e-6
#include "src/contest/template.hpp"
#include "src/geometry/CircleLine.h"

using P = Point<double>;
P rd(){
    double x,y;
    cin >> x >> y;
    return P(x,y);
}
void out(vector<P> v){
    sort(ALL(v),[](P a,P b){
        return abs(a.x-b.x)>1e-9?a.x<b.x:a.y<b.y;});
    for(int i=0;i<SZ(v);i++)
        cout << v[i].x << " " << v[i].y << (i+1<SZ(v)?" ":"\n");
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(10);
    P c=rd();
    double r;
    cin >> r;
    int q;
    cin >> q;
    while(q--){
        P a=rd(),b=rd();
        auto v=circleLine(c,r,a,b);
        if(SZ(v)==1)v.pb(v[0]);
        out(v);
    }
}
