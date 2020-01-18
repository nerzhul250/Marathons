#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef long long int ll;

vector<ll> countFreq(ll A){
	int digits=log10(A)+1;
	vector<ll> ans(10,0);
	fore(i,1,digits+1){
		ll divide=pow(10,i);
		ll divide2=divide/10;
		ll count=A/divide;
		fore(j,0,10){
			ans[j]+=count*divide2;
		}
		ans[0]-=divide2;
		string theNumber=to_string(A);
		int rem=theNumber[digits-i]-'0';
		fore(j,0,rem){
			ans[j]+=divide2;
		}
		ans[rem]+=A-(divide2*(A/divide2))+1;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll A,B;
    while(cin >> A >> B){
		if(A==0)break;
		vector<ll> freqB=countFreq(B);
		vector<ll> freqA=countFreq(A-1);
		fore(i,0,freqB.size()){
			if(i+1!=freqB.size()){
				cout<<freqB[i]-freqA[i]<<" ";
			}else{
				cout<<freqB[i]-freqA[i]<<"\n";
			}
		}
	}
    return 0;
}
