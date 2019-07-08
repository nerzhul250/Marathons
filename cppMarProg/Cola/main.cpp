#include <iostream>

using namespace std;
typedef long long ll;
ll n,k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n){
        ll maximum=-1;
        k=3;
        for(int i=0;i<3;i++){
            ll res=0;
            ll c=n,r=i;
            while(c!=0 || r>=k){
                res+=c;
                r+=c%k;
                c/=k;
                c+=r/k;
                r=r%k;
            }
            if(maximum<res && r>=i)maximum=res;
        }
        cout << maximum << "\n";
    }
    return 0;
}
