#pragma once

/**
 * Author: Teetat T.
 * Description: Link Cut Tree (1-indexed)
 */

template<int N,class T>
struct LinkCutTree{
    int ch[N][2],par[N],rev[N];
    T val[N],sum[N],rsum[N],lz[N];
    void toggle(int v){
        if(!v)return;
        swap(ch[v][0],ch[v][1]),swap(sum[v],rsum[v]),rev[v]^=1;
    }
    void apply(int v,T x){
        if(!v)return;
        val[v]=val[v]+x,lz[v]=lz[v]+x;
        sum[v]=sum[v]+x,rsum[v]=rsum[v]+x;
    }
    void push(int v){
        if(rev[v])toggle(ch[v][0]),toggle(ch[v][1]),rev[v]=0;
        apply(ch[v][0],lz[v]),apply(ch[v][1],lz[v]),lz[v]=T();
    }
    void pull(int v){
        sum[v]=sum[ch[v][0]]+val[v]+sum[ch[v][1]];
        rsum[v]=rsum[ch[v][1]]+val[v]+rsum[ch[v][0]];
    }
    bool pos(int v){return ch[par[v]][1]==v;}
    bool is_root(int v){return ch[par[v]][pos(v)]!=v;}
    void rotate(int v){
        int u=par[v],g=par[u],x=pos(v);
        if(!is_root(u))ch[g][pos(u)]=v;
        if((ch[u][x]=ch[v][!x]))par[ch[u][x]]=u;
        ch[v][!x]=u,par[u]=v,par[v]=g,pull(u),pull(v);
    }
    void splay(int v){
        for(push(v);!is_root(v);rotate(v)){
            int u=par[v],r=is_root(u);
            if(!r)push(par[u]);
            push(u),push(v);
            if(!r)rotate(pos(u)==pos(v)?u:v);
        }
    }
    void access(int v){
        for(int u=v,c=0;u;c=u,u=par[u])
            splay(u),ch[u][1]=c,pull(u);
        splay(v);
    }
    void reroot(int v){access(v),toggle(v);}
    bool connected(int u,int v){
        reroot(u),access(v);return u==v||par[u];}
    void link(int u,int v){
        reroot(u),access(v);
        assert(u!=v&&!par[u]);par[u]=v;}
    void cut(int u,int v){
        reroot(u),access(v);
        assert(ch[v][0]==u&&!ch[u][0]&&!ch[u][1]);
        ch[v][0]=par[u]=0,pull(v);
    }
    T aggregate(int u,int v){
        reroot(u),access(v);return sum[v];}
    void add(int u,int v,T x){reroot(u),access(v),apply(v,x);}
    void set(int u,T v){reroot(u),val[u]=v,pull(u);}
};