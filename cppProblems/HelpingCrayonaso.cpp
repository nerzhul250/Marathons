#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
 
const int MAXN=10+1e6;
 
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
  
// Array to store the  
// prime numbers 
vector<ll> primes; 
int cr[MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN){
		if(cr[i]<0){
			primes.pb(i);
			for(ll j=1LL*i*i;j<MAXN;j+=i)cr[j]=i;		
		}
	}
}
bool power_of_prime(ll n) 
{ 
	for(auto i : primes) 
	{  
	   if (n % i == 0) 
	   { 
		   while(n % i == 0) 
		   { 
			   n /= i; 
		   } 
		   if(n == 1)
			  return true; 
		   else
			  return false; 
	   } 
	}
	return false; 
} 
 
int main()
{
	ll n;
	cin >> n;
	if(rabin(n)){
		cout << "YES\n";
		return 0;
	}
	init_sieve();
	for (ll i = 1; i*i <= n; i++){
		ll square = i*i;
		if (n % square == 0){
			ll divided = n / square;
			if(divided==1 && n!=1){
				cout << "YES\n";
				return 0;
			}else{
				if(rabin(divided) || power_of_prime(divided)){
					cout << "YES\n";
					return 0;
				}
			}
		}
	}
	cout << "NO\n";
	return 0;
}
