#define PROBLEM "https://judge.yosupo.jp/problem/manhattanmst"
#include "src/contest/template.hpp"
#include "src/geometry/ManhattanMST.h"

int f[200005];
int fd(int x){return f[x]==x?x:f[x]=fd(f[x]);}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<P> v(n);
    for(auto &p:v)cin >> p.x >> p.y;
    auto e=manhattanMST(v);
    sort(ALL(e));
    iota(f,f+n,0);
    ll w=0;
    vector<pair<int,int>> res;
    for(auto [d,a,b]:e)if(fd(a)!=fd(b)){
        f[fd(a)]=fd(b);
        w+=d;
        res.pb({a,b});
    }
    cout << w << "\n";
    for(auto [a,b]:res)cout << a << " " << b << "\n";
}
