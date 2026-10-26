#pragma once
#include "src/data-structures/treap.hpp"

/**
 * Author: Teetat T.
 * Description: Euler tour tree: a dynamic forest on vertices $1..n$
 * with subtree add / subtree sum. Each tree is its Euler tour (vertex
 * nodes + a weight-0 node per directed edge) in a Treap. The subtree
 * of $v$ whose parent is $p$ (adjacent) lies between the edge nodes
 * $(p,v)$ and $(v,p)$. N > 3n (cut edge nodes are recycled).
 * Usage: EulerTourTree<N,ll> ett; ett.init(n); ett.set(v,x);
 *  ett.link(u,v); ett.cut(u,v); ett.add(v,p,x); ett.query(v,p);
 * Time: $O(\log n)$ expected per operation
 */

template<int N,class T>
struct EulerTourTree:Treap<N,T>{
    using B=Treap<N,T>;using B::t,B::make,B::split;
    using B::merge,B::root,B::pos,B::apply;
    map<pair<int,int>,int> E; // directed edge -> node
    vector<int> fr; // freed edge nodes
    void init(int n){for(int i=1;i<=n;i++)make(T());}
    int edge(){ // recycled or new weight-0 node
        if(fr.empty())return make(T(),0);
        int x=fr.back();fr.pop_back();
        return t[x]={0,0,0,1},x;
    }
    void reroot(int v){
        auto [a,b]=split(root(v),pos(v));
        merge(b,a);
    }
    void link(int u,int v){
        reroot(u),reroot(v);
        assert(root(u)!=root(v));
        int e=E[{u,v}]=edge(),f=E[{v,u}]=edge();
        merge(merge(merge(root(u),e),root(v)),f);
    }
    void cut(int u,int v){ // sides: y, and x+z minus edges
        auto [x,y,z,in]=range(v,u);
        fr.pb(E[{u,v}]),fr.pb(E[{v,u}]);
        E.erase({u,v}),E.erase({v,u});
        merge(split(x,t[x].sz-1).first,split(z,1).second);
    }
    // tour = X|Y|Z cut at edge nodes (p,v),(v,p); subtree of v
    // (parent p) is Y if (p,v) is first, else X and Z (cyclic)
    array<int,4> range(int v,int p){
        int a=pos(E[{p,v}]),b=pos(E[{v,p}]);
        auto [x,z]=split(root(v),max(a,b));
        auto [x1,y]=split(x,min(a,b)+1);
        return {x1,y,z,a<b};
    }
    void add(int v,int p,T w){
        auto [x,y,z,in]=range(v,p);
        if(in)apply(y,w);
        else apply(x,w),apply(z,w);
        merge(merge(x,y),z);
    }
    T query(int v,int p){
        auto [x,y,z,in]=range(v,p);
        T s=in?t[y].sum:t[x].sum+t[z].sum;
        merge(merge(x,y),z);
        return s;
    }
    void set(int v,T x){ // point set
        auto [a,b]=split(root(v),pos(v));
        auto [c,d]=split(b,1); // c == v
        t[c].val=t[c].sum=x;
        merge(a,merge(c,d));
    }
};
