#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node,edge;
vector<vector<ll> >adj;
vector<bool>visited;
bool idxOne=false;

void init()
{
    adj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
}

void unDirEdge(ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dirEdge(ll u, ll v)
{
    adj[u].push_back(v);
}

vector<ll>component;
void connCompDFS(ll s) {
    visited[s]=true ;
    component.push_back(s);
    for (auto u:adj[s]) {
        if (!visited[u])
            connCompDFS(u);
    }
}

vector<vector<ll> >connComp(){
    vector<vector<ll> >components;
    for(ll i=0;i<node;i++){
        if(!visited[i]){
            component.clear();
            connCompDFS(i);
            components.push_back(component);
        }
    }
    component.clear();
    return components;
}

