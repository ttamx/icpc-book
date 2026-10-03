#pragma once

/**
 * Author: Teetat T.
 * Date: 2025-07-19
 * Description: Aho-Corasick on a node pool (root = 1, 0 = sentinel).
 * insert() returns the end node of a pattern. After build(), ch is the
 * full automaton and val[u] = sum of val over all patterns that are
 * suffixes of u. Instance must be global; N > total pattern length.
 * Time: $O(A \cdot N)$ build
 */

template<int N,class T,int A=26>
struct AhoCorasick{
    int ch[N][A],fail[N],cnt=1;
    T val[N];
    int insert(const string &s,T v){
        int u=1;
        for(char x:s){
            int &w=ch[u][x-'a'];
            if(!w)w=++cnt;
            u=w;
        }
        val[u]+=v;
        return u;
    }
    void build(){
        fill(ch[0],ch[0]+A,1); // sentinel: every edge to root
        vector<int> q{1};
        for(int i=0;i<SZ(q);i++){
            int u=q[i];
            for(int c=0;c<A;c++){
                int &v=ch[u][c];
                if(!v)v=ch[fail[u]][c];
                else{
                    fail[v]=ch[fail[u]][c];
                    val[v]+=val[fail[v]],q.pb(v);
                }
            }
        }
    }
};
