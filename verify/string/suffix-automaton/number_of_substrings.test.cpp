#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include "src/contest/template.hpp"
#include "src/string/suffix-automaton.hpp"

SuffixAutomaton<1000005> sa;

int main(){
    string s;
    cin >> s;
    for(char c:s)sa.extend(c-'a');
    cout << sa.distinct_substrings();
}