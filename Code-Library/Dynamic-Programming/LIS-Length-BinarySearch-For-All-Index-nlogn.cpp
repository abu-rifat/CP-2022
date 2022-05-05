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
// Topic  	: Longest Increasing Subsequence Length for all Index
// Category	: Binary Search
// Complexity	: O(nlogn)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> LISLen(vector<ll>arr){
	vector<ll>emp;
	if(arr.size()==0)return emp;
	vector<ll>tail(arr.size(),0);
	vector<ll>lens(arr.size(),1);
	ll len=1;
	tail[0]=arr[0];
	for(ll i=1;i<(ll)arr.size();i++){
		auto b=tail.begin();
		auto e=tail.begin()+len;
		auto it=lower_bound(b,e,arr[i]);
		if(it==tail.begin()+len){
			tail[len++]=arr[i];
			lens[i]=len;
		}
		else{
			*it=arr[i];
			ll idx=it-tail.begin();
			lens[i]=idx+1;
		}
	}
	return lens;
}

int main(){
	vector<ll>arr{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	vector<ll>ans=LISLen(arr);
    for(ll i=0;i<ans.size();i++){
        cout<<"LIS Length from index 0 to index "<<i<<"(including index "<<i<<" value) is: "<<ans[i]<<endl;
    }
	return 0;
}


