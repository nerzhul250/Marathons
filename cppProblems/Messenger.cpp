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
typedef pair<char,ll> ii;
vector<int> z_function1(string s) {
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
vector<int> z_function2(vector<ll> &s) {
    int n = (int) s.size();
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
vector<ii> t,s;
int s2num(string str){
	int num=0;
	fore(i,0,str.size()){
		num*=10;
		num+=(str[i]-'0');
	}
	return num;
}
int main(){FIN;
	int n,m;
	cin >> n >> m;
	fore(i,0,n){
		string block;
		cin >> block;
		if(t.size()!=0 && t.back().ff==block[block.size()-1]){
			t.back().ss+=s2num(block.substr(0,block.size()-2));
		}else{
			t.pb(ii(block[block.size()-1],s2num(block.substr(0,block.size()-2))));
		}
	}
	fore(i,0,m){
		string block;
		cin >> block;
		if(s.size()!=0 && s.back().ff==block[block.size()-1]){
			s.back().ss+=s2num(block.substr(0,block.size()-2));
		}else{
			s.pb(ii(block[block.size()-1],s2num(block.substr(0,block.size()-2))));
		}
	}	
	n=t.size();
	m=s.size();
	if(s.size()==1){
		ll cnt=0;
		fore(i,0,t.size()){
			if(t[i].ff==s[0].ff && t[i].ss>=s[0].ss){
				cnt+=(t[i].ss-s[0].ss+1);
			}
		}
		cout << cnt << "\n";
	}else if(s.size()==2){
		int cnt=0;
		fore(i,0,t.size()-1){
			if(t[i].ff==s[0].ff && t[i].ss>=s[0].ss &&
			   t[i+1].ff==s[1].ff && t[i+1].ss>=s[1].ss){
				   cnt++;
			}
		}
		cout << cnt << "\n";
	}else{
		string T="";
		vector<ll> ap;
		fore(i,0,m){
			T+=s[i].ff;
			if(i>0 && i<m-1){
				ap.pb(s[i].ss);
			}
		}
		fore(i,0,n){
			T+=t[i].ff;
			ap.pb(t[i].ss);
		}
		vector<int> z1=z_function1(T);
		vector<int> z2=z_function2(ap);
		int cnt=0;
		fore(i,m,n+m){
			if(z1[i]>=m && t[i-m].ss>=s[0].ss &&
			   t[i-1].ss>=s[s.size()-1].ss &&
			   z2[i-1]>=m-2){
				cnt++;
			}
		}
		cout << cnt<<"\n";
	}
    return 0;
}
