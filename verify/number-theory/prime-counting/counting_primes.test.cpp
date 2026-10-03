#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"
#include "src/contest/template.hpp"
#include "src/number-theory/prime-counting.hpp"

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n;
    cin >> n;
    Lucy<ll> pi(n,[](ll v){return v-1;});
    cout << pi(n) << "\n";
}
