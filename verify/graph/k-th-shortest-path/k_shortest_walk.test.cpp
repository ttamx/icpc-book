#define PROBLEM "https://judge.yosupo.jp/problem/k_shortest_walk"
#include "src/contest/template.hpp"
#include "src/graph/k-th-shortest-path.hpp"

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,s,t,k;
    cin >> n >> m >> s >> t >> k;
    vector<vector<pair<int,ll>>> adj(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v,w);
    }
    auto ans=kth_shortest_path(adj,s,t,k);
    ans.resize(k,-1);
    for(auto x:ans)cout << x << "\n";
}