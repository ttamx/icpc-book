#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include "src/contest/template.hpp"
#include "src/number-theory/mod-sqrt.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ll y,p;
        cin >> y >> p;
        cout << mod_sqrt(y,p) << "\n";
    }
}
