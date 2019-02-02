#include <iostream>

using namespace std;

const int MAX=100;

int N,M,arr[MAX][MAX],dp[MAX][MAX][MAX][MAX];
int maxSum(int i,int j,int k,int l){

}
int main()
{
    memset(dp,-1,sizeof dp);
    scanf("%d %d",&N,&M);
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
                int val;
                scanf("%d",&val);
                arr[i][j]=val;
        }
    }
    printf("%d\n",maxSum(0,0,0,0););
}
