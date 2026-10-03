#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include "src/contest/template.hpp"
#include "src/number-theory/montgomery-modint.hpp"
#include "src/linear-algebra/gauss-mod.hpp"

using mint = mint998;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    Mat<mint> a(n,vector<mint>(n));
    for(auto &r:a)for(auto &v:r)cin >> v;
    cout << mat_det(a) << "\n";
}
