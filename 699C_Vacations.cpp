#include"bits/stdc++.h"
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
int dx[] ={-1,0}
,dy[] = {0,-1};
 
ll dp[101][7];
ll n,m;
ll calc(vector<ll>&ar , ll i , ll prev)
{
	if(i==n)
		return 0;
	if(dp[i][prev]!=-1)
		return dp[i][prev];
	
	ll x1=INT_MAX;
	if(ar[i]==0)
	{
		x1=min(x1,1+calc(ar,i+1,0));
	}
	else if(ar[i]==1)
	{
		if(prev!=2)
			x1=min(x1,calc(ar,i+1,2));
		if(prev==2)
			x1=min(x1,1+calc(ar,i+1,0));
	}
	else if(ar[i]==2)
	{
		if(prev!=1)
			x1=min(x1,calc(ar,i+1,1));
		if(prev==1)
			x1=min(x1,1+calc(ar,i+1,0));
	}
	else
	{
		if(prev!=1)
			x1=min(x1,calc(ar,i+1,1));
		if(prev!=2)
			x1=min(x1,calc(ar,i+1,2));
		if(prev==1)
			x1=min(x1,1+calc(ar,i+1,0));
		if(prev==2)
			x1=min(x1,1+calc(ar,i+1,0));
		
	}
	return dp[i][prev]=x1;
}
void solve()
{
	cin >> n;
	vector<ll>ar(n);
	for(ll i=0;i<n;i++)
		cin >> ar[i];
	memset(dp,-1,sizeof(dp));
	cout << calc(ar,0,0);
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
    	 //if(t>=1)
       		 //print;	
    }
}