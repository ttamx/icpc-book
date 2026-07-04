#pragma once

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