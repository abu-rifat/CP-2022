#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(a) cout<<#a" = "<<a<<"\n"
#define cs(T,val) cout<<"Case "<<T<<": "<<val<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll mod = 1;

void cal_mod(){
    for(ll i=0;i<61;i++){
        mod*=2;
    }
    mod--;
}

ll binpow(ll base, ll power, ll mod)
{
    base%=mod;
    // If mod is prime, power=power%(mod-1);
    ll result=1;
    while(power>0)
    {
        if(power&1)result=(result*base)%mod;
        base=(base*base)%mod;
        power>>=1;
    }
    return result;
}

ll modInv(ll a, ll mod)
{
    return binpow(a,mod-2,mod);
}

ll bigMul(ll a, ll b, ll mod)
{
    if(a==0)return 0;
    ll ans=(2*bigMul(a/2,b,mod))%mod;
    if(a&1)ans=(ans+(b%mod))%mod;
    return ans;
}

vector<ll>fact;
void calFact(ll n, ll mod)
{
    fact.resize(n+1);
    fact[0]=1;
    for(ll i=1; i<=n; i++)
    {
        fact[i]=bigMul(fact[i-1],i,mod);
    }
}

ll nCr(ll n, ll k, ll mod)
{
    if(n<k)return 0;
    ll p_a=fact[n];
    cout<<"p_a "<<p_a<<"\n";
    ll p_b=modInv(fact[k],mod);
    cout<<"p_b "<<p_b<<"\n";
    ll p_c=modInv(fact[n-k],mod);
    cout<<"p_c "<<p_c<<"\n";
    ll ans=bigMul(p_a,p_b,mod);
    cout<<"ans "<<ans<<"\n";
    ans=bigMul(ans,p_c,mod);
    cout<<"ans "<<ans<<"\n";
    return ans;
}

int main() {
    fast;
    cal_mod();
    calFact(50,mod);
    ll t;
    cin>>t;
    ll n,k;
    for(ll T=1; T<=t; T++) {
        cin>>n>>k;
        if(k>n) {
            cs(T,0);
            continue;
        }

        ll ans=nCr(n,k,mod);
        ans=bigMul(ans,ans,mod);
        ans=bigMul(ans,fact[k],mod);
        cs(T,ans);

    }
    return 0;
}
