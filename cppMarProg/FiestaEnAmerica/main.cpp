#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int ll;

int N,M,K;
int matrix[55][12];
ll dp[55][10][1<<14];
ll const MOD=7+1e9;

ll valAssigns(int i, int j, int oldMask, int newMask){
    if(i==M && j==0){
        return 1;
    }
    if(j==0){
        swap(oldMask,newMask);
        newMask=0;
    }
    int theMask=newMask|((oldMask>>(j*2))<<(j*2));
    if(dp[i][j][theMask]!=-1){
        return dp[i][j][theMask];
    }
    ll ways=0;
    int up,left,right,down;
    down=(i<M-1?matrix[i+1][j]:0);
    up=(i!=0?((oldMask>>(j*2))&3)+1:0);
    right=(j<N-1?matrix[i][j+1]:0);
    left=(j>0?((newMask>>((j-1)*2))&3)+1:0);
    if(matrix[i][j]!=0){
        int k=matrix[i][j];
        if(down!=k && up!=k && right!=k && left!=k){
            int theNewMask=newMask|((k-1)<<(j*2));
            ways=valAssigns(i+(j==N-1),(j+1)%N,oldMask,theNewMask);
        }else{
            ways=0;
        }
    }else{
        for(int k=1;k<=K;k++){
            if(down!=k && up!=k && right!=k && left!=k){
                int theNewMask=newMask|((k-1)<<(j*2));
                ways+=valAssigns(i+(j==N-1),(j+1)%N,oldMask,theNewMask);
            }
        }
    }
    if(i!=0)dp[i][j][theMask]=ways%MOD;
    return ways%MOD;
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

    for(int i=0;i<55;i++){
        for(int j=0;j<10;j++){
            for(int m=0;m<(1<<14);m++){
                dp[i][j][m]=-1;
            }
        }
    }

    cin >> N >> M >> K;
    for(int j=0;j<N;j++){
        for(int i=0;i<M;i++){
            char c;
            cin >> c;
            if(c=='-'){
                matrix[i][j]=0;
            }else{
                matrix[i][j]=c-'0';
            }
        }
    }

    cout << valAssigns(0,0,0,0)<<endl;

    return 0;
}
