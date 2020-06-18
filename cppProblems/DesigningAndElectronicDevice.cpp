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

ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
struct Frac{
	ll a,b;
	Frac(ll a,ll b): a(a),b(b) {}
	Frac(): a(0),b(1) {}
	Frac mul(Frac f){
		Frac res(a*f.a,b*f.b);
		ll g=gcd(res.a,res.b);
		res.a/=g;
		res.b/=g;
		if(res.a==0){
			res.b=1;
		}
		return res;
	}
	bool greater(Frac f){
		double a1=a;
		double b1=b;
		double a2=f.a;
		double b2=f.b;
		return (a1/b1)>(a2/b2);
	}
};
int main(){FIN;
	int N,K;
	while(cin >> N){
		cin >> K;
		vector<vector<ll>> costs;
		vector<vector<Frac>> probs;
		ll regulators[N+5];
		Frac dp[N+5][K+5];
		fore(i,0,N)cin >> regulators[i];
		fore(i,0,N){
			costs.pb(vector<ll>());
			probs.pb(vector<Frac>());
			costs[i].pb(0);
			probs[i].pb(Frac(0,1));
			fore(j,0,regulators[i]){
				ll a,b,c;
				cin >> a >> b >> c;
				probs[i].pb(Frac(b-a,b));
				costs[i].pb(c);
			}
			regulators[i]++;
		}
		fore(k,0,K+1){
			dp[0][k]=Frac(0,1);
			fore(j,0,regulators[0]){
				if(costs[0][j]<=k && probs[0][j].greater(dp[0][k])){
					dp[0][k]=probs[0][j];
				}
			}
		}
		fore(i,1,N){
			fore(k,0,K+1){
				dp[i][k]=Frac(0,1);
				fore(j,0,regulators[i]){
					if(costs[i][j]<=k && probs[i][j].mul(dp[i-1][k-costs[i][j]]).greater(dp[i][k])){
						dp[i][k]=probs[i][j].mul(dp[i-1][k-costs[i][j]]);
					}
				}
			}
		}
		Frac res(dp[N-1][K].a,dp[N-1][K].b);
		res=Frac(res.b-res.a,res.b);
		res=res.mul(Frac(1,1));
		cout <<res.a<< "/"<<res.b<<"\n";
	}
    return 0;
}
