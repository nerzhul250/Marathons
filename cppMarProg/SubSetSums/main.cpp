#include <iostream>
#include <bits/stdc++.h>#include <unordered_map>

using namespace std;

typedef long long ll;
ll targetSum,arr[45];
int N;
unordered_map<ll, ll> dp [45];

ll ways(int i,ll currentSum,int nonEmpty){
    if(currentSum==targetSum && nonEmpty)return 1;
    if(i>=N)return 0;
    if(dp[i].find(currentSum)!=dp[i].end())return dp[i][currentSum];
    return dp[i][currentSum]=ways(i+1,currentSum+arr[i],1)+ways(i+1,currentSum,nonEmpty);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> N){
        for(int i=0;i<N;i++)dp[i].clear();
        cin >>targetSum;
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        cout << ways(0,0,0)<<"\n";
    }
    return 0;
}
