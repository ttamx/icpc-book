#pragma once

/**
 * Author: Teetat T.
 * Date: 2025-10-31
 * Description: Online range inversion count in O(\sqrt{N}).
 */

const int N=1e5+5;
const int K=320;

int n,k;
int a[N];
pair<int,int> b[N],c[N];
int block[N],l[K],r[K],pre[N],suf[N];
ll dp[K][K],cnt[K][N];
vector<tuple<int,int,int>> qr[N];
int st=1,ed=0;
 
struct Fenwick{
	int t[N];
	void update(int i,int v){	
		while(i<N)t[i]+=v,i+=i&-i;
	}
	int query(int i){
		int res=0;
		while(i>0)res+=t[i],i-=i&-i;
		return res;
	}
}f;
 
ll calc(vector<int> &l,vector<int> &r){
	ll res=0;
	int p=0;
	for(auto x:l){
		while(p<r.size()&&x>r[p])p++;
		res+=p;
	}
	return res;
}
 
ll query(int L,int R){
	int bl=block[L],br=block[R];
	vector<int> x,y;
	if(bl==br){
		for(int i=l[bl];i<=r[bl];i++){
			auto [val,id]=c[i];
			if(id<L)x.emplace_back(val);
			if(L<=id&&id<=R)y.emplace_back(val);
		}
		return pre[R]-(L==l[bl]?0:pre[L-1])-calc(x,y);
	}
	ll ans=suf[L]+dp[bl+1][br-1]+pre[R];
	for(int i=bl+1;i<br;i++)ans+=cnt[i][r[bl]]-cnt[i][L-1]+cnt[i][R]-cnt[i][l[br]-1];
	for(int i=l[bl];i<=r[bl];i++){
		auto [val,id]=c[i];
		if(L<=id)x.emplace_back(val);
	}
	for(int i=l[br];i<=r[br];i++){
		auto [val,id]=c[i];
		if(id<=R)y.emplace_back(val);
	}
	return ans+calc(x,y);
}
 
void build(){
    for(int i=1;i<=n;i++){
        b[i]={a[i],i};
    }
	k=(n-1)/K+1;
	for(int i=1;i<=k;i++){
        l[i]=r[i-1]+1,r[i]=i*K;
    }
	r[k]=n;
	for(int i=1;i<=k;i++){
		sort(b+l[i],b+r[i]+1);
		for(int j=l[i];j<=r[i];j++){
            block[j]=i,c[j]=b[j];
        }
		int res=0;
		for(int j=l[i];j<=r[i];j++){
			f.update(a[j],+1);
			res+=f.query(n)-f.query(a[j]);
			pre[j]=res;
		}
		dp[i][i]=res;
		for(int j=l[i];j<=r[i];j++){
			suf[j]=res;
			f.update(a[j],-1);
			res-=f.query(a[j]-1);
		}
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=k;i++){
		for(int j=1,p=l[i];j<=n;j++){
			auto [val,id]=b[j];
			while(p<=r[i]&&val>c[p].first)p++;
			if(id<l[i])cnt[i][id]=p-l[i];
		}
		for(int j=1,p=l[i];j<=n;j++){
			auto [val,id]=b[j];
			while(p<=r[i]&&val>=c[p].first)p++;
			if(id>r[i])cnt[i][id]=r[i]-p+1;
		}
		for(int j=1;j<=n;j++)cnt[i][j]+=cnt[i][j-1];
	}
	for(int sz=2;sz<=k;sz++){
		for(int i=1,j=sz;j<=k;i++,j++){
			dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+cnt[j][r[i]]-cnt[j][l[i]-1];
		}
	}
}