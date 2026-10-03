#pragma once

/**
 * Author: Teetat T.
 * Description: Dominator tree of a directed graph from root $r$
 * (Lengauer-Tarjan). Returns idom, with idom[r]=r and -1 for nodes
 * unreachable from $r$. Helpers for common queries in namespace domtree.
 * Time: $O((N+M)\log N)$
 */

// u dominates v: every path r->v passes through u.
// idom(v): the strict dominator of v closest to v.
// e(u) = DFS preorder index; the code works in this numbering.
// g: 0-indexed, g[u] = out-neighbours of u
vector<int> dominator_tree(const vector<vector<int>> &g,int r){
    int n=g.size(),t=0;
    vector<int> id(n,-1),ord,p(n),it(n),st{r};
    id[r]=t++,ord.push_back(r);
    while(!st.empty()){ // iterative DFS, p = DFS parent
        int u=st.back();
        if(it[u]==SZ(g[u]))st.pop_back();
        else if(int v=g[u][it[u]++];id[v]<0)
            p[id[v]=t++]=id[u],ord.pb(v),st.pb(v);
    }
    vector<vector<int>> rg(t),bk(t);
    for(int u=0;u<n;u++)if(id[u]>=0)
        for(int v:g[u])if(id[v]>=0)rg[id[v]].push_back(id[u]);
    vector<int> sd(t),lb(t),f(t),dom(t),path;
    iota(ALL(sd),0),lb=f=sd;
    auto eval=[&](int v){ // min sdom label on DSU path
        if(f[v]==v)return v;
        for(int x=v;f[f[x]]!=f[x];x=f[x])path.push_back(x);
        for(;!path.empty();path.pop_back()){
            int y=path.back();
            if(sd[lb[f[y]]]<sd[lb[y]])lb[y]=lb[f[y]];
            f[y]=f[f[y]];
        }
        return lb[v];
    };
    // sdom(u) = v with min e(v) having a path v=w0..wk=u with
    // e(wi)>e(u) for 0<i<k; it is a proper DFS-tree ancestor.
    // x(u) = node on tree path (sdom(u),u] with min sdom(x).
    // x(u)==u -> idom(u)=sdom(u), else idom(u)=idom(x(u)).
    for(int w=t-1;w>0;w--){
        for(int v:rg[w])sd[w]=min(sd[w],sd[eval(v)]);
        bk[sd[w]].push_back(w),f[w]=p[w];
        for(int v:bk[p[w]]){ // eval(v) = x(v)
            int u=eval(v);
            dom[v]=sd[u]<sd[v]?u:p[w];
        }
        bk[p[w]].clear();
    }
    vector<int> res(n,-1);
    res[r]=r;
    for(int w=1;w<t;w++){ // dom[w]=x(w) -> idom(x(w))
        if(dom[w]!=sd[w])dom[w]=dom[dom[w]];
        res[ord[w]]=ord[dom[w]];
    }
    return res;
}

// usage helpers, idom = dominator_tree(g,r)
namespace domtree{
    // children lists of the dominator tree (edge idom[v]->v)
    vector<vector<int>> children(const vector<int> &idom){
        int n=idom.size();
        vector<vector<int>> ch(n);
        for(int v=0;v<n;v++)
            if(idom[v]>=0&&idom[v]!=v)ch[idom[v]].pb(v);
        return ch;
    }
    // O(1) "u dominates v" via tin/tout on the dominator tree
    // (u is an ancestor of v), false if v is unreachable
    struct Dominates{
        vector<int> tin,tout;
        Dominates(const vector<int> &idom,int r){
            auto ch=children(idom);
            int n=idom.size(),T=0;
            tin.assign(n,-1),tout.assign(n,-1);
            vector<int> st{r},it(n);
            tin[r]=T++;
            while(!st.empty()){ // iterative DFS
                int u=st.back();
                if(it[u]==SZ(ch[u]))tout[u]=T++,st.pop_back();
                else{
                    int v=ch[u][it[u]++];
                    tin[v]=T++,st.pb(v);
                }
            }
        }
        bool operator()(int u,int v){
            if(tin[v]<0)return false;
            return tin[u]<=tin[v]&&tout[v]<=tout[u];
        }
    };
    // nodes on every r->t path (critical nodes), t up to r;
    // size = number of dominators of t, empty if unreachable
    vector<int> critical(const vector<int> &idom,int t){
        vector<int> res;
        if(idom[t]<0)return res;
        for(;;t=idom[t]){
            res.pb(t);
            if(idom[t]==t)break;
        }
        return res;
    }
}
