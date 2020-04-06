#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef long long int ll;

vector<ll> nums;
ll N,K;

ll gcd(ll a, ll b){return (a==0?b:gcd(b%a,a));}

ll go(ll prev, ll index, ll mult){
	ll newPrev=(nums[index]*prev)/gcd(nums[index],prev);
	ll toReturn=mult*N/newPrev;
	fore(i,index+1,K){
		toReturn+=go(newPrev,i,mult*-1);
	}
	return toReturn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    fore(i,0,K){
		ll nam;
		cin >> nam;
		nums.pb(nam);
	}
	ll sum=0;
	fore(i,0,K){
		sum+=go(1,i,1);
	}
    cout << N-sum << "\n";
    return 0;
}
