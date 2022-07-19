#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree{
	vector<ll>tree;
	ll Trush=0;
public:
	SegentTree(int MXSIZ){
		MXSIZ*=4;
		tree.resize(MXSIZ);
	}
	ll combine(ll a, ll b){
		return a+b;
	}
	void build(ll &arr[], ll idx, ll tl, ll tr){
		if(tl==tr)tree[idx]=arr[tl];
		else{
			ll tm=tl+(tr-tl)/2;
			build(arr,idx*2,tl,tm);
			build(arr,idx*2+1,tm+1,tr);
			tree[idx]=combine(tree[idx*2],tree[idx*2+1]);
		}
	}
	ll query(ll idx, ll tl, ll tr, ll l, ll r){
		if(l>r)return Trush;
		if(l==tl&&r==tr)return tree[idx];
		ll tm=tl+(tr-tl)/2;
		return combine(query(idx*2,tl,tm,l,min(r,tm)),query(idx*2+1,tm+1,tr,max(l,tm+1),r));
	}
	void update(ll idx, ll tl, ll tr, ll pos, ll val){
		if(tl==tr)tree[idx]=val;
		else{
			ll tm=tl+(tr-tl)/2;
			if(pos<=tm)update(idx*2,tl,tm,pos,val);
			else update(idx*2+1,tm+1,tr,pos,val);
			tree[idx]=combine(tree[idx*2],tree[idx*2+1]);
		}
	}
};

int main(){
	
	return 0;
}
