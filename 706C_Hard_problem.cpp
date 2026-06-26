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
const ll maa =1e14,mee=-4e4;
string ar[100001];
ll ar2[100001];
ll dp[100001][3];
ll n,m;
ll calc(ll i , ll suc)
{
	if(i==n)
		return 0;
	if(dp[i][suc]!=-1)
		return dp[i][suc];
	
	
	string test="",test2=ar[i];
	reverse(test2.begin(),test2.end());
	if(i)
		test=ar[i-1];
	if(suc==1)
		reverse(test.begin(),test.end());
	ll c1=maa,c2=maa;
	if(suc==2||ar[i]>=test)
		c1=calc(i+1,0);
	if(suc==2||test2>=test)
		c2=ar2[i]+calc(i+1,1);
	//cout << c1 << " " << c2 << " "  << i;
	//print;
	return dp[i][suc]=min(c1,c2);
	
		
}
void solve()
{
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> ar2[i];
	for(ll i=0;i<n;i++)
		cin >> ar[i];
	memset(dp,-1,sizeof(dp));
	ll ans=calc(0,2);
	if(ans!=maa)
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
}