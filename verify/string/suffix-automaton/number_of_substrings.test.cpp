#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include "src/contest/template.hpp"
#include "src/string/suffix-automaton.hpp"

int main(){
    string s;
    cin >> s;
    SuffixAutomaton sa(s);
    cout << sa.distinct_substrings();
}