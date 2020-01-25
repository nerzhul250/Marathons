#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

int arr[100005],brs[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        fore(i,0,n)cin >> arr[i];
        fore(i,0,n)cin >> brs[i];
        int dif=0;
        int index=0;
        for(index=0;index<n;index++){
            if(brs[index]-arr[index]<0){
                dif=-1;
                break;
            }else if(brs[index]-arr[index]>0){
                dif=brs[index]-arr[index];
                break;
            }
        }
        if(dif<0){
            cout <<"NO\n";
        }else{
            int index2=0;
            for(index2=index;index2<n;index2++){
                if(brs[index2]-arr[index2]!=dif){
                    break;
                }
            }
            fore(i,index2,n){
                if(brs[i]-arr[i]!=0){
                    dif=-1;
                }
            }
            if(dif<0){
                cout << "NO\n";
            }else{
                cout << "YES\n";
            }
        }
    }
    return 0;
}
