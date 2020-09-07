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
// struct for FFT, for NTT is simple (ll with mod operations)
struct CD {  // or typedef complex<double> CD; (but 4x slower)
	double r,i;
	CD(double r=0,double i=0):r(r),i(i){}
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
	n-=2;
	p1.clear();
	fore(i,0,n)p1.pb(((ll)floor(cp1[i].real()+0.5))%1009); // change for NTT
}
int N,M,K;
int emes[200005];
vector<int> pols[200005];
struct comp{
    bool operator()(int i, int j){
        return emes[i]<emes[j];
    }
};
int main(){FIN;	
	cin >> N >> M >> K;
	fore(i,0,N){
		int nam;
		cin >> nam;
		nam--;
		emes[nam]++;
	}
	multiset<int, comp> pq;
	fore(i,0,M){
		pols[i]=vector<int>(++emes[i],1);
		pq.insert(i);
	}
	while(pq.size()>1){
		int one=*pq.begin();
		int second=*next(pq.begin());
		pq.erase(pq.begin());
		pq.erase(pq.begin());
		multiply(pols[one],pols[second]);
		emes[one]=pols[one].size();
		pq.insert(one);
	}
	vector<int> ans=pols[*pq.begin()];
	if(ans.size()>=K+1){
		cout << ans[K]%1009<<"\n";
	}else{
		cout << "0\n";
	}
    return 0;
}
