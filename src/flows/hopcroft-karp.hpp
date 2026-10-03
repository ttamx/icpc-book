#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-03-31
 * Description: Fast bipartite matching algorithm. Left $[0,n)$,
 * right $[0,m)$; after max\_matching(), match[i] ($i<n$) is
 * $n+$(matched right vertex) or -1.
 * Time: $O(E\sqrt{V})$
 */

struct HopcroftKarp{
    int n,m;
    vector<int> match,lv,ptr;
    vector<vector<int>> adj;
    HopcroftKarp(){}
    HopcroftKarp(int _n,int _m){init(_n,_m);}
    void init(int _n,int _m){n=_n,m=_m,adj.assign(n+m,{});}
    void add_edge(int u,int v){adj[u].pb(v+n);}
    void bfs(){
        lv.assign(n,-1);
        vector<int> q;
        for(int i=0;i<n;i++)if(match[i]==-1)lv[i]=0,q.pb(i);
        for(int i=0;i<SZ(q);i++)for(int v:adj[q[i]])
            if(int w=match[v];w!=-1&&lv[w]==-1)
                lv[w]=lv[q[i]]+1,q.pb(w);
    }
    bool dfs(int u){
        for(int &i=ptr[u];i<SZ(adj[u]);i++){
            int v=adj[u][i],w=match[v];
            if(w==-1||(lv[w]==lv[u]+1&&dfs(w)))
                return match[u]=v,match[v]=u,true;
        }
        return false;
    }
    int max_matching(){
        int ans=0,c=1;
        match.assign(n+m,-1);
        while(c){
            ptr.assign(n,0),bfs(),c=0;
            for(int i=0;i<n;i++)c+=match[i]==-1&&dfs(i);
            ans+=c;
        }
        return ans;
    }
};
