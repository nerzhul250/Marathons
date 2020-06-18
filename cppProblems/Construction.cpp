#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
vector<int> arr;
int N,M;
int main(){FIN;
	cin >> N >> M;
	fore(i,0,N*M){
		int num;
		cin >> num;
		arr.pb(num);
	}
	reverse(ALL(arr));
	int k=min(N,M);
	int sum=0;
	int next1=4,next2=6;
	int r1=3,r2=2;
	fore(i,0,k*k){
		if(i==0){
			sum+=4*arr[i];
		}else if(i==1){
			sum+=2*arr[i];
		}else if(i==2){
			sum+=2*arr[i];
		}else if(i==3){
			sum+=0;
		}
		if(i==next1){
			sum+=2*arr[i];
			next2=i+r2;
			r2++;
		}else if(i==next2){
			sum+=2*arr[i];
			next1=i+r1;
			r1++;
		}
	}
	int rem=max(N,M)-k;
	int index=k*k;
	fore(i,0,rem){
		sum+=2*arr[index];
		index+=k;
	}
	cout << sum <<"\n";
    return 0;
}
