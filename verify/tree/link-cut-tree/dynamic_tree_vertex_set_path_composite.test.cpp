#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"
#include "src/contest/template.hpp"
#include "src/number-theory/modint.hpp"
#include "src/tree/link-cut-tree.hpp"

using mint = mint998;

struct F{
    mint a=1,b=0;
    F operator+(const F &o)const{return {a*o.a,b*o.a+o.b};}
};

const int N=2e5+5;
LinkCutTree<N,F> lct;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        F f;
        cin >> f.a >> f.b;
        lct.set(i,f);
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        lct.link(u+1,v+1);
    }
    while(q--){
        int t;
        cin >> t;
        if(t==0){
            int u,v,w,x;
            cin >> u >> v >> w >> x;
            lct.cut(u+1,v+1),lct.link(w+1,x+1);
        }else if(t==1){
            int p;
            F f;
            cin >> p >> f.a >> f.b;
            lct.set(p+1,f);
        }else{
            int u,v;
            mint x;
            cin >> u >> v >> x;
            F f=lct.aggregate(u+1,v+1);
            cout << f.a*x+f.b << "\n";
        }
    }
}
