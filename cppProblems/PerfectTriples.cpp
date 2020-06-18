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
string toBin(ll n){
	string s="";
	while(n){
		s+=to_string(n%2);
		n-=n%2;
		n/=2;
	}
	reverse(ALL(s));
	return s;
}
int main(){FIN;
	int t;
	cin >>t;
	while(t--){
		ll n;
		cin >>n;
		ll k =(n-1)/3;
		ll e=log2(3*k+1)/2;
		ll rem=k-(((1LL<<(2*e))-1)/3);
		ll a=rem+(1LL<<(2*e));
		string A=toBin(a);
		//cout << A<<endl;
		ll b=2,c=3;
		for(int i=1;i<A.size();i+=2){
			b<<=2;
			c<<=2;
			if(A[i]=='0' &&A[i+1]=='1'){
				b+=2;
				c+=3;
			}else if(A[i]=='1' &&A[i+1]=='0'){
				b+=3;
				c+=1;
			}else if(A[i]=='1' &&A[i+1]=='1'){
				b+=1;
				c+=2;
			}
		}
		if((n-1)%3==0){
			cout << a<<"\n";
		}else if((n-1)%3==1){
			cout << b << "\n";
		}else{
			cout << c << "\n";
		}
	}
    return 0;
}

