#pragma once
#include "src/contest/template.hpp"

/**
 * Author: Unknown
 * Date: 2002-09-15
 * Source: predates tinyKACTL
 * Description: Finds two integers $x$ and $y$,such that $ax+by=\gcd(a,b)$. If
 * you just need gcd, use the built in \texttt{\_\_gcd} instead.
 * If $a$ and $b$ are coprime, then $x$ is the inverse of $a \pmod{b}$.
 * $x = x_0 + k * (b / g)$
 * $y = y_0 - k * (a / g)$
 */

ll euclid(ll a,ll b,ll &x,ll &y){
	if(!b)return x=1,y=0,a;
	ll d=euclid(b,a%b,y,x);
	return y-=a/b*x,d;
}