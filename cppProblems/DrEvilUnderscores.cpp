#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

int minmax(int i,vector<int> &a){
	if(i==-1)return 0;
	vector<int> a0;
	vector<int> a1;
	fore(j,0,a.size()){
		if(((1<<i)&a[j])!=0){
			a1.pb(a[j]);
		}else{
			a0.pb(a[j]);
		}
	}
	if(a0.size()==0){
		return minmax(i-1,a1);
	}else if(a1.size()==0){
		return minmax(i-1,a0);
	}else{
		return (1<<i)+min(minmax(i-1,a0),minmax(i-1,a1));
	}
}

int main(){FIN;
	int n;
	cin >> n;
	vector<int> a;
	fore(i,0,n){
		int num;
		cin >> num;
		a.pb(num);
	}
	cout <<minmax(29,a)<<"\n";
    return 0;
}
