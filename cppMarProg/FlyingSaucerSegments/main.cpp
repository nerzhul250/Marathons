#include <iostream>

using namespace std;
typedef long long int ll;
int n;
ll m;
ll ans(int exp){
    ll res=1;
    ll base=3;
    while(exp>0){
        if(exp&1)res=(res*base)%m;
        exp=exp>>1;
        base=(base*base)%m;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n>> m;
    ll toAdd=m-1;
    cout << (ans(n)+toAdd)%m << "\n";
    return 0;
}
