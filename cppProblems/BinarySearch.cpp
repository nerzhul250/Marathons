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
const int MAXN=10+1e6;
int cr[MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN)if(cr[i]<0)for(ll j=1LL*i*i;j<MAXN;j+=i)cr[j]=i;
}
int main(){FIN;
	init_sieve();
	cr[1]=0;
	cr[0]=0;
	int a,b,k;
	cin >> a >> b >> k;
	int l=k;
	int r=b-a+1;
	int ans=-1;
	while(l<=r){
		int m=(l+r)/2;
		bool can=true;
		int cnt=0;
		fore(p,a,a+m)if(cr[p]==-1)cnt++;
		if(cnt<k)can=false;
		fore(x,a+1,b+2-m){
			if(cr[x-1]==-1)cnt--;
			if(cr[x+m-1]==-1)cnt++;
			if(cnt<k)can=false;
		}
		if(can){
			r=m-1;
			ans=m;
		}else{
			l=m+1;
		}
	}
	cout << ans << "\n";
    return 0;
}
