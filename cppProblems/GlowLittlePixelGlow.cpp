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
struct wire{
	char type;
	int coor,ending;
};
bool cmp(const wire&a,const wire&b){
	if(a.coor!=b.coor){
		return a.coor<b.coor;
	}else if(a.ending!=b.ending){
		return a.ending<b.ending;
	}else{
		return a.type<b.type;
	}
}
int main(){FIN;
	int n;
	cin >>n;
	vector<wire> wires;
	fore(i,0,n){
		char ty;
		int t,l,a;
		cin >>ty>>t>>l>>a;
		wires.pb({ty,-t-l+a,1});
		wires.pb({ty,-t+a,-1});
	}
	sort(ALL(wires),cmp);
	ll cv=0,ch=0,ans=0;
	for(auto w:wires){
		if(w.type=='h'){
			ch+=w.ending;
			if(w.ending>0){
				ans+=cv;
			}
		}else{
			cv+=w.ending;
			if(w.ending>0){
				ans+=ch;
			}
		}
	}
	cout << ans << "\n";
    return 0;
}
