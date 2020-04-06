#include <bits/stdc++.h>
 
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)
 
using namespace std;
 
int vals[5005],acum[5005][5005];
vector<int> dp_before(5005),dp_current(5005);
int N,K;
 
int cost(int i, int j){
	return acum[j][j]-(i==0?0:acum[j][i-1])-(i==0?0:acum[i-1][j])+(i==0?0:acum[i-1][i-1]);
}
 
void dc(int l, int r,int ql,int qr){
	if(l>r)return;
	int mid=(l+r)/2;
	
	int optimalIndex=-1;
	int minimal=1e9;
	for(int i=max(ql,mid);i<=qr;i++){
		int tmp=dp_before[i+1]+cost(mid,i);
		if(tmp<minimal){
			minimal=tmp;
			optimalIndex=i;
		}
	}
	
	dp_current[mid]=minimal;
	dc(l,mid-1,ql,optimalIndex);
	dc(mid+1,r,optimalIndex,qr);
}
 
int main()
{
    scanf("%d%d",&N,&K);
    
    fore(i,0,N)scanf("%d",&vals[i]);
    
    fore(i,0,N)fore(j,i+1,N)if((i<j && vals[i]>vals[j])||(i>j && vals[i]<vals[j]))acum[i][j]=1;
    
    fore(i,1,N)fore(j,0,N)acum[i][j]+=acum[i-1][j];
    
    fore(i,0,N)fore(j,1,N)acum[i][j]+=acum[i][j-1];
    
    fore(i,0,N)dp_before[i]=cost(i,N-1);
    
    dp_current=dp_before;
    
    fore(i,2,K+1){
		dc(0,N-i,0,N-i);
		dp_before=dp_current;	
	}
    
    printf("%d\n",dp_current[0]);
        
    return 0;
}
