#include <iostream>

using namespace std;
typedef long long ll;
ll n,k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n){
        cin >> k;
        ll res=0;
        ll c=n,r=0;
        while(c!=0 || r>=k){
            res+=c;
            r+=c%k;
            c/=k;
            c+=r/k;
            r=r%k;
        }
        cout << res << "\n";
    }
    return 0;
}
