#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "src/contest/template.hpp"
#include "src/string/suffix-array.hpp"

int main(){
    string s;
    cin >> s;
    SuffixArray sa(s);
    for(int i=1;i<=s.size();++i)cout << sa.sa[i] << " ";
}