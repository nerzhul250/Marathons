#include <iostream>

using namespace std;
typedef long long ll;
ll x,y,d;

// store x, y, and d as global variables
void extendedEuclid(ll a, ll b) {
    if (b == 0) { x = 1; y = 0; d = a; return; } // base case
    extendedEuclid(b, a % b); // similar as the original gcd
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    while(n){
        ll c1,n1;
        ll c2,n2;
        cin >> c1 >> n1;
        cin >> c2 >> n2;
        ll a,b,e,f;
        a=n1<n2?n1:n2;
        b=n1<n2?n2:n1;
        e=n1<n2?c1:c2;
        f=n1<n2?c2:c1;
        extendedEuclid(a,b);
        if(n%d!=0){
            cout << "failed\n";
        }else{
            x*=(n/d);
            y*=(n/d);
            ll t=0;
            if(e>=f){
                if(x>0){
                    t=(x*d)/b;
                    t*=-1;
                }else if(x<0){
                    t=(x*d)/b;
                    t*=-1;
                    if((x+(b*t)/d)<0)t++;
                }
                x=(x+(b*t)/d);
                y=(y-(a*t)/d);
                if(x<0 || y<0){
                    cout << "failed\n";
                }else{
                    cout << (n1<n2?x:y) << " " << (n1<n2?y:x) << "\n";
                }
            }else{
                if(y>0){
                    t=(y*d)/a;
                }else if(y<0){
                    t=(y*d)/a;
                    if((y-(a*t)/d)<0)t--;
                }
                ll t2=0;

                if(x>0){
                    t2=(x*d)/b;
                    t2*=-1;
                }else if(x<0){
                    t2=(x*d)/b;
                    t2*=-1;
                    if((x+(b*t2)/d)<0)t2++;
                }

                if((y-(a*t2)/d)<0||(x+(b*t2)/d)<0|| (x+(b*t)/d)*e+(y-(a*t)/d)*f<(x+(b*t2)/d)*e+(y-(a*t2)/d)*f){
                    x=(x+(b*t)/d);
                    y=(y-(a*t)/d);
                }else{
                    x=(x+(b*t2)/d);
                    y=(y-(a*t2)/d);
                }
                if(x<0 || y<0){
                    cout << "failed\n";
                }else{
                    cout << (n1<n2?x:y) << " " << (n1<n2?y:x) << "\n";
                }
            }
        }
        cin >> n;
    }
    return 0;
}

