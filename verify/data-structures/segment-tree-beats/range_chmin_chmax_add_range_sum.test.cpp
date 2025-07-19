#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "src/contest/template.hpp"
#include "src/data-structures/segment-tree-beats.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<ll> a(n);
    for(auto &x:a)cin >> x;
    SegmentTreeBeats seg(n,[&](int i){return a[i];});
    while(q--){
        int op,l,r;
        cin >> op >> l >> r;
        r--;
        if(op==3){
            cout << seg.query(l,r) << "\n";
        }else{
            ll v;
            cin >> v;
            if(op==0){
                seg.range_chmin(l,r,v);
            }else if(op==1){
                seg.range_chmax(l,r,v);
            }else{
                seg.range_add(l,r,v);
            }
        }
    }
}