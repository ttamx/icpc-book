#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"
#include "src/contest/template.hpp"
#include "src/polynomials/polynomial-interpolation.hpp"

using mint = mint998;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<mint> xs(n),ys(n);
    for(auto &x:xs)cin >> x;
    for(auto &y:ys)cin >> y;
    auto f=polynomial_interpolation(xs,ys);
    for(int i=0;i<n;i++)cout << f[i] << " \n"[i==n-1];
}
