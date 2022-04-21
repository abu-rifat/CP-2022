#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MX 200010

ll node,edge;
vector<ll>adj[MX];
bool visited[MX];
bool idxOne=false;

//Initiate Containers OK
void init()
{
	for(ll i=0;i<MX;i++){
		adj[i].clear();
		visited[i]=false;
	}
}

//Undirected Edges OK
void unDirEdge(ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//Directed Edges
void dirEdge(ll u, ll v)
{
    adj[u].push_back(v);
}

//DFS to find single CC
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

//Get all CC and number of CC
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
