#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"
#include "src/contest/template.hpp"
#include "src/polynomials/taylor-shift.hpp"

using mint = mint998;
using FPS = FormalPowerSeries<mint>;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    mint c;
    cin >> n >> c;
    FPS f(n);
    for(auto &x:f)cin >> x;
    auto g=taylor_shift(f,c);
    for(int i=0;i<n;i++)cout << g[i] << " \n"[i==n-1];
}
