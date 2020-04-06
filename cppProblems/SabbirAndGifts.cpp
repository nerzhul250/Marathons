#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef long long int ll;

ll prices[100005];
ll acumPrices[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fore(i,0,n)cin >> prices[i];
	sort(prices,prices+n);
	fore(i,0,n)acumPrices[i]=(i==0?0:acumPrices[i-1])+prices[i];
	vector<ll> v(prices,prices+n);
    int q;
    cin >> q;
    fore(i,0,q){
		int a,b;
		cin >> a >> b;
		auto it1 = lower_bound(v.begin(),v.end(),a);
		auto it2 = upper_bound(v.begin(),v.end(),b);
		int lowerIndex=it1-v.begin();
		int upperIndex=it2-v.begin();
		upperIndex--;
		lowerIndex--;
		cout << (upperIndex==-1?0:acumPrices[upperIndex])-(lowerIndex==-1?0:acumPrices[lowerIndex])<<"\n";
	}    
    return 0;
}
