#define PROBLEM "https://judge.yosupo.jp/problem/furthest_pair"
#include "src/contest/template.hpp"
#include "src/geometry/ConvexHull.h"
#include "src/geometry/HullDiameter.h"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<P> v(n);
        map<P,vector<int>> id;
        for(int i=0;i<n;i++)cin >> v[i].x >> v[i].y,id[v[i]].pb(i);
        auto [a,b]=hullDiameter(convexHull(v));
        int i=id[a][0],j=id[b][a==b&&SZ(id[b])>1];
        cout << i << " " << j << "\n";
    }
}
