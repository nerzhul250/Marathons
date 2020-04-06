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

ll farm[1005];
ll cowsPerFarm[1005];
ll farmsOnDay[55];
int main(){FIN;
	int C,N,M;
	cin >> C >> N >> M;
	fore(i,0,N){
		cin >> cowsPerFarm[i];
		farm[i]++;
	}
	fore(i,0,51){
		ll sum=0;
		fore(j,0,N)sum+=farm[j];
		farmsOnDay[i]=sum;
		fore(j,0,N){
			cowsPerFarm[j]*=2;
			if(cowsPerFarm[j]>C){
				cowsPerFarm[j]/=2;
				farm[j]*=2;
			}
		}
	}
	fore(i,0,M){
		int day;
		cin >> day;
		cout << farmsOnDay[day] << "\n";
	}
    return 0;
}
