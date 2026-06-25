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
const ll maa =4e9;
ll n,d;
ll dp[100001][200];
ll calc(vector<ll>&ar , ll i , ll prev)
{
	if(prev>200)
		prev = ar[i]%prev;
	if(i>n)
		return 0;
	if(dp[i][prev]!=-1)
		return dp[i][prev];
	
	ll c1=0,c2=0;
	c1=calc(ar,i+1,ar[i]);
	
	if(ar[i]>=prev && gcdd(prev,ar[i])>1)
	{
		if(i+1<=n)
		{
			cout << ar[i] << " " << prev;
			print;
			c2=(1+calc(ar,i+1,ar[i]));
		}
		else
			c2=1;
	}
	//cout << c1 << " " << c2 << " " << i;
	//print;
	return dp[i][prev]=max(c1,c2);
}
void solve()
{
	cin >> n;
	memset(dp,-1,sizeof(dp));
	vector<ll>ar(n+1),dx(100001);
	for(ll i=1;i<=n;i++)
		cin >> ar[i];
	for(ll i=1;i<=n;i++)
	{
		set<ll>st;
		ll num=ar[i];
		for(ll j=2;j*j<=num;j++)
		{
			if(num%j==0)
			{
				st.insert(j);
				while(num%j==0)
					num/=j;
			}
		}
		ll cur=1;
		for(auto p : st)
    		cur = max(cur, dx[p] + 1);
	    if(num > 1)
	   	 cur = max(cur, dx[num] + 1);
		for(auto p : st)
   			 dx[p] = max(dx[p], cur);
   		if(num > 1)
        	dx[num] = max(dx[num], cur);
	}
	ll ans=1;
	for(ll i=1;i<=100000;i++)
		ans=max(ans,dx[i]);
	cout << ans;
	
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    //Mind();
    //prep();
    //sieve();
    //brute();
    ll t=1;
    //cin >> t;
    for(t1=1;t1<=t;t1++)
    {
    	solve();
    	 //if(t1<t)
       		 print;	
    }
}