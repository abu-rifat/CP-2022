// /*******Bismillahir-Rahmanir-Rahim**********/
// 
// Name         : Abu Rifat Muhammed Al Hasib
// Institution  : University of Barisal, Bangladesh
// Github       : https://github.com/abu-rifat
// website	: https://aburifat.com
// 
// Codeforces   : https://codeforces.com/profile/ARMaster
// lightoj      : https://lightoj.com/user/abu-rifat
// AtCoder      : https://atcoder.jp/users/aburifat
// codechef     : https://www.codechef.com/users/aburifat
// SPOJ         : https://www.spoj.com/users/abu_rifat
// UvaOJ        : https://uhunt.onlinejudge.org/id/889274
// 
// facebook     : https://facebook.com/AbuRifatM
// linkedin     : https://www.linkedin.com/in/aburifat
// Email        : rifat.cse4.bu@gmail.com
// 		  armalhasib@gmail.com
// 		  abu.rifat.m@gmail.com
// 
// Problem	: Ada and Spring Cleaning
// Contest	: SPOJ - Classical
// URL		: https://www.spoj.com/problems/ADACLEAN/
// Memory Limit : 1536 MB
// Time Limit	: 1000 ms


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
constexpr ll MX=1e6;
constexpr ll base=29;
constexpr ll base2=31;
constexpr ll mod=1000000007;
constexpr ll mod2=1000000009;
 
vector<ll>basePow,basePow2;
void ctPow()
{
    basePow.resize(MX+5);
    basePow2.resize(MX+5);
    basePow[0]=1;
    basePow2[0]=1;
    for(ll i=1;i<=MX;i++){
        basePow[i]=(basePow[i-1]*base)%mod;
        basePow2[i]=(basePow2[i-1]*base2)%mod2;
    }
}
 
vector<ll>preHash,preHash2;
void ctHash(string s)
{
    ll len=s.size();
    preHash.resize(len+5);
    preHash2.resize(len+5);
    preHash[0]=s[0]-'a'+1;
    preHash2[0]=s[0]-'a'+1;
    for(ll i=1;i<len;i++){
        preHash[i]=((preHash[i-1]*base)+(s[i]-'a'+1))%mod;
        preHash2[i]=((preHash2[i-1]*base2)+(s[i]-'a'+1))%mod2;
    }
}
 
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ctPow();
    ll t;
    cin>>t;
    ll n, k;
    while(t--){
        cin>>n>>k;
        string s;
        cin>>s;
        ctHash(s);
        unordered_map<pair<ll,ll> ,ll, hash_pair>mp;
        ll ct=0;
        for(ll i=k-1;i<n;i++){
            ll val=preHash[i];
            ll val2=preHash2[i];
            if(i>=k){
                val=val-(preHash[i-k]*basePow[k])%mod;
                val2=val2-(preHash2[i-k]*basePow2[k])%mod2;
            }
            if(val<0)val+=mod;
            if(val2<0)val2+=mod2;
            if(!mp[{val,val2}]){
                mp[{val,val2}]++;
                ct++;
            }
        }
        cout<<ct<<"\n";
    }
    return 0;
}