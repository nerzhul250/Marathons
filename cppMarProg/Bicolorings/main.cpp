#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

int const MOD=998244353;
int dp[1005][2005][5][5];
int n,K;
int ways(int i,int k,int b1,int b2){
    if(k<0)return 0;
    int &r=dp[i][k][b1][b2];
    if(r!=-1){
        return r;
    }
    if(i==n-1){
        if(b1==0 && b2==0){
            r=((k-1==0)+(k-2==0)+(k-2==0)+(k-2==0))%MOD;
        }else if(b1==1 && b2==0){
            r=((k-2==0)+(k-2==0)+(k-4==0)+(k-2==0))%MOD;
        }else if(b1==0 && b2==1){
            r=((k-2==0)+(k-4==0)+(k-2==0)+(k-2==0))%MOD;
        }else if(b1==1 && b2==1){
            r=((k-2==0)+(k-2==0)+(k-2==0)+(k-1==0))%MOD;
        }else if(b1==2 && b2==2){
            r=((k-1==0)+(k-2==0)+(k-2==0)+(k-1==0))%MOD;
        }
    }else{
        if(b1==0 && b2==0){
            r=(((ways(i+1,k,0,0)+ways(i+1,k,1,0))%MOD+ways(i+1,k,0,1))%MOD+ways(i+1,k-1,1,1))%MOD;
        }else if(b1==1 && b2==0){
            r=(((ways(i+1,k-1,0,0)+ways(i+1,k,1,0))%MOD+ways(i+1,k-2,0,1))%MOD+ways(i+1,k-1,1,1))%MOD;
        }else if(b1==0 && b2==1){
            r=(((ways(i+1,k-1,0,0)+ways(i+1,k-2,1,0))%MOD+ways(i+1,k,0,1))%MOD+ways(i+1,k-1,1,1))%MOD;
        }else if(b1==1 && b2==1){
            r=(((ways(i+1,k-1,0,0)+ways(i+1,k,1,0))%MOD+ways(i+1,k,0,1))%MOD+ways(i+1,k,1,1))%MOD;
        }else if(b1==2 && b2==2){
            r=(((ways(i+1,k,0,0)+ways(i+1,k,1,0))%MOD+ways(i+1,k,0,1))%MOD+ways(i+1,k,1,1))%MOD;
        }
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
     freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    cin >> n >> K;

    for(int i=0;i<1005;i++){
        for(int j=0;j<2005;j++){
            for(int l=0;l<5;l++){
                for(int m=0;m<5;m++){
                    dp[i][j][l][m]=-1;
                }
            }
        }
    }

    cout << ways(0,K,2,2)<<endl;

    return 0;
}
