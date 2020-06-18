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
ll mulmod(ll a, ll b, ll m) {
	ll r=a*b-(ll)((long double)a*b/m+.5)*m;
	return r<0?r+m:r;
}
ll expmod(ll b, ll e, ll m){
	if(!e)return 1;
	ll q=expmod(b,e/2,m);q=mulmod(q,q,m);
	return e&1?mulmod(b,q,m):q;
}
bool is_prime_prob(ll n, int a){
	if(n==a)return true;
	ll s=0,d=n-1;
	while(d%2==0)s++,d/=2;
	ll x=expmod(a,d,n);
	if((x==1)||(x+1==n))return true;
	fore(_,0,s-1){
		x=mulmod(x,x,n);
		if(x==1)return false;
		if(x+1==n)return true;
	}
	return false;
}
bool rabin(ll n){ // true iff n is prime
	if(n==1)return false;
	int ar[]={2,3,5,7,11,13,17,19,23};
	fore(i,0,9)if(!is_prime_prob(n,ar[i]))return false;
	return true;
}
ll rho(ll n){
	if(!(n&1))return 2;
	ll x=2,y=2,d=1;
	ll c=rand()%n+1;
	while(d==1){
		x=(mulmod(x,x,n)+c)%n;
		y=(mulmod(y,y,n)+c)%n;
		y=(mulmod(y,y,n)+c)%n;
		if(x>=y)d=gcd(x-y,n);
		else d=gcd(y-x,n);
	}
	return d==n?rho(n):d;
}
void fact(ll n, map<ll,int>& f){ //O (lg n)^3
	if(n==1)return;
	if(rabin(n)){f[n]++;return;}
	ll q=rho(n);fact(q,f);fact(n/q,f);
}
void div_rec(vector<ll>& r, vector<pair<ll,int> >& f, int k, ll c){
	if(k==f.size()){r.pb(c);return;}
	fore(i,0,f[k].ss+1)div_rec(r,f,k+1,c),c*=f[k].ff;
}
vector<ll> divisors(vector<pair<ll,int> > f){
	vector<ll> r; // returns divisors given factorization
	div_rec(r,f,0,1);
	return r;
}

int main(){FIN;
	int t;
	cin >>t;
	while(t--){
		ll n,k;
		cin >> n >> k;
		map<ll,int> f;
		fact(n,f);
		vector<pair<ll,int>> d;
		for(auto it=f.begin();it!=f.end();it++){
			d.pb({it->ff,it->ss});
		}
		vector<ll> divi=divisors(d);
		sort(ALL(divi));
		ll maximum=-1;
		fore(i,0,divi.size()){
			if(divi[i]<=k){
				maximum=divi[i];
			}else{
				break;
			}
		}
		cout << n/maximum<<"\n";
	}
    return 0;
}

