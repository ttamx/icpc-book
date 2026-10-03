#pragma once

/**
 * Author: Teetat T.
 * Date: 2025-07-18
 * Description: Segment Tree Beats. Supports range chmin, range
 * chmax, range add and range sum on 0-indexed inclusive $[l,r]$.
 * Construct with SegmentTreeBeats(n,f) where f(i) gives a[i].
 * Time: amortized $O(\log^2 N)$ per operation (with range add).
 */

struct SegmentTreeBeats{
    struct Node{
        ll sum=0,add=0,mn=LINF,mn2=LINF,fn=0;
        ll mx=-LINF,mx2=-LINF,fx=0;
        Node(){}
        Node(ll v):sum(v),mn(v),fn(1),mx(v),fx(1){}
        friend Node operator+(const Node &l,const Node &r){
            Node s;s.sum=l.sum+r.sum;
            auto &a=l.mx<r.mx?r:l,&b=l.mx<r.mx?l:r;
            s.mx=a.mx,s.fx=a.fx+(a.mx==b.mx?b.fx:0);
            s.mx2=max(a.mx2,a.mx==b.mx?b.mx2:b.mx);
            auto &c=r.mn<l.mn?r:l,&d=r.mn<l.mn?l:r;
            s.mn=c.mn,s.fn=c.fn+(c.mn==d.mn?d.fn:0);
            s.mn2=min(c.mn2,c.mn==d.mn?d.mn2:d.mn);
            return s;
        }
        void apply(ll k,ll v){
            sum+=k*v,mx+=v,mx2+=v,mn+=v,mn2+=v,add+=v;
        }
        void chmin(ll v){
            if(v<mx)sum+=(v-mx)*fx,mn=mn==mx?v:mn,
                mn2=mn2==mx?v:mn2,mx=v;
        }
        void chmax(ll v){
            if(v>mn)sum+=(v-mn)*fn,mx=mx==mn?v:mx,
                mx2=mx2==mn?v:mx2,mn=v;
        }
    };
    int n;vector<Node> t;
    SegmentTreeBeats(){}
    SegmentTreeBeats(int n){init(n,[&](int){return 0;});}
    template<class F>
    SegmentTreeBeats(int n,const F &f){init(n,f);}
    template<class F>
    void init(int _n,const F &f){
        n=_n;int s=1;while(s<n*2)s<<=1;
        t.assign(s,Node());build(f);
    }
    template<class F>
    void build(int l,int r,int i,const F &f){
        if(l==r)return void(t[i]=f(l));
        int m=(l+r)/2;
        build(l,m,i*2,f),build(m+1,r,i*2+1,f),pull(i);
    }
    void pull(int i){t[i]=t[i*2]+t[i*2+1];}
    void push(int l,int r,int i){
        int m=(l+r)/2;Node &p=t[i],&a=t[i*2],&b=t[i*2+1];
        a.apply(m-l+1,p.add),a.chmin(p.mx),a.chmax(p.mn);
        b.apply(r-m,p.add),b.chmin(p.mx),b.chmax(p.mn);
        p.add=0;
    }
    void range_add(int l,int r,int i,int x,int y,ll v){
        if(y<l||r<x)return;
        if(x<=l&&r<=y)return t[i].apply(r-l+1,v);
        int m=(l+r)/2;push(l,r,i),range_add(l,m,i*2,x,y,v);
        range_add(m+1,r,i*2+1,x,y,v),pull(i);
    }
    void range_chmin(int l,int r,int i,int x,int y,ll v){
        if(y<l||r<x||t[i].mx<=v)return;
        if(x<=l&&r<=y&&t[i].mx2<v)return t[i].chmin(v);
        int m=(l+r)/2;push(l,r,i),range_chmin(l,m,i*2,x,y,v);
        range_chmin(m+1,r,i*2+1,x,y,v),pull(i);
    }
    void range_chmax(int l,int r,int i,int x,int y,ll v){
        if(y<l||r<x||t[i].mn>=v)return;
        if(x<=l&&r<=y&&t[i].mn2>v)return t[i].chmax(v);
        int m=(l+r)/2;push(l,r,i),range_chmax(l,m,i*2,x,y,v);
        range_chmax(m+1,r,i*2+1,x,y,v),pull(i);
    }
    ll query(int l,int r,int i,int x,int y){
        if(y<l||r<x)return 0;
        if(x<=l&&r<=y)return t[i].sum;
        int m=(l+r)/2;push(l,r,i);
        return query(l,m,i*2,x,y)+query(m+1,r,i*2+1,x,y);
    }
    template<class F>
    void build(const F &f){if(n)build(0,n-1,1,f);}
    void range_add(int x,int y,ll v){range_add(0,n-1,1,x,y,v);}
    void range_chmin(int x,int y,ll v){
        range_chmin(0,n-1,1,x,y,v);}
    void range_chmax(int x,int y,ll v){
        range_chmax(0,n-1,1,x,y,v);}
    ll query(int x,int y){return query(0,n-1,1,x,y);}
};
