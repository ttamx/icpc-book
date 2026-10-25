#define PROBLEM "https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root"
#include "src/contest/template.hpp"
#include "src/number-theory/modint.hpp"
#include "src/tree/static-top-tree.hpp"

using mint = mint998;

vector<mint> a,b,c;
vector<int> orig;

struct TreeDP{
    struct Path{
        mint cnt,sum,b,c;
        static Path unit(){return {0,0,1,0};}
    };
    struct Point{
        mint cnt,sum;
        static Point unit(){return {0,0};}
    };
    static Path compress(Path p,Path q){
        return {p.cnt+q.cnt,p.sum+p.b*q.sum+p.c*q.cnt,p.b*q.b,p.b*q.c+p.c};
    }
    static Point rake(Point p,Point q){return {p.cnt+q.cnt,p.sum+q.sum};}
    static Point add_edge(Path p){return {p.cnt,p.sum};}
    static Path add_vertex(Point p,int v){
        mint k=p.cnt+orig[v];
        return {k,b[v]*(p.sum+a[v])+c[v]*k,b[v],c[v]};
    }
    static Path vertex(int v){return add_vertex(Point::unit(),v);}
};

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    int m=2*n-1;
    a.assign(m+1,0),b.assign(m+1,1),c.assign(m+1,0),orig.assign(m+1,0);
    for(int i=1;i<=n;i++)cin >> a[i],orig[i]=1;
    vector<vector<int>> adj(m+1);
    for(int i=0;i<n-1;i++){
        int u,v,e=n+1+i;
        cin >> u >> v >> b[e] >> c[e];
        u++,v++;
        adj[u].pb(e),adj[e].pb(u),adj[v].pb(e),adj[e].pb(v);
    }
    StaticTopTreeRerootingDP<TreeDP> dp(adj);
    while(q--){
        int ty;
        cin >> ty;
        if(ty==0){
            int w;
            cin >> w >> a[w+1];
            dp.update(w+1);
        }else{
            int e;
            cin >> e >> b[n+1+e] >> c[n+1+e];
            dp.update(n+1+e);
        }
        cout << dp.query_all().sum << "\n";
    }
}
