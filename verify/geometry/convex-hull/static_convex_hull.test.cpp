#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"
#include "src/contest/template.hpp"
#include "src/geometry/ConvexHull.h"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<P> v(n);
        for(auto &p:v)cin >> p.x >> p.y;
        auto h=convexHull(v);
        cout << SZ(h) << "\n";
        for(P p:h)cout << p.x << " " << p.y << "\n";
    }
}
