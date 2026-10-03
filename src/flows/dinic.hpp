#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-07-15
 * Description: Dinic's Algorithm for finding the maximum flow.
 * cut() returns the flow and res[i]=1 iff i is on the sink side.
 * Time: $O(V^2E)$ in general, $O(VE\log U)$ with scaling
 * where $U$ is the maximum capacity.
 */

template<class T,bool directed=true,bool scaling=true>
struct Dinic{
    static constexpr T INF=numeric_limits<T>::max()/2;
    struct Edge{
        int to;T flow,cap;
        T remain(){return cap-flow;}
    };
    int n,s,t;T U;
    vector<Edge> e;
    vector<vector<int>> g;
    vector<int> ptr,lv;
    bool calculated;T max_flow;
    Dinic(){}
    Dinic(int n,int s,int t){init(n,s,t);}
    void init(int _n,int _s,int _t){
        n=_n,s=_s,t=_t,U=0,calculated=false;
        e.clear(),g.assign(n,{});
    }
    void add_edge(int from,int to,T cap){
        assert(0<=from&&from<n&&0<=to&&to<n);
        g[from].pb(SZ(e)),e.pb({to,0,cap});
        g[to].pb(SZ(e)),e.pb({from,0,directed?0:cap});
        U=max(U,cap);
    }
    bool bfs(T scale){
        lv.assign(n,-1),lv[s]=0;
        vector<int> q{s};
        for(int i=0;i<SZ(q);i++)for(int j:g[q[i]]){
            int v=e[j].to;
            if(lv[v]==-1&&e[j].remain()>=scale)
                lv[v]=lv[q[i]]+1,q.pb(v);
        }
        return lv[t]!=-1;
    }
    T dfs(int u,int t,T f){
        if(u==t||f==0)return f;
        for(int &i=ptr[u];i<SZ(g[u]);i++){
            int j=g[u][i],v=e[j].to;
            if(lv[v]!=lv[u]+1)continue;
            T r=dfs(v,t,min(f,e[j].remain()));
            if(r>0)return e[j].flow+=r,e[j^1].flow-=r,r;
        }
        return 0;
    }
    T flow(){
        if(calculated)return max_flow;
        calculated=true,max_flow=0;
        T scale=scaling&&U?1LL<<(63-__builtin_clzll(U)):1LL;
        for(;scale>0;scale>>=1)while(bfs(scale)){
            ptr.assign(n,0);
            while(T f=dfs(s,t,INF))max_flow+=f;
        }
        return max_flow;
    }
    pair<T,vector<int>> cut(){
        flow();
        vector<int> res(n);
        for(int i=0;i<n;i++)res[i]=lv[i]==-1;
        return {max_flow,res};
    }
};
