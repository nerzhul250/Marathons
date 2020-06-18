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
int powers[10]={1,3,9,27,81,243,729,2187,6561,19683};
int dec2The[59054][15];
ll dp[25][59054];
ll cnt(ll n){
	n++;
	string s=to_string(n);
	ll sum=0;
	int mask=0;
	fore(i,0,s.size()){
		int p=s.size()-i-1;
		int limit=s[i]-'0';
		fore(k,(i?0:1),limit){
			if(dec2The[mask][k]<2){
				sum+=dp[p][mask+powers[k]];
			}
		}
		if(dec2The[mask][limit]==2){
			break;
		}else{
			mask+=powers[limit];
		}
	}
	fore(i,1,s.size()){
		int p=s.size()-i-1;
		fore(k,1,10){
			sum+=dp[p][powers[k]];
		}
	}
	return sum;
}
int main(){FIN;
	freopen("exchange.in","r",stdin);
	freopen("exchange.out","w",stdout);
	fore(msk,0,59049){
		dp[0][msk]=1;
		int aux=msk;
		fore(i,0,10){
			dec2The[msk][i]=aux%3;
			aux-=(aux%3);
			aux/=3;
		}
	}
	fore(i,1,20){
		fore(msk,0,59049){
			fore(k,0,10){
				if(dec2The[msk][k]<2){
					//assert(msk+powers[k]<59049);
					dp[i][msk]+=dp[i-1][msk+powers[k]];
				}
			}
		}
	}
	ll l,r;
	cin >> l >> r;
	cout << cnt(r)-cnt(l-1)<<"\n";
    return 0;
}
