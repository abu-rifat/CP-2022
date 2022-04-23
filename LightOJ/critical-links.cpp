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
// Problem	: Critical Links
// Contest	: LightOJ
// URL		: https://lightoj.com/problem/critical-links
// Memory Limit : 64 MB
// Time Limit	: 1000 ms

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MX 200010

ll node,edge;
vector<ll>adj[MX];
bool visited[MX];
bool idxOne=false;
ll timeIn[MX],timeLow[MX];
ll timer;
bitset<MX>AP;
map<pair<ll,ll>,ll>bridge;
vector<ll>apList;
vector<pair<ll,ll> >bridgeList;

void initGraph(){
    for(ll i=0;i<MX;i++){
		adj[i].clear();
		visited[i]=false;
	}
}

void initAPBridge(){
    AP.reset();
    apList.clear();
    bridge.clear();
    bridgeList.clear();
    for(ll i=0;i<MX;i++){
        timeIn[i]=-1;
        timeLow[i]=-1;
    }
}

void init()
{
    initGraph();
    initAPBridge();
}

void unDirEdge(ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void addAP(ll v){
    if(!AP[v]){
        AP[v]=1;
        apList.push_back(v);
    }
}

void addBridge(ll v, ll to){
    if(!bridge[{v,to}]&&!bridge[{to,v}])bridgeList.push_back({v,to});
    bridge[{v,to}]=1;
    bridge[{to,v}]=1;
}

void apBridgeDFS(ll v, ll p=-1){
    visited[v]=true;
    timeIn[v]=timeLow[v]=timer++;
    ll children=0;
    for(ll to:adj[v]){
        if(to==p)continue;
        if(visited[to]){
            timeLow[v]=min(timeLow[v],timeIn[to]);
        }else{
            apBridgeDFS(to,v);
            timeLow[v]=min(timeLow[v],timeLow[to]);
            if(timeLow[to]>=timeIn[v]&&p!=-1)addAP(v);
            if(timeLow[to]>timeIn[v])addBridge(v,to);
            ++children;
        }
    }
    if(p==-1&&children>1)addAP(v);
}

void apBridge(){
    timer=0;
    ll idx_st=0,idx_end=node;
    if(idxOne)idx_st++,idx_end++;
    for(ll i=idx_st;i<idx_end;i++){
        if(!visited[i]){
            apBridgeDFS(i);
        }
    }
}


int main(){
	ll t;
	cin>>t;
	for(ll T=1;T<=t;T++){
		init();
		cin>>node;
		for(ll i=0;i<node;i++){
			ll idx;
			cin>>idx;
			string s;
			cin>>s;
			s.erase(0,1);
			ll len=s.size();
			s.erase(len-1,1);
			len=stoi(s);
			ll u;
			for(ll j=0;j<len;j++){
				cin>>u;
				unDirEdge(idx,u);
			}
		}
		apBridge();
		cout<<"Case "<<T<<":"<<endl;
		ll ans=bridgeList.size();
		cout<<ans<<" critical links"<<endl;
		for(ll i=0;i<ans;i++){
			ll a=bridgeList[i].first;
			ll b=bridgeList[i].second;
			if(a>b)swap(a,b);
			bridgeList[i]={a,b};
		}
		sort(bridgeList.begin(),bridgeList.end());
		for(ll i=0;i<ans;i++){
			ll a=bridgeList[i].first;
			ll b=bridgeList[i].second;
			cout<<a<<" - "<<b<<endl;
		}
	}
	return 0;
}