#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

int toNum(string s){
	int n=0;
	fore(i,0,s.size()){
		if(s[i]=='.')continue;
		n*=10;
		n+=(s[i]-'0');
	}
	return n;
}
int scores[10];
int main(){FIN;
    string s;
    fore(i,0,5){
		cin >> s;
		scores[i]=toNum(s);
	}
	sort(begin(scores),begin(scores)+4);
	if(scores[1]+scores[2]+scores[3]<=3*scores[4]){
		cout << "infinite\n";
	}else if(3*scores[4]-scores[1]-scores[2]<=scores[3] &&3*scores[4]-scores[1]-scores[2]>=scores[0]){
		int x=3*scores[4]-scores[1]-scores[2];
		cout << fixed;
		cout << setprecision(2);
		cout << (x/100.0);
	}else if(scores[0]+scores[1]+scores[2]<=3*scores[4]){
		int x=scores[0];
		cout << fixed;
		cout << setprecision(2);
		cout << (x/100.0);
	}else{
		cout << "impossible\n";
	}
    return 0;
}
