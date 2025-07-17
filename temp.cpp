#line 1 "verify/data-structures/line-container/line_add_get_min.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#line 2 "src/contest/template.hpp"
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
using ll = long long;
using db = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<db,db>;
const int INF=0x3fffffff;
const ll LINF=0x1fffffffffffffff;
const db DINF=numeric_limits<db>::infinity();
const db EPS=1e-9;
const db PI=acos(db(-1));
 
template<class T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
#line 3 "src/data-structures/LineContainer.hpp"

/**
 * Author: Teetat T.
 * Description: Line Container (Minimize).
 * Time: O(\log N)
 */

struct Line{
	static bool querymode;
    ll m,c;
    mutable ll p;
    Line(ll m,ll c):m(m),c(c),p(0){}
    Line(ll p):m(0),c(0),p(p){}
    bool operator<(const Line &o)const{
        return querymode?p<o.p:m>o.m;
    }
};

bool Line::querymode=false;

struct LineContainer:multiset<Line>{
    ll div(ll a,ll b){
        return a/b-((a^b)<0&&a%b);
    }
    bool isect(iterator x,iterator y){
        if(y==end())return x->p=LINF,false;
        if(x->m==y->m)x->p=x->c<=y->c?LINF:-LINF;
        else x->p=div(x->c-y->c,y->m-x->m);
        return x->p>=y->p;
    }
    void add(ll m,ll c){
        auto x=insert(Line(m,c)),y=next(x);
        while(isect(x,y))y=erase(y);
        if((y=x)!=begin()&&isect(--x,y))isect(x,erase(y));
        while((y=x)!=begin()&&(--x)->p>=y->p)isect(x,erase(y));
    }
    ll get(ll x){
        if(empty())return LINF;
        Line::querymode=true;
        auto l=lower_bound(Line(x));
        Line::querymode=false;
        return l->m*x+l->c;
    }
};
#line 4 "verify/data-structures/line-container/line_add_get_min.test.cpp"

int n,q;
LineContainer cht;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    for(int i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        cht.add(a,b);
    }
    while(q--){
        int op;
        cin >> op;
        if(op==0){
            ll a,b;
            cin >> a >> b;
            cht.add(a,b);
        }else{
            ll p;
            cin >> p;
            cout << cht.get(p) << "\n";
        }
    }
}
