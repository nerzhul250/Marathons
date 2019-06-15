#include <iostream>

using namespace std;
typedef long long ll;
int main()
{
    ll x,y;
    cin >> x >> y;
    while(!(x==0 && y==0)){
        ll n=x+y-1;
        ll suma=n*(n+1);
        suma/=2;
        if(n%2==0){
           cout << -y+1+suma << endl;
        }else{
            cout << suma-x+1 << endl;
        }
        cin >> x >> y;
    }
    return 0;
}
