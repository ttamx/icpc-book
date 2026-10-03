#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"
#include "src/contest/template.hpp"
#include "src/polynomials/multipoint-evaluation.hpp"

using mint = mint998;
using FPS = FormalPowerSeries<mint>;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    FPS f(n);
    vector<mint> xs(m);
    for(auto &x:f)cin >> x;
    for(auto &x:xs)cin >> x;
    auto res=multipoint_evaluation(f,xs);
    for(int i=0;i<m;i++)cout << res[i] << " \n"[i==m-1];
}
