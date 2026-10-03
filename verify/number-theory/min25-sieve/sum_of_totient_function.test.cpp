#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"
#include "src/contest/template.hpp"
#include "src/number-theory/montgomery-modint.hpp"
#include "src/number-theory/min25-sieve.hpp"

using mint = mint998;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n;
    cin >> n;
    Lucy<mint> c(n,[](ll v){return mint(v-1);});
    Lucy<mint> s(n,[](ll v){return mint(v)*(v+1)/2-1;});
    auto g=[&](ll v){return s(v)-c(v);};
    auto fpe=[](ll p,int e){mint r=p-1;while(--e)r*=p;return r;};
    cout << min25<mint>(n,g,fpe) << "\n";
}
