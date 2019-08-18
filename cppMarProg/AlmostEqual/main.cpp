#include <iostream>

using namespace std;
int n,ans[500005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if(n%2==1){
        cout << "YES" << "\n";
        int flag=1;
        for(int i=1;i<=2*n;i+=2){
            if(flag){
                ans[(i-1)/2]=i;
                ans[((i-1)/2)+n]=i+1;
            }else{
                ans[(i-1)/2]=i+1;
                ans[((i-1)/2)+n]=i;
            }
            flag=1-flag;
        }
        for(int i=0;i<2*n;i++){
            if(i==2*n-1){
                cout << ans[i] << "\n";
            }else{
                cout << ans[i] << " ";
            }
        }
    }else{
        cout << "NO\n";
    }
    return 0;
}
