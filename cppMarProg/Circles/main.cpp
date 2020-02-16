#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x,y;
    cin >> x >> y;

    int pos1 = 0, pos2 = 0;
    for (int i = 0; i < x.size(); i++){
        if (x[x.size() - 1 - i] == '.'){
            pos1 = i;
            break;
        }
    }

    for (int i = 0; i < y.size(); i++){
        if (y[y.size() - 1 - i] == '.'){
            pos2 = i;
            break;
        }
    }

    ll x1 = 0;
    ll y1 = 0;
    for (int i =0; i < x.size(); i++){
        char act = x[i];
        if (act == '.')
            continue;
        x1 *= 10;
        x1 += (act - '0');
    }

    for (int i =0; i < y.size(); i++){
        char act = y[i];
        if (act == '.')
            continue;
        y1 *= 10;
        y1 += (act - '0');
    }

    if (pos1 < pos2)
        x1 *= pow(10, pos2-pos1);

    if (pos2 < pos1)
        y1 *= pow(10, pos1-pos2);
    cout << x1 << " "<<y1<<endl;

    ll rem=x1%y1;
    ll quot=(x1-rem)/y1;
    cout << quot << "\n";
}
