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
	int T;
	cin >> T;
	while(T--){
		int n,a,b,c,d;
		cin >> n >> a >>b>>c>>d;
		int minimo=n*(a-b);
		int maximo=n*(a+b);
		if(minimo>c+d || maximo<c-d){
			cout << "No\n";
		}else{
			cout << "Yes\n";
		}
	}
    return 0;
}
