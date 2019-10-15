#include <iostream>

using namespace std;
int const MAXSIZE=1005;
int dp1[MAXSIZE][MAXSIZE],dp2[MAXSIZE][MAXSIZE];
int m1[MAXSIZE][MAXSIZE],m2[MAXSIZE][MAXSIZE];
int n;
int minNum(int i,int j,int m[MAXSIZE][MAXSIZE],int dp[MAXSIZE][MAXSIZE]){
    int &r=dp[i][j];
    if(r!=-1)return r;
    if(i==n-1 && j==n-1)return r=m[i][j];
    if(i==n-1)return r=m[i][j]+minNum(i,j+1,m,dp);
    if(j==n-1)return r=m[i][j]+minNum(i+1,j,m,dp);
    return r=m[i][j]+min(minNum(i,j+1,m,dp),minNum(i+1,j,m,dp));
}
int getTwos(int num){
    int cnt=0;
    if(num==0)return 1;
    while(num%2==0){
        cnt++;
        num/=2;
    }
    return cnt;
}
int getFives(int num){
    int cnt=0;
    if(num==0) return 1;
    while(num%5==0){
        cnt++;
        num/=5;
    }
    return cnt;
}
void writePath(int i, int j,int dp[MAXSIZE][MAXSIZE],int m[MAXSIZE][MAXSIZE]){
    if(i==n-1 && j==n-1)return ;
    if(i==n-1){
        cout << "R";
        writePath(i,j+1,dp,m);
        return;
    }
    if(j==n-1){
        cout << "D";
        writePath(i+1,j,dp,m);
        return;
    }
    if(dp[i][j]==dp[i+1][j]+m[i][j]){
        cout << "D";
        writePath(i+1,j,dp,m);
        return;
    }
    if(dp[i][j]==dp[i][j+1]+m[i][j]){
        cout << "R";
        writePath(i,j+1,dp,m);
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp1[i][j]=-1;
            dp2[i][j]=-1;
        }
    }
    int thereIsZero=0,i0=-1,j0=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin >> num;
            if(num==0){
                thereIsZero=1;
                i0=i;
                j0=j;
            }
            int twos=getTwos(num);
            int fives=getFives(num);
            m1[i][j]=twos;
            m2[i][j]=fives;
        }
    }

    int min1=minNum(0,0,m1,dp1);
    int min2=minNum(0,0,m2,dp2);

    if(thereIsZero && min(min1,min2)>1){
        cout << "1\n";
        for(int i=0;i<i0;i++){
            cout << "D";
        }
        for(int j=0;j<j0;j++){
            cout << "R";
        }
        for(int i=i0;i<n-1;i++){
            cout << "D";
        }
        for(int j=j0;j<n-1;j++){
            cout << "R";
        }
        cout << "\n";
        return 0;
    }

    if(min1<min2){
        cout << min1 << "\n";
        writePath(0,0,dp1,m1);
        cout << "\n";
    }else{
        cout << min2 << "\n";
        writePath(0,0,dp2,m2);
        cout << "\n";
    }

    return 0;
}
