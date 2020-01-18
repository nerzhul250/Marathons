#include <bits/stdc++.h>

#define push_back pb
#define make_pair mp
#define first ff
#define second ss
#define forn(i,n) for(i=0;i<n;i++)

using namespace std;
int N,arr[105],dp[105][105],cost[105][105];
int gcd(int a,int b){return a==0?b:gcd(b%a,a);}

int minRemoval(int a,int b){
    if((a+1)%N==b)return 0;
    int &r=dp[a][b];
    if(r!=-1)return r;
    int i=(a+1)%N;
    int minimum=1e6;
    while(i!=b){
		int newValue=minRemoval(a,i)+minRemoval(i,b);
		if(newValue<minimum){
			minimum=newValue;
		}
        i=(i+1)%N;
    }
    return r=minimum+cost[a][b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> N){
        if(N==0)break;
        int i,j;
        forn(i,N)cin >> arr[i];
        memset(dp,-1,sizeof dp);
        int minimum=1e6;
        forn(i,N)forn(j,N)cost[i][j]=gcd(arr[i],arr[j]);
        forn(i,N){
            forn(j,N){
                if(i<j){
                    minimum=min(minimum,cost[i][j]+minRemoval(i,j)+minRemoval(j,i));
                }
            }
        }
        cout << minimum << endl;
    }
    return 0;
}
