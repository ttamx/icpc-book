---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/miscellaneous/range-inversion.hpp\"\n\n/**\n * Author:\
    \ Teetat T.\n * Date: 2025-10-31\n * Description: Online range inversion count\
    \ in O(\\sqrt{N}).\n */\n\nconst int N=1e5+5;\nconst int K=320;\n\nint n,k;\n\
    int a[N];\npair<int,int> b[N],c[N];\nint block[N],l[K],r[K],pre[N],suf[N];\nll\
    \ dp[K][K],cnt[K][N];\nvector<tuple<int,int,int>> qr[N];\nint st=1,ed=0;\n \n\
    struct Fenwick{\n\tint t[N];\n\tvoid update(int i,int v){\t\n\t\twhile(i<N)t[i]+=v,i+=i&-i;\n\
    \t}\n\tint query(int i){\n\t\tint res=0;\n\t\twhile(i>0)res+=t[i],i-=i&-i;\n\t\
    \treturn res;\n\t}\n}f;\n \nll calc(vector<int> &l,vector<int> &r){\n\tll res=0;\n\
    \tint p=0;\n\tfor(auto x:l){\n\t\twhile(p<r.size()&&x>r[p])p++;\n\t\tres+=p;\n\
    \t}\n\treturn res;\n}\n \nll query(int L,int R){\n\tint bl=block[L],br=block[R];\n\
    \tvector<int> x,y;\n\tif(bl==br){\n\t\tfor(int i=l[bl];i<=r[bl];i++){\n\t\t\t\
    auto [val,id]=c[i];\n\t\t\tif(id<L)x.emplace_back(val);\n\t\t\tif(L<=id&&id<=R)y.emplace_back(val);\n\
    \t\t}\n\t\treturn pre[R]-(L==l[bl]?0:pre[L-1])-calc(x,y);\n\t}\n\tll ans=suf[L]+dp[bl+1][br-1]+pre[R];\n\
    \tfor(int i=bl+1;i<br;i++)ans+=cnt[i][r[bl]]-cnt[i][L-1]+cnt[i][R]-cnt[i][l[br]-1];\n\
    \tfor(int i=l[bl];i<=r[bl];i++){\n\t\tauto [val,id]=c[i];\n\t\tif(L<=id)x.emplace_back(val);\n\
    \t}\n\tfor(int i=l[br];i<=r[br];i++){\n\t\tauto [val,id]=c[i];\n\t\tif(id<=R)y.emplace_back(val);\n\
    \t}\n\treturn ans+calc(x,y);\n}\n \nvoid build(){\n    for(int i=1;i<=n;i++){\n\
    \        b[i]={a[i],i};\n    }\n\tk=(n-1)/K+1;\n\tfor(int i=1;i<=k;i++){\n   \
    \     l[i]=r[i-1]+1,r[i]=i*K;\n    }\n\tr[k]=n;\n\tfor(int i=1;i<=k;i++){\n\t\t\
    sort(b+l[i],b+r[i]+1);\n\t\tfor(int j=l[i];j<=r[i];j++){\n            block[j]=i,c[j]=b[j];\n\
    \        }\n\t\tint res=0;\n\t\tfor(int j=l[i];j<=r[i];j++){\n\t\t\tf.update(a[j],+1);\n\
    \t\t\tres+=f.query(n)-f.query(a[j]);\n\t\t\tpre[j]=res;\n\t\t}\n\t\tdp[i][i]=res;\n\
    \t\tfor(int j=l[i];j<=r[i];j++){\n\t\t\tsuf[j]=res;\n\t\t\tf.update(a[j],-1);\n\
    \t\t\tres-=f.query(a[j]-1);\n\t\t}\n\t}\n\tsort(b+1,b+n+1);\n\tfor(int i=1;i<=k;i++){\n\
    \t\tfor(int j=1,p=l[i];j<=n;j++){\n\t\t\tauto [val,id]=b[j];\n\t\t\twhile(p<=r[i]&&val>c[p].first)p++;\n\
    \t\t\tif(id<l[i])cnt[i][id]=p-l[i];\n\t\t}\n\t\tfor(int j=1,p=l[i];j<=n;j++){\n\
    \t\t\tauto [val,id]=b[j];\n\t\t\twhile(p<=r[i]&&val>=c[p].first)p++;\n\t\t\tif(id>r[i])cnt[i][id]=r[i]-p+1;\n\
    \t\t}\n\t\tfor(int j=1;j<=n;j++)cnt[i][j]+=cnt[i][j-1];\n\t}\n\tfor(int sz=2;sz<=k;sz++){\n\
    \t\tfor(int i=1,j=sz;j<=k;i++,j++){\n\t\t\tdp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+cnt[j][r[i]]-cnt[j][l[i]-1];\n\
    \t\t}\n\t}\n}\n"
  code: "#pragma once\n\n/**\n * Author: Teetat T.\n * Date: 2025-10-31\n * Description:\
    \ Online range inversion count in O(\\sqrt{N}).\n */\n\nconst int N=1e5+5;\nconst\
    \ int K=320;\n\nint n,k;\nint a[N];\npair<int,int> b[N],c[N];\nint block[N],l[K],r[K],pre[N],suf[N];\n\
    ll dp[K][K],cnt[K][N];\nvector<tuple<int,int,int>> qr[N];\nint st=1,ed=0;\n \n\
    struct Fenwick{\n\tint t[N];\n\tvoid update(int i,int v){\t\n\t\twhile(i<N)t[i]+=v,i+=i&-i;\n\
    \t}\n\tint query(int i){\n\t\tint res=0;\n\t\twhile(i>0)res+=t[i],i-=i&-i;\n\t\
    \treturn res;\n\t}\n}f;\n \nll calc(vector<int> &l,vector<int> &r){\n\tll res=0;\n\
    \tint p=0;\n\tfor(auto x:l){\n\t\twhile(p<r.size()&&x>r[p])p++;\n\t\tres+=p;\n\
    \t}\n\treturn res;\n}\n \nll query(int L,int R){\n\tint bl=block[L],br=block[R];\n\
    \tvector<int> x,y;\n\tif(bl==br){\n\t\tfor(int i=l[bl];i<=r[bl];i++){\n\t\t\t\
    auto [val,id]=c[i];\n\t\t\tif(id<L)x.emplace_back(val);\n\t\t\tif(L<=id&&id<=R)y.emplace_back(val);\n\
    \t\t}\n\t\treturn pre[R]-(L==l[bl]?0:pre[L-1])-calc(x,y);\n\t}\n\tll ans=suf[L]+dp[bl+1][br-1]+pre[R];\n\
    \tfor(int i=bl+1;i<br;i++)ans+=cnt[i][r[bl]]-cnt[i][L-1]+cnt[i][R]-cnt[i][l[br]-1];\n\
    \tfor(int i=l[bl];i<=r[bl];i++){\n\t\tauto [val,id]=c[i];\n\t\tif(L<=id)x.emplace_back(val);\n\
    \t}\n\tfor(int i=l[br];i<=r[br];i++){\n\t\tauto [val,id]=c[i];\n\t\tif(id<=R)y.emplace_back(val);\n\
    \t}\n\treturn ans+calc(x,y);\n}\n \nvoid build(){\n    for(int i=1;i<=n;i++){\n\
    \        b[i]={a[i],i};\n    }\n\tk=(n-1)/K+1;\n\tfor(int i=1;i<=k;i++){\n   \
    \     l[i]=r[i-1]+1,r[i]=i*K;\n    }\n\tr[k]=n;\n\tfor(int i=1;i<=k;i++){\n\t\t\
    sort(b+l[i],b+r[i]+1);\n\t\tfor(int j=l[i];j<=r[i];j++){\n            block[j]=i,c[j]=b[j];\n\
    \        }\n\t\tint res=0;\n\t\tfor(int j=l[i];j<=r[i];j++){\n\t\t\tf.update(a[j],+1);\n\
    \t\t\tres+=f.query(n)-f.query(a[j]);\n\t\t\tpre[j]=res;\n\t\t}\n\t\tdp[i][i]=res;\n\
    \t\tfor(int j=l[i];j<=r[i];j++){\n\t\t\tsuf[j]=res;\n\t\t\tf.update(a[j],-1);\n\
    \t\t\tres-=f.query(a[j]-1);\n\t\t}\n\t}\n\tsort(b+1,b+n+1);\n\tfor(int i=1;i<=k;i++){\n\
    \t\tfor(int j=1,p=l[i];j<=n;j++){\n\t\t\tauto [val,id]=b[j];\n\t\t\twhile(p<=r[i]&&val>c[p].first)p++;\n\
    \t\t\tif(id<l[i])cnt[i][id]=p-l[i];\n\t\t}\n\t\tfor(int j=1,p=l[i];j<=n;j++){\n\
    \t\t\tauto [val,id]=b[j];\n\t\t\twhile(p<=r[i]&&val>=c[p].first)p++;\n\t\t\tif(id>r[i])cnt[i][id]=r[i]-p+1;\n\
    \t\t}\n\t\tfor(int j=1;j<=n;j++)cnt[i][j]+=cnt[i][j-1];\n\t}\n\tfor(int sz=2;sz<=k;sz++){\n\
    \t\tfor(int i=1,j=sz;j<=k;i++,j++){\n\t\t\tdp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+cnt[j][r[i]]-cnt[j][l[i]-1];\n\
    \t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/miscellaneous/range-inversion.hpp
  requiredBy: []
  timestamp: '2025-11-01 00:50:37+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/miscellaneous/range-inversion.hpp
layout: document
redirect_from:
- /library/src/miscellaneous/range-inversion.hpp
- /library/src/miscellaneous/range-inversion.hpp.html
title: src/miscellaneous/range-inversion.hpp
---
