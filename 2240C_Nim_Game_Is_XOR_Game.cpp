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
void solve()
{
	ll n;
	cin >> n;
	vector<ll>ar(n+2);
	for(ll i=1;i<=n;i++)
		cin >> ar[i];
	
	ll pre=0;
	for(ll i=1;i<=n;i++)
		pre^=ar[i];
	ll ans=0,index=0;
	bool suc=0;
	for(ll i=1;i<=n;i++)
	{
		//cout<< (pre^ar[i]) <<  " " << ar[i];
		//print;
		if((pre^ar[i])<ar[i])
			ans++;
		
	}
	if(n==1)
		cout << 0;
	else
		cout << max(ans,1LL);
	
	
}
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