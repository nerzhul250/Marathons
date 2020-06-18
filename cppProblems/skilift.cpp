#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int acum1[100005],acum2[100005],acum[100005];
int main(){FIN;
	int n;
	cin >> n;
	fore(i,0,n){
		int x,y,a;
		cin >> x >> y >> a;
		if(a==1){
			acum1[y]++;
		}else{
			acum2[y]++;
		}
	}
	int ans=0;
	fore(i,0,100000){
		acum[i]+=acum1[i]+acum2[i];
		int temp=acum2[i+1];
		while(acum2[i+1] && acum[i]){
			ans++;
			acum2[i+1]--;
			acum[i]--;
		}
		acum2[i+1]=temp;
		while(acum1[i+1] && acum[i]){
			ans++;
			acum1[i+1]--;
			acum[i]--;
		}
	}
	cout << ans<<"\n";
    return 0;
}
