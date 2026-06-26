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
const ll maa =-1,mee=-4e4;
int ar[200],ar2[200];
int dp[101][200001];
int n,m;
int calc(int i , int diff)
{
	if(i>n)
	{
		if(diff==0)
			return 0;
		else
			return mee;
	}
	if(dp[i][diff+100000]!=-1)
		return dp[i][diff+100000];
	
	int c1=mee,c2=mee;
	c1=calc(i+1,diff+ar[i] - m * ar2[i]);
	if(c1!=mee)
		c1+=ar[i];
	c2=calc(i+1,diff);
	return dp[i][diff+100000]=max(c1,c2);
		
}
void solve()
{
	cin >> n >> m;
	for(ll i=1;i<=n;i++)
		cin >> ar[i];
	for(ll i=1;i<=n;i++)
		cin >> ar2[i];
	memset(dp,-1,sizeof(dp));
	int ans=calc(1,0);
	if(ans>0)
		cout << ans;
	else
		cout << -1;
	
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
}//2