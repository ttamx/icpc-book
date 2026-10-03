/**
 * Author: Oleksandr Bacherikov, chilli
 * Date: 2019-05-07
 * License: Boost Software License
 * Source: https://github.com/AlCash07/ACTL/blob/master/include/actl/geometry/algorithm/intersect/line_convex_polygon.hpp
 * Description: Line-convex polygon intersection. The polygon must be ccw and have no collinear points.
 * lineHull(line, poly) returns a pair describing the intersection of a line with the polygon:
 *  \begin{itemize*}
 *    \item $(-1, -1)$ if no collision,
 *    \item $(i, -1)$ if touching the corner $i$,
 *    \item $(i, i)$ if along side $(i, i+1)$,
 *    \item $(i, j)$ if crossing sides $(i, i+1)$ and $(j, j+1)$.
 *  \end{itemize*}
 *  In the last case, if a corner $i$ is crossed, this is treated as happening on side $(i, i+1)$.
 *  The points are returned in the same order as the line hits the polygon.
 * \texttt{extrVertex} returns the point of a hull with the max projection onto a line.
 * Time: O(\log n)
 * Status: stress-tested
 */
#pragma once

#include "src/geometry/Point.h"

#define CMP(i,j) sgn(dir.perp().cross(poly[(i)%n]-poly[(j)%n]))
#define EXTR(i) CMP(i+1,i)>=0&&CMP(i,i-1+n)<0
template<class P> int extrVertex(vector<P>& poly,P dir){
	int n=SZ(poly),lo=0,hi=n;
	if(EXTR(0))return 0;
	while(lo+1<hi){
		int m=(lo+hi)/2;if(EXTR(m))return m;
		int ls=CMP(lo+1,lo),ms=CMP(m+1,m);
		(ls<ms||(ls==ms&&ls==CMP(lo,m))?hi:lo)=m;
	}
	return lo;
}
#define CMPL(i) sgn(a.cross(poly[i],b))
template<class P>
array<int,2> lineHull(P a,P b,vector<P>& poly){
	int endA=extrVertex(poly,(a-b).perp());
	int endB=extrVertex(poly,(b-a).perp());
	if(CMPL(endA)<0||CMPL(endB)>0)return {-1,-1};
	array<int,2> res;
	for(int i=0;i<2;i++){
		int lo=endB,hi=endA,n=SZ(poly);
		while((lo+1)%n!=hi){
			int m=((lo+hi+(lo<hi?0:n))/2)%n;
			(CMPL(m)==CMPL(endB)?lo:hi)=m;
		}
		res[i]=(lo+!CMPL(hi))%n;
		swap(endA,endB);
	}
	if(res[0]==res[1])return {res[0],-1};
	if(!CMPL(res[0])&&!CMPL(res[1]))
		switch((res[0]-res[1]+SZ(poly)+1)%SZ(poly)){
			case 0:return {res[0],res[0]};
			case 2:return {res[1],res[1]};
		}
	return res;
}
