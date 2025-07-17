#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "src/contest/template.hpp"
#include "src/data-structures/LineContainer.hpp"

int n,q;
LineContainer cht;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    for(int i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        cht.add(a,b);
    }
    while(q--){
        int op;
        cin >> op;
        if(op==0){
            ll a,b;
            cin >> a >> b;
            cht.add(a,b);
        }else{
            ll p;
            cin >> p;
            cout << cht.get(p) << "\n";
        }
    }
}