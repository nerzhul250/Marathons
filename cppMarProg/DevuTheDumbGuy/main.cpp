#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int ll ;
ll arr[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll x;
    cin >> n >> x;
    for(int i=0;i<n;i++)cin >> arr[i];
    sort(arr,arr+n);
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=(x*arr[i]);
        x=max((ll)1,x-1);
    }
    cout << sum << "\n";
    return 0;
}
