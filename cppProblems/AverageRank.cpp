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

struct Triple{
	double sum;
	int rank;
	int week;
	Triple(){
		sum=0;
		rank=1;
		week=0;
	}
};

int n,w;
double acumRank[300005];
Triple groups[1000005];
int compToScore[300005];

int main(){FIN;
	cin >> n >> w;
	double div=w;
	fore(i,1,w+1){
		int k;
		cin >> k;
		fore(j,0,k){
			int c;
			cin >> c;
			groups[compToScore[c]].sum+=groups[compToScore[c]].rank*((i/div)-(groups[compToScore[c]].week/div));
			groups[compToScore[c]].rank++;
			groups[compToScore[c]].week=i;
			acumRank[c]+=groups[compToScore[c]].sum;
			
			compToScore[c]++;
			
			acumRank[c]-=groups[compToScore[c]].rank*((i/div)-(groups[compToScore[c]].week/div));
			acumRank[c]-=groups[compToScore[c]].sum;
		}
	}
	
	cout << fixed;
	cout << setprecision(9);
	
	fore(i,1,n+1){
		acumRank[i]+=groups[compToScore[i]].rank*(((w+1)/div)-(groups[compToScore[i]].week/div));
		acumRank[i]+=groups[compToScore[i]].sum;
		acumRank[i]-=(1/div);
		cout << acumRank[i] << "\n";
	}
	return 0;
}
