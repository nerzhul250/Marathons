#include <iostream>
#include <algorithm>
#include <iomanip>
#include <bits/stdc++.h>
//#include <fstream>

using namespace std;
double dp[10005][125][12];
int N,inf[10005][7];
double f(int i,int l,int v){
    if(i>=N){return 0;};
    if(l<=0 || v==1){
        int ele=(120-inf[i][1])<=0?0:120-inf[i][1];
        if(dp[i+1][ele][2]+1>0.001)return inf[i][0]+dp[i+1][ele][2];
        dp[i+1][ele][2]=f(i+1,ele,2);
        return inf[i][0]+dp[i+1][ele][2];
    }else{
        double f1,f2;
        int dur1=(l-inf[i][1])<=0?0:l-inf[i][1], dur2=(120-inf[i][1])<=0?0:120-inf[i][1];
        int v1=(v+1)==7?1:v+1,v2=2;
        if(dp[i+1][dur1][v1]+1>0.001){
            f1=dp[i+1][dur1][v1];
        }else{
            dp[i+1][dur1][v1]=f(i+1,dur1,v1);
            f1=dp[i+1][dur1][v1];
        }
        if(dp[i+1][dur2][v2]+1>0.001){
            f2=dp[i+1][dur2][v2];
        }else{
            dp[i+1][dur2][v2]=f(i+1,dur2,v2);
            f2=dp[i+1][dur2][v2];
        }
        if(v==2){
            return min(f1+0.5*inf[i][0],f2+inf[i][0]);
        }else{
            return min(f1+0.25*inf[i][0],f2+inf[i][0]);
        }
    }
}
int main()
{
    memset(dp,-1,sizeof dp);
    int D,C;
//    ifstream inFile;
//    inFile.open("E:\\DATA\\ImportantFiles\\ProgrammingStuff\\Competitive programming\\cppMarProg\\randomTestGenerator\\tests.txt");
//    inFile >> N;
    scanf("%d",&N);
//    cin >>N;
    for (int i=0;i<N;i++){
        scanf("%d %d",&D,&C);
//          inFile >> D >> C;
//          cin >> D >> C;
          inf[i][0]=C;
          inf[i][1]=D;
    }
//
//    cout << setprecision(2) << fixed;
//    cout << f(0,0,1)<<'\n';
      printf("%.2f\n",f(0,0,1));
    return 0;
}
