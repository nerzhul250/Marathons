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
const ll mod=7+1e9;
ll dp[1000005];
ll inv[1000005];
ll cat(int n){
	if(n==1)return 1;
	if(dp[n]!=0)return dp[n];
	ll ans=2*cat(n-1)*(2*n-1);
	ans%=mod;
	ans=(ans*inv[n+1])%mod;
	return dp[n]=ans;
}
int main(){FIN;
	inv[1] = 1;
	for(int i = 2; i < 1000010; ++i)inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
	stack<int> seq;
	int N;
	cin >>N;
	ll ans=1;
	fore(i,0,N){
		int num;
		cin >> num;
		while(!seq.empty() && seq.top()>num){
			int rep=seq.top();
			seq.pop();
			int cnt=1;
			while(!seq.empty() && rep==seq.top()){
				cnt++;
				seq.pop();
			}
			ans*=cat(cnt);
			ans=ans%mod;
		}
		seq.push(num);	
	}	
	while(!seq.empty()){
		int rep=seq.top();
		seq.pop();
		int cnt=1;
		while(!seq.empty() && rep==seq.top()){
			cnt++;
			seq.pop();
		}
		ans*=cat(cnt);
		ans=ans%mod;
	}
	cout << ans << "\n";
    return 0;
}
