#pragma once

/**
 * Author: Teetat T.
 * Description: Link Cut Tree (1-indexed)
 */

template<int N,class T>
struct LinkCutTree{
    int ch[N][2],par[N],lz[N],rev[N];
    T val[N],sum[N],rsum[N];
    void toggle(int v){
        if(!v)return;
        swap(ch[v][0],ch[v][1]);
        swap(sum[v],rsum[v]);
        rev[v]^=1;
    }
    void push(int v){
        if(!v||!rev[v])return;
        toggle(ch[v][0]);
        toggle(ch[v][1]);
        rev[v]=0;
    }
    void pull(int v){
        if(!v)return;
        sum[v]=sum[ch[v][0]]+val[v]+sum[ch[v][1]];
        rsum[v]=rsum[ch[v][0]]+val[v]+rsum[ch[v][1]];
    }
    bool is_root(int v){
        return ch[par[v]][0]!=v&&ch[par[v]][1]!=v;
    }
    bool pos(int v){
        return ch[par[v]][1]==v;
    }
    void rotate(int v){
        int u=par[v],g=par[u];
        bool x=pos(v);
        if(!is_root(u))ch[g][pos(u)]=v;
        ch[u][x]=ch[v][!x];
        if(ch[u][x])par[ch[u][x]]=u;
        ch[v][!x]=u,par[u]=v,par[v]=g;
        pull(u),pull(v);
    }
    void splay(int v){
        if(!v)return;
        for(push(v);!is_root(v);rotate(v)){
            int u=par[v];
            if(is_root(u))push(u),push(v);
            else push(par[u]),push(u),push(v),rotate(pos(u)==pos(v)?u:v);
        }
    }
    void access(int v){
        for(int u=v,c=0;u;u=par[u]){
            splay(u);
            ch[u][1]=c;
            pull(c=u);
        }
        splay(v);
    }
    void evert(int v){
        access(v),toggle(v);
    }
    void link(int u,int v){
        evert(u);
        access(v);
        par[u]=v;
    }
    void cut(int u,int v){
        evert(u);
        access(v);
        assert(par[u]==v);
        ch[v][0]=par[u]=0;
        pull(v);
    }
    T aggregate(int u,int v){
        evert(u);
        access(v);
        return sum[v];
    }
    void set(int u,T v){
        evert(u);
        val[u]=v;
        pull(u);
    }
};