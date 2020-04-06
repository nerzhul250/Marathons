#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

typedef __int128 ll;

const int INF=1e9;
const int length=100;
const ll zero=0;

int N;
int m;
int dp[length+5][100005][5];
int minOnes(int i, int rem, int toSum,int thereIsOne){
	if(i==length && rem==0 && thereIsOne)return dp[i][rem][thereIsOne]=0;
	if(i==length && (rem!=0 || !thereIsOne))return dp[i][rem][thereIsOne]=INF;
	if(dp[i][rem][thereIsOne]!=-1)return dp[i][rem][thereIsOne];
	return dp[i][rem][thereIsOne]=min(minOnes(i+1,(rem+toSum)%m,(toSum*2)%m,1)+1,
									  minOnes(i+1,rem,(toSum*2)%m,thereIsOne));
}


vector<ll> printIndices(int i, int rem, int toSum,int thereIsOne,vector<ll> &indices,ll power){
	long long int toPrint=indices[0];
	cout << toPrint << endl;
	if(indices[0]<zero){
		indices[0]=1e30;
		return indices;
	}
	if(i==length)return indices;
	if(dp[i][rem][thereIsOne]==dp[i+1][(rem+toSum)%m][1]+1 && dp[i][rem][thereIsOne]==dp[i+1][rem][thereIsOne]){
		vector<ll> aux1=indices;
		aux1.pb(i);
		aux1[0]+=power;
		vector<ll> indices1=printIndices(i+1,(rem+toSum)%m,(toSum*2)%m,1,aux1,power*2);
		vector<ll> indices2=printIndices(i+1,rem,(toSum*2)%m,thereIsOne,indices,power*2);
		if(indices1[0]<indices2[0]){
			return indices1;
		}else{
			return indices2;
		}
	}else if(dp[i][rem][thereIsOne]==dp[i+1][(rem+toSum)%m][1]+1){
		indices.pb(i);
		indices[0]+=power;
		return printIndices(i+1,(rem+toSum)%m,(toSum*2)%m,1,indices,power*2);
	}else{
		return printIndices(i+1,rem,(toSum*2)%m,thereIsOne,indices,power*2);
	}
}


int main(){FIN;
	cin >> N;
	fore(i,0,N){
		memset(dp,-1,sizeof dp);
		cin >> m;
		minOnes(0,0,1,0);
		//cout << dp[0][0][0] << endl;
		vector<ll> indices;
		indices.pb(0);
		indices=printIndices(0,0,1,0,indices,1);
		vector<long long int > indices2;
		for(auto x : indices){
			long long int nam=x;
			indices2.pb(nam);
		}
		cout << indices2[0];
		fore(j,1,indices2.size()){
			if(j==SZ(indices2)-1){
				cout << indices2[j] << "\n";
			}else{
				cout << indices2[j] << " ";
			}
		}
	}
    return 0;
}
