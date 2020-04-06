#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

int n;
int rows[20],columns[20];
char theSudoku[20][20];

bool check(int i,int j,int val){
	char up=theSudoku[i*2-1][j*2];
	int upnum=theSudoku[i*2-2][j*2]-'0';
	char left=theSudoku[i*2][j*2-1];
	int leftnum=theSudoku[i*2][j*2-2]-'0';
	
	return (rows[i]!=(rows[i]|(1<<(val-1)))) && 
		   (columns[j]!=(columns[j]|(1<<(val-1)))) &&
		   (i?(up=='v'?upnum>val:(up=='^'?upnum<val:true)):true) &&
		   (j?(left=='<'?leftnum<val:(left=='>'?leftnum>val:true)):true);
}

bool check2(int i,int j,int val){
	char up=theSudoku[i*2-1][j*2];
	int upnum=theSudoku[i*2-2][j*2]-'0';
	char left=theSudoku[i*2][j*2-1];
	int leftnum=theSudoku[i*2][j*2-2]-'0';
	return (i?(up=='v'?upnum>val:(up=='^'?upnum<val:true)):true) &&
		   (j?(left=='<'?leftnum<val:(left=='>'?leftnum>val:true)):true);
}

bool solve(int y,int x){
	if(y==2*n)return true;
	if(theSudoku[y][x]=='-'){
		fore(i,1,n+1){
			if(check(y/2,x/2,i)){
					theSudoku[y][x]=i+'0';
					rows[y/2]|=(1<<(i-1));
					columns[x/2]|=(1<<(i-1));
					if(solve((x+2==2*n?y+2:y),(x+2)%(2*n))){
						return true;
					}else{
						rows[y/2]^=(1<<(i-1));
						columns[x/2]^=(1<<(i-1));
					}						
			}			
		}			
		theSudoku[y][x]='-';
	}else{
		if(check2(y/2,x/2,theSudoku[y][x]-'0')){
			if(x+2==2*n)y+=2;
			return solve(y,(x+2)%(2*n)); 
		}else{
			return false;
		}
	}
	return false;
}

int main(){FIN;
	cin >> n;
	fore(i,0,2*n-1){
		fore(j,0,2*n-1){
			cin >> theSudoku[i][j];
			if(theSudoku[i][j]>='1' && theSudoku[i][j]<='9'){
				rows[i/2]^=(1<<(theSudoku[i][j]-'1'));
				columns[j/2]^=(1<<(theSudoku[i][j]-'1'));
			}
		}
	}
	solve(0,0);
	for(int i=0;i<2*n-1;i+=2){
		for(int j=0;j<2*n-1;j+=2){
			cout << theSudoku[i][j];
		}
		cout << "\n";
	}
    return 0;
}
