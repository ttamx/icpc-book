#line 1 "verify\\graph\\k-th-shortest-path\\k_shortest_walk.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/k_shortest_walk"
#line 2 "src\\contest\\template.hpp"
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define SORT(a) sort(ALL(a))
#define RSORT(a) sort(RALL(a))
#define REV(a) reverse(ALL(a))
#define UNI(a) a.erase(unique(ALL(a)),a.end())
#define SZ(a) (int)(a.size())
#define LB(a,x) (int)(lower_bound(ALL(a),x)-a.begin())
#define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())
#define MIN(a) *min_element(ALL(a))
#define MAX(a) *max_element(ALL(a))

using ll = long long;
using db = long double;
using i128 = __int128_t;
using u32 = uint32_t;
using u64 = uint64_t;

const int INF=INT_MAX/2;
const ll LINF=LLONG_MAX/4;
const db DINF=numeric_limits<db>::infinity();
const int MOD=998244353;
const int MOD2=1000000007;
const db EPS=1e-9;
const db PI=acos(db(-1));

template<class T>
using PQ = priority_queue<T,vector<T>,greater<T>>;

#define vv(T,a,n,...) vector<vector<T>> a(n,vector<T>(__VA_ARGS__))
#define vvv(T,a,n,m,...) vector<vector<vector<T>>> a(n,vector<vector<T>>(m,vector<T>(__VA_ARGS__)))
#define vvvv(T,a,n,m,k,...) vector<vector<vector<vector<T>>>> a(n,vector<vector<vector<T>>>(m,vector<vector<T>>(k,vector<T>(__VA_ARGS__))))

template<class T,class U>
bool chmin(T &a,U b){return b<a?a=b,1:0;}
template<class T,class U>
bool chmax(T &a,U b){return a<b?a=b,1:0;}
template<class T,class U>
T SUM(const U &a){return accumulate(ALL(a),T{});}

template<class T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
#line 2 "src\\graph\\k-th-shortest-path.hpp"

/**
 * Author: Teetat T.
 * Description: K-th shortest path
 */

vector<ll> kth_shortest_path(vector<vector<pair<int,ll>>> &adj,int s,int t,int k){
    int n=adj.size();
    vector<vector<pair<int,ll>>> radj(n);
    for(int u=0;u<n;u++)for(auto [v,w]:adj[u])radj[v].emplace_back(u,w);
    using P = pair<ll,int>;
    priority_queue<P,vector<P>,greater<P>> pq;
    vector<ll> dist(n,LINF);
    vector<int> par(n,-1);
    pq.emplace(dist[t]=0,t);
    while(!pq.empty()){
        auto [d,u]=pq.top();pq.pop();
        if(d>dist[u])continue;
        for(auto [v,w]:radj[u])if(d+w<dist[v])pq.emplace(dist[v]=d+w,v),par[v]=u;
    }
    if(dist[s]==LINF)return {};
    struct Node{
        ll val;
        int id,rank,l,r;
    };
    vector<Node> nodes;
    auto new_node=[&](ll val,int id,int rank,int l,int r){
        nodes.emplace_back(Node{val,id,rank,l,r});
        return (int)nodes.size()-1;
    };
    function<int(int,ll,int)> insert=[&](int t,ll val,int id){
        if(t==-1||val<nodes[t].val)return new_node(val,id,0,t,-1);
        int l=nodes[t].l,r=insert(nodes[t].r,val,id);
        if(l==-1||nodes[r].rank>nodes[l].rank)swap(l,r);
        return new_node(nodes[t].val,nodes[t].id,r!=-1?nodes[r].rank+1:0,l,r);
    };
    vector<int> ptr(n,-1);
    vector<vector<int>> ch(n);
    for(int i=0;i<n;i++)if(par[i]!=-1)ch[par[i]].emplace_back(i);
    queue<int> q;
    q.emplace(t);
    while(!q.empty()){
        int u=q.front();q.pop();
        bool f=false;
        for(auto [v,w]:adj[u])if(dist[v]<LINF){
            ll c=w+dist[v]-dist[u];
            if(!f&&!c&&v==par[u]){
                f=true;
                continue;
            }
            ptr[u]=insert(ptr[u],c,v);
        }
        for(auto v:ch[u]){
            ptr[v]=ptr[u];
            q.emplace(v);
        }
    }
    vector<ll> ans{dist[s]};
    if(ptr[s]==-1)return ans;
    pq.emplace(dist[s]+nodes[ptr[s]].val,ptr[s]);
    while(!pq.empty()&&ans.size()<k){
        auto [d,u]=pq.top();pq.pop();
        ans.emplace_back(d);
        ll val=nodes[u].val;
        int v=nodes[u].id,l=nodes[u].l,r=nodes[u].r;
        if(ptr[v]!=-1)pq.emplace(d+nodes[ptr[v]].val,ptr[v]);
        if(l!=-1)pq.emplace(d+nodes[l].val-val,l);
        if(r!=-1)pq.emplace(d+nodes[r].val-val,r);
    }
    return ans;
}
#line 4 "verify\\graph\\k-th-shortest-path\\k_shortest_walk.test.cpp"

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
