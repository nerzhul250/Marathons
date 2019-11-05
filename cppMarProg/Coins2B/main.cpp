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

    int n,s;
    cin >> n >> s;
    int cnt=0;
    while(s!=0){
        cnt+=s/n;
        s=s%n;
        n--;
    }
    cout << cnt << endl;
}
