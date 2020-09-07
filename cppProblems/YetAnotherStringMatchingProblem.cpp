#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
// MOD-1 needs to be a multiple of MAXN !!
// big mod and primitive root for NTT:
#define MOD 2305843009255636993
#define RT 5
using namespace std;
typedef long long int ll;
// struct for FFT, for NTT is simple (ll with mod operations)
struct CD {  // or typedef complex<double> CD; (but 4x slower)
	double r,i;
	CD(double r=0, double i=0):r(r),i(i){}
	double real()const{return r;}
	void operator/=(const int c){r/=c, i/=c;}
};
CD operator*(const CD& a, const CD& b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const double pi=acos(-1.0); // FFT
const int MAXN=1<<18;
CD cp1[MAXN+9],cp2[MAXN+9];  // MAXN must be power of 2 !!
int R[MAXN+9];
ll g[125005][10];
int cnt[10];
int visited[10];
//CD root(int n, bool inv){ // NTT
//	ll r=pm(RT,(MOD-1)/n); // pm: modular exponentiation
//	return CD(inv?pm(r,MOD-2):r);
//}
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		double z=2*pi/m*(inv?-1:1); // FFT
		CD wi=CD(cos(z),sin(z)); // FFT
		// CD wi=root(m,inv); // NTT
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv)fore(i,0,n)a[i]/=n; // FFT
	//if(inv){ // NTT
	//	CD z(pm(n,MOD-2)); // pm: modular exponentiation
	//	fore(i,0,n)a[i]=a[i]*z;
	//}
}
void multiply(vector<int>& p1, vector<int>& p2,vector<int>& res){
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
	n-=2;
	fore(i,0,n)res[i]=(ll)floor(cp1[i].real()+0.5); // change for NTT
}
void dfs(int &pos,int &node){
	visited[node]=1;
	fore(k,0,6){
		if(!visited[k] && (g[pos][node]&(1<<k))){
			dfs(pos,k);
		}
	}
}
int main(){FIN;
	string S,T;
	cin >> S >> T;
	vector<vector<int>> P(6,vector<int> (S.size(),0));
	vector<vector<int>> Q(6,vector<int>(T.size(),0));
	fore(i,0,6){
		fore(k,0,S.size()){
			if(S[k]-'a'==i){
				P[i][k]=1;
			}else{
				P[i][k]=0;
			}
		}
		fore(k,0,T.size()){
			if(T[k]-'a'==i){
				Q[i][T.size()-1-k]=1;
			}else{
				Q[i][T.size()-1-k]=0;
			}
		}
	}
	vector<int> ans(S.size()+T.size()-1,0);
	fore(i,0,6){
		fore(j,0,6){
			if(i!=j){
				multiply(P[i],Q[j],ans);
				fore(k,0,S.size()-T.size()+1){
					if(ans[k+T.size()-1]>0){
						g[k][i]|=(1<<j);
						g[k][j]|=(1<<i);
					}
				}
			}
		}
	}
	fore(i,0,T.size()){
		cnt[T[i]-'a']++;
		cnt[S[i]-'a']++;
	}
	fore(i,0,S.size()-T.size()+1){
		if(i){
			cnt[S[i-1]-'a']--;
			cnt[S[i-1+T.size()]-'a']++;
		}
		int comps=0;
		int total=0;
		fore(j,0,6)visited[j]=0;
		fore(j,0,6){
			if(cnt[j]>0){
				total++;
				if(!visited[j]){
					comps++;
					dfs(i,j);
				}
			}
		}
		if(i==S.size()-T.size()){
			cout << total-comps << "\n";
		}else{
			cout << total-comps<<" ";
		}
	}
    return 0;
}
