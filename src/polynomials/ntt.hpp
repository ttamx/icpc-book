#pragma once
#include "src/modular-arithmetic/binpow.hpp"
#include "src/modular-arithmetic/montgomery-modint.hpp"

/**
 * Author: Teetat T.
 * Description: Number Theoretic Transform
 * Time: $O(N \log N)$
 */

template<class mint>
struct NTT{
	using vm = vector<mint>;
	
	static constexpr mint root=mint::get_root();
    static_assert(root!=0);

	static void ntt(vm &a){
		int n=a.size(),L=31-__builtin_clz(n);
		vm rt(n);
		rt[1]=1;
		for(int k=2,s=2;k<n;k*=2,s++){
			mint z[]={1,binpow(root,MOD>>s)};
			for(int i=k;i<2*k;i++)rt[i]=rt[i/2]*z[i&1];
		}
		vector<int> rev(n);
		for(int i=1;i<n;i++)rev[i]=(rev[i/2]|(i&1)<<L)/2;
		for(int i=1;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
		for(int k=1;k<n;k*=2)for(int i=0;i<n;i+=2*k)for(int j=0;j<k;j++){
			mint z=rt[j+k]*a[i+j+k];
			a[i+j+k]=a[i+j]-z;
			a[i+j]+=z;
		}
	}
	static vm conv(const vm &a,const vm &b){
		if(a.empty()||b.empty())return {};
		int s=a.size()+b.size()-1,n=1<<(32-__builtin_clz(s));
		mint inv=mint(n).inv();
		vm in1(a),in2(b),out(n);
		in1.resize(n),in2.resize(n);
		ntt(in1),ntt(in2);
		for(int i=0;i<n;i++)out[-i&(n-1)]=in1[i]*in2[i]*inv;
		ntt(out);
		return vm(out.begin(),out.begin()+s);
	}
	vm operator()(const vm &a,const vm &b){
		return conv(a,b);
	}
};

