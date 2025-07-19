#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "src/contest/template.hpp"
#include "src/miscellaneous/integrate.hpp"

int main(){
    for(int r=1;r<=20;r++){
        double out=quad(-r,r,[&](db x){
            return quad(-r,r,[&](db y){
                return quad(-r,r,[&](db z){
                    return x*x+y*y+z*z<r*r;
                },100);
            },100);
        },100);
        double ans=4*PI*r*r*r/3;
        auto err=abs(out-ans)/max(ans,1.0);
        assert(err<1e-4);
    }
    int a,b;
    cin >> a >> b;
    cout << a+b << "\n";
}
