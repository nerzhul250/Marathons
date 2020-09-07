#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;

class CollisionProbability {
	public:
	double collisionProbability(int,vector<int>);
};

double CollisionProbability::collisionProbability(int num, vector <int> counts) {
	int c=0;
	fore(i,0,counts.size())c+=counts[i];
	double dnum=num;
	double dnumrep=num;
	double res=1;
	fore(i,0,c){
		res*=(dnumrep/dnum);
		dnumrep--;
	}
	return 1-res;
}

int main(){FIN;
	cout << CollisionProbability().collisionProbability(2000000000,{100,150,482,71,349,57,751,673,761,942})<<"\n";
}
