#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int nrm[100005][40],comp[100005][40];
int numeros[100005];
int main(){FIN;
	int n;
	cin >> n;
	fore(i,0,n){
		int a;
		cin >> a;
		numeros[i]=a;
		fore(j,0,32){
			if(((1<<j)&a)!=0){
				nrm[i][j]=1;
			}
		}
		a=~a;
		fore(j,0,32){
			if(((1<<j)&a)!=0){
				comp[i][j]=1+(i?comp[i-1][j]:0);
			}
		}
	}
	int greatest=-1;
	int index=-1;
	fore(i,0,n){
		int result=0;
		fore(j,0,32){
			int sum=nrm[i][j]+(i?comp[i-1][j]:0)+comp[n-1][j]-comp[i][j];
			if(sum==n)result|=(1<<j);
		}
		if(result>greatest){
			index=i;
			greatest=result;
		}
	}
	swap(numeros[0],numeros[index]);
	fore(i,0,n){
		if(i==n-1){
			cout << numeros[i]<<"\n";
		}else{
			cout << numeros[i] << " ";
		}
	}
    return 0;
}

