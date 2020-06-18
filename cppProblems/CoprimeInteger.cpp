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
const int MAXN=10000005;
short mu[MAXN] = {0,1};
void mobius(){
	fore(i,1,MAXN)if(mu[i])for(int j=i+i;j<MAXN;j+=i)mu[j]-=mu[i];
}
int main(){FIN;
	mobius();
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	ll D=max(b,d);
	ll sum=0;
	fore(i,1,D+1){
		sum+=(mu[i]*((b/i)-((a-1)/i))*((d/i)-((c-1)/i)));
	}
	cout << sum<<"\n";
    return 0;
}
