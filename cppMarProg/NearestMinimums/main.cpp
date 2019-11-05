#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
int arr[100005];
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
    }
    int minimo=arr[0];
    int index=0;
    int closest=1000000;
    for(int i=1;i<n;i++){
        if(arr[i]==minimo){
            closest=min(closest,i-index);
            index=i;
        }else if(arr[i]<minimo){
            minimo=arr[i];
            index=i;
            closest=1e6;
        }
    }
    cout << closest << endl;
}
