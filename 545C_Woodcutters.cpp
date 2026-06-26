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
const ll maa =4e9,mee=-4e9;
map<ll,map<ll,ll>>dp;
ll n;
ll calc(vector<pair<ll,ll>>&ar , ll i , ll prev)
{
	if(i>n)
		return 0;
	if(dp.find(i)!=dp.end())
	{
		if(dp[i].find(prev)!=dp[i].end())
			return dp[i][prev];
	}
	ll c1=mee,c2=mee,c3=mee;
	c1=calc(ar,i+1,ar[i].first);
	if(i+1>n || ar[i].first+ar[i].second<ar[i+1].first)
		c2=1+calc(ar,i+1,ar[i].first+ar[i].second);
	if(ar[i].first-ar[i].second>prev)
		c3=1+calc(ar,i+1,ar[i].first);
	//cout << c1 << " " << c2 << " " << c3;
	//print ;
	return dp[i][prev]=max({c1,c2,c3});
		
}
void solve()
{
	cin >> n;
	vector<pair<ll,ll>>ar(n+1);
	for(ll i=1;i<=n;i++)
		cin >> ar[i].first >> ar[i].second;
		
	cout << calc(ar,1,mee);
	
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
       		 //print;	
    }
}