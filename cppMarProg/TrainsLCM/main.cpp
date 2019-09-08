#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;
ll a,b;
ll gcd(ll c, ll d){return d==0 ? c :gcd(d,c%d);}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    ll lcm=(a*b)/gcd(a,b);
    ll timesa=lcm/a;
    ll timesb=lcm/b;
    if(a>b){
        timesb--;
    }else{
        timesa--;
    }
    if(timesa==timesb){
        cout << "Equal\n";
    }else if(timesa>timesb){
        cout << "Dasha\n";
    }else{
        cout << "Masha\n";
    }
    return 0;
}
