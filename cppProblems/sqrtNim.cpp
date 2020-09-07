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
/*int dp[1000005];
int get_grundy(int n){
	if(n==0)return 0;
	if(dp[n]!=-1)return dp[n];
	int limit=sqrt(n);
	set<int> grundies;
	fore(i,1,limit+1){
		grundies.insert(get_grundy(n-i));
	}
	int ngrundy=0;
	while(grundies.count(ngrundy))ngrundy++;
	return dp[n]=ngrundy;
}*/
int main(){FIN;
	/*memset(dp,-1,sizeof dp);
	fore(i,0,100){
		cout << i<< " "<<get_grundy(i)<<endl;
	}*/
	
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	
	
	ll n;
	cin >> n;
	ll k=sqrt(n);
	list<int> lista;
	lista.pb(0);
	lista.pb(1);
	fore(i,2,k+1){
		lista.pb(i);
		lista.insert(next(lista.rbegin()).base(),*lista.begin());	
		lista.erase(lista.begin());
	}
	vector<int> grundyNumbers;
	auto it=lista.rbegin();
	while(it!=lista.rend()){
		grundyNumbers.pb(*it);
		//cout << *it << endl;
		it=next(it);
	}
	int index=0;
	fore(i,0,n-k*k)index++;
	index%=grundyNumbers.size();
	if(grundyNumbers[index]==0){
		cout << "LOSE\n";
	}else{
		cout << "WIN\n";
	}
    return 0;
}
