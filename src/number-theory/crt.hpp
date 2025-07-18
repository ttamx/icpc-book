#pragma once
#include "src/number-theory/euclid.hpp" 

/**
 * Author: Simon Lindholm
 * Date: 2019-05-22
 * License: CC0
 * Description: Chinese Remainder Theorem.
 *
 * \texttt{crt(a, m, b, n)} computes $x$ such that $x\equiv a \pmod m$, $x\equiv b \pmod n$.
 * If $|a| < m$ and $|b| < n$, $x$ will obey $0 \le x < \text{lcm}(m, n)$.
 * Assumes $mn < 2^{62}$.
 * If x0 and y0 is one of the solutions of ax + by = g, then the general solution is
 * x = x0 + k * (b / g) and y = y0 - k * (a / g).
 * Time: $\log(n)$
 * Status: Works
 */

ll crt(ll a,ll m,ll b,ll n){
	if(n>m)swap(a,b),swap(m,n);
	ll x,y,g=euclid(m,n,x,y);
	if((a-b)%g!=0)return -1LL; // no solution
	x=(b-a)%n*x%n/g*m+a;
	return x<0?x+m*n/g:x;
}