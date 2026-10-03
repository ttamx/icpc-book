#pragma once

/**
 * Author: Teetat T.
 * Description: Implicit treap on a node pool (1-indexed, 0 = null),
 * with range sum and lazy range reverse. Merge picks the root with
 * probability proportional to size, so no priorities are stored and
 * subtrees can be shared: with P=true every write clones the node
 * first (persistent treap, old roots stay valid). The instance must be
 * global; N must cover all clones (about $2\ln n$ per op if P).
 * Usage:
 *  Treap<N,ll> T; int root=0; // or Treap<N,ll,true> (persistent)
 *  root=T.merge(root,T.make(x)); // push back x
 *  auto [a,b]=T.split(root,k); // a = first k elements
 *  root=T.reverse(root,l,r); ll s=T.query(root,l,r); // [l,r)
 * Time: $O(\log N)$ expected per operation
 */

template<int N,class T,bool P=false>
struct Treap{
    struct Node{int l,r,sz;bool rev;T val,sum;} t[N];
    int cnt=0;
    int make(T v){t[++cnt]={0,0,1,0,v,v};return cnt;}
    int cp(int u){ // clone before writing (persistent only)
        if(!P||!u)return u;
        t[++cnt]=t[u];
        return cnt;
    }
    void pull(int u){
        auto &[l,r,sz,rev,val,sum]=t[u];
        sz=t[l].sz+1+t[r].sz;
        sum=t[l].sum+val+t[r].sum;
    }
    void flip(int &u){
        if(!u)return;
        u=cp(u),swap(t[u].l,t[u].r),t[u].rev^=1;
    }
    void push(int u){
        if(t[u].rev)flip(t[u].l),flip(t[u].r),t[u].rev=0;
    }
    // first k elements | rest
    pair<int,int> split(int u,int k){
        if(!u)return {0,0};
        u=cp(u),push(u);
        if(t[t[u].l].sz>=k){
            auto [a,b]=split(t[u].l,k);
            t[u].l=b,pull(u);
            return {a,u};
        }
        auto [a,b]=split(t[u].r,k-t[t[u].l].sz-1);
        t[u].r=a,pull(u);
        return {u,b};
    }
    int merge(int a,int b){
        if(!a||!b)return a^b;
        if(int(rng()%(t[a].sz+t[b].sz))<t[a].sz){
            a=cp(a),push(a);
            t[a].r=merge(t[a].r,b),pull(a);
            return a;
        }
        b=cp(b),push(b);
        t[b].l=merge(a,t[b].l),pull(b);
        return b;
    }
};
