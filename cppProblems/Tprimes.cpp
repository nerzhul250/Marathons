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

//Our goal is to calculate minimum prime factor lp[i] for every number i in the segment [2;n]. O(n*lglgn)
const int N = 10000000;
int lp[N+1];
vector<int> pr;

int main(){FIN;
	int n;
	cin >> n;	
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)lp[i * pr[j]] = pr[j];
	}
	while(n--){
		ll nam;
		cin >> nam;
		ll mm=sqrt(nam);
		if(nam==1){
			cout << "NO\n";
		}else{
			if(nam==mm*mm && lp[(int)mm]==mm){
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
		}
	}
    return 0;
}
