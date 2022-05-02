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
// Problem	: Binary Simulation
// Contest	: LightOJ
// URL		: https://lightoj.com/problem/binary-simulation
// Memory Limit : 64 MB
// Time Limit	: 2000 ms


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MX = 5e5+7;

ll tree[MX] = { 0 };
ll lazy[MX] = { 0 };
ll arr[MX] = { 0 };

void STLazyInit(){
	for(ll i=0;i<MX;i++){
		tree[i]=0;
		lazy[i]=0;
		arr[i]=0;
	}
}


void STLazyBuild(ll node, ll left, ll right)
{
	if (left ==right) {
		tree[node] = arr[left];
		return;
	}
	ll lc=(node<<1);
	ll rc=((node<<1)|1);
	ll mid=(left+right)/2;
	STLazyBuild(lc, left, mid);
	STLazyBuild(rc, mid+1, right);
	tree[node] = tree[lc] + tree[rc];
}

void STLazyUpdate(ll node, ll left, ll right, ll qLeft, ll qRight)
{
	ll lc=(node<<1);
	ll rc=((node<<1)|1);
	if (lazy[node] != 0) {
		tree[node] = !tree[node];
		if (left != right) {
			lazy[lc] =!(lazy[lc]);
			lazy[rc] =!(lazy[rc]);
		}
		lazy[node] = 0;
	}
	if (left > right || left > qRight || right < qLeft)return;
	if (left >= qLeft && right <= qRight) {
		tree[node] = !tree[node];
		if (left != right) {
			lazy[lc] = !(lazy[lc]);
			lazy[rc] = !(lazy[rc]);
		}
		return;
	}
	ll mid=(left+right)/2;
	STLazyUpdate(lc, left, mid, qLeft, qRight);
	STLazyUpdate(rc, mid+1, right, qLeft, qRight);
	tree[node] = tree[lc] + tree[rc];
}

ll STLazyQuery(ll node, ll left, ll right, ll qLeft, ll qRight)
{
	ll lc=(node<<1);
	ll rc=((node<<1)|1);
	if (left > right || left > qRight || right < qLeft)return 0;
	if (lazy[node] != 0) {
		tree[node] = !tree[node];
		if (left != right) {
			lazy[lc] =!(lazy[lc]);
			lazy[rc] =!(lazy[rc]);
		}
		lazy[node] = 0;
	}
	if (left >= qLeft && right <= qRight)return tree[node];
	ll mid=(left+right)/2;
	ll q1 = STLazyQuery(lc, left, mid, qLeft, qRight);
	ll q2 = STLazyQuery(rc, mid+1, right, qLeft, qRight);
	return q1 + q2;
}

int main() {
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
    	STLazyInit();
    	string s;
    	cin>>s;
    	ll len=s.size();
    	for(ll i=0;i<len;i++){
    		arr[i+1]=s[i]-'0';
    	}
    	STLazyBuild(1, 1, len);
    	ll q;
    	cin>>q;
    	cout<<"Case "<<T<<":"<<endl;
    	for(ll i=0;i<q;i++){
    		cin>>s;
    		ll a,b;
    		if(s=="I"){
    			cin>>a>>b;
    			STLazyUpdate(1, 1, len, a, b);
    		}else{
    			cin>>a;
    			ll ans=STLazyQuery(1, 1, len, a, a);
    			cout<<ans<<endl;
    		}
    	}
    }
    return 0;
}