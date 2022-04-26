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
// Problem	: Just another Robbery
// Contest	: LightOJ
// URL		: https://lightoj.com/problem/just-another-robbery
// Memory Limit : 64 MB
// Time Limit	: 2000 ms


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<double>probs;
vector<ll>money;
ll n;
double prob;
ll maxMoney=0;

void nextProb(double preProb, ll preMoney, ll idx){
	//cout<<"idx: "<<idx<<endl;
	if(idx>=n)return;
	double newProb=((double)1-preProb)*probs[idx];
	newProb+=preProb;
	if(newProb<=prob){
		ll newMoney=preMoney+money[idx];
		maxMoney=max(maxMoney,newMoney);
		nextProb(newProb,newMoney,idx+1);
	}
	if(preProb<=prob)nextProb(preProb,preMoney,idx+1);
}

int main(){
	ll t;
	cin>>t;
	for(ll T=1;T<=t;T++){
		probs.clear();
		money.clear();
		cin>>prob>>n;
		for(ll i=0;i<n;i++){
			ll a;
			double b;
			cin>>a>>b;
			money.push_back(a);
			probs.push_back(b);
		}
		//cout<<"I'm ok";
		//cout<<endl;
		nextProb((double)0,0,0);
		cout<<"Case "<<T<<": "<<maxMoney<<endl;
	}
	return 0;
}