#include"bits/stdc++.h"
#include<cstdint>
#define print cout << "\n";
#define ll long long int
#define ull unsigned long long
#define all(v) v.begin(),v.end()
#define sz(v) ((ll)((v).size()))
#define re(a) (a.resize(unique(a.begin(), a.end()) - a.begin()))
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
typedef tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_multiset;
// SOONER OR LATER --> WE GOT EM' THE DREAM <33
// (إِنَّ اللَّهَ وَمَلَائِكَتَهُ يُصَلُّونَ عَلَى النَّبِيِّ ۚ يَا أَيُّهَا الَّذِينَ آمَنُوا صَلُّوا عَلَيْهِ وَسَلِّمُوا تَسْلِيمًا)
/*
https://github.com/InfernalMindv2/CP/blob/main/tips
https://github.com/InfernalMindv2/CP/blob/main/templatecpp
*/
ll gcdd(ll A, ll B)
{
	if(B==0)
		return A;
	else
		return gcdd(B,A%B);
}
ll fast_power(ll base, ll power) {
    ll result = 1;
    base = base % ((ll)998244353);
    while(power > 0) {
 
        if(power % 2 == 1) { 
            result = ((result%((ll)998244353))*(base%((ll)998244353))) %((ll)998244353);
        }
        base = ((base%((ll)998244353)) * (base%((ll)998244353))) %((ll)998244353);
        power = power / 2; 
    }
    return result;
}
void Mind()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
 
}
 
ll t1=1;
const int oo =0x3f3f3f3f;
int dx[] ={1,0}
,dy[] = {0,1};
int knightx[]={-2,-2,1,-1,1,-1,2,2}
,knighty[]={1,-1,-2,-2,2,2,1,-1};
const ll maa =1e16,mee=-4e16;
ll n;
bool suc=1;
void calc(string x, ll index ,ll first, ll second)
{
	if(x!=""&&stoll(x)>1e9)
		return;
	if(index>5)
		return;
	if(x!="")
	{
		ll test=  stoll(x),pro=stoll(x)*n;
		if(pro>1e9 || test>1e9)
			return;
		set<ll>st,st2;
		while(test>0)
		{
			st.insert(test%10);
			test/=10;
		}
		test=pro;
		while(test>0)
		{
			st2.insert(test%10);
			test/=10;
		}
		if(st2.size()<=2&&st.size()<=2 &&stoll(x)>=n&&suc
		&& pro%n==0 && pro/n>1 && pro<1e9)
		{
			suc=0;
			cout << x;
			return;
		}
	}
	if(index==1)
	{
		for(ll i=1;i<=9;i++)
			calc(to_string(i),2,i,-1);
	}
	else if(index==2)
	{
		for(ll i=1;i<=9;i++)
		{
			calc(x+to_string(i),3,first,i);
		}
	}
	else
	{
		set<ll>st,st2;
		for(ll i=0;i<x.size();i++)
			st.insert(x[i]-'0');
		for(ll i=1;i<=9;i++)
		{
			st2=st;
			st2.insert(i);
			string pre = x+to_string(i);
			if(st2.size()<=2 &&stoll(pre)<=1e9)
				calc(x+to_string(i),index+1,first,second);
		}
	}
}
bool isValid(ll x)
{
	ll pre=x;
	set<ll>st;
	while(pre>0)
	{
		st.insert(pre%10);
		pre/=10;
	}
	return (st.size()<=1 || st.find(0)!=st.end());
}
bool isValid2(ll x)
{
	ll pre=x,pro=x*n;
	set<ll>st,st2;
	while(pre>0)
	{
		st.insert(pre%10);
		pre/=10;
	}
	while(pro>0)
	{
		st2.insert(pro%10);
		pro/=10;
	}
	return (st.size()<=2 && st2.size()<=2);
}
map<int,ll>mp;
void solve()
{
	cin >> n;
	string x= to_string(n)+to_string(n);
	cout<< stoll(x)/n;
	
}
// :  1 2 3 4 5 6 7 8 9 
//3 : 3 6 9 2 5 8 1 4 7 0
//4 : 4 8 2 6 0 4 8 2 6 0
//5 : 5 0 5 0 5 0 5 0 5 0
//6 : 6 2 8 4 0 6 2 8 4 0
//7 : 7 4 1 8 5 2 9 6 3 0
//8 : 8 6 4 2 0 8 6 4 2 0
//9 : 9 8 7 6 5 4 3 2 1 0
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    //Mind();
    //prep();
    //sieve();
    //brute();
    ll t=1;
    cin >> t;
    for(t1=1;t1<=t;t1++)
    {
    	solve();
    	 //if(t1<t)
       		 print;	
    }
}