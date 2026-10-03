#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"
#include "src/contest/template.hpp"
#include "src/number-theory/montgomery-modint.hpp"
#include "src/linear-algebra/gauss-mod.hpp"

using mint = mint998;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    Mat<mint> a(n,vector<mint>(m));
    vector<mint> b(n),x;
    for(auto &r:a)for(auto &v:r)cin >> v;
    for(auto &v:b)cin >> v;
    Mat<mint> K;
    if(solve(a,b,m,x,K)<0){
        cout << "-1\n";
        return 0;
    }
    cout << SZ(K) << "\n";
    for(int i=0;i<m;i++)cout << x[i] << " \n"[i==m-1];
    for(auto &k:K)for(int i=0;i<m;i++)cout << k[i] << " \n"[i==m-1];
}
