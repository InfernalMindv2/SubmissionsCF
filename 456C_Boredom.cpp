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
 
ll dp[100001];
ll n,m;
map<ll,ll>mp;
ll calc( ll num)
{
	if(num>100000)
		return 0;
	if(dp[num]!=-1)
		return dp[num];
	ll c1=(mp[num]*num)+calc(num+2)
	,c2 = calc(num+1);
	//cout << c1 << " " << c2;
	//print;
	return dp[num] = max(c1,c2);
}
void solve()
{
	cin >> n;
	vector<ll>ar(n);
	for(ll i=0;i<n;i++)
		cin >> ar[i];
	for(ll i=0;i<n;i++)
		mp[ar[i]]++;
	memset(dp,-1,sizeof(dp));
	for(ll i=100000;i>=1;i--)
	{
		ll take = mp[i] * i + (i + 2 <= 100000 ? dp[i + 2] : 0);
        ll skip = (i + 1 <= 100000 ? dp[i + 1] : 0);
        
        dp[i] = max(take, skip);
	}
	cout << dp[1] << " ";
	
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
       		 print;	
    }
}