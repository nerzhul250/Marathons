#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

int z[1<<22];
int parents[1<<22];
int arr[1000005];
void solve(int mask,int parent){
    if(z[mask])return;
    z[mask]=1;
    parents[mask]=parent;
    for(int i=0;i<22;i++){
        solve(mask|(1<<i),parent);
    }
    return;
}
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
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        solve(arr[i],arr[i]);
    }
    for(int i=0;i<n;i++){
        int y=(-arr[i]-1)&((1<<22)-1);
        if(z[y]){
            cout << parents[y];
        }else{
            cout << "-1";
        }
        if(i==n+1){
            cout <<"\n";
        }else{
            cout << " ";
        }
    }
}
