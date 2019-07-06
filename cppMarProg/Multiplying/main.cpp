#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

unordered_map<ll,ll> dp;
vector<ll> divisors;
ll N,B;

ll best(ll k){
    if(k<B)return k;
    if(dp.find(k)!=dp.end())return dp[k];
    ll sol=-1;
    for(int i=0;i<divisors.size();i++){
        ll d=divisors[i];
        if(k%d==0){
            ll b=best(k/d);
            if(b>((LLONG_MAX-d)/B))continue;
            ll bestOfNow=b*B+d;
            sol=(sol==-1?bestOfNow:min(bestOfNow,sol));
        }
    }
    return dp[k]=sol;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> B >> N;
    for(ll d=2;d<B;d++){
        if(N%d==0)divisors.push_back(d);
    }
    cout << best(N)<<"\n";
    return 0;
}
