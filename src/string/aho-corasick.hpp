#pragma once

/**
 * Author: Teetat T.
 * Date: 2025-07-19
 * Description: Aho-Corasick.
 */

template<class T>
struct AhoCorasick{
    struct Node{
        array<int,26> ch;
        int fail;
        T val;
        Node(){
            fill(ch.begin(),ch.end(),-1);
            fail=-1;
            val=0;
        }
    };
    vector<Node> nodes;
    AhoCorasick(){new_node();}
    int new_node(){
        nodes.emplace_back(Node());
        return nodes.size()-1;
    }
    void insert(const string &s,const T &val){
        int u=0;
        for(auto x:s){
            int c=x-'a';
            if(nodes[u].ch[c]==-1)nodes[u].ch[c]=new_node();
            u=nodes[u].ch[c];
        }
        nodes[u].val+=val;
    }
    void build(){
        vector<int> q{0};
        for(int i=0;i<q.size();i++){
            int u=q[i];
            int v;
            for(int c=0;c<26;c++){
                if((v=nodes[u].ch[c])!=-1){
                    int p=nodes[u].fail;
                    while(p!=-1&&nodes[p].ch[c]==-1)p=nodes[p].fail;
                    p=p!=-1?nodes[p].ch[c]:0;
                    nodes[v].fail=p;
                    nodes[v].val+=nodes[p].val;
                    q.emplace_back(v);
                }
            }
        }
        for(auto u:q){
            for(int c=0;c<26;c++){
                if(nodes[u].ch[c]==-1){
                    int p=nodes[u].fail;
                    while(p!=-1&&nodes[p].ch[c]==-1)p=nodes[p].fail;
                    nodes[u].ch[c]=p!=-1?nodes[p].ch[c]:0;
                }
            }
        }
    }
};