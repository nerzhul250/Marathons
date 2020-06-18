#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
typedef long long int ll;
ll toDec(string s){
	ll ans=0;
	fore(i,0,s.size()){
		ans*=2;
		ans+=s[i]-'0';
	}
	return ans;
}
string dec2S(ll n,int m){
	string s="";
	while(m){
		s+=to_string(n%2);
		n-=(n%2);
		n/=2;
		m--;
	}
	reverse(ALL(s));
	return s;
}
int main(){FIN;
	int t;
	cin >>t;
	while(t--){
		vector<ll> nums;
		int n,m;
		cin >>n>>m;
		fore(i,0,n){
			string s;
			cin >>s;
			nums.pb(toDec(s));
		}
		nums.pb(-1);
		nums.pb((1LL<<m));
		sort(ALL(nums));
		ll k=((1LL<<m)-n-1)/2;
		ll leftk=0;
		ll rightk=-1;
		fore(i,1,n+2){
			leftk=rightk+1;
			rightk=nums[i]-nums[i-1]+leftk-2;
			//cout << leftk<<" "<<rightk<<endl;
			//cout << nums[i]<<endl;
			//cout << k<<endl;
			if(leftk<=k && k<=rightk){
				ll theNum=nums[i-1]+1+k-leftk;
				cout << dec2S(theNum,m)<<"\n";
				break;		
			}
		}
	}
    return 0;
}
