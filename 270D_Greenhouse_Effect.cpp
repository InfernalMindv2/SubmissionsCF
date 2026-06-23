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
 
 
bool isValid(vector<ll>&ar , char x,ll index)
{
	vector<char>pre =  {'a', 'A', 'b', 'c', 'H', 'y'};
	bool suc=0;
	for(ll i=0;i<6;i++)
	{
		if(pre[i]==x)
		{
			suc=1;
			break;
		}
	}
	//cout << suc << " " << ar[x-'a'];
	//print;
	return (!suc)|| (suc&&(ar[x]+1<=1));
}
 
 
 
ll t1=1;
const int oo =0x3f3f3f3f;
int dx[] ={1,0}
,dy[] = {0,1};
ll n,k;
ll dp[5002][5002];
 
ll calc(vector<pair<ll,double>>&ar , ll i , ll prev)
{
	//cout << "a7a";
	if(i>n)
		return 0;
	if(dp[i][prev]!=-1)
		return dp[i][prev];
	
	ll c1=0,c2=0;
	c1=calc(ar,i+1,prev);
	if(ar[i].first>=prev)
		c2=(1+calc(ar,i+1,ar[i].first));
	//cout << c1 << " " << c2 << " " << i;
	//print;
	return dp[i][prev]=max(c1,c2);
}
void solve()
{
	cin >> n >> k;
	memset(dp,-1,sizeof(dp));
	vector<pair<ll,double>>ar(n+1);
	for(ll i=1;i<=n;i++)
		cin >> ar[i].first >> ar[i].second;
	
	cout << n - calc(ar,1,0);
	
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