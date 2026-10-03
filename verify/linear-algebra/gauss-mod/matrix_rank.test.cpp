#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"
#include "src/contest/template.hpp"
#include "src/number-theory/montgomery-modint.hpp"
#include "src/linear-algebra/gauss-mod.hpp"

using mint = mint998;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    Mat<mint> a(n,vector<mint>(m));
    for(auto &r:a)for(auto &v:r)cin >> v;
    cout << mat_rank(a,m) << "\n";
}
