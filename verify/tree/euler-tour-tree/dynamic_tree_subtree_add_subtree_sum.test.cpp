#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum"
#include "src/contest/template.hpp"
#include "src/tree/euler-tour-tree.hpp"

const int N=2e5+5;
EulerTourTree<3*N,ll> ett;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    ett.init(n);
    for(int i=1;i<=n;i++){
        ll a;
        cin >> a;
        ett.set(i,a);
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        ett.link(u+1,v+1);
    }
    while(q--){
        int t;
        cin >> t;
        if(t==0){
            int u,v,w,x;
            cin >> u >> v >> w >> x;
            ett.cut(u+1,v+1),ett.link(w+1,x+1);
        }else if(t==1){
            int v,p;
            ll x;
            cin >> v >> p >> x;
            ett.add(v+1,p+1,x);
        }else{
            int v,p;
            cin >> v >> p;
            cout << ett.query(v+1,p+1) << "\n";
        }
    }
}
