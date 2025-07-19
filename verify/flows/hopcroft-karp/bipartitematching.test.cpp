#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "src/contest/template.hpp"
#include "src/flows/hopcroft-karp.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,e;
    cin >> n >> m >> e;
    HopcroftKarp bm(n,m);
    for(int i=0;i<e;i++){
        int u,v;
        cin >> u >> v;
        bm.add_edge(u,v);
    }
    cout << bm.max_matching() << "\n";
    for(int i=0;i<n;i++){
        if(bm.match[i]!=-1){
            cout << i << " " << bm.match[i]-n << "\n";
        }
    }
}