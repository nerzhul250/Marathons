#include <iostream>

using namespace std;
int n,ans[4][100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if(n%2==0){
        cout << "-1\n";
    }else{
        for(int i=0;i<n;i++){
            ans[2][i]=i;
            ans[0][i]=(2*n-2-i)%n;
            ans[1][i]=(2+i*2)%n;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
                if(j!=n-1){
                    cout << ans[i][j]<<" ";
                }else{
                    cout << ans[i][j]<<"\n";
                }
            }
        }
    }
}
