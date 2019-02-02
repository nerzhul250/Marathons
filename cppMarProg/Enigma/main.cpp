#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAX_N=1000;
int N,dp[MAX_N+5][MAX_N+5];
char c[MAX_N+5];
string s;
int f(int i,int m){
    if(dp[i][m]!=-1)return dp[i][m];
    if(i==s.length()){if(m==0){return 1;}else{return 0;}}
    if(c[i]=='?'){
        int found=0;
        for (int j=0;j<=9 && found==0;j++){
            if(i==0 && j==0)continue;
            found=f(i+1,(m*10+j)%N);
            if(found==1){c[i]=j+'0';}
        }
        dp[i][m]=found;
        return dp[i][m];
    }else{
        dp[i][m]=f(i+1,(m*10+(c[i]-'0'))%N);
        return dp[i][m];
    }
}
int main()
{
    while(cin >> s >> N){
        strcpy(c, s.c_str());
        memset(dp,-1,sizeof dp);
        int val=f(0,0);
        if(val==1){
            printf("%.*s\n",s.length(),c);
        }else{
            printf("%c\n",'*');
        }
    }
    return 0;
}
