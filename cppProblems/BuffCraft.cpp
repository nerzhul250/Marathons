#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
 
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

int main(){FIN;
	freopen("buffcraft.in","r",stdin);
	freopen("buffcraft.out","w",stdout);
	int b,k,cd,cp; cin>>b>>k>>cd>>cp;
	vector<ii> direct(cd),percen(cp);
	fore(i,0,cd){
		ll a; cin>>a;
		direct[i]={a,i+1};
	}
	fore(i,0,cp){
		ll a; cin>>a;
		percen[i]={a,i+1};
	}
	sort(direct.begin(),direct.end(),greater<ii>());
	sort(percen.begin(),percen.end(),greater<ii>());
	ll base=b, per=100;
	int ck=k;
	int posd=0,posp=0;
	while(ck){
		if(posd<cd){
			base += direct[posd].ff;
			posd++;
			ck--;
		}else if(posp < cp){
			per += percen[posp].ff;
			posp++;
			ck--;
		}else{
			break;
		}
	}
	posd--;
	ll mx = base * per;
	int dmejor=posd;
	int pmejor=posp-1;
	while(posd>=0 && posp < cp){
		ll nbase = base - direct[posd].ff;
		ll nper = per + percen[posp].ff;
		ll nmx = nbase*nper;
		if(nmx >= mx){
			mx=nmx;
			dmejor=posd-1;
			pmejor=posp;
		}
		base = nbase;
		per = nper;
		posd--;
		posp++;
	}
	cout<<dmejor+1<<" "<<pmejor+1<<"\n";
	for(int i = 0; i<=dmejor;i++){
		cout<<direct[i].ss<<" ";
	}
	cout<<"\n";
	for(int i = 0; i<=pmejor;i++){
		cout<<percen[i].ss<<" ";
	}
	cout<<"\n";
	return 0;
}
