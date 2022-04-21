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
// Problem	: Building Roads
// Contest	: CSES - CSES Problem Set
// URL		: https://cses.fi/problemset/task/1666/
// Memory Limit : 512 MB
// Time Limit	: 1000 ms

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MX 200010

ll node,edge;
vector<ll>adj[MX];
bool visited[MX];
bool idxOne=false;

void init()
{
	for(ll i=0;i<MX;i++){
		adj[i].clear();
		visited[i]=false;
	}
}

void unDirEdge(ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<ll>comp[MX];
void compDFS(ll s,ll idx) {
    visited[s]=true ;
    comp[idx].push_back(s);
    for (auto u:adj[s]) {
        if (!visited[u]){
        	visited[u]=true ;
            compDFS(u,idx);
        }
    }
}

ll conComp(){
	for(ll i=0;i<MX;i++)comp[i].clear();
	ll ctComp=0;
    ll idx_st=0,idx_end=node;
    if(idxOne)idx_st++,idx_end++;
    for(ll i=idx_st;i<idx_end;i++){
        if(!visited[i]){
            compDFS(i,ctComp);
            ctComp++;
        }
    }
    return ctComp;
}

int main(){
	init();
	cin>>node>>edge;
	idxOne=true;
	ll a,b;
	for(ll i=1;i<=edge;i++){
		cin>>a>>b;
		//cout<<"Ck\n";
		unDirEdge(a,b);
	}
	
	ll len=conComp();
	ll ans=len-1;
	cout<<ans<<"\n";
	a=comp[0][0];
	if(len>1){
		for(ll i=1;i<len;i++){
			b=comp[i][0];
			cout<<a<<" "<<b<<"\n";
		}
	}
	return 0;
}
