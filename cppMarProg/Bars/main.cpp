#include <iostream>

using namespace std;

typedef long long ll;

ll sum[(1<<20)+5];
ll arr[25];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        ll n;
        int p;
        cin >> n;
        cin >> p;
        for(int i=0;i<p;i++){cin >> arr[i];sum[1<<i]=arr[i];}
        int found=0;
        for(int i=0;i<(1<<p) &&!found;i++){sum[i]=sum[i-((i-1)&i)]+sum[((i-1)&i)];if(sum[i]==n)found=1;}
        if(found){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
