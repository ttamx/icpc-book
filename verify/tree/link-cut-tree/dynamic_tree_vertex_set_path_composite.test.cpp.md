---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':heavy_check_mark:'
    path: src/number-theory/modint.hpp
    title: src/number-theory/modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/tree/link-cut-tree.hpp
    title: src/tree/link-cut-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
  bundledCode: "#line 1 \"verify/tree/link-cut-tree/dynamic_tree_vertex_set_path_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n#line 2 \"src/contest/template.hpp\"\n#include<bits/stdc++.h>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n \nusing namespace std;\nusing namespace\
    \ __gnu_pbds;\n\n#define pb push_back\n#define eb emplace_back\n\n#define ALL(a)\
    \ a.begin(),a.end()\n#define RALL(a) a.rbegin(),a.rend()\n#define SORT(a) sort(ALL(a))\n\
    #define RSORT(a) sort(RALL(a))\n#define REV(a) reverse(ALL(a))\n#define UNI(a)\
    \ a.erase(unique(ALL(a)),a.end())\n#define SZ(a) (int)(a.size())\n#define LB(a,x)\
    \ (int)(lower_bound(ALL(a),x)-a.begin())\n#define UB(a,x) (int)(upper_bound(ALL(a),x)-a.begin())\n\
    #define MIN(a) *min_element(ALL(a))\n#define MAX(a) *max_element(ALL(a))\n\nusing\
    \ ll = long long;\nusing db = long double;\nusing i128 = __int128_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\n\nconst int INF=INT_MAX/2;\nconst ll LINF=LLONG_MAX/4;\n\
    const db DINF=numeric_limits<db>::infinity();\nconst int MOD=998244353;\nconst\
    \ int MOD2=1000000007;\nconst db EPS=1e-9;\nconst db PI=acos(db(-1));\n\ntemplate<class\
    \ T>\nusing PQ = priority_queue<T,vector<T>,greater<T>>;\n\ntemplate<class T,class\
    \ U>\nbool chmin(T &a,U b){return b<a?a=b,1:0;}\ntemplate<class T,class U>\nbool\
    \ chmax(T &a,U b){return a<b?a=b,1:0;}\ntemplate<class T,class U>\nT SUM(const\
    \ U &a){return accumulate(ALL(a),T{});}\n\ntemplate<class T>\nusing ordered_set\
    \ = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;\n\
    \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\nmt19937_64\
    \ rng64(chrono::steady_clock::now().time_since_epoch().count());\n#line 2 \"src/number-theory/modint.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2026-04-15\n * Description: modular arithmetic\
    \ operations\n */\n\ntemplate<int mod,int root=0>\nstruct ModInt{\n    using mint\
    \ = ModInt;\n    \n\tstatic_assert(mod>0,\"mod must be positive\");\n\n    int\
    \ x;\n\n    constexpr ModInt():x(0){}\n    constexpr ModInt(ll x):x((x%=mod)<0?x+mod:x){}\n\
    \    constexpr explicit operator int()const{return x;}\n    constexpr int val()const{return\
    \ x;}\n    constexpr static int get_mod(){return mod;}\n    constexpr static mint\
    \ get_root(){return mint(root);}\n    \n    constexpr mint operator-()const{\n\
    \        mint res;\n        res.x=x?mod-x:0;\n        return res;\n    }\n   \
    \ constexpr mint operator+()const{return *this;}\n\n    constexpr mint inv()const{\n\
    \        int a=x,b=mod,u=1,v=0,q=0;\n        while(b>0){\n            q=a/b;\n\
    \            swap(a-=q*b,b);\n            swap(u-=q*v,v);\n        }\n       \
    \ return mint(u);\n    }\n    constexpr mint pow(ll n)const{\n        mint res=1,a=*this;\n\
    \        for(;n>0;a*=a,n>>=1)if(n&1)res*=a;\n        return res;\n    }\n    constexpr\
    \ mint &operator+=(const mint &o){\n        if((x+=o.x)>=mod)x-=mod;\n       \
    \ return *this;\n    }\n    constexpr mint &operator-=(const mint &o){\n     \
    \   if((x-=o.x)<0)x+=mod;\n        return *this;\n    }\n    constexpr mint &operator*=(const\
    \ mint &o){\n        x=(ll(x)*o.x)%mod;\n        return *this;\n    }\n    constexpr\
    \ mint &operator/=(const mint &o){\n        return *this*=o.inv();\n    }\n\n\
    \    constexpr mint operator+(const mint &o)const{return mint(*this)+=o;}\n  \
    \  constexpr mint operator-(const mint &o)const{return mint(*this)-=o;}\n    constexpr\
    \ mint operator*(const mint &o)const{return mint(*this)*=o;}\n    constexpr mint\
    \ operator/(const mint &o)const{return mint(*this)/=o;}\n\n    constexpr mint\
    \ &operator++(){return *this+=mint(1);}\n    constexpr mint &operator--(){return\
    \ *this-=mint(1);}\n    constexpr mint operator++(int){mint res=*this;*this+=mint(1);return\
    \ res;}\n    constexpr mint operator--(int){mint res=*this;*this-=mint(1);return\
    \ res;}\n    \n    constexpr bool operator==(const mint &o)const{return x==o.x;}\n\
    \    constexpr bool operator!=(const mint &o)const{return x!=o.x;}\n    constexpr\
    \ bool operator<(const mint &o)const{return x<o.x;}\n    \n    friend istream\
    \ &operator>>(istream &is,mint &o){ll x{};is>>x;o=mint(x);return is;}\n    friend\
    \ ostream &operator<<(ostream &os,const mint &o){return os<<o.x;}\n};\nusing mint998\
    \ = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;\n#line 2 \"src/tree/link-cut-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Description: Link Cut Tree (1-indexed)\n */\n\
    \ntemplate<int N,class T>\nstruct LinkCutTree{\n    int ch[N][2],par[N],rev[N];\n\
    \    T val[N],sum[N],rsum[N],lz[N];\n    void toggle(int v){\n        if(!v)return;\n\
    \        swap(ch[v][0],ch[v][1]),swap(sum[v],rsum[v]),rev[v]^=1;\n    }\n    void\
    \ apply(int v,T x){\n        if(!v)return;\n        val[v]=val[v]+x,lz[v]=lz[v]+x;\n\
    \        sum[v]=sum[v]+x,rsum[v]=rsum[v]+x;\n    }\n    void push(int v){\n  \
    \      if(rev[v])toggle(ch[v][0]),toggle(ch[v][1]),rev[v]=0;\n        apply(ch[v][0],lz[v]),apply(ch[v][1],lz[v]),lz[v]=T();\n\
    \    }\n    void pull(int v){\n        sum[v]=sum[ch[v][0]]+val[v]+sum[ch[v][1]];\n\
    \        rsum[v]=rsum[ch[v][1]]+val[v]+rsum[ch[v][0]];\n    }\n    bool pos(int\
    \ v){return ch[par[v]][1]==v;}\n    bool is_root(int v){return ch[par[v]][pos(v)]!=v;}\n\
    \    void rotate(int v){\n        int u=par[v],g=par[u],x=pos(v);\n        if(!is_root(u))ch[g][pos(u)]=v;\n\
    \        if((ch[u][x]=ch[v][!x]))par[ch[u][x]]=u;\n        ch[v][!x]=u,par[u]=v,par[v]=g,pull(u),pull(v);\n\
    \    }\n    void splay(int v){\n        for(push(v);!is_root(v);rotate(v)){\n\
    \            int u=par[v],r=is_root(u);\n            if(!r)push(par[u]);\n   \
    \         push(u),push(v);\n            if(!r)rotate(pos(u)==pos(v)?u:v);\n  \
    \      }\n    }\n    void access(int v){\n        for(int u=v,c=0;u;c=u,u=par[u])\n\
    \            splay(u),ch[u][1]=c,pull(u);\n        splay(v);\n    }\n    void\
    \ reroot(int v){access(v),toggle(v);}\n    bool connected(int u,int v){\n    \
    \    reroot(u),access(v);return u==v||par[u];}\n    void link(int u,int v){\n\
    \        reroot(u),access(v);\n        assert(u!=v&&!par[u]);par[u]=v;}\n    void\
    \ cut(int u,int v){\n        reroot(u),access(v);\n        assert(ch[v][0]==u&&!ch[u][0]&&!ch[u][1]);\n\
    \        ch[v][0]=par[u]=0,pull(v);\n    }\n    T aggregate(int u,int v){\n  \
    \      reroot(u),access(v);return sum[v];}\n    void add(int u,int v,T x){reroot(u),access(v),apply(v,x);}\n\
    \    void set(int u,T v){reroot(u),val[u]=v,pull(u);}\n};\n#line 5 \"verify/tree/link-cut-tree/dynamic_tree_vertex_set_path_composite.test.cpp\"\
    \n\nusing mint = mint998;\n\nstruct F{\n    mint a=1,b=0;\n    F operator+(const\
    \ F &o)const{return {a*o.a,b*o.a+o.b};}\n};\n\nconst int N=2e5+5;\nLinkCutTree<N,F>\
    \ lct;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int\
    \ n,q;\n    cin >> n >> q;\n    for(int i=1;i<=n;i++){\n        F f;\n       \
    \ cin >> f.a >> f.b;\n        lct.set(i,f);\n    }\n    for(int i=0;i<n-1;i++){\n\
    \        int u,v;\n        cin >> u >> v;\n        lct.link(u+1,v+1);\n    }\n\
    \    while(q--){\n        int t;\n        cin >> t;\n        if(t==0){\n     \
    \       int u,v,w,x;\n            cin >> u >> v >> w >> x;\n            lct.cut(u+1,v+1),lct.link(w+1,x+1);\n\
    \        }else if(t==1){\n            int p;\n            F f;\n            cin\
    \ >> p >> f.a >> f.b;\n            lct.set(p+1,f);\n        }else{\n         \
    \   int u,v;\n            mint x;\n            cin >> u >> v >> x;\n         \
    \   F f=lct.aggregate(u+1,v+1);\n            cout << f.a*x+f.b << \"\\n\";\n \
    \       }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n#include \"src/contest/template.hpp\"\n#include \"src/number-theory/modint.hpp\"\
    \n#include \"src/tree/link-cut-tree.hpp\"\n\nusing mint = mint998;\n\nstruct F{\n\
    \    mint a=1,b=0;\n    F operator+(const F &o)const{return {a*o.a,b*o.a+o.b};}\n\
    };\n\nconst int N=2e5+5;\nLinkCutTree<N,F> lct;\n\nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n\
    \    int n,q;\n    cin >> n >> q;\n    for(int i=1;i<=n;i++){\n        F f;\n\
    \        cin >> f.a >> f.b;\n        lct.set(i,f);\n    }\n    for(int i=0;i<n-1;i++){\n\
    \        int u,v;\n        cin >> u >> v;\n        lct.link(u+1,v+1);\n    }\n\
    \    while(q--){\n        int t;\n        cin >> t;\n        if(t==0){\n     \
    \       int u,v,w,x;\n            cin >> u >> v >> w >> x;\n            lct.cut(u+1,v+1),lct.link(w+1,x+1);\n\
    \        }else if(t==1){\n            int p;\n            F f;\n            cin\
    \ >> p >> f.a >> f.b;\n            lct.set(p+1,f);\n        }else{\n         \
    \   int u,v;\n            mint x;\n            cin >> u >> v >> x;\n         \
    \   F f=lct.aggregate(u+1,v+1);\n            cout << f.a*x+f.b << \"\\n\";\n \
    \       }\n    }\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/number-theory/modint.hpp
  - src/tree/link-cut-tree.hpp
  isVerificationFile: true
  path: verify/tree/link-cut-tree/dynamic_tree_vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 16:18:54+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/tree/link-cut-tree/dynamic_tree_vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/tree/link-cut-tree/dynamic_tree_vertex_set_path_composite.test.cpp
- /verify/verify/tree/link-cut-tree/dynamic_tree_vertex_set_path_composite.test.cpp.html
title: verify/tree/link-cut-tree/dynamic_tree_vertex_set_path_composite.test.cpp
---
