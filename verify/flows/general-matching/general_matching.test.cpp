#define PROBLEM "https://judge.yosupo.jp/problem/general_matching"
#include "src/contest/template.hpp"
#include "src/flows/general-matching.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    GeneralMatching gm(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        gm.add_edge(u,v);
    }
    cout << gm.max_matching() << "\n";
    for(int i=0;i<n;i++){
        if(gm.match[i]!=-1&&i<gm.match[i]){
            cout << i << " " << gm.match[i] << "\n";
        }
    }
}