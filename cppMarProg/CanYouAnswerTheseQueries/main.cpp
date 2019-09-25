#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
int n;
ll arr[50005];
unordered_map<int,ll> dp [50005];
ll smax(int i,int limit){
    if(i==limit)return arr[i];
    if(dp[i].find(limit)!=dp[i].end())return dp[i][limit];
    dp[i][limit]=max(arr[i],arr[i]+smax(i+1,limit));
    int otherLimits=limit+1;
    while(otherLimits<n && arr[otherLimits]<=0){
        int otherIndexes=i;
        while(otherIndexes<otherLimits && (arr[otherIndexes]<=0 || otherIndexes==i)){
            dp[otherIndexes][otherLimits]=dp[i][limit];
            otherIndexes++;
        }
        otherLimits++;
    }
    return dp[i][limit];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M;
    cin >> n;
    for(int i=0;i<n;i++)cin >> arr[i];
    cin >> M;
    vector<ii> queries;
    for(int i=0;i<M;i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        queries.push_back(ii(x,y));
    }
    sort(queries.begin(),queries.end());
    for(int i=0;i<M;i++){
        int x,y;
        x=queries[i].first;
        y=queries[i].second;
        ll maximum=-1e15;
        for(int j=x;j<=y;j++){
            maximum=max(maximum,smax(j,y));
        }
        cout << maximum << "\n";
    }
    return 0;
}
