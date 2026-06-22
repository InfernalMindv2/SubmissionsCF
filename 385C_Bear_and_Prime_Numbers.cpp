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
//2
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
vector<ll>ar2;
vector<ll> ar(10000002);
void sieve()
{
	ar[0]=1;
	ar[1]=1;
	for(ll i=2;i*i<=10000001;i++)
	{
		if(ar[i]==0)
		{
			for(ll j=i*i;j<=10000001;j+=i)
			{
				if(ar[j]==0)
				{
					ar[j]=1;
				}
			}
		}
	}
	for(ll i=2;i<=10000001;i++)
	{
		if(ar[i]==0)
		{
			ar2.emplace_back(i);
		}
	}
}
 
 
 
 
ll t1=1;
const int oo =0x3f3f3f3f;
int dx[] ={0,0,1,-1}
,dy[] = {1,-1,0,0};
void solve()
{
    ll n,mx=-1;
    cin >> n;
    vector<ll>ele(n);
    for(ll i=0;i<n;i++)
    	cin >> ele[i];
    for(ll i=0;i<n;i++)
    {
    	//cout << ele[i] << " ";
    	mx=max(mx,ele[i]);
    }
    vector<ll>freq(mx+2);
    vector<ll>vis(mx+2);
	//map<ll,vector<ll>>primes;
	ll maxprime=-1;
    vector<vector<ll>>primes(mx+2);
    for(ll i=0;i<n;i++)
    {
    	if(!vis[ele[i]])
    	{
    		vis[ele[i]]=1;
    		ll target = ele[i];
    		for(ll j=0;j<ar2.size() &&ar2[j]*ar2[j]<=target &&ar[target];j++)
    		{
    			if(target%ar2[j]==0)
    			{
    				primes[ele[i]].push_back(ar2[j]);
    				freq[ar2[j]]++;
    				maxprime=max(maxprime,ele[i]);
    			}
    			while(target%ar2[j]==0)
    			{
    				//cout << ar2[j] << " ";
    				//primes[ele[i]].push_back(ar2[j]);
    				//freq[ar2[j]]++;
    				target/=ar2[j];
    			}
    		}
    		if(target>1)
    		{
    			freq[target]++;
    			maxprime=max(maxprime,target);
    			primes[ele[i]].push_back(target);
    			//cout << target << " ";
    		}
    		//print;
    	}
    	else
    	{
    		for(auto it : primes[ele[i]])
    			freq[it]++;
    	}
    }
    for(ll i=1;i<=maxprime;i++)
    {
    	//cout << freq[i] << " ";
    	freq[i]+=freq[i-1];
    }
    //print;
    ll m;
    cin >> m;
    for(ll i=1;i<=m;i++)
    {
    	ll x,y;
    	cin >> x >> y;
    	if(x>maxprime)
    	{
    		cout << 0;
    		print;
    		continue;
    	}
    	y=min(y,maxprime);
    	cout << freq[y] - freq[x-1] ;
    	print;
    }
    
    
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    //Mind();
    //prep();
    sieve();
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