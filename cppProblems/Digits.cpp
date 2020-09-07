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
int times[25];
ll sum[25];
int main(){FIN;
	
	freopen("digits.in","r",stdin);
	freopen("digits.out","w",stdout);
	int n;
	cin >> n;
	fore(i,1,10000000){
		int cnt=0;
		int num=i;
		while(num){
			cnt+=(num%10);
			num/=10;
		}
		if(cnt<21){
			if(times[cnt]==0){
				sum[cnt]+=i;
				times[cnt]=1;			
			}else if(times[cnt]<n){
				sum[cnt]+=i;
				times[cnt]++;
			}
		}
	}
	ll minimo=1e18;
	fore(i,1,21){
		if(times[i]==n){
			minimo=min(minimo,sum[i]);
		}
	}
	cout << minimo<<"\n";
    return 0;
}
