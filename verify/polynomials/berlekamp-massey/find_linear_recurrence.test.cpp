#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"
#include "src/contest/template.hpp"
#include "src/polynomials/berlekamp-massey.hpp"
#include "src/number-theory/montgomery-modint.hpp"

using mint = mint998;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<mint> a(n);
    for(auto &x:a)cin >> x;
    auto c=berlekamp_massey(a);
    int d=c.size();
    cout << d << "\n";
    for(int i=0;i<d;i++)cout << c[i] << " \n"[i==d-1];
}
