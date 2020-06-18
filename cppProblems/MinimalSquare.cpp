#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >>a>>b;
		int prod=a*b*2;
		int l=sqrt(prod);
		int shortest=2*min(a,b);
		int largest=max(a,b);
		while(l<largest ||l<shortest || l*l<prod){
			l++;
		}
		cout << l*l<<"\n";
	}
    return 0;
}
