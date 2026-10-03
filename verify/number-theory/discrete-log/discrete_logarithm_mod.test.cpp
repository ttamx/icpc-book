#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include "src/contest/template.hpp"
#include "src/number-theory/discrete-log.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ll x,y,m;
        cin >> x >> y >> m;
        cout << discrete_log(x,y,m) << "\n";
    }
}
