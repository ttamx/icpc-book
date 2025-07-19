#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "src/contest/template.hpp"
#include "src/string/z-algorithm.hpp"

int main(){
    string s;
    cin >> s;
    for(auto x:z_algorithm(s))cout << x << " ";
}