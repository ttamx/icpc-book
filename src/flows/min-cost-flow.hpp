#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-03-31
 * Description: Minimum-cost maximum flow (successive shortest
 * paths, Dijkstra with potentials; Bellman-Ford initializes the
 * potentials if there are negative costs). No negative cycles.
 * Time: $O(FE\log{V})$ where $F$ is max flow.
 */

template<class F,class C>
struct MinCostFlow{
    struct Edge{
        int to;F flow,cap;C cost;
        F getcap(){return cap-flow;}
    };
    int n;
    vector<Edge> e;
    vector<vector<int>> adj;
    vector<C> pot,dist;
    vector<int> pre;
    bool neg;
    const F FINF=numeric_limits<F>::max()/2;
    const C CINF=numeric_limits<C>::max()/2;
    MinCostFlow(){}
    MinCostFlow(int _n){init(_n);}
    void init(int _n){n=_n,neg=0,e.clear(),adj.assign(n,{});}
    void addEdge(int u,int v,F cap,C cost){
        adj[u].pb(SZ(e)),e.pb({v,0,cap,cost});
        adj[v].pb(SZ(e)),e.pb({u,0,0,-cost});
        if(cost<0)neg=true;
    }
    bool dijkstra(int s,int t){
        using P=pair<C,int>;
        dist.assign(n,CINF),pre.assign(n,-1);
        PQ<P> pq;
        dist[s]=0,pq.emplace(0,s);
        while(!pq.empty()){
            auto [d,u]=pq.top();pq.pop();
            if(dist[u]<d)continue;
            for(int i:adj[u]){
                C nd=d+pot[u]-pot[e[i].to]+e[i].cost;
                if(e[i].getcap()>0&&chmin(dist[e[i].to],nd))
                    pre[e[i].to]=i,pq.emplace(nd,e[i].to);
            }
        }
        return dist[t]<CINF;
    }
    pair<F,C> flow(int s,int t){
        F flow=0;C cost=0;
        pot.assign(n,0);
        if(neg)for(int k=0;k<n;k++)for(int i=0;i<SZ(e);i++)
            if(int u=e[i^1].to,v=e[i].to;e[i].getcap()>0)
                pot[v]=min(pot[v],pot[u]+e[i].cost);
        while(dijkstra(s,t)){
            for(int i=0;i<n;i++)pot[i]+=dist[i]<CINF?dist[i]:0;
            F aug=FINF;
            for(int u=t;u!=s;u=e[pre[u]^1].to)
                aug=min(aug,e[pre[u]].getcap());
            for(int u=t;u!=s;u=e[pre[u]^1].to)
                e[pre[u]].flow+=aug,e[pre[u]^1].flow-=aug;
            flow+=aug,cost+=aug*(pot[t]-pot[s]);
        }
        return {flow,cost};
    }
};
