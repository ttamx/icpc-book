#pragma once
#include "src/polynomials/ntt.hpp"

/**
 * Author: Teetat T.
 * Date: 2024-03-17
 * Description: basic operations of formal power series
 */

template<class mint>
struct FormalPowerSeries:vector<mint>{
    using vector<mint>::vector;
    using FPS = FormalPowerSeries;

    FPS &operator+=(const FPS &r){
        if(r.size()>this->size())this->resize(r.size());
        for(int i=0;i<r.size();i++)(*this)[i]+=r[i];
        return *this;
    }
    FPS &operator+=(const mint &r){
        if(this->empty())this->resize(1);
        (*this)[0]+=r;
        return *this;
    }
    FPS &operator-=(const FPS &r){
        if(r.size()>this->size())this->resize(r.size());
        for(int i=0;i<r.size();i++)(*this)[i]-=r[i];
        return *this;
    }
    FPS &operator-=(const mint &r){
        if(this->empty())this->resize(1);
        (*this)[0]-=r;
        return *this;
    }
    FPS &operator*=(const FPS &r){
        auto res=NTT<mint>()(*this,r);
        return *this=FPS(res.begin(),res.end());
    }
    FPS &operator*=(const mint &r){
        for(auto &a:*this)a*=r;
        return *this;
    }
    FPS &operator/=(const FPS &r){ // r.back()!=0
        if(this->size()<r.size())return *this=FPS();
        int n=this->size()-r.size()+1;
        return *this=(rev().pre(n)*r.rev().inv(n)).pre(n).rev();
    }
    FPS &operator%=(const FPS &r){
        *this-=*this/r*r;
        return *this=pre(r.size()-1).shrink();
    }

    friend FPS operator+(FPS l,const FPS &r){return l+=r;}
    friend FPS operator+(FPS l,const mint &r){return l+=r;}
    friend FPS operator+(const mint &l,FPS r){return r+=l;}
    friend FPS operator-(FPS l,const FPS &r){return l-=r;}
    friend FPS operator-(FPS l,const mint &r){return l-=r;}
    friend FPS operator-(const mint &l,FPS r){return -(r-l);}
    friend FPS operator*(FPS l,const FPS &r){return l*=r;}
    friend FPS operator*(FPS l,const mint &r){return l*=r;}
    friend FPS operator*(const mint &l,FPS r){return r*=l;}
    friend FPS operator/(FPS l,const FPS &r){return l/=r;}
    friend FPS operator%(FPS l,const FPS &r){return l%=r;}

    FPS operator-()const{return (*this)*-1;}

    FPS rev()const{
        FPS res(*this);
        reverse(res.begin(),res.end());
        return res;
    }
    FPS pre(int sz)const{
        FPS res(this->begin(),this->begin()+min((int)this->size(),sz));
        if(res.size()<sz)res.resize(sz);
        return res;
    }
    FPS shrink()const{
        FPS res(*this);
        while(!res.empty()&&res.back()==mint{})res.pop_back();
        return res;
    }
    FPS operator>>(int sz)const{
        if(this->size()<=sz)return {};
        FPS res(*this);
        res.erase(res.begin(),res.begin()+sz);
        return res;
    }
    FPS operator<<(int sz)const{
        FPS res(*this);
        res.insert(res.begin(),sz,mint{});
        return res;
    }
    FPS diff()const{
        const int n=this->size();
        FPS res(max(0,n-1));
        for(int i=1;i<n;i++)res[i-1]=(*this)[i]*mint(i);
        return res;
    }
    FPS integral()const{
        const int n=this->size();
        FPS res(n+1);
        res[0]=0;
        if(n>0)res[1]=1;
        ll mod=mint::get_mod();
        for(int i=2;i<=n;i++)res[i]=(-res[mod%i])*(mod/i);
        for(int i=0;i<n;i++)res[i+1]*=(*this)[i];
        return res;
    }
    mint eval(const mint &x)const{
        mint res=0,w=1;
        for(auto &a:*this)res+=a*w,w*=x;
        return res;
    }

    FPS inv(int deg=-1)const{
        assert(!this->empty()&&(*this)[0]!=mint(0));
        if(deg==-1)deg=this->size();
        FPS res{mint(1)/(*this)[0]};
        for(int i=2;i>>1<deg;i<<=1){
            res=(res*(mint(2)-res*pre(i))).pre(i);
        }
        return res.pre(deg);
    }
    FPS log(int deg=-1)const{
        assert(!this->empty()&&(*this)[0]==mint(1));
        if(deg==-1)deg=this->size();
        return (pre(deg).diff()*inv(deg)).pre(deg-1).integral();
    }
    FPS exp(int deg=-1)const{
        assert(this->empty()||(*this)[0]==mint(0));
        if(deg==-1)deg=this->size();
        FPS res{mint(1)};
        for(int i=2;i>>1<deg;i<<=1){
            res=(res*(pre(i)-res.log(i)+mint(1))).pre(i);
        }
        return res.pre(deg);
    }
    FPS pow(ll k,int deg=-1)const{
        const int n=this->size();
        if(deg==-1)deg=n;
        if(k==0){
            FPS res(deg);
            if(deg)res[0]=mint(1);
            return res;
        }
        for(int i=0;i<n;i++){
            if(__int128_t(i)*k>=deg)return FPS(deg,mint(0));
            if((*this)[i]==mint(0))continue;
            mint rev=mint(1)/(*this)[i];
            FPS res=(((*this*rev)>>i).log(deg)*k).exp(deg);
            res=((res*binpow((*this)[i],k))<<(i*k)).pre(deg);
            return res;
        }
        return FPS(deg,mint(0));
    }
};