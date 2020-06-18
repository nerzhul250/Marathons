#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
typedef long long int ll;
ll dp[200005];
int main(){FIN;
	string s;
	cin >> s;
	while(s[0]!='0'){
		dp[0]=1;
		int n=s.size();
		fore(i,1,n+1){
			dp[i]=0;
			if(i>=1){
				int nam=(s[i-1]-'0');
				if(nam>=1 && nam<=9)dp[i]+=dp[i-1];
			}
			if(i>1){
				int nam=(s[i-2]-'0')*10+(s[i-1]-'0');
				if(nam>=10 && nam<=26){
					dp[i]+=dp[i-2];
				}
			}
			//cout << dp[i]<<endl;
		}
		cout << dp[n]<<"\n";
		cin >> s;
	}
    return 0;
}
