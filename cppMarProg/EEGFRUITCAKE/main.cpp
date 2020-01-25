#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef long long int ll;

int minI[100005];
string cake;
int minIndex(int i){
    if(minI[i]!=-1)return minI[i];
    if(cake[i]=='E'){
        return minI[i]=i;
    }else{
        return minI[i]=minIndex((i+1)%cake.size());
    }
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

    memset(minI,-1,sizeof minI);
    cin >> cake;
    int s;
    cin >> s;
    fore(i,0,cake.size()){
        minIndex(i);
    }

    ll ans=0;

    fore(i,0,cake.size()){
        int elIndex=minI[i];
        if(elIndex<i){

        }else{
            ans+=(s+i-elIndex);
        }
    }
    return 0;
}
