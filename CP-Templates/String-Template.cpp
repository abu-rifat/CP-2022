#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//String to Integer Multiplication OK
string bigMul(string str, ll num)
{
    ll len=str.size();
    ll carry=0;
    ll val=0;
    ll neg=0;
    if(len>0){
        if(str[0]=='-'){
            neg=1;
            str.erase(0,1);
            len--;
        }
    }
    if(num<0){
        neg=(neg+1)%2;
        num=(-num);
    }
    for(ll i=len-1;i>=0;i--){
        val=num*(str[i]-'0');
        val+=carry;
        carry=val/10;
        val%=10;
        str[i]=(val+'0');
    }
    if(carry){
        while(carry){
            char ch=(carry%10)+'0';
            str=ch+str;
            carry/=10;
        }
    }
    if(neg)str="-"+str;
    return str;
}

//String to Integer Division OK
pair<string,ll>bigDiv(string str, ll num)
{
    ll len=str.size();
    string res="";
    ll rem=0;
    ll neg=0;
    if(len>0){
        if(str[0]=='-'){
            neg=1;
            str.erase(0,1);
            len--;
        }
    }
    if(num<0){
        neg=(neg+1)%2;
        num=(-num);
    }
    for(ll i=0;i<len;i++){
        rem*=10;
        rem+=(str[i]-'0');
        if(rem>=num){
            ll tmp=rem/num;
            res=res+to_string(tmp);
            rem%=num;
        }
    }
    if(neg)res="-"+res;
    return {res,rem};
}

