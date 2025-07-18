#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"
#include "src/contest/template.hpp"
#include "src/tree/LinkCutTree.hpp"

const int N=2e5+5;

int n,q;
ll a[N];
LinkCutTree<N,ll> lct;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        lct.set(i,a[i]);
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        u++,v++;
        lct.link(u,v);
    }
    while(q--){
        int op;
        cin >> op;
        if(op==0){
            int u,v,x,y;
            cin >> u >> v >> x >> y;
            u++,v++,x++,y++;
            lct.cut(u,v);
            lct.link(x,y);
        }else if(op==1){
            int u,x;
            cin >> u >> x;
            u++;
            lct.set(u,a[u]+=x);
        }else{
            int u,v;
            cin >> u >> v;
            u++,v++;
            cout << lct.aggregate(u,v) << "\n";
        }
    }
}