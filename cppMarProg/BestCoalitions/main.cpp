#include <iostream>
#include <unordered_map>
#include <iomanip>
using namespace std;
int participation[105];
int n,x;
unordered_map<int,double> dp[105];

int parsePercentage(string percentage){
    int num=0;
    for(int i=0;i<percentage.size();i++){
        if(percentage[i]=='.')continue;
        num*=10;
        num+=percentage[i]-'0';
    }
    return num;
}

double maximumProfit(int i, int sum){
    if(i==n){
        if(sum>5000){
            double par=participation[x];
            par*=100;
            return par/sum;
        }else{
            return -1;
        }
    }

    if(dp[i].find(sum)!=dp[i].end())return dp[i][sum];

    if(i==x){
        return dp[i][sum]=maximumProfit(i+1,sum);
    }else{
        return dp[i][sum]=max(maximumProfit(i+1,participation[i]+sum),maximumProfit(i+1,sum));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n){
        cin >> x;
        if(n==0 && x==0)break;
        x--;
        for(int i=0;i<n;i++){
            dp[i].clear();
        }
        for(int i=0;i<n;i++){
            string par;
            cin >> par;
            participation[i]=parsePercentage(par);
        }
        cout << fixed;
        cout << setprecision(2);
        cout << maximumProfit(0,participation[x]) << "\n";
    }
    return 0;
}
