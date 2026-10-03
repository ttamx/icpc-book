#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "src/contest/template.hpp"
#include "src/number-theory/factorization.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--){
        u64 a;
        cin >> a;
        auto f=factor(a);
        cout << f.size();
        for(auto x:f)cout << " " << x;
        cout << "\n";
    }
}
