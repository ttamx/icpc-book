---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/contest/template.hpp
    title: src/contest/template.hpp
  - icon: ':question:'
    path: src/number-theory/modint.hpp
    title: src/number-theory/modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/tree/static-top-tree.hpp
    title: src/tree/static-top-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum
  bundledCode: "#line 1 \"verify/tree/static-top-tree/point_set_tree_path_composite_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum\"\
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
    \ = ModInt<998244353,3>;\nusing mint107 = ModInt<1000000007>;\n#line 3 \"src/tree/static-top-tree.hpp\"\
    \n\n/**\n * Author: Teetat T.\n * Date: 2024-11-14\n * Description: Static top\
    \ tree of a tree with vertices $1..n$ (adj has size $n+1$, root $1$).\n * Node\
    \ pool is 1-indexed, 0 = null, at most $2n-1$ nodes; vertex $v$ is its own Vertex/AddVertex\
    \ node.\n * Balanced by subtree size, height $O(\\log n)$.\n * StaticTopTreeRerootingDP\
    \ takes a DP struct D (interface in the code).\n * After changing the data of\
    \ $v$, call update($v$).\n * Time: build $O(n \\log n)$, update / query\\_subtree\
    \ / query\\_reroot $O(\\log n)$, query\\_all $O(1)$\n */\n\nstruct StaticTopTree{\n\
    \    using P = pair<int,int>;\n    using G = vector<vector<int>>;\n    enum Type{Compress,Rake,AddVertex,Vertex};\n\
    \    int n,cnt,root;\n    G &adj;\n    vector<int> hv,fa,l,r,par,t;\n    StaticTopTree(G\
    \ &g):adj(g){ // 1-indexed\n        n=cnt=SZ(g)-1;\n        hv=fa=l=r=par=t=vector<int>(2*n+1);\n\
    \        vector<int> o{1},s(n+1,1);s[0]=0; // BFS order, sizes\n        for(int\
    \ i=0;i<SZ(o);i++){\n            int u=o[i];\n            for(int v:adj[u])if(v!=fa[u])fa[v]=u,o.pb(v);\n\
    \        }\n        for(int i=n-1;i>0;i--){\n            int u=o[i],p=fa[u];s[p]+=s[u];\n\
    \            if(s[u]>s[hv[p]])hv[p]=u;\n        }\n        root=compress(1).first;\n\
    \    }\n    int add(int i,int a,int b,Type ty){\n        if(!i)i=++cnt;\n    \
    \    l[i]=a,r[i]=b,t[i]=ty,par[a]=par[b]=i;\n        return i;\n    }\n    P merge(const\
    \ vector<P> &a,int x,int y,Type ty){\n        if(y-x==1)return a[x];\n       \
    \ int tot=0,m=x;\n        for(int k=x;k<y;k++)tot+=a[k].second;\n        while(tot>a[m].second)tot-=2*a[m++].second;\n\
    \        auto [i,si]=merge(a,x,m,ty);\n        auto [j,sj]=merge(a,m,y,ty);\n\
    \        return {add(0,i,j,ty),si+sj};\n    }\n    P compress(int i){\n      \
    \  vector<P> a{add_vertex(i)};\n        while(hv[i])a.eb(add_vertex(i=hv[i]));\n\
    \        return merge(a,0,SZ(a),Compress);\n    }\n    P rake(int i){\n      \
    \  vector<P> a;\n        for(int j:adj[i])\n            if(j!=fa[i]&&j!=hv[i])a.eb(compress(j));\n\
    \        return a.empty()?P(0,0):merge(a,0,SZ(a),Rake);\n    }\n    P add_vertex(int\
    \ i){\n        auto [j,s]=rake(i);\n        return {add(i,j,0,j?AddVertex:Vertex),s+1};\n\
    \    }\n};\n/* struct D{\n    struct Path{static Path unit();};\n    struct Point{static\
    \ Point unit();};\n    static Path vertex(int v),add_vertex(Point p,int v),\n\
    \        compress(Path up,Path down);\n    static Point add_edge(Path p),rake(Point\
    \ a,Point b);\n}; */\ntemplate<class D>\nstruct StaticTopTreeRerootingDP:StaticTopTree{\n\
    \    using Path = typename D::Path;\n    using Point = typename D::Point;\n  \
    \  vector<Path> path,rvpath;\n    vector<Point> point;\n    StaticTopTreeRerootingDP(G\
    \ &g):StaticTopTree(g){\n        path=rvpath=vector<Path>(cnt+1),point.resize(cnt+1);\n\
    \        calc(root);\n    }\n    void pull(int u){\n        int lc=l[u],rc=r[u];\n\
    \        if(t[u]==Vertex)path[u]=rvpath[u]=D::vertex(u);\n        else if(t[u]==Compress){\n\
    \            path[u]=D::compress(path[lc],path[rc]);\n            rvpath[u]=D::compress(rvpath[rc],rvpath[lc]);\n\
    \        }\n        else if(t[u]==Rake)point[u]=D::rake(pt(lc),pt(rc));\n    \
    \    else path[u]=rvpath[u]=D::add_vertex(pt(lc),u);\n    }\n    Point pt(int\
    \ c){\n        return t[c]==Rake?point[c]:D::add_edge(path[c]);}\n    void calc(int\
    \ u){if(u)calc(l[u]),calc(r[u]),pull(u);}\n    void update(int u){for(;u;u=par[u])pull(u);}\n\
    \    Path query_all(){return path[root];}\n    Path query_subtree(int u){\n  \
    \      Path res=path[u];\n        for(int p;(p=par[u])&&t[p]==Compress;u=p)\n\
    \            if(l[p]==u)res=D::compress(res,path[r[p]]);\n        return res;\n\
    \    }\n    pair<Path,Path> around(int u){ // {below u, rest of tree}\n      \
    \  Path dn=Path::unit(),up=dn;\n        int p=par[u];\n        for(;p&&t[p]==Compress;p=par[u=p])\n\
    \            if(l[p]==u)dn=D::compress(dn,path[r[p]]);\n            else up=D::compress(up,rvpath[l[p]]);\n\
    \        if(p){\n            Point s=Point::unit();\n            for(;t[p]==Rake;p=par[u=p])\n\
    \                s=D::rake(s,pt(l[p]^r[p]^u));\n            s=D::rake(s,out(p));\n\
    \            up=D::compress(up,D::add_vertex(s,p));\n        }\n        return\
    \ {dn,up};\n    }\n    Point out(int u){\n        auto [dn,up]=around(u);\n  \
    \      return D::rake(D::add_edge(dn),D::add_edge(up));\n    }\n    Path query_reroot(int\
    \ u){\n        Point s=out(u);\n        if(t[u]==AddVertex)s=D::rake(s,pt(l[u]));\n\
    \        return D::add_vertex(s,u);\n    }\n    Path query_side(int v,int w){//\
    \ remove (v,w) then query(v)\n        return fa[v]==w?query_subtree(v):around(w).second;\n\
    \    }\n};\n#line 5 \"verify/tree/static-top-tree/point_set_tree_path_composite_sum.test.cpp\"\
    \n\nusing mint = mint998;\n\nvector<mint> a,b,c;\nvector<int> orig;\n\nstruct\
    \ TreeDP{\n    struct Path{\n        mint cnt,sum,b,c;\n        static Path unit(){return\
    \ {0,0,1,0};}\n    };\n    struct Point{\n        mint cnt,sum;\n        static\
    \ Point unit(){return {0,0};}\n    };\n    static Path compress(Path p,Path q){\n\
    \        return {p.cnt+q.cnt,p.sum+p.b*q.sum+p.c*q.cnt,p.b*q.b,p.b*q.c+p.c};\n\
    \    }\n    static Point rake(Point p,Point q){return {p.cnt+q.cnt,p.sum+q.sum};}\n\
    \    static Point add_edge(Path p){return {p.cnt,p.sum};}\n    static Path add_vertex(Point\
    \ p,int v){\n        mint k=p.cnt+orig[v];\n        return {k,b[v]*(p.sum+a[v])+c[v]*k,b[v],c[v]};\n\
    \    }\n    static Path vertex(int v){return add_vertex(Point::unit(),v);}\n};\n\
    \nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n \
    \   cin >> n >> q;\n    int m=2*n-1;\n    a.assign(m+1,0),b.assign(m+1,1),c.assign(m+1,0),orig.assign(m+1,0);\n\
    \    for(int i=1;i<=n;i++)cin >> a[i],orig[i]=1;\n    vector<vector<int>> adj(m+1);\n\
    \    for(int i=0;i<n-1;i++){\n        int u,v,e=n+1+i;\n        cin >> u >> v\
    \ >> b[e] >> c[e];\n        u++,v++;\n        adj[u].pb(e),adj[e].pb(u),adj[v].pb(e),adj[e].pb(v);\n\
    \    }\n    StaticTopTreeRerootingDP<TreeDP> dp(adj);\n    while(q--){\n     \
    \   int ty,r;\n        cin >> ty;\n        if(ty==0){\n            int w;\n  \
    \          cin >> w >> a[w+1] >> r;\n            dp.update(w+1);\n        }else{\n\
    \            int e;\n            cin >> e >> b[n+1+e] >> c[n+1+e] >> r;\n    \
    \        dp.update(n+1+e);\n        }\n        cout << dp.query_reroot(r+1).sum\
    \ << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum\"\
    \n#include \"src/contest/template.hpp\"\n#include \"src/number-theory/modint.hpp\"\
    \n#include \"src/tree/static-top-tree.hpp\"\n\nusing mint = mint998;\n\nvector<mint>\
    \ a,b,c;\nvector<int> orig;\n\nstruct TreeDP{\n    struct Path{\n        mint\
    \ cnt,sum,b,c;\n        static Path unit(){return {0,0,1,0};}\n    };\n    struct\
    \ Point{\n        mint cnt,sum;\n        static Point unit(){return {0,0};}\n\
    \    };\n    static Path compress(Path p,Path q){\n        return {p.cnt+q.cnt,p.sum+p.b*q.sum+p.c*q.cnt,p.b*q.b,p.b*q.c+p.c};\n\
    \    }\n    static Point rake(Point p,Point q){return {p.cnt+q.cnt,p.sum+q.sum};}\n\
    \    static Point add_edge(Path p){return {p.cnt,p.sum};}\n    static Path add_vertex(Point\
    \ p,int v){\n        mint k=p.cnt+orig[v];\n        return {k,b[v]*(p.sum+a[v])+c[v]*k,b[v],c[v]};\n\
    \    }\n    static Path vertex(int v){return add_vertex(Point::unit(),v);}\n};\n\
    \nint main(){\n    cin.tie(nullptr)->sync_with_stdio(false);\n    int n,q;\n \
    \   cin >> n >> q;\n    int m=2*n-1;\n    a.assign(m+1,0),b.assign(m+1,1),c.assign(m+1,0),orig.assign(m+1,0);\n\
    \    for(int i=1;i<=n;i++)cin >> a[i],orig[i]=1;\n    vector<vector<int>> adj(m+1);\n\
    \    for(int i=0;i<n-1;i++){\n        int u,v,e=n+1+i;\n        cin >> u >> v\
    \ >> b[e] >> c[e];\n        u++,v++;\n        adj[u].pb(e),adj[e].pb(u),adj[v].pb(e),adj[e].pb(v);\n\
    \    }\n    StaticTopTreeRerootingDP<TreeDP> dp(adj);\n    while(q--){\n     \
    \   int ty,r;\n        cin >> ty;\n        if(ty==0){\n            int w;\n  \
    \          cin >> w >> a[w+1] >> r;\n            dp.update(w+1);\n        }else{\n\
    \            int e;\n            cin >> e >> b[n+1+e] >> c[n+1+e] >> r;\n    \
    \        dp.update(n+1+e);\n        }\n        cout << dp.query_reroot(r+1).sum\
    \ << \"\\n\";\n    }\n}\n"
  dependsOn:
  - src/contest/template.hpp
  - src/number-theory/modint.hpp
  - src/tree/static-top-tree.hpp
  isVerificationFile: true
  path: verify/tree/static-top-tree/point_set_tree_path_composite_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 18:23:08+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/tree/static-top-tree/point_set_tree_path_composite_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/tree/static-top-tree/point_set_tree_path_composite_sum.test.cpp
- /verify/verify/tree/static-top-tree/point_set_tree_path_composite_sum.test.cpp.html
title: verify/tree/static-top-tree/point_set_tree_path_composite_sum.test.cpp
---
