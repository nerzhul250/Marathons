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
#define MOD 7340033
#define RT 5
// struct for FFT, for NTT is simple (ll with mod operations)
struct CD {  // or typedef complex<double> CD; (but 4x slower)
	ll x;
	CD(ll x=0):x(x){}
	ll get()const{return x;}
};
CD operator*(const CD& a, const CD& b){
	return CD((a.x*b.x)%MOD);}
CD operator+(const CD& a, const CD& b){return CD((a.x+b.x)%MOD);}
CD operator-(const CD& a, const CD& b){return CD((a.x-b.x+MOD)%MOD);}
const int MAXN=1<<13;
CD cp1[MAXN+9],cp2[MAXN+9];  // MAXN must be power of 2 !!
int R[MAXN+9];
ll pm(ll a, ll b){
	ll res=1;
	while(b){
		if(b&1)res=(a*res)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
CD root(int n, bool inv){ // NTT
	ll r=pm(RT,(MOD-1)/n); // pm: modular exponentiation
	return CD(inv?pm(r,MOD-2):r);
}
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		CD wi=root(m,inv); // NTT
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv){ // NTT
		CD z(pm(n,MOD-2)); // pm: modular exponentiation
		fore(i,0,n)a[i]=a[i]*z;
	}
}
void multiply(vector<int>& p1, vector<int>& p2){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m)cp1[i]=0,cp2[i]=0;
	fore(i,0,p1.size())cp1[i]=p1[i];
	fore(i,0,p2.size())cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	vector<int> res;
	n-=2;
	p1.clear();
	fore(i,0,n)p1.pb(cp1[i].get()); // change for NTT
}
int dp[35][1005];
int main(){FIN;	
	vector<int> P(1001,0);
	P[0]=1;
	P[1]=1;
	dp[0][0]=1;
	fore(i,2,31){
		fore(k,0,P.size())dp[i-1][k]=P[k];
		multiply(P,P);
		multiply(P,P);
		P.insert(P.begin(),1);
		if(P.size()>1001)P.resize(1001);
	}
	int q;
	cin >> q;
	while(q--){
		int n,k;
		cin >> n >> k;
		int height=0;
		while(n&1 && n!=1){
			height++;
			n>>=1;
		}	
		cout << dp[height][k]<<"\n";
	}
    return 0;
}
