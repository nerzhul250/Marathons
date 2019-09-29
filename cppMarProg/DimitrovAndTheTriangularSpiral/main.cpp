#include <iostream>

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        ll x,y;
        cin >> x >> y;
        if((x>=0 && y>=0) || (y<0 && -2*y<=x)){
            ll N=x+y;
            ll initMov=(2*N-1)*2*N;
            cout << initMov+x+1 << "\n";
        }else if((x<0 && y>=0) || (y<0 && 2*y-1>=x)){
            ll N=y-x;
            ll initMov=(2*N-1)*2*N;
            cout << initMov+x+1 << "\n";
        }else{
            ll xd=-2*y;
            ll N= xd+y;
            ll initMov=(2*N-1)*2*N+xd;
            cout << initMov+abs(x-xd)+1 << "\n";
        }
    }
    return 0;
}
