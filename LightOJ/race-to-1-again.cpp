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
// Problem	: Race to 1 Again
// Contest	: LightOJ
// URL		: https://lightoj.com/problem/race-to-1-again
// Memory Limit : 64 MB
// Time Limit	: 1000 ms

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MX 100010

vector<ll>nod;
void nodAll(ll n) {
    nod.resize(n+1);
    nod[0]=0;
    nod[1]=1;
    for(ll i=2; i<=n; i++)
        nod[i]=1;
    for(ll i=2; i<=n; i++) {
        if(nod[i]==1) {
            for(ll j=i; j<=n; j+=i) {
                ll power=0;
                ll val=i;
                while(j%val==0) {
                    power++;
                    val*=i;
                }
                nod[j]*=(power+1);
            }
        }
    }
}

double dp[MX];

void init(){
	for(ll i=0;i<MX;i++)dp[i]=-1;
}

double ctDP(ll n){
	if(dp[n]>=0)return dp[n];
	if(n<=1)return dp[n]=0;
	if(n==2)return dp[n]=2;
	ll prob=(double)1/(double)nod[n];
	double val=prob*(double)nod[n];
	for(ll i=2;i<=sqrt(n);i++){
		if(n%i==0){
			cout<<"I was there: "<<n<<" "<<i<<endl;
			val+=(prob*ctDP(i));
			if((n/i)>i){
				cout<<"I also was there: "<<n<<" "<<n/i<<endl;
				val+=(prob*ctDP(n/i));
			}
		}
	}
	//val/=((double)(nod[n]-1));
	return dp[n]=val;
}

int main(){
	nodAll(MX);
	ll t;
	cin>>t;
	for(ll T=1;T<=t;T++){
		init();
		double ans;
		ll n;
		cin>>n;
		ans=ctDP(n);
		cout<<"Case "<<T<<": "<<ans<<endl;
	}
	return 0;
}