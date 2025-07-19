#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "template.hpp"
#include "src/string/manacher.hpp"

int main(){
    string s;
    cin >> s;
    for(auto x:manacher(s))cout << x << " ";
}