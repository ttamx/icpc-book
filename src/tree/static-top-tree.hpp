#pragma once
#include "src/contest/template.hpp"

/**
 * Author: Teetat T.
 * Date: 2024-11-14
 * Description: Static top tree of a tree with vertices $1..n$ (adj has size $n+1$, root $1$).
 * Node pool is 1-indexed, 0 = null, at most $2n-1$ nodes; vertex $v$ is its own Vertex/AddVertex node.
 * Balanced by subtree size, height $O(\log n)$.
 * StaticTopTreeRerootingDP takes a DP struct D (interface in the code).
 * After changing the data of $v$, call update($v$).
 * Time: build $O(n \log n)$, update / query\_subtree / query\_reroot $O(\log n)$, query\_all $O(1)$
 */

struct StaticTopTree{
    using P = pair<int,int>;
    using G = vector<vector<int>>;
    enum Type{Compress,Rake,AddVertex,Vertex};
    int n,cnt,root;
    G &adj;
    vector<int> hv,fa,l,r,par,t;
    StaticTopTree(G &g):adj(g){ // 1-indexed
        n=cnt=SZ(g)-1;
        hv=fa=l=r=par=t=vector<int>(2*n+1);
        vector<int> o{1},s(n+1,1);s[0]=0; // BFS order, sizes
        for(int i=0;i<SZ(o);i++){
            int u=o[i];
            for(int v:adj[u])if(v!=fa[u])fa[v]=u,o.pb(v);
        }
        for(int i=n-1;i>0;i--){
            int u=o[i],p=fa[u];s[p]+=s[u];
            if(s[u]>s[hv[p]])hv[p]=u;
        }
        root=compress(1).first;
    }
    int add(int i,int a,int b,Type ty){
        if(!i)i=++cnt;
        l[i]=a,r[i]=b,t[i]=ty,par[a]=par[b]=i;
        return i;
    }
    P merge(const vector<P> &a,int x,int y,Type ty){
        if(y-x==1)return a[x];
        int tot=0,m=x;
        for(int k=x;k<y;k++)tot+=a[k].second;
        while(tot>a[m].second)tot-=2*a[m++].second;
        auto [i,si]=merge(a,x,m,ty);
        auto [j,sj]=merge(a,m,y,ty);
        return {add(0,i,j,ty),si+sj};
    }
    P compress(int i){
        vector<P> a{add_vertex(i)};
        while(hv[i])a.eb(add_vertex(i=hv[i]));
        return merge(a,0,SZ(a),Compress);
    }
    P rake(int i){
        vector<P> a;
        for(int j:adj[i])
            if(j!=fa[i]&&j!=hv[i])a.eb(compress(j));
        return a.empty()?P(0,0):merge(a,0,SZ(a),Rake);
    }
    P add_vertex(int i){
        auto [j,s]=rake(i);
        return {add(i,j,0,j?AddVertex:Vertex),s+1};
    }
};
/* struct D{
    struct Path{static Path unit();};
    struct Point{static Point unit();};
    static Path vertex(int v),add_vertex(Point p,int v),
        compress(Path up,Path down);
    static Point add_edge(Path p),rake(Point a,Point b);
}; */
template<class D>
struct StaticTopTreeRerootingDP:StaticTopTree{
    using Path=typename D::Path;
    using Point=typename D::Point;
    vector<Path> path,rvpath;
    vector<Point> point;
    StaticTopTreeRerootingDP(G &g):StaticTopTree(g){
        path=rvpath=vector<Path>(cnt+1),point.resize(cnt+1);
        calc(root);
    }
    void _update(int u){
        int lc=l[u],rc=r[u];
        if(t[u]==Vertex)path[u]=rvpath[u]=D::vertex(u);
        else if(t[u]==Compress){
            path[u]=D::compress(path[lc],path[rc]);
            rvpath[u]=D::compress(rvpath[rc],rvpath[lc]);
        }
        else if(t[u]==Rake)point[u]=D::rake(pt(lc),pt(rc));
        else path[u]=rvpath[u]=D::add_vertex(pt(lc),u);
    }
    Point pt(int c){
        return t[c]==Rake?point[c]:D::add_edge(path[c]);}
    void calc(int u){if(u)calc(l[u]),calc(r[u]),_update(u);}
    void update(int u){for(;u;u=par[u])_update(u);}
    Path query_all(){return path[root];}
    Path query_subtree(int u){
        Path res=path[u];
        for(int p;(p=par[u])&&t[p]==Compress;u=p)
            if(l[p]==u)res=D::compress(res,path[r[p]]);
        return res;
    }
    pair<Path,Path> around(int u){ // {below u, rest of tree}
        Path dn=Path::unit(),up=dn;
        int p=par[u];
        for(;p&&t[p]==Compress;p=par[u=p])
            if(l[p]==u)dn=D::compress(dn,path[r[p]]);
            else up=D::compress(up,rvpath[l[p]]);
        if(p){
            Point s=Point::unit();
            for(;t[p]==Rake;p=par[u=p])
                s=D::rake(s,pt(l[p]^r[p]^u));
            s=D::rake(s,out(p));
            up=D::compress(up,D::add_vertex(s,p));
        }
        return {dn,up};
    }
    Point out(int u){
        auto [dn,up]=around(u);
        return D::rake(D::add_edge(dn),D::add_edge(up));
    }
    Path query_reroot(int u){
        Point s=out(u);
        if(t[u]==AddVertex)s=D::rake(s,pt(l[u]));
        return D::add_vertex(s,u);
    }
    Path query_side(int v,int w){// remove (v,w) then query(v)
        return fa[v]==w?query_subtree(v):around(w).second;
    }
};
