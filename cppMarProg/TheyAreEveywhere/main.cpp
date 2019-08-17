#include <iostream>
#include <set>

using namespace std;
typedef long long int ll;
int n;
ll k;
string pokemons;
int dp[100005];
int minHouses(int init,int index,ll mask){
    if(dp[init]!=0)return dp[init];
    if(mask==k)return (index-init);
    if(index>=n)return 100000000;

    ll add;
    if(pokemons[index]>='a'){
        add=((ll)1)<<((pokemons[index]-'a')+26);
    }else{
        add=((ll)1)<<(pokemons[index]-'A');
    }

    if((mask&add)==0){
        mask=mask|add;
        dp[init]=minHouses(init,index+1,mask);
    }else{
        dp[init]=min(minHouses(init,index+1,mask),minHouses(index,index+1,add));
    }
    return dp[init];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> pokemons;
    for(int i=0;i<pokemons.size();i++){
        if(pokemons[i]>='a'){
            ll add=((ll)1)<<((pokemons[i]-'a')+26);
            k=k|add;
        }else{
            ll add=((ll)1)<<(pokemons[i]-'A');
            k=k|add;
        }
    }
    cout << minHouses(0,0,0) << "\n";
    return 0;
}
