#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)
using namespace std;

typedef long long int ll;

map<ll,ll> holesToIndex;
ll last,first;

ll patches[2];
vector<ll> dp;
vector<int> visited;
vector<ll> holes;

ll dfs(ll st){

    if(st >= last) return 0;

    int index = holesToIndex[st];
    if(visited[index]) return dp[index];
    ll minx = 1e18;
    fore(i,0,2){
        if(holesToIndex.upper_bound(st+patches[i]) == holesToIndex.end()){
            minx = min(dfs(holesToIndex.upper_bound(st+patches[i]) -> first)+patches[i],minx);
        }else if(holesToIndex.upper_bound(st+patches[i]) -> first == last){
            if(st+patches[i] == last){
                minx = min(dfs(holesToIndex.upper_bound(st+patches[i]) -> first)+patches[i],minx);
            }else{
                minx= min(dfs(holesToIndex.upper_bound(st+patches[i]) -> first)+patches[i]+patches[0],minx);
            }
        }else{
             minx = min(dfs(holesToIndex.upper_bound(st+patches[i]) -> first)+patches[i],minx);
        }


    }
    visited[index] = 1;
    dp[index] = minx;
    return minx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N,C,T1,T2; cin>>N>>C>>T1>>T2;
    visited.resize(N);
    dp.resize(N);
    if(T1> T2){
        swap(T1,T2);
    }
    patches[0] = T1;
    patches[1] = T2;

    fore(i,0,N){
        ll h; cin>>h;
        holesToIndex[h] = i;
        if(i == 0) first = h;
        if(i== N-1){
            last = h;
        }
        holes.pb(h);
    }

    ll res = dfs(first);
    dp.clear();
    visited.clear();

    dp.resize(N);
    visited.resize(N);
    map<ll,ll> newIndexes;
    vector<ll> newVals;
    newVals.pb(0);
    newVals.pb(C-last+first);
    ll accumms = C-last+first;
    for(int i = N-2;i>=1;i--){
        accumms += holes[i+1]-holes[i];
        newVals.pb(accumms);
    }
    fore(i,0,N){
        newIndexes[newVals[i]] = i;
        if(i == 0) first = newVals[i];
        if(i== N-1){
            last = newVals[i];
        }
    }
    cout<<first<<" "<<last<<endl;
    holesToIndex.clear();
    holesToIndex = newIndexes;
    ll res2= dfs(first);

    cout<<min(res,res2)<<endl;

    return 0;
}
