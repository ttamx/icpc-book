#pragma once

/**
 * Author: Teetat T.
 * Date: 2024-06-14
 * Description: Suffix Automaton on a node pool (root = 1, 0 = null).
 * Call extend(c) with c in [0,A) for each character. Instance must be
 * global; N > 2|s|. For a large alphabet use map<int,int> nxt[N].
 * Time: $O(|s| \cdot A)$
 */

template<int N,int A=26>
struct SuffixAutomaton{
    int nxt[N][A],link[N],len[N],occ[N],cnt=1,last=1;
    void extend(int c){
        int cur=++cnt,p=last;
        len[cur]=len[last]+1,occ[cur]=1;
        for(;p&&!nxt[p][c];p=link[p])nxt[p][c]=cur;
        if(!p)link[cur]=1;
        else if(int q=nxt[p][c];len[p]+1==len[q])link[cur]=q;
        else{
            int r=++cnt;
            len[r]=len[p]+1,link[r]=link[q];
            copy(nxt[q],nxt[q]+A,nxt[r]);
            for(;p&&nxt[p][c]==q;p=link[p])nxt[p][c]=r;
            link[q]=link[cur]=r;
        }
        last=cur;
    }
    // ---- usages ----
    // # distinct non-empty substrings
    ll distinct_substrings(){
        ll res=0;
        for(int i=2;i<=cnt;i++)res+=len[i]-len[link[i]];
        return res;
    }
    // states sorted by len (shortest first), counting sort;
    // link[u] is shorter than u, nxt[u][c] is longer
    vector<int> order(){
        vector<int> c(len[last]+1),o(cnt);
        for(int i=1;i<=cnt;i++)c[len[i]]++;
        for(int i=1;i<SZ(c);i++)c[i]+=c[i-1];
        for(int i=cnt;i>=1;i--)o[--c[len[i]]]=i;
        return o;
    }
    // occ[u] = # occurrences (endpos size) of u's strings,
    // call once after building
    void calc_occ(){
        auto o=order();
        for(int i=cnt-1;i>0;i--)occ[link[o[i]]]+=occ[o[i]];
    }
    // # occurrences of non-empty t in s (needs calc_occ)
    int count(const string &t){
        int u=1;
        for(char x:t)if(!(u=nxt[u][x-'a']))return 0;
        return occ[u];
    }
    // longest common substring of s and t
    int lcs(const string &t){
        int u=1,l=0,res=0;
        for(char x:t){
            int c=x-'a';
            while(u>1&&!nxt[u][c])u=link[u],l=len[u];
            if(nxt[u][c])u=nxt[u][c],l++;
            res=max(res,l);
        }
        return res;
    }
    // k-th (1-indexed) lexicographically smallest distinct
    // substring, needs 1 <= k <= distinct_substrings()
    string kth(ll k){
        auto o=order();
        vector<ll> dp(cnt+1,1); // # paths from u (incl. empty)
        for(int i=cnt-1;i>=0;i--)for(int c=0;c<A;c++)
            if(int v=nxt[o[i]][c])dp[o[i]]+=dp[v];
        string res;
        for(int u=1;k>0;){
            for(int c=0;c<A;c++)if(int v=nxt[u][c]){
                if(dp[v]>=k){res+=char('a'+c),u=v,k--;break;}
                k-=dp[v];
            }
        }
        return res;
    }
};
