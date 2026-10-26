#pragma once

/**
 * Author: Teetat T.
 * Description: Treap (1-indexed, 0 = null) with lazy reverse and
 * lazy add (T needs +, T*int, ==). Weight-0 nodes take a position but
 * no value. root/pos use parent pointers (not with P or pending rev).
 * N about $2\ln n$ per op if P.
 */

template<int N,class T,bool P=false>
struct Treap{
    struct Node{int l,r,p,sz,w,c;bool rev;T val,sum,lz;} t[N];
    int cnt=0;
    int make(T v,int w=1){
        t[++cnt]={0,0,0,1,w,w,0,v,w?v:T(),T()};return cnt;}
    int cp(int u){ // clone before writing (persistent only)
        if(!P||!u)return u;
        t[++cnt]=t[u];
        return cnt;
    }
    void pull(int u){
        auto &[l,r,p,sz,w,c,rev,val,sum,lz]=t[u];
        sz=t[l].sz+1+t[r].sz,c=t[l].c+w+t[r].c;
        sum=t[l].sum+t[r].sum;
        if(w)sum=sum+val;
        t[l].p=t[r].p=u;
    }
    void flip(int &u){
        if(!u)return;
        u=cp(u),swap(t[u].l,t[u].r),t[u].rev^=1;
    }
    void apply(int &u,T x){ // add x to every value in u
        if(!u)return;
        u=cp(u);
        auto &a=t[u];
        a.val=a.val+x,a.sum=a.sum+x*a.c,a.lz=a.lz+x;
    }
    void push(int u){
        if(t[u].rev)flip(t[u].l),flip(t[u].r),t[u].rev=0;
        T &x=t[u].lz;
        if(!(x==T()))apply(t[u].l,x),apply(t[u].r,x),x=T();
    }
    pair<int,int> split(int u,int k){ // first k elements, rest
        if(!u)return {0,0};
        u=cp(u),push(u);
        if(t[t[u].l].sz>=k){
            auto [a,b]=split(t[u].l,k);
            t[u].l=b,pull(u),t[u].p=0;
            return {a,u};
        }
        auto [a,b]=split(t[u].r,k-t[t[u].l].sz-1);
        t[u].r=a,pull(u),t[u].p=0;
        return {u,b};
    }
    int merge(int a,int b){
        if(!a||!b)return t[a^b].p=0,a^b;
        if(int(rng()%(t[a].sz+t[b].sz))<t[a].sz){
            a=cp(a),push(a);
            t[a].r=merge(t[a].r,b),pull(a),t[a].p=0;
            return a;
        }
        b=cp(b),push(b);
        t[b].l=merge(a,t[b].l),pull(b),t[b].p=0;
        return b;
    }
    int root(int u){while(t[u].p)u=t[u].p;return u;}
    int pos(int u){ // index of node u in its sequence
        int k=t[t[u].l].sz;
        for(;t[u].p;u=t[u].p)
            if(t[t[u].p].r==u)k+=t[t[t[u].p].l].sz+1;
        return k;
    } // (0-indexed)
};
