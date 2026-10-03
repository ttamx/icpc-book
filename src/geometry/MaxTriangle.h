/**
 * Author: Teetat T.
 * Date: 2026-10-04
 * License: CC0
 * Description: Returns twice the maximum area of a triangle with
 * vertices among the given points, and the triangle (0 if $n<3$ or all
 * collinear). On the convex hull, the best triangle rooted at $r$
 * (vertices $r<j<k$) interleaves with those rooted at $a<r<b$, so
 * divide and conquer over roots, each rooted search being a two-pointer
 * scan of the allowed ranges.
 * Usage: auto [a2,t]=maxTriangle(pts);
 * Time: O(n \log n)
 * Status: stress-tested
 */
#pragma once
#include "src/geometry/ConvexHull.h"

pair<ll,array<P,3>> maxTriangle(vector<P> pts){
	vector<P> h=convexHull(pts);
	int n=SZ(h);
	pair<ll,array<P,3>> res{};
	if(n<3)return res;
	typedef array<int,2> J;
	auto at=[&](int i){return h[i%n];};
	auto A=[&](int a,int b,int c){
		return at(a).cross(at(b),at(c));};
	// best (r,j,k) with j in [jl,jr], k in [kl,kr], j<k
	auto rooted=[&](int r,int jl,int jr,int kl,int kr){
		J t{jl,kl};ll mx=-1;
		for(int j=jl,k=kl;j<=jr;j++){
			k=max(k,j+1);
			if(k>kr)break;
			while(k<kr&&A(r,j,k+1)>=A(r,j,k))k++;
			if(A(r,j,k)>mx)mx=A(r,j,k),t={j,k};
		}
		res=max(res,{mx,{at(r),at(t[0]),at(t[1])}});
		return t;
	};
	auto rec=[&](auto &&self,int a,int b,J L,J R)->void {
		if(b-a<2)return;
		int m=(a+b)/2;
		J M=rooted(m,max(L[0],m+1),min(R[0],m+n-2),
			max(L[1],m+2),min(R[1],m+n-1));
		self(self,a,m,L,M),self(self,m,b,M,R);
	};
	J t=rooted(0,1,n-2,2,n-1);
	rec(rec,0,n,t,{t[0]+n,t[1]+n});
	return res;
}
