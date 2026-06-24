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
ll n,m,k;
ll dp[200][200][200];
const ll maa= 4e12;
ll calc(vector<ll>&ar ,vector<vector<ll>>&ar2,
 ll i , ll prev , ll si)
{
	if(i>n)
	{
		if(k==si)
			return 0;
		else
			return maa;
	}
	if(dp[i][prev][si]!=-1)
		return dp[i][prev][si];
	
	ll c1=maa;
	if(ar[i]==0)
	{
		for(ll j=1;j<=m;j++)
		{
			//cout << i << " " << j << " " << prev;
			//print;
			if(j!=prev)
			c1=min(c1,ar2[i][j]+calc(ar,ar2,i+1,j,si+1));
			else
			c1=min(c1,ar2[i][j]+calc(ar,ar2,i+1,j,si));
		}
	}
	else
	{
		//cout << i << " " << ar[i] << " " << prev << "!";
		//print;
		if(ar[i]!=prev)
		c1=min(c1,calc(ar,ar2,i+1,ar[i],si+1));
		else
			c1=min(c1,calc(ar,ar2,i+1,prev,si));
	}
	//cout << i << " "<< c1 << " " << si;
	//print;
	return dp[i][prev][si]=c1;
}
void solve()
{
	cin >> n >>m >>k;
	memset(dp,-1,sizeof(dp));
	vector<vector<ll>>ar2(n+1,vector<ll>(m+2));
	vector<ll>ar(n+1);
	for(ll i=1;i<=n;i++)
		cin >> ar[i];
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			cin >> ar2[i][j];
			
	
	
	ll mn=calc(ar,ar2,1,150,0);
	if(mn>=maa)
		cout << -1;
	else
		cout << mn;
	
	
}
//2
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