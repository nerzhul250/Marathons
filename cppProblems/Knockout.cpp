#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
const int MAXN=(1<<9);
double vals[MAXN+5];
int sums[MAXN+5];
double dp[MAXN+5];
int visited[MAXN+5];
int vis;
double goMax(int mask){
	if(mask==0)return 0;
	if(visited[mask]==vis)return dp[mask];
	visited[mask]=vis;
	double expected=0;
	fore(i,1,7){
		fore(j,1,7){
			int sum=i+j;
			double maxExp=0;
			bool gotIn=false;
			for(int s=mask;s;s=(s-1)&mask){
				if(sums[s]==sum){
					gotIn=true;
					double mx=goMax(s^mask);
					if(mx>maxExp){
						maxExp=mx;
					}
				}
			}
			if(gotIn){
				expected+=maxExp/36;
			}else{
				expected+=vals[mask]/36;
			}
		}
	}
	return dp[mask]=expected;
}
double goMin(int mask){
	if(mask==0)return 0;
	if(visited[mask]==vis)return dp[mask];
	visited[mask]=vis;
	double expected=0;
	fore(i,1,7){
		fore(j,1,7){
			int sum=i+j;
			double minExp=1e18;
			bool gotIn=false;
			for(int s=mask;s;s=(s-1)&mask){
				if(sums[s]==sum){
					gotIn=true;
					double mn=goMin(s^mask);
					if(mn<minExp){
						minExp=mn;
					}
				}
			}
			if(gotIn){
				expected+=minExp/36;
			}else{
				expected+=vals[mask]/36;
			}
		}
	}
	return dp[mask]=expected;
}
int main(){FIN;
	cout << fixed;
	cout << setprecision(5);
	fore(mask,0,(1<<9)){
		double sum=0;
		int theOtherSum=0;
		fore(i,0,9){
			if(((1<<i)&(mask))!=0){
				sum*=10;
				sum+=(i+1);
				theOtherSum+=(i+1);
			}
		}
		vals[mask]=sum;
		sums[mask]=theOtherSum;
	}
	string board;
	int a,b;
	cin>>board>>a>>b;
	int mask=0;
	fore(i,0,board.size()){
		int nam=board[i]-'1';
		mask+=(1<<nam);
	}
	vis++;
	bool gotIn=false;
	double minVal=1e18;
	int st=0;
	for(int s=mask;s;s=(s-1)&mask){
		//cout << s <<endl;
		if(sums[s]==(a+b)){
			gotIn=true;
			double mn=goMin(mask^s);
			if(mn<minVal){
				minVal=mn;
				st=s;	
			}
		}
	}
	if(gotIn){
		string dig="";
		fore(i,0,9)if((st&(1<<i))!=0)dig+=to_string(i+1);
		cout <<dig<<" "<<minVal<<"\n";
	}else{
		cout << "-1 "<<vals[mask]<<"\n";
	}
	vis++;
	gotIn=false;
	double maxVal=-1;
	st=0;
	for(int s=mask;s;s=(s-1)&mask){
		if(sums[s]==(a+b)){
			gotIn=true;
			double mx=goMax(mask^s);
			if(mx>maxVal){
				maxVal=mx;
				st=s;
			}
		}
	}
	if(gotIn){
		string dig="";
		fore(i,0,9)if((st&(1<<i))!=0)dig+=to_string(i+1);
		cout <<dig<<" "<<maxVal<<"\n";
	}else{
		cout << "-1 "<<vals[mask]<<"\n";
	}
    return 0;
}
