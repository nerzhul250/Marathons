#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

int n,k;
double monsters[505];
double acum[505];

double getSum(int l, int r){
	if(l>r){
		return acum[n-1]-(l?acum[l-1]:0)+acum[r];
	}else{
		return acum[r]-(l?acum[l-1]:0);
	}
}
int main(){FIN;
	cin >> n >> k;
	k=n-k;
	fore(i,0,n){
		cin >> monsters[i];
		acum[i]=monsters[i]+(i?acum[i-1]:0);
	}
	vector<double> ans;
	fore(i,0,n){
		if(k==n-1){
			ans.pb(getSum(0,n-1)/n);
		}else{
			double sum=getSum(i,i);
			double multiplier=1;
			fore(c,1,k+1){
				multiplier*=((k-(c-1)+0.0)/(n-(c+1)));
				sum+=(getSum((i-c+n)%n,i)*multiplier);
			}
			sum*=(((n-k)*(n-k-1)+0.0)/((n)*(n-1)));
			ans.pb(sum);
		}
	}
	
	cout << setprecision(9);
	
	fore(i,0,n){
		if(i==n-1){
			cout << ans[i]<<"\n";
		}else{
			cout << ans[i]<<" ";
		}
	}
	return 0;
}
