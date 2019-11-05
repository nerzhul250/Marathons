#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    int n;
    while(cin >> n){
        if(n%6==0){
            cout << "Y\n";
        }else{
            cout << "N\n";
        }
    }
}
