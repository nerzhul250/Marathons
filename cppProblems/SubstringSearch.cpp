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
struct CD {
	double r,i;
	CD(double r=0, double i=0):r(r),i(i){}
	double real()const{return r;}
	void operator/=(const int c){r/=c, i/=c;}
};
CD operator*(const CD& a, const CD& b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const double pi=acos(-1.0);
const int MAXN=1<<19;
CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		double z=2*pi/m*(inv?-1:1);
		CD wi=CD(cos(z),sin(z));
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv)fore(i,0,n)a[i]/=n;
}
vector<double> multiply(vector<CD>& p1, vector<CD>& p2){
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
	vector<double> res;
	n-=2;
	fore(i,0,n)res.pb(cp1[i].real()); // change for NTT
	return res;
}
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
int perm[30];
int cycleSizes[30];
int cycleNum;
int cycleMember[30];
int cycleMemberCnt[30];
int main(){FIN;
	fore(i,0,26){
		cin >> perm[i];
		perm[i]--;
	}
	memset(cycleMember,-1,sizeof cycleMember);
	fore(i,0,26){
		if(cycleMember[i]==-1){
			cycleNum++;
			int current=i;
			int cnt=0;
			while(cycleMember[current]==-1){
				cycleMember[current]=cycleNum-1;
				cycleMemberCnt[current]=cnt;
				cnt++;
				current=perm[current];
			}
			cycleSizes[cycleNum-1]=cnt;
		}
	}
	string s,t;
	cin >> s >> t;
	string frstTest="";
	fore(i,0,s.size()){
		frstTest+=to_string(cycleMember[s[i]-'a']);
	}
	fore(i,0,t.size()){
		frstTest+=to_string(cycleMember[t[i]-'a']);
	}
	vector<int> firstTest=z_function(frstTest);
	vector<CD> P(t.size(),CD(0,0)),Q(s.size(),CD(0,0));
	fore(i,0,t.size()){
		double ang=(pi-2*pi*cycleMemberCnt[t[i]-'a'])/(cycleSizes[cycleMember[t[i]-'a']]);
		P[i]=CD(cos(ang),sin(ang));
	}
	double expected=0;
	fore(i,0,s.size()){
		double ang=(2*pi*cycleMemberCnt[s[i]-'a'])/(cycleSizes[cycleMember[s[i]-'a']]);
		Q[s.size()-1-i]=CD(cos(ang),sin(ang));
		expected+=cos(pi/cycleSizes[cycleMember[s[i]-'a']]);
	}
	vector<double> secondTest=multiply(P,Q);
	fore(i,0,P.size()-Q.size()+1){
		if(firstTest[i+s.size()]>=s.size() && abs(secondTest[i+Q.size()-1]-expected)<=0.01){
			cout << "1";
		}else{
			cout << "0";
		}
	}
	cout << "\n";
    return 0;
}
