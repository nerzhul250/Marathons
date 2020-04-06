#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

int cards[1000005];
int main(){FIN;
	int n;
	cin >> n;
	fore(i,0,n)cin >> cards[i];
	int pos1=0,pos2=0,flag=0;
	fore(i,0,n-1){
		if(flag==0 && cards[i]>cards[i+1]){
			pos1=i;
			while(pos1!=0 && cards[pos1-1]==cards[pos1])pos1--;
			flag++;
		}else if(flag==1 && cards[i]<cards[i+1]){
			pos2=i;
			flag++;
		}else if(flag==2 && cards[i]>cards[i+1]){
			flag=-1;
		}
	}
	
	if(flag==1)pos2=n-1;
	
	int aux[n+1];
	fore(i,0,n){
		int index=0;
		if(i>=pos1 && i<=pos2){
			index=pos2-i+pos1;
		}else{
			index=i;
		}
		aux[i]=cards[index];
	}
	
	fore(i,0,n-1){
		if(aux[i]>aux[i+1]){
			flag=-1;
			break;
		}
	}
	
	if(flag==-1){
		cout << "impossible\n";
	}else{
		if(flag==0){
			cout << "1 1\n";
		}else{
			cout << pos1+1 << " "<< pos2+1 << "\n";
		}
	}
	return 0;
}
