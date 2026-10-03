/**
 * Author: Teetat T.
 * Date: 2026-10-03
 * License: CC0
 * Source: https://cp-algorithms.com/geometry/halfplane-intersection.html
 * Description: Intersection of half-planes. Half-plane $(s,e)$ keeps
 *  the points LEFT of the directed line $s\to e$, i.e. $s.cross(e,p)\ge0$
 *  (opposite of polygonCut, which keeps the right side).
 *  Returns the vertices in ccw order, empty if the intersection is empty
 *  or has zero area. The result must be bounded: add a bounding box.
 *  EPS is absolute: with a huge box ($B>10^5$) zero-area answers may
 *  survive as thin slivers.
 * Usage:
 * 	vector<L> h={...}; double B=1e5;
 * 	P c[4]={P(-B,-B),P(B,-B),P(B,B),P(-B,B)};
 * 	for(int i=0;i<4;i++)h.pb({c[i],c[(i+1)%4]});
 * 	vector<P> poly=halfPlane(h);
 * Time: $O(n \log n)$
 * Status: stress-tested against repeated polygonCut
 */
#pragma once

#include "src/geometry/Point.h"

typedef Point<double> P;
typedef array<P,2> L;
P hpInter(L a,L b){
	P d=a[1]-a[0],e=b[1]-b[0];
	return a[0]+d*((b[0]-a[0]).cross(e)/d.cross(e));
}
vector<P> halfPlane(vector<L> h){
	auto dir=[](L l){return l[1]-l[0];};
	auto out=[](L l,P p){return l[0].cross(l[1],p)<-EPS;};
	auto hf=[&](L l){P d=dir(l);return d.y<0||(!d.y&&d.x<0);};
	auto cr=[&](L a,L b){return dir(a).cross(dir(b));};
	sort(ALL(h),[&](L a,L b){
		if(hf(a)!=hf(b))return hf(a)<hf(b);
		return cr(a,b)?cr(a,b)>0:b[0].cross(b[1],a[0])>0;});
	deque<L> q;
	auto bk=[&]{return hpInter(q[SZ(q)-1],q[SZ(q)-2]);};
	auto fr=[&]{return hpInter(q[0],q[1]);};
	for(int i=0;i<SZ(h);i++){
		L l=h[i];
		if(i&&hf(l)==hf(h[i-1])&&!cr(l,h[i-1]))continue;
		while(SZ(q)>1&&out(l,bk()))q.pop_back();
		while(SZ(q)>1&&out(l,fr()))q.pop_front();
		if(SZ(q)&&abs(dir(l).cross(dir(q.back())))<EPS){
			if(dir(l).dot(dir(q.back()))<0)return {};
			if(out(l,q.back()[0]))q.pop_back();
			else continue;
		}
		q.pb(l);
	}
	while(SZ(q)>2&&out(q[0],bk()))q.pop_back();
	while(SZ(q)>2&&out(q.back(),fr()))q.pop_front();
	if(SZ(q)<3)return {};
	vector<P> r;double a=0;
	for(int i=0;i<SZ(q);i++)r.pb(hpInter(q[i],q[(i+1)%SZ(q)]));
	for(int i=0;i<SZ(r);i++)a+=r[i].cross(r[(i+1)%SZ(r)]);
	return a>EPS?r:vector<P>();
}
