/**
 * Author: Ulf Lundstrom, Victor Lecomte, chilli
 * License: CC0
 * Source: https://vlecomte.github.io/cp-geo.pdf, tinyKACTL
 * Description: Basic primitives: lineDist, sideOf, onSegment,
 * segDist, lineInter, segInter, lineProj,
 * linearTransformation, ccRadius/ccCenter (circumcircle),
 * polygonArea2, polygonCenter. Integer points: products of up
 * to three coordinates, watch overflow.
 * Time: O(1), polygon ones O(n)
 * Status: tested
 */
#pragma once

#include "src/geometry/Point.h"

// signed dist from p to line ab (>0 left); a==b gives nan
template<class P> double lineDist(P a,P b,P p){
	return (double)(b-a).cross(p-a)/(b-a).dist();
}
// p seen from s towards e: 1 left, 0 on, -1 right
template<class P>
int sideOf(P s,P e,P p){return sgn(s.cross(e,p));}
// eps version: 0 if p within distance eps of line
template<class P> int sideOf(P s,P e,P p,double eps){
	auto a=(e-s).cross(p-s);
	double l=(e-s).dist()*eps;
	return (a>l)-(a<-l);
}
// p on segment se (exact; for doubles use segDist<=eps)
template<class P> bool onSegment(P s,P e,P p){
	return p.cross(s,e)==0&&(s-p).dot(e-p)<=0;
}
// dist from p to segment se (Point<double>)
template<class P> double segDist(P s,P e,P p){
	if(s==e)return (p-s).dist();
	auto d=(e-s).dist2(),t=min(d,max(.0,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}
// lines s1e1,s2e2: {1,p} unique, {0,(0,0)} parallel,
// {-1,(0,0)} same line. Wrong if Point<ll> and p not integer
template<class P> pair<int,P> lineInter(P s1,P e1,P s2,P e2){
	auto d=(e1-s1).cross(e2-s2);
	if(d==0)return {-(s1.cross(e1,s2)==0),P(0,0)}; // parallel
	auto p=s2.cross(e1,e2),q=s2.cross(e2,s1);
	return {1,(s1*p+e1*q)/d};
}
// segments ab,cd: {} none, {p} one point, {p,q} overlap
template<class P> vector<P> segInter(P a,P b,P c,P d){
	auto oa=c.cross(d,a),ob=c.cross(d,b);
	auto oc=a.cross(b,c),od=a.cross(b,d);
	if(sgn(oa)*sgn(ob)<0&&sgn(oc)*sgn(od)<0)
		return {(a*ob-b*oa)/(ob-oa)};
	set<P> s;
	if(onSegment(c,d,a))s.insert(a);
	if(onSegment(c,d,b))s.insert(b);
	if(onSegment(a,b,c))s.insert(c);
	if(onSegment(a,b,d))s.insert(d);
	return {ALL(s)};
}
// projection of p onto line ab (refl: reflection instead)
template<class P> P lineProj(P a,P b,P p,bool refl=false){
	P v=b-a;
	return p-v.perp()*(1+refl)*v.cross(p-a)/v.dist2();
}
// move the plane (rotate+scale+translate, never mirror) so
// p0->q0 and p1->q1; returns where r lands. As complex
// numbers: q0+(r-p0)*(q1-q0)/(p1-p0). Use Point<double>
template<class P>
P linearTransformation(P p0,P p1,P q0,P q1,P r){
	P dp=p1-p0,dq=q1-q0,num(dp.cross(dq),dp.dot(dq));
	return q0+P((r-p0).cross(num),(r-p0).dot(num))/dp.dist2();
}
// circumcircle of ABC: radius / center (Point<double>)
template<class P> double ccRadius(P A,P B,P C){
	return (B-A).dist()*(C-B).dist()*(A-C).dist()/
		abs((B-A).cross(C-A))/2;
}
template<class P> P ccCenter(const P& A,const P& B,const P& C){
	P b=C-A,c=B-A;
	return A+(b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}
// twice signed area (CW negative)
template<class T> T polygonArea2(const vector<Point<T>>& v){
	T a=v.back().cross(v[0]);
	for(int i=0;i<SZ(v)-1;i++)a+=v[i].cross(v[i+1]);
	return a;
}
// center of mass of polygon (Point<double>)
template<class P> P polygonCenter(const vector<P>& v){
	P res(0,0);double A=0;
	for(int i=0,j=SZ(v)-1;i<SZ(v);j=i++){
		res=res+(v[i]+v[j])*v[j].cross(v[i]);
		A+=v[j].cross(v[i]);
	}
	return res/A/3;
}
