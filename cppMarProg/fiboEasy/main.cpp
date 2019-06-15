#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

vector<vector<ll> > mm(vector<vector<ll> >&a,vector<vector<ll> >&b){
    vector<vector<ll> > ans;
    ans.push_back(vector<ll>(2));
    ans.push_back(vector<ll>(2));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ll res=0;
            for(int k=0;k<2;k++){
                res+=(a[i][k]*b[k][j])%MOD;
            }
            ans[i][j]=res%MOD;
        }
    }
    return ans;
}

vector<vector<ll> > modExp(int n){
    vector<vector<ll> > res;
    res.push_back(vector<ll>(2));
    res.push_back(vector<ll>(2));
    res[0][0]=1;res[0][1]=0;
    res[1][0]=0;res[1][1]=1;
    vector<vector<ll> > pow;
    pow.push_back(vector<ll>(2));
    pow.push_back(vector<ll>(2));
    pow[0][0]=1;pow[0][1]=1;
    pow[1][0]=1;pow[1][1]=0;
    if(n==0)return pow;
    int power=1;
    int index=0;
    int upperBound=log2(n)+1;
    while(index<upperBound){
        if(power&n){
            res=mm(res,pow);
        }
        pow=mm(pow,pow);
        index++;
        power=power<<1;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll a,b;
        int n;
        cin >> a >> b >> n;
        n--;
        if(n==0){
            cout << b << endl;
        }else{
            vector<vector<ll> > res=modExp(n);
            cout << (res[0][0]*b+res[0][1]*a)%MOD << endl;
        }
    }
    return 0;
}
