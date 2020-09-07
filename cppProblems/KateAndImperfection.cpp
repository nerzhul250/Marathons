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
typedef pair<int,int> ii;
const int MAXN=500005;
int cr[MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	cr[1]=1;
	fore(i,2,MAXN){
		if(cr[i]<0){
			cr[i]=1;
			for(ll j=1LL*i*i;j<MAXN;j+=i)cr[j]=(cr[j]==-1?i:cr[j]);
		}
	}
}

int main(){FIN;
	init_sieve();
	int n;
	cin >> n;
	vector<ii> nums;
	fore(i,1,n+1){
		if(cr[i]==1){
			nums.pb(ii(1,i));
		}else{
			nums.pb(ii(i/cr[i],i));
		}
	}
	sort(ALL(nums));
	fore(k,0,n-1){
		cout << nums[k+1].ff<<" ";
	}
	cout << "\n";
    return 0;
}
